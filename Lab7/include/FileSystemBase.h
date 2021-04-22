#pragma once

#include <iostream>
#include <vector>
#include <string>

/** class representing base of file system hierarchy */
class FileSystemBase {

    /** 
     * operator<<
     * friend overloaded << operator printing element on output stream
     * @param os - output stream
     * @param element - element to print
     */
    friend std::ostream& operator<< (std::ostream& os, const FileSystemBase& element);

protected:

    std::string m_name;     /** element name */
    std::string m_type;     /** type of element */

public:

    /** 
     * two-argument constructor
     * @param name - name
     * @param type - type
     */
    FileSystemBase(std::string name, std::string type = "");

    /** 
     * destructor
     */
    virtual ~FileSystemBase() = default;

    /**
     * getName()
     * methoda returning name of element
     * @return name
     */
    virtual std::string getName() const final;

    /**
     * getType()
     * methoda returning type of element
     * @return type
     */
    virtual std::string getType() const final;

    /**
     * to_string()
     * methoda returning element as string
     * @param spaces - indent size
     * @return - element as string
     */
    virtual std::string to_string(int spaces = 0) const = 0;

    /**
     * createCopy()
     * methoda creating copy of object
     * @return - copy (pointer)
     */
    virtual FileSystemBase* createCopy() const = 0;

};

