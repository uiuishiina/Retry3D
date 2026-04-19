#include"DebugWindowLogger.h"
#include<Windows.h>
#include<sstream>

//@brief	ログ出力関数本体
static void OutPutMessage(const char* message)noexcept {
	OutputDebugStringA(message);
}

void DebugWindowLogger::OutPut(const LogStruct::LogMessage& log) {
	//構造体分解
	const auto& [level, context, message] = log;
	std::ostringstream oss;

	//ログレベル文字列変換
	const auto level_str = LogStruct::LevelToString(level);
	oss << "[ " << level_str << " ]" << message;

	if (LogStruct::HasVisibilityFlag(ContextFlags_, LogStruct::LevelToVisibility(level))) {
		if (context.HasValue()) {
			oss << "\n" << "[ " << context.function_ << " ]" << "[ " << context.file_ << " ]" << "[ " << context.line_ << " ]";
		}
	}

	const auto str = oss.str();
	OutPutMessage(str.c_str());
	LineBreak(1);
}

void DebugWindowLogger::LineBreak(const size_t BreakLength) {
	for (size_t i = 0; i < BreakLength; i++) {
		OutPutMessage("\n");
	}
}