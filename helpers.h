#ifndef HELPERS_H
#define HELPERS_H

#pragma once

#include<vector>
#include <string>
class helpers
{
public:

    helpers();

    void hi();

    std::vector<std::string> ReadFileLines(const std::string &path);

    void WriteFileLines(const std::string &path, const std::vector<std::string> &lines, bool append = true);

    std::vector<std::string> SplitString(const std::string &str, const std::string &delimiter = "," ); 

    int ToInt(const std::string &str);

    int ReadInt(int low, int high);

    int ShowReadMenu(const std::vector<std::string> &choices);
    
    ~helpers();

private:

};

#endif