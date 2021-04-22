#pragma once

#include "FileSystemBase.h"

/** class representing file */
class File : public FileSystemBase {

private:

    int m_size;     /** file size */

public:

    /**
     * two-argument constructor
     * @param name - name
     * @param size - size 
     */
    File(std::string name, int size = 0);

    /**
     * destructor
     */
    ~File();

    std::string to_string(int spaces = 0) const override;
    FileSystemBase* createCopy() const override;
    
};
