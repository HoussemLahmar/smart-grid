#include "SmartGrid.hpp"
#include <iostream>
#include <iomanip> // Pour afficher des nombres formatés

#include "SmartGrid.hpp"
#include "ConsommateurIndustriel.hpp"
#include "ConsommateurDomicile.hpp"


SmartGrid::SmartGrid(SystèmeStockage stockage) : stockage(stockage) {}

void SmartGrid::ajouterUnitéProduction(std::shared_ptr<UnitéProduction> unité) {
    unitésProduction.push_back(unité);
}

void SmartGrid::ajouterConsommateur(std::shared_ptr<Consommateur> consommateur) {
    consommateurs.push_back(consommateur);
}

void SmartGrid::distribuerPuissance() {
    float puissanceProduiteTotale = 0;
    for (const auto& unité : unitésProduction) {
        puissanceProduiteTotale += unité->calculerPuissanceProduite();
    }

    float puissanceDemandéeTotale = 0;
    for (const auto& consommateur : consommateurs) {
        puissanceDemandéeTotale += consommateur->calculerConsommation();
    }

    if (puissanceProduiteTotale >= puissanceDemandéeTotale) {
        std::cout << "Puissance excédentaire : " << (puissanceProduiteTotale - puissanceDemandéeTotale) << " W, envoyée à la batterie.\n";
        stockage.stocker(puissanceProduiteTotale - puissanceDemandéeTotale);
    } else {
        std::cout << "Puissance insuffisante pour répondre à la demande des consommateurs.\n";
    }
}

void SmartGrid::calculerFactures() {
    std::cout << "\n--- Calcul des factures des consommateurs ---\n";
    for (const auto& consommateur : consommateurs) {
        float consommation = consommateur->calculerConsommation(); // Consommation en kWh
        float facture = 0.0;

        if (consommation <= 2400) {
            facture = consommation * 0.181; // Tarif pour consommation <= 2.400 kWh
        } else if (consommation <= 3600) {
            facture = consommation * 0.223; // Tarif pour consommation entre 2.401 et 3.600 kWh
        } else {
            facture = consommation * 0.223; // Étendre cette logique pour d'autres seuils si nécessaire
        }

        std::cout << "Consommateur ID: " << consommateur->getId()
                  << ", Consommation: " << consommation << " kWh"
                  << ", Facture: " << std::fixed << std::setprecision(3) << facture << " DT\n";
    }
}

void SmartGrid::afficherRésuméConsommateurs() {
    std::cout << "\n--- Résumé des consommateurs ---\n";
    for (const auto& consommateur : consommateurs) {
        std::cout << "Consommateur ID: " << consommateur->getId()
                  << ", Localisation: " << consommateur->getLocalisation()
                  << ", Consommation: " << consommateur->calculerConsommation() << " kWh\n";
    }
}



void SmartGrid::sauvegarderConsommateurs(const std::string& filename) {
    std::vector<std::vector<std::string>> data;
    for (const auto& consommateur : consommateurs) {
        std::vector<std::string> row = {
            consommateur->getType(), // "Domicile" ou "Industriel"
            std::to_string(consommateur->getId()),
            consommateur->getAdresse(),
            consommateur->getLocalisation(),
            std::to_string(consommateur->getPuissanceContractee())
        };
        data.push_back(row);
    }
    CSVHandler::writeToFile(filename, data);
}

void SmartGrid::chargerConsommateurs(const std::string& filename) {
    auto data = CSVHandler::readFromFile(filename);
    for (const auto& row : data) {
        if (row[0] == "Domicile") {
            consommateurs.push_back(std::make_shared<ConsommateurDomicile>(
                std::stoi(row[1]), row[2], row[3], 0.0f, 0.0f));
        } else if (row[0] == "Industriel") {
            consommateurs.push_back(std::make_shared<ConsommateurIndustriel>(
                std::stoi(row[1]), row[2], row[3], 0.0f, 0.0f));
        }
    }
    std::cout << "Consommateurs chargés depuis " << filename << std::endl;
}