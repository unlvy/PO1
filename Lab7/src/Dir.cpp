#include "Dir.h"

Dir::Dir(std::string name) : FileSystemBase(name, "dir") {}

Dir::Dir(const Dir& other) : FileSystemBase(other.getName(), other.getType()) {
    for (int i = 0; i < static_cast<int>(other.m_subElements.size()); i++) {
        copy(other.m_subElements[i]);
    }
}

Dir::~Dir() {
    std::cout << "Destruktor Dir: " << getName() << std::endl;
    for (int i = 0; i < static_cast<int>(m_subElements.size()); i++) {
        delete m_subElements[i];
    }
}

std::string Dir::to_string(int spaces) const {
    std::string result = "";
    for (int i = 0; i < spaces; i++) {
        result += " ";
    }
    result += getName() + "(dir)\n";
    for (auto* subElement : m_subElements) {
        result += subElement->to_string(spaces + 2);
    }
    return result;
}

void Dir::operator+= (FileSystemBase* subElement) {
    m_subElements.push_back(subElement);
}

FileSystemBase* Dir::createCopy() const {
    return new Dir(*this);
}

FileSystemBase* Dir::get(std::string name) const {
    FileSystemBase* result = nullptr;
    for (auto* subElement : m_subElements) {
        if (subElement->getName() == name) {
            return subElement;
        } else if (subElement->getType() == "dir") {
            result = dynamic_cast<Dir*>(subElement)->get(name);
            if (result != nullptr) {
                return result;
            }
        }
    }
    return result;
}

Dir* Dir::getDir(std::string name) const {
    Dir* result = nullptr;
    for (auto* subElement : m_subElements) {
        if (subElement->getType() == "dir") {
            if (subElement->getName() == name) {
                return dynamic_cast<Dir*>(subElement);
            }
            result = dynamic_cast<Dir*>(subElement)->getDir(name);
            if (result != nullptr) {
               return result;
            }
        }
    }
    return result;
}

void Dir::copy(FileSystemBase* element) {
    (*this) += element->createCopy();
}

void Dir::operator-= (std::string name) {
    for (int i = 0; i < static_cast<int>(m_subElements.size()); i++) {
        if (m_subElements[i]->getName() == name) {
            delete m_subElements[i];
            m_subElements.erase(m_subElements.begin() + i);
            return;
        }
    }
}
