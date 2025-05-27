#ifndef DATOS_POKEMON_H
#define DATOS_POKEMON_H
#include <string>
#include <vector>

using namespace std;

struct AllPokes{
    string name;
    vector<string> type;
    int PS;
    int Attack;
    int SpAttack;
    int Defense;
    int SpDefense;
    int Velocity;
};
const AllPokes All_Pokes [12] = {
    //Red
    {"Pikachu", {"Electrico"}, 35, 110, 40, 100, 50, 90},
    {"Charizard", {"Fuego", "Volador"}, 130, 111, 130, 85, 100},
    {"Blastoise", {"Agua"}, 79, 103, 120, 135, 115, 78},
    {"Venasaur", {"Planta", "Veneno"}, 80, 100, 123, 122, 120, 80},
    {"Snorlax", {"Normal"}, 160, 110, 65, 65, 110, 30},
    {"Lapras", {"Agua", "Hielo"}, 130, 85, 80, 85, 95, 60},
    //Blue
    {"Exeggutor", {"Planta", "Psiquico"}, 95, 95, 85, 125, 65, 55},
    {"Machamp", {"Lucha"}, 90, 130 ,80, 65, 85, 55},
    {"Arcanine", {"Fuego"}, 90, 110, 80, 100, 80, 95},
    {"Tyranitar", {"Roca", "Siniestro"}, 100, 134, 110, 95, 100, 61},
    {"Rhyperior", {"Tierra", "Roca"}, 115, 140, 130, 55, 55, 40},
    {"Pidgeot", {"Normal", "Volador"}, 83, 80,80, 135, 80, 121}
};
#endif 