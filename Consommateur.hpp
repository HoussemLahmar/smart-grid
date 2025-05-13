#ifndef CONSOMMATEUR_HPP
#define CONSOMMATEUR_HPP

#include <string>

class Consommateur {
protected:
    int id;                       // Identifiant unique
    std::string adresse;          // Adresse physique
    std::string localisation;     // Localisation géographique
    float puissanceContractee;    // Puissance contractée (W)

public:
    Consommateur(int id, std::string adresse, std::string localisation, float puissance);
    virtual ~Consommateur() = default;

    virtual float calculerConsommation() = 0;  // Méthode abstraite
    std::string getLocalisation() const;
    int getId() const;
    std::string getAdresse() const;
    float getPuissanceContractee() const;
};

#endif // CONSOMMATEUR_HPP