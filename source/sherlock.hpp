#pragma once

#include <vector>
#include <iostream>
#include <filesystem>

class sherlock {
    public:
        sherlock(const std::string &directory = ".");
        ~sherlock() = default;

        /**
         * @brief Remove corresponding files
         * 
         */
        void remove(void);
        
        /**
         * @brief Get directory path
         * 
         * @return const std::string &
         */
        const std::string &directory(void);
        
        /**
         * @brief Get found file list
         * 
         * @return std::vector<std::string> & 
         */
        std::vector<std::string> &files(void);
        
        /**
         * @brief Scan given directory and fill the file list
         * 
         * @return const std::vector<std::string> & 
         */
        const std::vector<std::string> &scan(void);

    protected:
    private:
        std::vector<std::string> _files;
        const std::string &_directory = ".";
};
