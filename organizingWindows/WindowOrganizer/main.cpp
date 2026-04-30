#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

struct WindowConfig {
    wstring partialName;
    int x, y, w, h;
};

struct SearchData {
    wstring target;
    HWND result;
};


BOOL CALLBACK EnumProc(HWND hwnd, LPARAM lParam) {
    SearchData* data = (SearchData*)lParam;
    wchar_t title[256];
    GetWindowTextW(hwnd, title, 256);
    wstring currentTitle(title);

    if (currentTitle.find(data->target) != wstring::npos) {
        data->result = hwnd;
        return FALSE;
    }
    return TRUE;
}

HWND FindMyWindow(wstring part) {
    SearchData data = {part, NULL};
    EnumWindows(EnumProc, (LPARAM)&data);
    return data.result;
}


void OrganizeWorkspace(const vector<WindowConfig>& layout) {
    for (const auto& config : layout) {
        HWND hwnd = FindMyWindow(config.partialName);
        if (hwnd) {
            MoveWindow(hwnd, config.x, config.y, config.w, config.h, TRUE);
        }
    }
}



int main() {

    vector<WindowConfig> myLayout = {
        {L"Brave", 1913, 158, 1094, 943},
        {L"Steam", 1920, -778, 1080, 936},
        {L"Discord", 1920, -778, 1080, 936},
        {L"Spotify", 1913, 158, 1094, 943},
        {L"Microsoft Store", 1913, 158, 1094, 943},
        {L"Wallpaper", 1913, 158, 1094, 943},
        {L"Settings", 1913, 158, 1094, 943},
        {L"File Explorer", 1913, 158, 1094, 943},
        {L"Free Download Manager", 1913, 158, 1094, 943},
        {L"Telegram", 1913, 158, 1094, 943}
    };



    if (!RegisterHotKey(NULL, 1, MOD_ALT, VK_F11)) {
        return 1;
    }

    MSG msg = {0};

    while (GetMessage(&msg, NULL, 0, 0)) {
        if (msg.message == WM_HOTKEY) {
            if (msg.wParam == 1) {
                OrganizeWorkspace(myLayout);
            }
        }
    }

    return 0;
}
