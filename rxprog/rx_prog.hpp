#pragma once
//=====================================================================//
/*!	@file
	@brief	RX programmer クラス
	@author	平松邦仁 (hira@rvf-rc45.net)
*/
//=====================================================================//
#include "rx63t_protocol.hpp"
#include "rx24t_protocol.hpp"
#include "rx64m_protocol.hpp"
#include <boost/format.hpp>
#include <boost/variant.hpp>

namespace rx {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief	rx_prog クラス
	 */
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	class prog {
		bool		verbose_;

		utils::rs232c_io	rs232c_;

		using protocol_type = boost::variant<rx63t::protocol, rx24t::protocol, rx64m::protocol>;
		protocol_type protocol_;

		std::string out_section_(uint32_t n, uint32_t num) const {
			return (boost::format("#%02d/%02d: ") % n % num).str();
		}

		struct bind_visitor {
			using result_type = bool;

			const std::string& path_;
			uint32_t brate_;
			const rx::protocol::rx_t& rx_;

			bind_visitor(const std::string& path, uint32_t brate, const rx::protocol::rx_t& rx) :
				path_(path), brate_(brate), rx_(rx) { }

    		template <class T>
    		bool operator()(T& x) {
				return x.bind(path_, brate_, rx_);
			}
		};


		struct erase_page_visitor {
			using result_type = bool;

			uint32_t adr_;
			erase_page_visitor(uint32_t adr) : adr_(adr) { }

    		template <class T>
    		bool operator()(T& x) {
				return x.erase_page(adr_);
			}
		};


		struct read_visitor {
			using result_type = bool;

			uint32_t adr_;
			uint8_t* dst_;
			uint32_t len_;
			read_visitor(uint32_t adr, uint8_t* dst, uint32_t len) : adr_(adr), dst_(dst), len_(len) { }

    		template <class T>
    		bool operator()(T& x) {
				return x.read(adr_, dst_, len_);
			}
		};


		struct select_write_visitor {
			using result_type = bool;

			bool	data_;
			select_write_visitor(bool data) : data_(data) { }

    		template <class T>
    		bool operator()(T& x) {
				return x.select_write_area(data_);
			}
		};


		struct write_visitor {
			using result_type = bool;

			uint32_t adr_;
			const uint8_t* src_;
			write_visitor(uint32_t adr, const uint8_t* src) : adr_(adr), src_(src) { }

    		template <class T>
    		bool operator()(T& x) {
				return x.write_page(adr_, src_);
			}
		};


		struct end_visitor {
			using result_type = void;

    		template <class T>
    		void operator()(T& x) {
				x.end();
			}
		};

	public:
		//-------------------------------------------------------------//
		/*!
			@brief	コンストラクター
		*/
		//-------------------------------------------------------------//
		prog(bool verbose = false) : verbose_(verbose) { }


		//-------------------------------------------------------------//
		/*!
			@brief	接続速度を変更する
			@param[in]	path	シリアル・デバイス・パス
			@param[in]	brate	ボーレート
			@param[in]	rx		CPU 設定
			@return エラー無ければ「true」
		*/
		//-------------------------------------------------------------//
		bool start(const std::string& path, uint32_t brate, const rx::protocol::rx_t& rx)
		{
			if(rx.cpu_type_ == "RX63T") {
				protocol_ = rx63t::protocol();
			} else if(rx.cpu_type_ == "RX24T") {
				protocol_ = rx24t::protocol();
			} else if(rx.cpu_type_ == "RX64M") {
				protocol_ = rx64m::protocol();
			} else {
				std::cerr << "CPU type missmatch: '" << rx.cpu_type_ << "'" << std::endl;
				return false;
			}


			{  // 開始
				bind_visitor vis(path, brate, rx);
            	if(!boost::apply_visitor(vis, protocol_)) {
					end();
					return false;
				}
			}

			return true;
		}


		//-------------------------------------------------------------//
		/*!
			@brief	ページ消去
			@param[in]	adr	開始アドレス
			@return 成功なら「true」
		*/
		//-------------------------------------------------------------//
		bool erase_page(uint32_t adr) {
			erase_page_visitor vis(adr);
           	if(!boost::apply_visitor(vis, protocol_)) {
				end();
				std::cerr << std::endl << boost::format("Erase page error: %08X") % adr << std::endl;
				return false;
			}
			return true;
		}


		//-------------------------------------------------------------//
		/*!
			@brief	リード
			@param[in]	adr	開始アドレス
			@param[out]	dst	書き込みアドレス
			@param[in]	len	読み出しサイズ
			@return 成功なら「true」
		*/
		//-------------------------------------------------------------//
		bool read(uint32_t adr, uint8_t* dst, uint32_t len) {
			read_visitor vis(adr, dst, len);
           	if(!boost::apply_visitor(vis, protocol_)) {
				end();
				std::cerr << "Read error." << std::endl;
				return false;
			}
			return true;
		}


		//-------------------------------------------------------------//
		/*!
			@brief	ベリファイ
			@param[in]	adr	開始アドレス
			@param[in]	src	書き込みアドレス
			@param[in]	len	読み出しサイズ
			@return 成功なら「true」
		*/
		//-------------------------------------------------------------//
		bool verify(uint32_t adr, const uint8_t* src, uint32_t len) {
			std::vector<uint8_t> dev;
			dev.resize(len);
			if(!read(adr, &dev[0], len)) {
				return false;
			}
			uint32_t errcnt = 0;
			for(auto d : dev) {
				auto m = *src++;
				if(d != m) {
					++errcnt;
					if(verbose_) {
						std::cerr << (boost::format("0x%08X: D(%02X) to M(%02X)") % adr %
							static_cast<uint32_t>(d) % static_cast<uint32_t>(m)) << std::endl;
					}
				}
				++adr;
			}
			if(errcnt > 0) {
				std::cerr << "Verify error: " << errcnt << std::endl;
				return false;
			}
			return true;
		}


		//-------------------------------------------------------------//
		/*!
			@brief	ライト開始
			@param[in]	data	「true」ならデータ領域
			@return 成功なら「true」
		*/
		//-------------------------------------------------------------//
		bool start_write(bool data) {
			select_write_visitor vis(data);
           	if(!boost::apply_visitor(vis, protocol_)) {
				end();
				std::cerr << "Write start error.(first)" << std::endl;
				return false;
			}
			return true;
		}


		//-------------------------------------------------------------//
		/*!
			@brief	ライト（２５６バイト）
			@param[in]	adr	開始アドレス
			@param[in]	src	書き込みアドレス
			@return 成功なら「true」
		*/
		//-------------------------------------------------------------//
		bool write(uint32_t adr, const uint8_t* src) {
			write_visitor vis(adr, src);
           	if(!boost::apply_visitor(vis, protocol_)) {
				end();
				std::cerr << "Write body error." << std::endl;
				return false;
			}
			return true;
		}


		//-------------------------------------------------------------//
		/*!
			@brief	ライト終了
			@return 成功なら「true」
		*/
		//-------------------------------------------------------------//
		bool final_write() {
			write_visitor vis(0xffffffff, nullptr);
           	if(!boost::apply_visitor(vis, protocol_)) {
				end();
				std::cerr << "Write final error. (fin)" << std::endl;
				return false;
			}
			return true;
		}


		//-------------------------------------------------------------//
		/*!
			@brief	終了
		*/
		//-------------------------------------------------------------//
		void end() {
			end_visitor vis;
           	boost::apply_visitor(vis, protocol_);
		}
	};
}
