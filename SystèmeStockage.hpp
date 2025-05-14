#ifndef SYSTEME_STOCKAGE_HPP
#define SYSTEME_STOCKAGE_HPP

#include <string>

class SystèmeStockage {
private:
    float capacité;  // Capacité totale (Wh)
    float niveauCharge;  // Niveau de charge actuel (%)
    float puissanceMax;  // Puissance maximale (W)

public:
    SystèmeStockage(float capacité, float puissanceMax);
    ~SystèmeStockage() = default;

    float calculerCapacitéRestante();
    void stocker(float puissance);
    float fournirEnergie(float puissanceDemandée);

    // Nouvelles méthodes pour la gestion des fichiers CSV
    void sauvegarderEtat(const std::string& filename);
    void chargerEtat(const std::string& filename);
};

#endif // SYSTEME_STOCKAGE_HPP