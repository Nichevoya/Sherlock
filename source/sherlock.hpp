#pragma once

#include <vector>
#include <iostream>
#include <filesystem>

class sherlock {
    public:
        sherlock(const std::string &directory = ".");
        ~sherlock() = default;

        void remove(void);
        const std::string &directory(void);
        std::vector<std::string> &files(void);
        const std::vector<std::string> &scan(void);

    protected:
    private:
        std::vector<std::string> _files;
        const std::string &_directory = ".";
};
