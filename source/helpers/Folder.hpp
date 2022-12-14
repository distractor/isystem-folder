#ifndef DIRECTORY_FOLDER_HPP
#define DIRECTORY_FOLDER_HPP

#include "Enums.hpp"
#include "File.hpp"
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <list>
#include <string>
namespace fs = std::filesystem;

using namespace std;

class Folder {
  private:
    string master_path_;
    list<File> files_;

  public:
    Folder(string path) : master_path_(path) {
        // Get folder stricture.
        initialize();
    }
    ~Folder() {}

    /**
     * Initialize by adding files.
     */
    void initialize() {
        for (const auto& entry : fs::recursive_directory_iterator(master_path_)) {
            if (!entry.is_directory()) {
                string file_name = (string)entry.path();
                files_.push_back(
                    File(file_name.substr(file_name.find_last_of("/\\") + 1), entry.file_size()));
            }
        }
    }

    /**
     * Print all files from master directory.
     */
    void printAllFiles(order ordering) {
        if (ordering == order::size_ascending) {
            files_.sort([](File& f, File& s) { return f.getFilesize() < s.getFilesize(); });
        }
        if (ordering == order::size_descending) {
            files_.sort([](File& f, File& s) { return f.getFilesize() > s.getFilesize(); });
        }
        if (ordering == order::name_descending) {
            files_.sort([](File& f, File& s) { return f.getFileName() < s.getFileName(); });
        }
        if (ordering == order::name_ascending) {
            files_.sort([](File& f, File& s) { return f.getFileName() > s.getFileName(); });
        }

        for (auto file : files_) {
            cout << "File: " << file.getFileName() << "(" << file.getFilesize() << " bytes)"
                 << endl;
        }
    }
};

#endif  // DIRECTORY_FOLDER_HPP
