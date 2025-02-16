#ifndef FILEMAN_H
#define FILEMAN_H
#ifdef __cplusplus

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <optional>

namespace FileMan{
    
    class File{
    public:
        std::string filePath;

        inline File()
            :filePath(""),
            m_file(), m_readFile()
        {}
        inline File(std::string t_FilePath)
            : filePath(t_FilePath),
            m_file(t_FilePath, std::ios::app),
            m_readFile(t_FilePath, std::ios::app)
        {}

        inline ~File(){
            m_file.close();
            m_readFile.close();
        }

        inline bool Open(){
            m_file.open(filePath, std::ios::app);
            m_readFile.open(filePath, std::ios::app);
            return m_file.good();
        }

        inline bool Open(std::string t_FilePath){
            filePath = t_FilePath;

            m_file.open(filePath, std::ios::app);
            m_readFile.open(filePath, std::ios::app);

            return m_file.good() && m_readFile.good();
        }

        inline bool IsOpen(){
            return m_file.is_open() && m_readFile.is_open();
        }

        inline std::optional<std::stringstream> Read(){
            if (!this->IsOpen()){
                return {};
            }
            std::stringstream contents;

            contents << m_readFile.rdbuf();
    
            return contents;
        }

        inline bool Write(std::string t_Content){
            if (!this->IsOpen()){
                return false;
            }
            m_file << t_Content;
            m_file.flush();
            return true;
        }

        inline bool Clear(){
            this->Close();

            std::ofstream clearFile(filePath);
            clearFile.close();

            this->Open();

            return this->IsOpen();            
        }

        inline void Close(){
            m_file.close();
            m_readFile.close();
        }

    private:
        std::fstream m_file;
        std::ifstream m_readFile;

    };

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
    
    static inline bool ClearFile(std::string t_FilePath){
        if (!std::filesystem::exists(t_FilePath)){
            return false;
        }
        std::ofstream file;
        file.open(t_FilePath);
        if (!file.good()){
            file.close();
            return false;
        }
        
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

    static inline bool Exists(std::string t_FilePath){
        return std::filesystem::exists(t_FilePath);
    }

    static inline bool NewFile(std::string t_FileName){
        std::ofstream file;
        file.open(t_FileName);
        file.close();

        return std::filesystem::exists(t_FileName);
    }

}


#endif
#endif