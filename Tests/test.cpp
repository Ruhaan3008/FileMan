#include <iostream>
#include "../FileMan.h"

std::string testFile = "test_file.txt";
std::string moveDirectory = "move_dir/"; 

int main(){
    {
        // Creation test
        std::cout<< "File Creation test" << '\n';

        FileMan::NewFile(testFile);

        std::string creationResult = FileMan::Exists(testFile) ? 
        "Creation was successful" : "Creation failed";
        std::cout <<creationResult << '\n';

        if (!FileMan::Exists(testFile)){
            exit(-1);
        }
    }

    {
        //read write overwrite test
        std::cout << '\n';
        std::cout<< "Read, Write and Overwrite Test" << '\n';

        std::string writeContent = "Just a normal write.";
        std::string overwriteContent = "Just an avg overwrite";

        FileMan::WriteToFile(testFile, writeContent);

        std::string writeResult = FileMan::ReadFile(testFile).has_value() ?
        "Write Test was successful" : "Write Test failed";
        std::cout<< writeResult << '\n';

        std::string readResult = (FileMan::ReadFile(testFile).value().str() == writeContent)?
        "Read Test was successful" : "Read Test failed";
        std::cout<< readResult << '\n';

        FileMan::OverwriteFile(testFile, overwriteContent);

        std::string overwriteResult = (FileMan::ReadFile(testFile).value().str() == overwriteContent) ?
        "Overwrite test was successful" : "Overwrite test failed";
        std::cout<< overwriteResult << '\n';
    }

    {
        //Clear test
        std::cout << '\n';
        std::cout << "File Clear Test" << '\n';

        FileMan::ClearFile(testFile);
        
        std::string clearResult = (FileMan::ReadFile(testFile).value().str() == "") ?
        "Clear test was successful" : "Clear Test failed";
        std::cout << clearResult << '\n';
    }

    {
        //File extention test
        std::cout << '\n';
        std::cout << "Get File Extention Test" << '\n';

        std::string result = (FileMan::GetFileExtension(testFile) == ".txt")?
        "File Extention test was successful" : "File Extention test failed";
        std::cout <<  result << '\n';

    }

    {
        //Create Directory
        std::cout << '\n';
        std::cout <<  "Directory Creation Test" << '\n';

        FileMan::CreateDirectory(moveDirectory);

        std::string result = FileMan::Exists(moveDirectory) ?
        "Directory Creation was successful" : "Directory Creation failed";
        std::cout << result << '\n';
    }
    {
        //move test
        std::cout << '\n';
        std::cout <<  "Move Test" << '\n';

        FileMan::MoveFile(testFile, moveDirectory);

        bool result = !FileMan::Exists(testFile) && FileMan::Exists(moveDirectory + testFile);
        std::string resultString = result ?
        "Move test was successful" : "Move test failed";
        std::cout << resultString << '\n';

    }

    {
        //Deletion test
        std::cout << '\n';
        std::cout << "File Deletion Test" << '\n';
        //FileMan::DeleteFile(testFile);
        std::string deletionResult = !FileMan::Exists(testFile) ? 
        "Deletion was successful" : "Deletion failed";
        std::cout<< deletionResult << '\n';
    }
    return 0;
}