#pragma once
//=====================================================================//
/*!	@file
	@brief	シーンＩＤ
			Copyright 2017 Kunihito Hiramatsu
	@author	平松邦仁 (hira@rvf-rc45.net)
*/
//=====================================================================//

namespace app {

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	/*!
		@brief	ルート・メニュー・クラス
	*/
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	enum class scene_id {
		root_menu,		///< ルート・メニュー

		logging,		///< ロギング
		recall,			///< リコール
		setup,			///< セットアップ
	};

}

