# FileMan
## Table Of Contents
- [How to use](#how-to-use)
- [Documentation](#doc)

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

<a id = "doc"> </a>

## Documentation

### Reading Files:
```c++
#include <iostream>
#include "FileMan.h"

int main(){
    //return a std::optional<std::sstream>
    //return empty if the file does not exist
    std::cout << FileMan::ReadFile("FilePath.txt").value();
    return 0;
}
```

### Overwriting File Contents
```c++
#include <iostream>
#include "FileMan.h"

int main(){
    //return a bool
    //true if overwrite was successful
    std::cout << FileMan::OverwriteFile("FilePath.txt", "replace text");
    return 0;
}
```

### Write to File
```c++
#include <iostream>
#include "FileMan.h"

int main(){
    //appends text to the end of the file
    //return a bool
    //true if write was successful
    std::cout << FileMan::WriteToFile("FilePath.txt", "replace text");
    return 0;
}
```
