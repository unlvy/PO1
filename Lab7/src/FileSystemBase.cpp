#include "FileSystemBase.h"

std::ostream& operator<< (std::ostream& os, const FileSystemBase& element) {
    return os << element.to_string();
}

FileSystemBase::FileSystemBase(std::string name, std::string type) : m_name(name), m_type(type) {}

std::string FileSystemBase::getName() const {
    return m_name;
}

std::string FileSystemBase::getType() const {
    return m_type;
}
