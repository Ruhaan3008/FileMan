#include <iostream>
#include "../FileMan.h"

std::string testFile = "test_file.txt";
std::string moveDirectory = "move_dir/"; 

int main(){
    std::cout << "Commencing Static Function Tests" << '\n';
    bool staticFuncTests = true;
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
        staticFuncTests = staticFuncTests && FileMan::Exists(testFile);
    }

    {
        //read write overwrite test
        std::cout << '\n';
        std::cout<< "Read, Write and Overwrite Test" << '\n';

        std::string writeContent = "Just a normal write.";
        std::string overwriteContent = "Just an avg overwrite";

        FileMan::WriteToFile(testFile, writeContent);

        bool resWrtie = FileMan::ReadFile(testFile).has_value();
        std::string writeResult = FileMan::ReadFile(testFile).has_value() ?
        "Write Test was successful" : "Write Test failed";
        std::cout<< writeResult << '\n';

        bool res1 = FileMan::ReadFile(testFile).value().str() == writeContent;
        std::string readResult = (FileMan::ReadFile(testFile).value().str() == writeContent)?
        "Read Test was successful" : "Read Test failed";
        std::cout<< readResult << '\n';

        FileMan::OverwriteFile(testFile, overwriteContent);

        bool success = FileMan::ReadFile(testFile).value().str() == overwriteContent;
        std::string overwriteResult = (success) ?
        "Overwrite test was successful" : "Overwrite test failed";
        std::cout<< overwriteResult << '\n';

        success = success && res1 && resWrtie;

        staticFuncTests = staticFuncTests && success;
    }

    {
        //Clear test
        std::cout << '\n';
        std::cout << "File Clear Test" << '\n';

        FileMan::ClearFile(testFile);
        
        std::string clearResult = (FileMan::ReadFile(testFile).value().str() == "") ?
        "Clear test was successful" : "Clear Test failed";
        std::cout << clearResult << '\n';

        staticFuncTests = staticFuncTests && FileMan::ReadFile(testFile).value().str() == "";
    }

    {
        //File extention test
        std::cout << '\n';
        std::cout << "Get File Extention Test" << '\n';

        std::string result = (FileMan::GetFileExtension(testFile) == ".txt")?
        "File Extention test was successful" : "File Extention test failed";
        std::cout <<  result << '\n';

        staticFuncTests = staticFuncTests && FileMan::GetFileExtension(testFile) == ".txt";

    }

    {
        //Create Directory
        std::cout << '\n';
        std::cout <<  "Directory Creation Test" << '\n';

        FileMan::CreateDirectory(moveDirectory);

        std::string result = FileMan::Exists(moveDirectory) ?
        "Directory Creation was successful" : "Directory Creation failed";
        std::cout << result << '\n';

        staticFuncTests = staticFuncTests &&  FileMan::Exists(moveDirectory);
    }
    {
        //move test
        std::cout << '\n';
        std::cout <<  "Move Test" << '\n';

        if (FileMan::Exists(moveDirectory+testFile)){
            FileMan::DeleteFile(moveDirectory+testFile);
        }

        FileMan::MoveFile(testFile, moveDirectory);

        bool result = !FileMan::Exists(testFile) && FileMan::Exists(moveDirectory + testFile);
        std::string resultString = result ?
        "Move test was successful" : "Move test failed";
        std::cout << resultString << '\n';

        staticFuncTests = staticFuncTests && result;
    }

    {
        //Copy test
        std::cout <<  '\n';
        std::cout <<  "Copy Test" << '\n';

        FileMan::NewFile(testFile);
        FileMan::CopyFile(moveDirectory+testFile, testFile);

        bool result = FileMan::Exists(testFile) && FileMan::Exists(moveDirectory + testFile);
        std::string resultString = result ?
        "Copy test was successful" : "Copy test failed";
        std::cout << resultString << '\n';

        staticFuncTests = staticFuncTests && result;
    }

    {
        std::cout << '\n';
        std::cout <<  "Directory Deletion Test" << '\n';

        FileMan::DeleteDirectory(moveDirectory);

        bool result = !FileMan::Exists(moveDirectory);
        std::string resultString = result ?
        "Directory Deletion test was successful" : "Directory Deletion failed";
        std::cout << resultString << '\n';

        staticFuncTests = staticFuncTests && result;
    }

    {
        //Deletion test
        std::cout << '\n';
        std::cout << "File Deletion Test" << '\n';

        FileMan::DeleteFile(testFile);

        std::string deletionResult = !FileMan::Exists(testFile) ? 
        "Deletion was successful" : "Deletion failed";
        std::cout<< deletionResult << '\n';

        staticFuncTests = staticFuncTests && !FileMan::Exists(testFile);
    }

    std::cout << '\n';
    std::cout << (staticFuncTests ? "All Static Function Tests were Successful" : "All Static Function Tests were not Successful");
    std::cout << '\n';
    std::cout << '\n';
    
    std::cout << "Commencing Class tests" << '\n';
    bool classTests = true;

    FileMan::NewFile(testFile);
    
    FileMan::File file(testFile);

    {
        std::cout << '\n';
        std::cout << "Opening file: ";

        std::string result = file.IsOpen() ?
        "Success" : "Failed";
        std::cout << result;

        classTests = classTests && file.IsOpen();
    }

    {
        std::cout << '\n';
        std::cout << "Read and Write to file: ";

        std::string writeContent = "Just some content";
        file.Write(writeContent);

        bool success = file.Read().value().str() == writeContent;
        std::string result = success ?
        "Success" : "Fail";
        std::cout << result;

        classTests = classTests && success;
    }

    {
        std::cout << '\n';
        std::cout << "Clear file: ";

        file.Clear();

        bool success = file.Read().value().str() == "";
        std::string result = success ?
        "Success" : "Fail";
        std::cout << result;

        classTests = classTests && success;
    }

    {
        std::cout << '\n';
        std::cout << "Closing file: ";

        file.Close();

        std::string result = !file.IsOpen() ?
        "Success" : "Failed";
        std::cout << result;

        classTests = classTests && !file.IsOpen();
    }

    std::cout << '\n';
    std::cout << '\n';
    std::cout << (classTests ? "All Class Tests were Successful" : "All Class Tests were not Successful");

    std::cout << '\n';
    std::cout << (staticFuncTests && classTests ? "All Tests were Successful" : "All Tests were not Successful");

    return 0;
}