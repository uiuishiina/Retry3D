#pragma once
#include"LoggerBase.h"

class DebugWindowLogger final : public LoggerBase
{
public:
	explicit DebugWindowLogger(LogStruct::ContextVisibility flags = LogStruct::ContextVisibility::None) :
		LoggerBase(flags) {	//継承かつBaseのコンストラクタを作っているため呼び出す必要がある
	};
	~DebugWindowLogger() = default;

	/*
	 * @brief	ログ出力派生関数
	 * @param	log	ログメッセージ構造体
	 */
	void OutPut(const LogStruct::LogMessage& log)override;

	/*
	 * @brief	ログ改行派生関数
	 * @param	BreakLength	改行する段落数
	 */
	void LineBreak(const size_t BreakLength)override;
};