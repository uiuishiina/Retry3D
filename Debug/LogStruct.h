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

	//@brief	===  ログレベル文字列変換関数  ===
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

	//@brief	ログ詳細表示ビットフラグ
	enum class ContextVisibility : uint8_t {
		None = 0,
		Info = 1 << 0,
		Warning = 1 << 1,
		Error = 1 << 2,
		All = Info | Warning | Error
	};

	/*
	 * @brief	===  ログ詳細表示ビットフラグ追加演算子  ===
	 * @param	lhs 左辺
	 * @param	rhs 右辺
	 */
	constexpr ContextVisibility operator|(ContextVisibility lhs, ContextVisibility rhs) {
		//bitをかけ合わせて[0]のところに[1]が入ると[1]になる
		return static_cast<ContextVisibility>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
	}

	/*
	 * @brief	===  ログレベルビットフラグ変換関数  ===
	 * @param	level	ログレベル
	 */
	constexpr ContextVisibility LevelToVisibility(Level level) noexcept {
		switch (level) {
		case Level::Info:    return ContextVisibility::Info;
		case Level::Warning: return ContextVisibility::Warning;
		case Level::Error:   return ContextVisibility::Error;
		}
		return ContextVisibility::None;
	}

	/*
	 * @brief	ログ詳細表示ビットフラグ判定関数
	 * @param	flags	表示設定フラグ
	 * @param	flag	所持確認対象フラグ
	 */
	constexpr bool HasVisibilityFlag(ContextVisibility flags, ContextVisibility flag) {

		return (static_cast<uint8_t>(flags) & static_cast<uint8_t>(flag)) != 0;
	}

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