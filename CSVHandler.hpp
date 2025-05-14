#ifndef CSVHANDLER_HPP
#define CSVHANDLER_HPP

#include <fstream>
#include <vector>
#include <string>

class CSVHandler {
public:
    static void writeToFile(const std::string& filename, const std::vector<std::vector<std::string>>& data);
    static std::vector<std::vector<std::string>> readFromFile(const std::string& filename);
};

#endif // CSVHANDLER_HPP