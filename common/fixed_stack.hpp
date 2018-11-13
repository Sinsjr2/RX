#pragma once
//=====================================================================//
/*!	@file
	@brief	固定サイズ・スタック・クラス
    @author 平松邦仁 (hira@rvf-rc45.net)
	@copyright	Copyright (C) 2017, 2018 Kunihito Hiramatsu @n
				Released under the MIT license @n
				https://github.com/hirakuni45/RX/blob/master/LICENSE
*/
//=====================================================================//
#include <cstdint>

namespace utils {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief  fixed_stack class
		@param[in]	UNIT	ユニット型
		@param[in]	SIZE	サイズ
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	template <typename UNIT, uint32_t SIZE>
	class fixed_stack {
	public:
		typedef UNIT	value_type;

	private:
		UNIT		stack_[SIZE];
		uint32_t	pos_;

	public:
		//-----------------------------------------------------------------//
		/*!
			@brief  コンストラクタ
		*/
		//-----------------------------------------------------------------//
		fixed_stack() noexcept : pos_(0) { }


		//-----------------------------------------------------------------//
		/*!
			@brief  格納可能な最大サイズを返す
			@return 格納可能な最大サイズ
		*/
		//-----------------------------------------------------------------//
		uint32_t capacity() const noexcept { return SIZE; }


        //-----------------------------------------------------------------//
        /*!
            @brief  クリア
        */
        //-----------------------------------------------------------------//
		void clear() noexcept { pos_ = 0; }


		//-----------------------------------------------------------------//
		/*!
			@brief  要素数を返す
			@return 要素数
		*/
		//-----------------------------------------------------------------//
		uint32_t size() const noexcept { return pos_; }


		//-----------------------------------------------------------------//
		/*!
			@brief  コンテナが空か？
			@return 空なら「true」
		*/
		//-----------------------------------------------------------------//
		bool empty() const noexcept { return pos_ == 0; }


		//-----------------------------------------------------------------//
		/*!
			@brief  先頭の要素参照
			@return 先頭の要素
		*/
		//-----------------------------------------------------------------//
		const UNIT& top() const noexcept { return stack_[0]; }


		//-----------------------------------------------------------------//
		/*!
			@brief  要素の参照
			@return 要素
		*/
		//-----------------------------------------------------------------//
		const UNIT& at() const noexcept { return stack_[pos_]; }


		//-----------------------------------------------------------------//
		/*!
			@brief  プッシュ
			@return 成功なら「true」
		*/
		//-----------------------------------------------------------------//
		bool push(const UNIT& u) noexcept
		{
			if(pos_ >= SIZE) {
				return false;
			}

			stack_[pos_] = u;
			++pos_;
			return true;
		}


		//-----------------------------------------------------------------//
		/*!
			@brief  ポップ @n
					※格納要素が無い場合、要素型の初期値が返される。
			@return 要素を返す
		*/
		//-----------------------------------------------------------------//
		const UNIT& pop() noexcept
		{
			if(pos_ == 0) {
				static const UNIT u;
				return u;
			}
			--pos_;
			return stack_[pos_];
		}
	};
}
