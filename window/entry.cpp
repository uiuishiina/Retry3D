#include<Windows.h>
#include"../Debug/Debug.h"
#include"../Debug/DebugWindowLogger.h"

int WINAPI WinMain(HINSTANCE hInstance ,HINSTANCE, LPSTR, int) {
	
	DEBUG_INITIALIZE(std::make_shared<DebugWindowLogger>());
	DEBUG_LOG(Level::Info, "aaa");
	return 0;
}