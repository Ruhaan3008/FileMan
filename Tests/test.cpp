#include <iostream>
#include "../FileMan.h"

int main(){
    std::cout << FileMan::ReadFile("D:/MyLibs/FileMan/Tests/test_file.txt").has_value();
    return 0;
}