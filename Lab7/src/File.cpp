#include "File.h"

File::File(std::string name, int size) : FileSystemBase(name, "file"), m_size(size) {}

File::~File() {
    std::cout << "---Destruktor file: " << getName() << std::endl;
}

std::string File::to_string(int spaces) const {
    std::string result = "";
    for (int i = 0; i < spaces; i++) {
        result += " ";
    }
    return result += getName() + "(" + std::to_string(m_size) + ")\n";
}

FileSystemBase* File::createCopy() const {
    return new File(*this);
}
