#include <iostream>
#include "../FileMan.h"

int main(){
    FileMan::OverwriteFile("test_file.txt", "This was a overwrite test.");
    FileMan::WriteToFile("test_file.txt", "This was a write test.");
    std::cout << FileMan::ReadFile("test_file.txt").value().str();
    return 0;
}