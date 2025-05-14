#include "SystèmeStockage.hpp"
#include <iostream>
#include "CSVHandler.hpp"

SystèmeStockage::SystèmeStockage(float capacité, float puissanceMax)
    : capacité(capacité), niveauCharge(100), puissanceMax(puissanceMax) {}

float SystèmeStockage::calculerCapacitéRestante() {
    return capacité * (niveauCharge / 100);
}

void SystèmeStockage::stocker(float puissance) {
    float énergieAjoutée = puissance * 1;  // Simplification : temps = 1h
    float capacitéRestante = calculerCapacitéRestante();
    if (énergieAjoutée <= capacitéRestante) {
        niveauCharge += (énergieAjoutée / capacité) * 100;
        std::cout << "Énergie stockée avec succès.\n";
    } else {
        std::cout << "Impossible de stocker : capacité insuffisante.\n";
    }
}

float SystèmeStockage::fournirEnergie(float puissanceDemandée) {
    float énergieDisponible = calculerCapacitéRestante();
    if (puissanceDemandée <= énergieDisponible) {
        niveauCharge -= (puissanceDemandée / capacité) * 100;
        return puissanceDemandée;
    } else {
        std::cout << "Énergie insuffisante, fourniture limitée à " << énergieDisponible << " Wh.\n";
        niveauCharge = 0;
        return énergieDisponible;
    }
}

#include "CSVHandler.hpp"

// Ajouter une méthode pour sauvegarder l'état du stockage dans un fichier CSV
void SystèmeStockage::sauvegarderEtat(const std::string& filename) {
    std::vector<std::vector<std::string>> data = {
        {"Capacité", std::to_string(capacité)},
        {"Niveau de Charge", std::to_string(niveauCharge)},
        {"Puissance Max", std::to_string(puissanceMax)}
    };
    CSVHandler::writeToFile(filename, data);
}

// Ajouter une méthode pour charger l'état du stockage depuis un fichier CSV
void SystèmeStockage::chargerEtat(const std::string& filename) {
    auto data = CSVHandler::readFromFile(filename);
    if (data.size() >= 3) {
        capacité = std::stof(data[0][1]);
        niveauCharge = std::stof(data[1][1]);
        puissanceMax = std::stof(data[2][1]);
    }
}