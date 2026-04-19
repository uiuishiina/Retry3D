#pragma once
#include"LoggerBase.h"

class DebugWindowLogger final : public LoggerBase
{
public:
	DebugWindowLogger() = default;
	~DebugWindowLogger() = default;

	/*
	 * @brief	ログ出力派生関数
	 * @param	log	ログメッセージ構造体
	 */
	void OutPut(const LogStruct::LogMessage& log)override;

	/*
	 * @brief	ログ改行派生関数
	 * @param	BreakLengh	改行する段落数
	 */
	void LineBreak(const size_t BreakLength)override;
};