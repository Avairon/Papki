#include <iostream>
#include <string>

using std::cout;
using std::cin;
using namespace std;;

string* folders = {};
string* files = {};
string inputStr = "";
float inputInt;
char buff;

bool check(string str) {
    char buff;
    for (int i = 0; i < str.length(); i++) {
        buff = str[i];
        if (buff == '.') {
            return true;
        }
    }
    return false;
}

void createFolder(string str, int inter) {

    folders = new string[inter];

    for (int i = 0; i < inter; i++) {
        str += str[str.length() - 1];
        folders[i] = str;
    }
}

string expansion(string str) {
    string outStr = "";
    char buff;

    for (int i = str.length(); i > 0; i -= 1) {
        buff = str[i];
        if (buff == '.') {
            for (int a = i; a < str.length(); a++) {
                buff = str[a];
                outStr += buff;
            }
            break;
        }
    }

    return outStr;
}

string converter(string str) {
    string outStr = "";
    char buff;
    for (int i = 0; i < str.length(); i++) {
        buff = str[i];
        if (buff == '.') break;
        outStr += buff;
    }
    return outStr;
}

void createFile(string str, int inter) {
    string buff;
    string buff2;

    files = new string[inter];

    buff = expansion(str);
    str = converter(str);

    for (int i = 0; i < inter; i++) {
        str += str[str.length() - 1];

        buff2 = str + buff;

        files[i] = buff2;
    }
}

int main()
{
    //int checkInt;

    cout << "\nInput the folder name: ";
    cin >> inputStr;
    cout << "\nInput cout of folder: ";
    cin >> inputInt;

    while (inputInt > 255) {
        cout << "You cant write count > 255! Please, try again\n";
        cout << "\nInput cout of folder: ";
        cin >> inputInt;
    }

    /*_______I CANT FIX IT______
    
     checkInt = inputInt;
     while (checkInt != inputInt) {
        cout << "Uncorrect nubber! Please, try again\n";
        cout << "\nInput cout of folder: ";
        cin >> inputInt;
    }

    */
    
    createFolder(inputStr, inputInt);

    cout << "\nCreated folders:";
    for (int i = 0; i < inputInt; i++) {
        cout << "\n" << folders[i];
    }
    cout << "\n";

    cout << "\nInput the file name: ";
    cin >> inputStr;

    while (!check(inputStr)) {
        cout << "Uncorrect file format! Please, try again\n";
        cout << "\nInput the file name: ";
        cin >> inputStr;
    }

    cout << "\nInput cout of files: ";
    cin >> inputInt;

    while (inputInt > 255) {
        cout << "You cant write count > 255! Please, try again\n";
        cout << "\nInput cout of files: ";
        cin >> inputInt;
    }

    createFile(inputStr, inputInt);

    /*
    ____________DEBUG____________
    cout << "Exp: " << expansion(inputStr) << "\n";
    cout << "Conv: " << converter(inputStr) << "\n";
    */
    cout << "\nCreated files:";
    for (int i = 0; i < inputInt; i++) {
        cout << "\n" << files[i];
    }
    cout << "\n";
}
