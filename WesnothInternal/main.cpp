#include<windows.h>

void Injected_thread() {
	while (true) {
		if (GetAsyncKeyState('T')) {
			DWORD* player_Base = (DWORD*)0x017EED18;
			DWORD* game_Base = (DWORD*)(*player_Base + 0xA90);
			DWORD* gold = (DWORD*)(*game_Base + 4);
			*gold = 444;
		}
	
		Sleep(1);
	}
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {


	MessageBox(NULL, L"Hello, World!", L"Message", MB_OK);
	if (fdwReason == DLL_PROCESS_ATTACH) {
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Injected_thread, NULL, 0, NULL);
	}

	return TRUE;
}