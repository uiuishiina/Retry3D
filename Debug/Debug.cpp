#include"Debug.h"

/*
 *	@brief	===  デバッグシステム初期化関数  ===
 *	@param	Logger	ログ出力クラス
 */
void Debug::Initialize(std::shared_ptr<LoggerBase> Logger) {

	Loggers_.clear();
	Loggers_.push_back(Logger);
}

/*
 *	@brief	===  デバッグシステム追加関数  ===
 *	@param	Logger	追加ログ出力クラス
 */
void Debug::AddLogger(std::shared_ptr<LoggerBase> Logger) {
	Loggers_.push_back(Logger);
}