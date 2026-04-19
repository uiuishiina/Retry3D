#include<Windows.h>
#include"window.h"

/*
 * @brief	=== ウィンドウ作成関数 ===
 * @param	hInstance	ウィンドウインスタンス
 * @param	width		ウィンドウの横幅
 * @param	height		ウィンドウの縦幅
*/
[[nodiscard]] bool window::Create(HINSTANCE hInstance, int width, int height) {
	return false;
}

//@brief	===  ウィンドウハンドル取得関数  ===
[[nodiscard]] HWND window::GetHWND()const noexcept {
	return hwnd_;
}

//@brief	===  ウィンドウサイズ取得関数  ===
[[nodiscard]] std::pair<int, int> window::GetWindowSize()const noexcept {
	return window_size;
}