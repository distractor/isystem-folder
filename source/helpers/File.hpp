#ifndef DIRECTORY_FILE_HPP
#define DIRECTORY_FILE_HPP

using namespace std;

class File {
private:
  string name_;
  int size_;

public:
  explicit File(string name, int size) : name_{name}, size_{size} {}
  ~File() {}

  /**
   * Gets file name.
   * @return File name.
   */
  string getFileName() { return name_; }

  /**
   * Gets file size.
   * @return File size in bytes.
   */
  int getFilesize() { return size_; }
};

#endif // DIRECTORY_FILE_HPP
