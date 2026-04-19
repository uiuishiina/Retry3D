#pragma once
#include<string>

namespace LogStruct
{
	//@brief	ログレベル
	enum class Level {
		Info,
		Warning,
		Error,
	};

	//@brief	===  ログレベル変換関数  ===
	inline constexpr std::string_view LevelToString(Level level)noexcept {
		switch (level)
		{
		case Level::Info:	return "Info";
		case Level::Warning:	return "Warning";
		case Level::Error:	return "Error";
		default: return "Unknown";
		}
	}

	/*
	 * @brief	ログ詳細構造体
	 * @param	function	呼び出し関数名
	 * @param	file	呼び出しファイル名
	 * @param	line	呼び出しファイル行番号
	 */
	struct LogContext {
		std::string_view function_;
		std::string_view file_;
		int line_ = -1;

		LogContext() = default;
		LogContext(std::string_view func, std::string_view file, int line) :
			function_(func), file_(file), line_(line) {
		};

		bool HasValue() const noexcept {
			return line_ >= 0;
		}
	};
	

	/*
	 * @brief	ログメッセージ構造体
	 * @param	Level	ログレベル
	 * @param	context	ログ詳細構造体
	 * @param	message	ログメッセージ
	 */
	struct LogMessage {
		Level level_{};
		LogContext context_{};
		std::string message_{};
	};
}