#include "miniGit.hpp"

using namespace std;

bool miniGit::getCurrentVersion(){
    return currentVersion;
}
void miniGit::setCurrentVersion(bool setter){
    currentVersion = setter;
}

int miniGit::getCurrentCommit(){
    return currentDoubly->commitNumber;
}

void miniGit::initializeHeadDoubly(){
    doublyNode *toAdd = new doublyNode;
    toAdd->commitNumber = 0;
    headDoubly = toAdd;
    currentDoubly = headDoubly;
}

void miniGit::copyFile(string from, string to)
{
    fs::remove(to);
    ifstream fromStream(from);
    ofstream toStream(to);
    toStream << fromStream.rdbuf();
}

//returns true if the same, false if different
bool fileComparison(singlyNode *suspect){
    string getLiner;
    for(int i = 0; i < 5; i++){
        cout << "t1";
    }
    getline(cin, getLiner);
    ifstream fileOne(suspect->fileName);
    ifstream fileTwo;
    try{
        for(int i = 0; i < 5; i++){
            cout << "t2";
        }
        getline(cin, getLiner);
        fileTwo.open(".minigit/" + suspect->fileVersion);
    } catch(const std::bad_alloc e){
        return false;
    }
    string temp1;
    string temp2;
    while(getline(fileOne, temp1)){
        getline(fileTwo, temp2);
        if(temp1 != temp2){
            return false;
        }
    }
    return true;
}

void copySingly(singlyNode *copier, singlyNode *copied){
    copier->fileName = copied->fileName;
    copier->fileVersion = copied->fileVersion;
}

void miniGit::commitChanges(){
    string getLiner;
    
    singlyNode *curr = currentDoubly->head;
    for(int i = 0; i < 5; i++){
        cout << "l1";
    }
    getline(cin, getLiner);
    while(curr != NULL){
        for(int i = 0; i < 5; i++){
            cout << "l6";
        }
        getline(cin, getLiner);
            
        if(!fs::exists(".minigit/" + curr->fileVersion)){
            for(int i = 0; i < 5; i++){
                cout << "l2";
            }
            getline(cin, getLiner);
            copyFile(curr->fileName, ".minigit/" + curr->fileVersion);
        }
        else if(!fileComparison(curr)){
            for(int i = 0; i < 5; i++){
                cout << "l3";
            }
            getline(cin, getLiner);
            copyFile(curr->fileName, ".minigit/" + curr->fileName + "__" + to_string(getCurrentCommit() + 1) + "__");
        }
        for(int i = 0; i < 5; i++){
            cout << "l4";
        }
        getline(cin, getLiner);
        curr = curr->next;
    }
    for(int i = 0; i < 5; i++){
        cout << "l5";
    }
    getline(cin, getLiner);

    doublyNode *toAdd;
    currentDoubly->next = toAdd;
    toAdd->previous = currentDoubly;
    toAdd->commitNumber = currentDoubly->commitNumber++;
    currentDoubly = toAdd;

    curr = currentDoubly->previous->head;
    copySingly(currentDoubly->head, curr);
    singlyNode *newCurr = currentDoubly->head;
    curr = curr->next;
    while(curr != NULL){
        singlyNode *toAdd;
        copySingly(toAdd, curr);
        newCurr->next = toAdd;
        newCurr = newCurr->next;
        curr = curr->next;
    }

    // currentDoubly->next->commitNumber = currentDoubly->commitNumber++;
    // currentDoubly->next->previous = currentDoubly;
    // currentDoubly = currentDoubly->next;
}

void miniGit::removeFile(string fileName){
    if(currentDoubly->head->fileName == fileName){
        singlyNode *temp = currentDoubly->head;
        currentDoubly->head = currentDoubly->head->next;
        delete temp;
        return;
    }
    singlyNode *curr = currentDoubly->head->next;
    singlyNode *prev = currentDoubly->head;
    while(curr != NULL){
        if(curr->fileName == fileName){
            singlyNode *temp = curr;
            prev->next = curr->next;
            delete temp;
            return;
        }
        curr = curr->next;
        prev = prev->next;
    }
}

void miniGit::addFiles(string fileName, string fileVersion){
    singlyNode *toAdd = new singlyNode;
    toAdd->fileName = fileName;
    toAdd->fileVersion = fileVersion; //inserts singlyNode at pos0 of linked list
    toAdd->next = currentDoubly->head;
    currentDoubly->head = toAdd->next;
    currentDoubly->numsinglies++;
}

bool miniGit::existsFileName(string fileName){
    // string getLiner;
    if(currentDoubly->head == NULL){
        return false;
    }
    // for(int i = 0; i < 600; i++){
    //     cout << "g1";
    // }
    singlyNode *current = currentDoubly->head;
    // for(int i = 0; i < 600; i++){
    //     cout << "g2";
    // }
    int counter = 0;
    while(current != nullptr && counter < currentDoubly->numsinglies){
        // for(int i = 0; i < 5; i++){
        //     cout << "g3";
        // }
        // getline(cin, getLiner);
        if(current->fileName == fileName){
            // for(int i = 0; i < 5; i++){
            //     cout << "g4";
            // }
            // getline(cin, getLiner);
            return true;
        }
        // for(int i = 0; i < 5; i++){
        //     cout << "g5";
        // }
        // getline(cin, getLiner);
        // cout << current << current->next;
        counter++;
        current = current->next;
    }
    // for(int i = 0; i < 5; i++){
    //     cout << "g5";
    // }
    // getline(cin, getLiner);
    return false;
}

doublyNode* miniGit::desiredDoublyNumbered(int commitNumber){
    doublyNode *curr = headDoubly;
    while(curr != NULL){
        if(curr->commitNumber == commitNumber){
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}