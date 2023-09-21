#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using namespace std;;

string* folders = {};
string* files = {};
string inputStr = "";
float inputInt;
char buff;



class folderFiles {
public:
    string folderName;
    string *filesInFolder = {};
    int countFiles;

    folderFiles() {

    }
    folderFiles(string folderNameUS, string *filesInFolderUS, int countFilesUS) {

        filesInFolder = new string[countFilesUS];

        folderName = folderNameUS;
        filesInFolder = filesInFolderUS;
        countFiles = countFilesUS;
    }
};

folderFiles* foldersWithFiles = {};

/*string howTime () {
    time_t currentTime = time(nullptr);
    char timeString[20];
    strftime(timeString, sizeof(timeString), "%Y:%m:%d:%H:%M:%S", localtime(&currentTime));

    return timeString;
}*/

void log(string str) {
    ofstream out;
    out.open("logs.txt", ios::app);
    if (out.is_open())
    {
        out << str << endl;
    }
    out.close();
}


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

void createFile(string str, int inter, string folderName) {
    string buff;
    string buff2;

    files = new string[inter];

    buff = expansion(str);
    str = converter(str);

    log("Files in folders:\n");

    for (int i = 0; i < inter; i++) {
        str += str[str.length() - 1];

        buff2 = str + buff;

        files[i] = buff2;

        log(files[i] + "\n");
    }
}

void createFolder(string str, int inter) {

    folders = new string[inter];


    for (int i = 0; i < inter; i++) {
        str += str[str.length() - 1];
        folders[i] = str;

        log("Created folder: " + folders[i] + " " /*+ howTime() */+ "\n");

        cout << "\nInput the file name in folder" + folders[i] + ": ";
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


        createFile(inputStr, inputInt, folders[i]);

        foldersWithFiles[i] = { *new folderFiles(folders[i], files, inputInt) };
        files = {};
    }
}

int main()
{
    //int checkInt;

    cout << "\nInput the folder name: ";
    cin >> inputStr;

    /*while (inputStr.length) {
        cout << "You cant write count > 255! Please, try again\n";
        cout << "\nInput cout of files: ";
        cin >> inputInt;
    }*/

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

    foldersWithFiles = new folderFiles[inputInt];

    createFolder(inputStr, inputInt);

    cout << "\nCreated folders:";
    for (int i = 0; i < inputInt; i++) {
        cout << "\n" << folders[i];
    }
    cout << "\n";

    

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
