#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    HWND hwnd = FindWindowW(NULL, L"Steam");

    if(hwnd == NULL) {
        cout << "There is no window. "<<endl ;
        return 1;

    }
   RECT rect;

   if (GetWindowRect(hwnd, &rect)){
       int width = rect.right - rect.left;
       int height = rect.bottom - rect.top;

       cout << "The current Coordinates "<<endl;
       cout << "X (left): "<<rect.left<<endl;
       cout << "y (top): "<<rect.top<<endl;
       cout << "Width: "<<width<<endl;
       cout << "Height: "<<height<<endl;

   }
    return 0;
}
