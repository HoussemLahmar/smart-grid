#ifndef RESEAU_DISTRIBUTION_HPP
#define RESEAU_DISTRIBUTION_HPP

class RéseauDistribution {
private:
    float tension;  // Tension du réseau (V)
    float impédance;  // Impédance du réseau (Ω)

public:
    RéseauDistribution(float tension, float impédance);
    ~RéseauDistribution() = default;

    float calculerPertes();
    void distribuerPuissance(float puissance);
};

#endif // RESEAU_DISTRIBUTION_HPP