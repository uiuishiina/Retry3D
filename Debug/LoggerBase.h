#pragma once
#include"LogStruct.h"

//@brief	Log出力基底クラス
class LoggerBase
{
protected:
	LogStruct::ContextVisibility ContextFlags_ = LogStruct::ContextVisibility::None;
public:
	explicit LoggerBase(LogStruct::ContextVisibility flags = LogStruct::ContextVisibility::None) :
		ContextFlags_(flags) {};
	virtual ~LoggerBase() = default;

	/*
	 * @brief	ログ出力基底関数
	 * @param	log	ログメッセージ構造体
	 */
	virtual void OutPut(const LogStruct::LogMessage& log) = 0;

	/*
	 * @brief	ログ改行基底関数
	 * @param	BreakLength	改行する段落数
	 */
	virtual void LineBreak(const size_t BreakLength) = 0;
};