#ifndef FILEMAN_H
#define FILEMAN_H
#ifdef __cplusplus

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <optional>

namespace FileMan{
    
    static inline std::optional<std::stringstream> ReadFile(std::string t_FilePath){
        if (!std::filesystem::exists(t_FilePath)){
            return {};
        }
        std::ifstream file;
        file.open(t_FilePath, std::ios::app);

        std::stringstream contents;

        if (file.good()){
            contents << file.rdbuf();
        }

        file.close();

        return contents;


    }

    static inline bool OverwriteFile(std::string t_FilePath, std::string t_Content){
        if (!std::filesystem::exists(t_FilePath)){
            return false;
        }
        std::ofstream file;
        file.open(t_FilePath);
        if (!file.good()){
            file.close();
            return false;
        }

        file << t_Content;

        file.close();

        return true;

    }

    static inline bool WriteToFile(std::string t_FilePath, std::string t_Content){
        if (!std::filesystem::exists(t_FilePath)){
            return false;
        }
        std::fstream file;
        file.open(t_FilePath, std::fstream::app);
        if (!file.good()){
            file.close();
            return false;
        }

        file << t_Content;


        file.close();

        return true;

    }

}


#endif
#endif