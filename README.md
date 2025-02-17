# FileMan
## Table Of Contents
- [How to use](#how-to-use)
- [Documentation](#doc)
- [Classes](#classes)

<a id = "how-to-use"> </a>

## How to use
Just downlad the FileMan.h header file and include to it in your code. No need for any additional dependencies.

```c++
#include <iostream>
#include "FileMan.h"

int main(){
    std::cout << FileMan::ReadFile("FilePath.txt").value();
    return 0;
}
```

If you want to run a test to see if everything is working fine, then you can try the following command in the shell:
```sh
cd Tests

make re
make run
```

<a id = "doc"> </a>

## Documentation

### Static functions:
1. [ReadFile](#reading-files)
2. [OverwriteFile](#overwriting-file-contents)
3. [ClearFile](#clearing-the-file-contents)
4. [WriteToFile](#write-to-file)
5. [Exists](#check-if-file-exists)
6. [GetSize](#check-file-size)
7. [NewFile](#create-a-new-file)
8. [DeleteFile](#delete-a-file)


#### Reading Files:
```c++
static std::optional<std::stringstream> FileMan::ReadFile("FilePath.txt");
```
Read the contents of the file. Return a an optional string stream. The optional has a value if the read was successful.

#### Overwriting File Contents:
```c++
static bool FileMan::OverwriteFile("FilePath.txt", "replace text");
```
Overwrites the pre-existing data. Returns true if the overwrite was successful. If the file does not exist, the function return false.

#### Clearing the file contents
```c++
static bool FileMan::ClearFile("FilePath.txt");
```
Clears the contents of the file. Return true if the operation was successful. 

#### Write to File:
```c++
static bool FileMan::WriteToFile("FilePath.txt", "replace text");
```
Appends to data to the end of the file. Returns true if the write was successful. If the file does not exist, the function return false.

#### Check if file Exists:
```c++
static bool FileMan::ReadFile("FilePath.txt");
```
Reuturns true if the file exists.

#### Check file size:
```c++
static unsigned long long  FileMan::GetSize("FilePath.txt");
```
Returns the file size in bytes.

#### Create a new file:
```c++
static bool FileMan::NewFile("FilePath.txt");
```
Creates a new file. Returns true if the creation was successful. 

#### Delete a file:
```c++
static bool FileMan::DeleteFile("FilePath.txt");
```
Returns true if the file does not exist after the delete operation.

## Classes

1.[File](#file-class)

### File Class

Public Functions and Variable;

- filePath
- [Open()](#opening-a-file)
- [IsOpen()](#opening-a-file)
- [Clear()](#clearing-file-contents)
- [Read()](#reading-the-file-contents)
- [Write()](#writing-to-the-file)
- [Close()](#closing-the-file)

#### Opening a File:
Can be done directly with a constructor:
```c++
FileMan::File file("filePath.txt");
```
Or can be done with the open function.
```c++
FileMan::File file();
file.Open("filePath.txt");
```
If no parameter is passed to the Open function the file in the filePath variable will be opened.<br/>
To check if the file is open you can do the following:
```c++
FileMan::File file("filePath.txt");
std::cout << file.IsOpen() ? "File is open" : "File is not open";
```
#### Clearing File Contents:
Clearing the file contents can be done like this:
```c++
FileMan::File file("filePath.txt");
file.Clear();
```
All the file contents will be cleared and will return true if the file was successfully cleared.

#### Reading the File Contents:
```c++
FileMan::File file("filePath.txt");
std::stringstream  = file.Read().value();
```
Read() retruns a optional string stream. It has a value if the read was successful.

#### Writing to the File:
```c++
FileMan::File file("filePath.txt");
file.Write("Whatever you want to write.");
```
Write() returns true if the write was successful.

#### Closing the File:
It is important that the file is closed after you done using is it. It can be done like this:
```c++
FileMan::File file("filePath.txt");
file.Close();
```