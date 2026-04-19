#pragma once
#include"LoggerBase.h"
#include<vector>
#include<memory>
#include<sstream>


using Level = LogStruct::Level;
using LogContext = LogStruct::LogContext;

//マクロ

#define DEBUG_INITIALIZE(expr)	Debug::Instance().Initialize(expr)
#define DEBUG_ADDLOGGER(expr)	Debug::Instance().AddLogger(expr)

#define LOG_CONTEXT() (LogContext{__func__, __FILE__, __LINE__})
#define LOG_CONTEXT_NONE() LogContext{}

#define	DEBUG_LOG(expr,...)	Debug::Instance().DebugLog(expr,LOG_CONTEXT(),__VA_ARGS__)
#define	DEBUG_LINEBREAK(BreakLength)	Debug::Instance().DebugLineBreak(BreakLength)

//====================================================================================================

//@brief	デバッグクラス
class Debug final
{
	Debug() = default;
	~Debug() = default;

	std::vector<std::shared_ptr<LoggerBase>> Loggers_{};

public:
	//@brief	デバッグシステムインスタンス
	static Debug& Instance()noexcept {
		static Debug ins;
		return ins;
	}

	/*
	 *	@brief	===  デバッグシステム初期化関数  ===
	 *	@param	Logger	ログ出力クラス
	 */
	void Initialize(std::shared_ptr<LoggerBase> Logger);

	/*
	 *	@brief	===  デバッグシステム追加関数  ===
	 *	@param	Logger	追加ログ出力クラス
	 */
	void AddLogger(std::shared_ptr<LoggerBase> Logger);

	/*
	 *	@brief	===  デバッグログ出力関数  ===
	 *	@param	LogLevel::Level	出力ログレベル
	 *	@param	args	出力ログパラメーターパック
	 */
	template<typename... Args>
	void DebugLog(Level level,const LogContext& context, Args&&...args) {
		//ログに変換
		std::ostringstream oss;
		((oss << std::forward<Args>(args) << " "), ...);
		LogStruct::LogMessage log = { level,context,oss.str() };

		//ログ出力クラス全体に流す
		for (auto& pLogger : Loggers_) {
			pLogger->OutPut(log);
		}
	};

	void DebugLineBreak(const size_t BreakLength) {
		//ログ出力クラス全体に流す
		for (auto& pLogger : Loggers_) {
			pLogger->LineBreak(BreakLength);
		}
	}
};