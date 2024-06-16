#include <iostream>  
#include <string>
#include <windows.h>
using namespace std;

void copyToClipboard(const string& text) {
    const size_t len = text.length() + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), text.c_str(), len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
}

int main() {
    string original;
    while(true){
        
        //recieves user input
        getline(cin, original);

        int count = 1;
        string newStr = "";

        for(char c : original) {
            //capitalize every other letter    
            if(count % 2 == 0){
                //if the letter is lowercase, switch them to upper, vice versa
                if(c >= 'a' && c <= 'z') newStr += (char)(c - 32);
                else if(c >= 'A' && c <= 'Z') newStr  += (char)(c+32);

                else newStr += c;
            }
            else{
                newStr += c;
            }

            count++;
        }
        cout << newStr << endl;
        cout << "^ copied to clipboard ^" << endl;
        copyToClipboard(newStr);
    }

    return 0;
}