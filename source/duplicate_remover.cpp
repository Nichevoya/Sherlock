#include "duplicate_remover.hpp"

duplicate_remover::duplicate_remover(const std::string &directory) : _directory(directory) 
{
    this->scan();
    this->remove();
}

void duplicate_remover::remove(void) 
{
    for (uint32_t y = 0; y < files().size(); y++) {
        for (uint32_t x = 0; x < files().size(); x++) {
            if (files().at(y) == files().at(x) && 
                files().at(y).find_first_of('(') != std::string::npos && 
                files().at(y).find_last_of(')') != std::string::npos) {
                std::remove(files().at(y).c_str());
            }
        }
    }
}

const std::string &duplicate_remover::directory(void) { return _directory; }

std::vector<std::string> &duplicate_remover::files(void) { return _files; }

const std::vector<std::string> &duplicate_remover::scan(void) 
{
    for (const auto &file : std::filesystem::recursive_directory_iterator(directory())) {
        _files.push_back(file.path().c_str());
    }
    
    return _files;
}
