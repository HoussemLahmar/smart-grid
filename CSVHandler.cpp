#include "CSVHandler.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void CSVHandler::writeToFile(const std::string& filename, const std::vector<std::vector<std::string>>& data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier pour l'écriture.\n";
        return;
    }
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) file << ",";
        }
        file << "\n";
    }
    file.close();
}

std::vector<std::vector<std::string>> CSVHandler::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<std::string>> data;
    if (!file.is_open()) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier pour la lecture.\n";
        return data;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }
    file.close();
    return data;
}