#include <cassert>
#include <iostream>

#include "helpers/Folder.hpp"
#include "helpers/Enums.hpp"
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    // Check for input parameter.
    assert(argc >= 2 && "Second parameter is expected to be the path to directory.");
    std::string path = argv[1];
    cout << path << endl;

    Folder folder(path);

    cout << "Folder '" << path << "' contains:" << endl;
    folder.printAllFiles(order::size_descending);

    cout << "--------------" << endl;
    cout << "Finished! Have a nice day." << endl;

    return 0;
}
