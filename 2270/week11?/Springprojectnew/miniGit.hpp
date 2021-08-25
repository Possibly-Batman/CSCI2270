#ifndef MINIGIT_HPP
#define MINIGIT_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;

namespace fs = std::filesystem;

struct singlyNode{
    string fileName;    // Name of local file
    string fileVersion; // Name of file in .minigit folder
    singlyNode *next;
};

struct doublyNode{
    int commitNumber = -1;
    int numsinglies = 0;
    singlyNode *head;
    doublyNode *previous;
    doublyNode *next;
};

// void copyFile(string from, string to )
// {
//     fs::remove(to);
//     ifstream fromStream(from);
//     ofstream toStream(to);
//     toStream << fromStream.rdbuf();
// }

class miniGit{
private:
    doublyNode *headDoubly;
    doublyNode *currentDoubly;
    bool currentVersion = true;
public: 
    bool getCurrentVersion();
    void setCurrentVersion(bool setter);

    void copyFile(string from, string to);

    int getCurrentCommit();
    
    void initializeHeadDoubly(); //start everything

    bool existsFileName(string fileName);

    void addFiles(string fileName, string fileVersion); //Adding files to the current commit
    void removeFile(string fileName); //Removing files from the current commit
    void commitChanges(); //Committing changes
    //Checking out a specific version based on a unique commit number

    doublyNode* desiredDoublyNumbered(int commitNumber);
};

#endif