#pragma once
#include<memory>

struct HWND__;
using HWND = HWND__*;

struct HINSTANCE__;
using HINSTANCE = HINSTANCE__*;

/**
 * @brief	windowクラス
 */
class window final
{
	HWND hwnd_;			//ウィンドウハンドル
	std::pair<int, int> window_size;	//ウィンドウサイズ
public:
	window() = default;
	~window() = default;
	
	/*
	 * @brief	=== ウィンドウ作成関数 ===
	 * @param	hInstance	ウィンドウインスタンス
	 * @param	width		ウィンドウの横幅
	 * @param	height		ウィンドウの縦幅
	*/
	[[nodiscard]] bool Create(HINSTANCE hInstance,int width,int height);

	//@brief	===  ウィンドウハンドル取得関数  ===
	[[nodiscard]] HWND GetHWND()const noexcept;

	//@brief	===  ウィンドウサイズ取得関数  ===
	[[nodiscard]] std::pair<int, int> GetWindowSize()const noexcept;
};