
#include "miniGit.hpp"

using namespace std;

//compile command: g++ -std=c++17 driver.cpp miniGit.cpp

void displayMenu()
{
    // COMPLETE
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. add to current commit " << endl;
    cout << " 2. remove from current commit " << endl;
    cout << " 3. commit changes " << endl;
    cout << " 4. Check out specific version with commit number " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
} 

// void copyFile(string from, string to )
// {
//     fs::remove(to);
//     ifstream fromStream(from);
//     ofstream toStream(to);
//     toStream << fromStream.rdbuf();
// }

int main()
{
    miniGit *gitfriend;
    gitfriend->setCurrentVersion(true);

    int chosenOption = 0;
    string inputString;

    cout << "Do you wish to initialize an empty repository in the current directory?" << endl << "Y / N? ";
    getline(cin, inputString);
    if(inputString[0] == 'y' || inputString[0] == 'Y'){
        fs::remove_all(".minigit"); // removes a directory and its contents
        fs::create_directory(".minigit");  // create a new directory
        gitfriend->initializeHeadDoubly();
    } else{

    }

    while(chosenOption != 5) {

        displayMenu();

        getline(cin, inputString);
        chosenOption = stoi(inputString);

        switch(chosenOption) {
            case 1: { //add to current commit
                if(!gitfriend->getCurrentVersion()){
                    cout << "Can't do in past version!" << endl;
                    break;
                }
                string inputFileName;
                while(true){
                    cout << "Please enter a valid file name. Type in 'break' to leave the loop" << endl;
                    getline(cin, inputFileName); 
                    if(!fs::exists(inputFileName)){
                        // while(true){
                        //     cout << "p0";
                        // }
                        cout << "Invalid because file does not exist" << endl;
                    } 
                    else if(gitfriend->existsFileName(inputFileName)){
                        // while(true){
                        //     cout << "p1";
                        // }
                        cout << "Invalid because file is already in current commit" << endl;
                    }
                    else if(inputFileName == "break"){
                        // while(true){
                        //     cout << "p2";
                        // }
                        break;
                    }
                    else{
                        break;
                    }
                }
                
                //fs::copyFile(inputFileName, ".minigit/" + inputFileName + "__" + gitfriend->getCurrentCommit() + "__")

                // while(true){
                //     cout << "p";
                // }

                gitfriend->addFiles(inputFileName, inputFileName + "__" + to_string(gitfriend->getCurrentCommit()) + "__");

                break;
            }

            case 2: { //remove from current commit
                if(!gitfriend->getCurrentVersion()){
                    cout << "Can't do in past version!" << endl;
                    break;
                }
                string inputFileName;
                cout << "Please enter a valid file name" << endl;
                cout << "The program will proceed even if the name is invalid" << endl;
                getline(cin, inputFileName);

                if(gitfriend->existsFileName(inputFileName)){
                    gitfriend->removeFile(inputFileName);
                    cout << "removal complete!" << endl;
                }
                else {
                    cout << "Invalid file name, removal canceled" << endl;
                }
                break;
            }

            case 3: { //commit changes
                if(!gitfriend->getCurrentVersion()){
                    cout << "Can't do in past version!" << endl;
                    break;
                }
                gitfriend->commitChanges();
                cout << "commit complete!" << endl;
                break;
            }

            case 4: { //Check out specific version with commit number
                string input;
                cout << "Please enter a commit number" << endl;
                getline(cin, input);
                int desiredVersion = stoi(input);
                cout << "Are you sure? Doing this will overwrite non-commited changes" << endl << "Y / N? ";
                getline(cin, input);
                if(inputString[0] == 'y' || inputString[0] == 'Y'){
                    doublyNode *desired = gitfriend->desiredDoublyNumbered(desiredVersion);
                    singlyNode *curr = desired->head;
                    while(curr != NULL){
                        gitfriend->copyFile(".minigit/" + curr->fileVersion, curr->fileName);
                        curr = curr->next;
                    }
                    if(desiredVersion == gitfriend->getCurrentCommit()){
                        gitfriend->setCurrentVersion(true);
                    }
                    else{
                        gitfriend->setCurrentVersion(false);
                    }
                }
                break;
            }

            case 5: {
                cout << "Quitting..." << endl;
                break;
            }

        }
    }

    return 0;
}
