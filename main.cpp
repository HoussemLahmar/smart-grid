#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include "SmartGrid.hpp"
#include "Solaire.hpp"
#include "Éolienne.hpp"
#include "Géothermique.hpp"
#include "Hydraulique.hpp"
#include "Charbon.hpp"
#include "GazNaturel.hpp"
#include "Pétrole.hpp"
#include "ConsommateurDomicile.hpp"
#include "ConsommateurIndustriel.hpp"
#include "SystèmeStockage.hpp"
#include "RéseauDistribution.hpp"

// Fonction pour vider le buffer d'entrée
void viderBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Fonction pour afficher le menu principal
void afficherMenuPrincipal() {
    std::cout << "\n========== SMART GRID - MENU PRINCIPAL ==========\n";
    std::cout << "1. Gérer les unités de production\n";
    std::cout << "2. Gérer les consommateurs\n";
    std::cout << "3. Gérer le système de stockage\n";
    std::cout << "4. Gérer le réseau de distribution\n";
    std::cout << "5. Simuler le réseau\n";
    std::cout << "6. Afficher les statistiques\n";
    std::cout << "7. Quitter\n";
    std::cout << "================================================\n";
    std::cout << "Votre choix : ";
}

// Fonction pour afficher le menu des unités de production
void afficherMenuUnitésProduction() {
    std::cout << "\n========== GESTION DES UNITÉS DE PRODUCTION ==========\n";
    std::cout << "1. Ajouter une unité solaire\n";
    std::cout << "2. Ajouter une éolienne\n";
    std::cout << "3. Ajouter une unité géothermique\n";
    std::cout << "4. Ajouter une unité hydraulique\n";
    std::cout << "5. Ajouter une unité à charbon\n";
    std::cout << "6. Ajouter une unité à gaz naturel\n";
    std::cout << "7. Ajouter une unité à pétrole\n";
    std::cout << "8. Afficher toutes les unités de production\n";
    std::cout << "9. Retour au menu principal\n";
    std::cout << "====================================================\n";
    std::cout << "Votre choix : ";
}

// Fonction pour afficher le menu des consommateurs
void afficherMenuConsommateurs() {
    std::cout << "\n========== GESTION DES CONSOMMATEURS ==========\n";
    std::cout << "1. Ajouter un consommateur domicile\n";
    std::cout << "2. Ajouter un consommateur industriel\n";
    std::cout << "3. Afficher tous les consommateurs\n";
    std::cout << "4. Calculer les factures\n";
    std::cout << "5. Retour au menu principal\n";
    std::cout << "=============================================\n";
    std::cout << "Votre choix : ";
}

// Fonction pour afficher le menu du système de stockage
void afficherMenuStockage() {
    std::cout << "\n========== GESTION DU SYSTÈME DE STOCKAGE ==========\n";
    std::cout << "1. Afficher les informations de stockage\n";
    std::cout << "2. Stocker de l'énergie\n";
    std::cout << "3. Utiliser de l'énergie stockée\n";
    std::cout << "4. Retour au menu principal\n";
    std::cout << "=================================================\n";
    std::cout << "Votre choix : ";
}

// Fonction pour afficher le menu du réseau de distribution
void afficherMenuRéseau() {
    std::cout << "\n========== GESTION DU RÉSEAU DE DISTRIBUTION ==========\n";
    std::cout << "1. Afficher les informations du réseau\n";
    std::cout << "2. Calculer les pertes du réseau\n";
    std::cout << "3. Distribuer la puissance\n";
    std::cout << "4. Retour au menu principal\n";
    std::cout << "=====================================================\n";
    std::cout << "Votre choix : ";
}

// Fonction pour afficher le menu de simulation
void afficherMenuSimulation() {
    std::cout << "\n========== SIMULATION DU RÉSEAU ==========\n";
    std::cout << "1. Simuler la production d'énergie\n";
    std::cout << "2. Simuler la consommation\n";
    std::cout << "3. Simuler la distribution complète\n";
    std::cout << "4. Détecter les anomalies\n";
    std::cout << "5. Retour au menu principal\n";
    std::cout << "=========================================\n";
    std::cout << "Votre choix : ";
}

// Fonction pour afficher le menu des statistiques
void afficherMenuStatistiques() {
    std::cout << "\n========== STATISTIQUES DU RÉSEAU ==========\n";
    std::cout << "1. Bilan de production\n";
    std::cout << "2. Bilan de consommation\n";
    std::cout << "3. Rapport d'efficacité du réseau\n";
    std::cout << "4. Statistiques financières\n";
    std::cout << "5. Retour au menu principal\n";
    std::cout << "==========================================\n";
    std::cout << "Votre choix : ";
}

// Fonction pour ajouter une unité solaire
void ajouterUnitéSolaire(SmartGrid& smartGrid) {
    std::string localisation;
    float rendement, surface;
    
    std::cout << "\n----- Ajout d'une unité solaire -----\n";
    std::cout << "Localisation : ";
    std::cin.ignore();
    std::getline(std::cin, localisation);
    
    std::cout << "Rendement (0-1) : ";
    std::cin >> rendement;
    
    std::cout << "Surface des panneaux (m²) : ";
    std::cin >> surface;
    
    smartGrid.ajouterUnitéProduction(std::make_shared<Solaire>(localisation, rendement, surface));
    std::cout << "Unité solaire ajoutée avec succès.\n";
}

// Fonction pour ajouter une éolienne
void ajouterÉolienne(SmartGrid& smartGrid) {
    std::string localisation;
    float hauteur, vitesseVent;
    
    std::cout << "\n----- Ajout d'une éolienne -----\n";
    std::cout << "Localisation : ";
    std::cin.ignore();
    std::getline(std::cin, localisation);
    
    std::cout << "Hauteur (m) : ";
    std::cin >> hauteur;
    
    std::cout << "Vitesse du vent (m/s) : ";
    std::cin >> vitesseVent;
    
    smartGrid.ajouterUnitéProduction(std::make_shared<Éolienne>(localisation, hauteur, vitesseVent));
    std::cout << "Éolienne ajoutée avec succès.\n";
}

// Fonction pour ajouter une unité géothermique
void ajouterGéothermique(SmartGrid& smartGrid) {
    std::string localisation;
    float profondeur;
    
    std::cout << "\n----- Ajout d'une unité géothermique -----\n";
    std::cout << "Localisation : ";
    std::cin.ignore();
    std::getline(std::cin, localisation);
    
    std::cout << "Profondeur (m) : ";
    std::cin >> profondeur;
    
    smartGrid.ajouterUnitéProduction(std::make_shared<Géothermique>(localisation, profondeur));
    std::cout << "Unité géothermique ajoutée avec succès.\n";
}

// Fonction pour ajouter une unité hydraulique
void ajouterHydraulique(SmartGrid& smartGrid) {
    std::string localisation;
    float debit, hauteurChute;
    
    std::cout << "\n----- Ajout d'une unité hydraulique -----\n";
    std::cout << "Localisation : ";
    std::cin.ignore();
    std::getline(std::cin, localisation);
    
    std::cout << "Débit (m³/s) : ";
    std::cin >> debit;
    
    std::cout << "Hauteur de chute (m) : ";
    std::cin >> hauteurChute;
    
    smartGrid.ajouterUnitéProduction(std::make_shared<Hydraulique>(localisation, debit, hauteurChute));
    std::cout << "Unité hydraulique ajoutée avec succès.\n";
}

// Fonction pour ajouter une unité à charbon
void ajouterCharbon(SmartGrid& smartGrid) {
    std::string localisation, carburant, qualite;
    
    std::cout << "\n----- Ajout d'une unité à charbon -----\n";
    std::cout << "Localisation : ";
    std::cin.ignore();
    std::getline(std::cin, localisation);
    
    carburant = "Charbon";
    
    std::cout << "Qualité (Haute/Moyenne/Basse) : ";
    std::cin >> qualite;
    
    smartGrid.ajouterUnitéProduction(std::make_shared<Charbon>(localisation, carburant, qualite));
    std::cout << "Unité à charbon ajoutée avec succès.\n";
}

// Fonction pour ajouter une unité à gaz naturel
void ajouterGazNaturel(SmartGrid& smartGrid) {
    std::string localisation, carburant;
    float pression;
    
    std::cout << "\n----- Ajout d'une unité à gaz naturel -----\n";
    std::cout << "Localisation : ";
    std::cin.ignore();
    std::getline(std::cin, localisation);
    
    carburant = "Gaz naturel";
    
    std::cout << "Pression (bar) : ";
    std::cin >> pression;
    
    smartGrid.ajouterUnitéProduction(std::make_shared<GazNaturel>(localisation, carburant, pression));
    std::cout << "Unité à gaz naturel ajoutée avec succès.\n";
}

// Fonction pour ajouter une unité à pétrole
void ajouterPétrole(SmartGrid& smartGrid) {
    std::string localisation, carburant, type;
    
    std::cout << "\n----- Ajout d'une unité à pétrole -----\n";
    std::cout << "Localisation : ";
    std::cin.ignore();
    std::getline(std::cin, localisation);
    
    carburant = "Pétrole";
    
    std::cout << "Type (Brut/Raffiné) : ";
    std::cin >> type;
    
    smartGrid.ajouterUnitéProduction(std::make_shared<Pétrole>(localisation, carburant, type));
    std::cout << "Unité à pétrole ajoutée avec succès.\n";
}

// Fonction pour ajouter un consommateur domicile
void ajouterConsommateurDomicile(SmartGrid& smartGrid) {
    int id;
    std::string adresse, localisation;
    float puissanceContractee, puissanceActive;
    
    std::cout << "\n----- Ajout d'un consommateur domicile -----\n";
    std::cout << "ID : ";
    std::cin >> id;
    
    std::cout << "Adresse : ";
    std::cin.ignore();
    std::getline(std::cin, adresse);
    
    std::cout << "Localisation : ";
    std::getline(std::cin, localisation);
    
    std::cout << "Puissance contractée (W) : ";
    std::cin >> puissanceContractee;
    
    std::cout << "Puissance active consommée (W) : ";
    std::cin >> puissanceActive;
    
    smartGrid.ajouterConsommateur(std::make_shared<ConsommateurDomicile>(id, adresse, localisation, puissanceContractee, puissanceActive));
    std::cout << "Consommateur domicile ajouté avec succès.\n";
}

// Fonction pour ajouter un consommateur industriel
void ajouterConsommateurIndustriel(SmartGrid& smartGrid) {
    int id;
    std::string adresse, localisation;
    float puissanceContractee, puissanceReactive;
    
    std::cout << "\n----- Ajout d'un consommateur industriel -----\n";
    std::cout << "ID : ";
    std::cin >> id;
    
    std::cout << "Adresse : ";
    std::cin.ignore();
    std::getline(std::cin, adresse);
    
    std::cout << "Localisation : ";
    std::getline(std::cin, localisation);
    
    std::cout << "Puissance contractée (W) : ";
    std::cin >> puissanceContractee;
    
    std::cout << "Puissance réactive consommée (VAR) : ";
    std::cin >> puissanceReactive;
    
    smartGrid.ajouterConsommateur(std::make_shared<ConsommateurIndustriel>(id, adresse, localisation, puissanceContractee, puissanceReactive));
    std::cout << "Consommateur industriel ajouté avec succès.\n";
}

// Fonction pour simuler la production d'énergie
void simulerProduction(SmartGrid& smartGrid, std::vector<std::shared_ptr<UnitéProduction>>& unitésProduction) {
    float puissanceTotale = 0.0;
    
    std::cout << "\n----- Simulation de la production d'énergie -----\n";
    std::cout << "Unités de production en fonctionnement :\n";
    
    for (size_t i = 0; i < unitésProduction.size(); ++i) {
        float puissance = unitésProduction[i]->calculerPuissanceProduite();
        puissanceTotale += puissance;
        
        std::cout << "Unité " << (i+1) << " (" << unitésProduction[i]->getLocation() << ") : "
                  << std::fixed << std::setprecision(2) << puissance << " W\n";
    }
    
    std::cout << "Puissance totale produite : " << std::fixed << std::setprecision(2) << puissanceTotale << " W\n";
}

// Fonction pour détecter les anomalies
void détecterAnomalies(const std::vector<std::shared_ptr<UnitéProduction>>& unitésProduction) {
    bool anomaliesDetectées = false;
    
    std::cout << "\n----- Détection des anomalies -----\n";
    
    for (size_t i = 0; i < unitésProduction.size(); ++i) {
        if (unitésProduction[i]->detecterAnomalie()) {
            std::cout << "Anomalie détectée dans l'unité " << (i+1) << " (" << unitésProduction[i]->getLocation() << ")\n";
            anomaliesDetectées = true;
        }
    }
    
    if (!anomaliesDetectées) {
        std::cout << "Aucune anomalie détectée dans les unités de production.\n";
    }
}

// Fonction principale
int main() {
    // Initialisation du système de stockage et du Smart Grid
    SystèmeStockage stockage(10000, 5000); // Capacité 10 kWh, Puissance max 5 kW
    SmartGrid smartGrid(stockage);
    
    // Initialisation du réseau de distribution
    RéseauDistribution réseauDistribution(230, 0.01); // 230V, 0.01 Ohm
    
    // Vecteur pour stocker les références aux unités de production
    std::vector<std::shared_ptr<UnitéProduction>> unitésProduction;
    
    int choixPrincipal = 0;
    while (choixPrincipal != 7) {
        afficherMenuPrincipal();
        std::cin >> choixPrincipal;
        
        switch (choixPrincipal) {
            case 1: { // Gérer les unités de production
                int choixUnités = 0;
                while (choixUnités != 9) {
                    afficherMenuUnitésProduction();
                    std::cin >> choixUnités;
                    
                    switch (choixUnités) {
                        case 1: ajouterUnitéSolaire(smartGrid); break;
                        case 2: ajouterÉolienne(smartGrid); break;
                        case 3: ajouterGéothermique(smartGrid); break;
                        case 4: ajouterHydraulique(smartGrid); break;
                        case 5: ajouterCharbon(smartGrid); break;
                        case 6: ajouterGazNaturel(smartGrid); break;
                        case 7: ajouterPétrole(smartGrid); break;
                        case 8: 
                            std::cout << "\nLa fonctionnalité d'affichage des unités n'est pas encore implémentée.\n";
                            break;
                        case 9: break; // Retour au menu principal
                        default:
                            std::cout << "Option invalide, veuillez réessayer.\n";
                            break;
                    }
                }
                break;
            }
            
            case 2: { // Gérer les consommateurs
                int choixConsommateurs = 0;
                while (choixConsommateurs != 5) {
                    afficherMenuConsommateurs();
                    std::cin >> choixConsommateurs;
                    
                    switch (choixConsommateurs) {
                        case 1: ajouterConsommateurDomicile(smartGrid); break;
                        case 2: ajouterConsommateurIndustriel(smartGrid); break;
                        case 3: smartGrid.afficherRésuméConsommateurs(); break;
                        case 4: smartGrid.calculerFactures(); break;
                        case 5: break; // Retour au menu principal
                        default:
                            std::cout << "Option invalide, veuillez réessayer.\n";
                            break;
                    }
                }
                break;
            }
            
            case 3: { // Gérer le système de stockage
                int choixStockage = 0;
                while (choixStockage != 4) {
                    afficherMenuStockage();
                    std::cin >> choixStockage;
                    
                    switch (choixStockage) {
                        case 1: 
                            std::cout << "\nCapacité restante : " << stockage.calculerCapacitéRestante() << " Wh\n";
                            break;
                        case 2: {
                            float puissance;
                            std::cout << "Entrez la puissance à stocker (W) : ";
                            std::cin >> puissance;
                            stockage.stocker(puissance);
                            break;
                        }
                        case 3: {
                            float puissance;
                            std::cout << "Entrez la puissance demandée (W) : ";
                            std::cin >> puissance;
                            float fournie = stockage.fournirEnergie(puissance);
                            std::cout << "Énergie fournie : " << fournie << " Wh\n";
                            break;
                        }
                        case 4: break; // Retour au menu principal
                        default:
                            std::cout << "Option invalide, veuillez réessayer.\n";
                            break;
                    }
                }
                break;
            }
            
            case 4: { // Gérer le réseau de distribution
                int choixRéseau = 0;
                while (choixRéseau != 4) {
                    afficherMenuRéseau();
                    std::cin >> choixRéseau;
                    
                    switch (choixRéseau) {
                        case 1:
                            std::cout << "\nInformations du réseau non disponibles pour le moment.\n";
                            break;
                        case 2: {
                            float pertes = réseauDistribution.calculerPertes();
                            std::cout << "Pertes du réseau : " << pertes << " W\n";
                            break;
                        }
                        case 3: {
                            float puissance;
                            std::cout << "Entrez la puissance à distribuer (W) : ";
                            std::cin >> puissance;
                            réseauDistribution.distribuerPuissance(puissance);
                            break;
                        }
                        case 4: break; // Retour au menu principal
                        default:
                            std::cout << "Option invalide, veuillez réessayer.\n";
                            break;
                    }
                }
                break;
            }
            
            case 5: { // Simuler le réseau
                int choixSimulation = 0;
                while (choixSimulation != 5) {
                    afficherMenuSimulation();
                    std::cin >> choixSimulation;
                    
                    switch (choixSimulation) {
                        case 1:
                            simulerProduction(smartGrid, unitésProduction);
                            break;
                        case 2:
                            std::cout << "\nLa simulation de consommation n'est pas encore implémentée.\n";
                            break;
                        case 3:
                            smartGrid.distribuerPuissance();
                            break;
                        case 4:
                            détecterAnomalies(unitésProduction);
                            break;
                        case 5: break; // Retour au menu principal
                        default:
                            std::cout << "Option invalide, veuillez réessayer.\n";
                            break;
                    }
                }
                break;
            }
            
            case 6: { // Afficher les statistiques
                int choixStatistiques = 0;
                while (choixStatistiques != 5) {
                    afficherMenuStatistiques();
                    std::cin >> choixStatistiques;
                    
                    switch (choixStatistiques) {
                        case 1:
                            std::cout << "\nLe bilan de production n'est pas encore implémenté.\n";
                            break;
                        case 2:
                            std::cout << "\nLe bilan de consommation n'est pas encore implémenté.\n";
                            break;
                        case 3:
                            std::cout << "\nLe rapport d'efficacité du réseau n'est pas encore implémenté.\n";
                            break;
                        case 4:
                            std::cout << "\nLes statistiques financières ne sont pas encore implémentées.\n";
                            break;
                        case 5: break; // Retour au menu principal
                        default:
                            std::cout << "Option invalide, veuillez réessayer.\n";
                            break;
                    }
                }
                break;
            }
            
            case 7: // Quitter
                std::cout << "\nFermeture du programme. Au revoir !\n";
                break;
                
            default:
                std::cout << "Option invalide, veuillez réessayer.\n";
                break;
        }
    }
    
    return 0;
}