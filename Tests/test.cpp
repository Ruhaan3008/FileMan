#include <iostream>
#include "../FileMan.h"

int main(){
    FileMan::NewFile("test_file.txt");

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

    return 0;
}