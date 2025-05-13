#include "SystèmeStockage.hpp"
#include <iostream>

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