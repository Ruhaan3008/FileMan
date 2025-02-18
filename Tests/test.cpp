#include <iostream>
#include "../FileMan.h"

int main(){
    FileMan::NewFile("test_file.txt");
    std::cout << FileMan::GetFileExtension("test_file.txt") << '\n';

    if (!FileMan::Exists("test_file.txt")){
        std::cout << "File creation failed.";
        return 1;
    }

    FileMan::OverwriteFile("test_file.txt", "This was a overwrite test.");
    FileMan::WriteToFile("test_file.txt", " This was a write test.");
    std::cout << FileMan::ReadFile("test_file.txt").value().str() << std::endl;
    FileMan::ClearFile("test_file.txt");

    std::cout << "File Class test is now commencing..." << std::endl;

    FileMan::File file("test_file.txt");
    file.Write(" This is a file class write test.");
    std::cout << file.Read().value().str();

    file.Clear();
    file.Write("All the test have been successfully.");
    file.Close();

    FileMan::DeleteFile("del_test.txt");

    FileMan::RenameFile("test_file.txt", "t.txt");
    FileMan::MoveFile("t.txt", "success/");

    FileMan::NewFile("copyTest.txt");
    FileMan::CopyFile("success/t.txt", "copyTest.txt");

    return 0;
}