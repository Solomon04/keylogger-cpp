#include <fstream>
#include <iostream>
#include <sstream> //std::stringstream
#include <windows.h>

using namespace std;

int main(){

    rename("C:\\Users\\Dell\\Desktop\\Google Chrome.LNK", "C:\\Users\\Dell\\Desktop\\Browse.LNK");

    ifstream inFile;
    inFile.open("shortcut.vbs"); //open the input file
 
    stringstream strStream;
    strStream << inFile.rdbuf();       //read the file
    string str = strStream.str(); //str holds the content of the file

    //Prepare Executable shell command
    string exe = "C:\\Windows\\System32\\cscript.exe temp.vbs";
    //Create temporary vbs file
    ofstream tmpFile;
    tmpFile.open("temp.vbs", ios_base::app);
    tmpFile << str;
    tmpFile.close(); 
    LPSTR command = const_cast<char *>(exe.c_str());

    //Run Executable shell command
    system(command); 
   
   //Delete temporary vbs file
    remove("temp.vbs"); 

    return 0;
}