#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;;

string* folders = {};
string* files = {};
string inputStr = "";
int inputInt = 0;
char buff;

void createFolder(string str, int inter) {

    folders = new string[inter];

    for (int i = 0; i < inter; i++) {
        str += str[str.length() - 1];
        folders[i] = str;
    }
}

string converter(string str) {
    string outStr;
    for (int i = 0; i < str.length(); i++) {

    }
}

int main()
{
    cout << "Input the folder name\n";
    cin >> inputStr;
    cout << "Input cout of folder\n";
    cin >> inputInt;

    createFolder(inputStr, inputInt);
    for (int i = 0; i < inputInt; i++) {
        cout << "\n" << folders[i];
    }
}
