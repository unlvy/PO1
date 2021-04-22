#pragma once

#include "FileSystemBase.h"

/** class representing directory */
class Dir final : public FileSystemBase {   

private:
    std::vector<FileSystemBase*> m_subElements;        /** elements in directory */

public:

    /**
     * one-argument construcotr
     * @param name - name
     */
    explicit Dir(std::string name);

    /**
     * copy constructor
     * @param other - object to be copied
     */
    Dir(const Dir& other);

    /**
     * destructor
     */
    ~Dir();

    /**
     * operator+=
     * adds elements to directory
     * @param subElement - element to add
     */
    void operator+= (FileSystemBase* subElement);

    /**
     * operator-=
     * removes element from catalog
     * @param name - name of element to remove
     */
    void operator-= (std::string name);

    std::string to_string(int spaces = 0) const override;
    FileSystemBase* createCopy() const override;

    /**
     * get()
     * method returning pointer to element with given name (or nullptr if element doesnt exist)
     * @param name - name
     * @return - pointer 
     */
    FileSystemBase* get(std::string name) const;

    /**
     * getDir()
     * method returning pointer to subdirectory with given name (or nullptr if subdirectory doesnt exist)
     * @param name - name
     * @return - pointer 
     */
    Dir* getDir(std::string name) const;

    /**
     * copy()
     * method adding copy of element to directory
     * @param - element to be copied (pointer)
     */
    void copy(FileSystemBase* element);
};
