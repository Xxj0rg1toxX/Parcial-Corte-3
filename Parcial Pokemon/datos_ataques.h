#ifndef DATOS_ATAQUES_H
#define DATOS_ATAQUES_H
#include <vector>
#include <string>

using namespace std;

struct AllAttacks{
    string name;
    string type;
    string category;
    int damage;
    int precision;
    vector<pair<string, int>> efecto;
    vector<tuple<string, int, int>> stats;
    pair<bool,float> autodamage;
    bool prioridad;
    float criticprop;
};
const AllAttacks All_Attacks [38] = {
    //Pikachu
    {"Placaje Electrico", "Electrico", "Fisico", 120, 100, {{"paralisis", 10}}, {}, {true, 1/3}, 0},
    {"Cola Ferrea", "Acero", "Fisico", 100, 75, {}, {{"Defense", -1, 30}}, {}, 0},
    {"Ataque Rapido", "Normal", "Fisico", 40, 100, {}, {}, {}, 1},
    {"Rayo", "Electrico", "Especial", 90, 100, {{"paralisis", 10}}, {}, {}, 0},
    //Snorlax
    {"Bola Sombra", "Fantasma", "Especial", 80, 100, {}, {{"SpDefense", -1, 20}}, {}, 0},
    {"Triturar", "Siniesto", "Fisico", 80, 100, {}, {{"Defense", -1, 20}}, {}, 0},
    {"Ventisca", "Hielo", "Especial", 110, 70, {{"congelar", 10}}, {}, {}, 0},
    {"Gigaimpacto", "Normal", "Fisico", 150, 90, {}, {}, {}, 0},
    //Venasaur
    {"Bomba Lodo", "Veneno", "Especial", 90, 100, {{"veneno", 30}}, {}, {}, 0},
    {"Gigadrenado", "Planta", "Especial", 75, 100, {{"robovida", 50}}, {}, {}, 0},
    {"Somnifero", "Planta", "Estado", 0, 75, {{"dormir", 100}}, {}, {}, 0},
    {"Planta Feroz", "Planta", "Especial", 150, 90, {{"esperarturno", 1}}, {}, {}, 0},
    //Lapras
    {"Salmuera", "Agua", "Especial", 65, 100, {{"mitad de vida", 65}}, {}, {}, 0},
    {"Psíquico", "Psiquico", "Especial", 90, 100, {}, {{"SpDefense", -1, 10}}, {}, 0},
    {"Golpe Cuerpo", "Normal", "Fisico", 80, 100, {{"paralisis", 30}}, {}, {}, 0},
    //Blastoise
    {"Honda Certera", "Lucha", "Especial", 120, 70, {}, {{"SpDefense", -1, 10}}, {}, 0},
    {"Hidrocañón", "Agua", "Especial", 150, 90, {{"esperarturno", 1}}, {}, {}, 0},
    {"Foco Resplandor", "Acero", "Especial", 80, 100, {}, {{"SpDefense", -1, 10}}},
    //Charizard
    {"Envite Igneo", "Fuego", "Fisico", 120, 100, {{"quemar", 10}}, {}, {true, 1/3}, 0},
    {"Tajo Aereo", "Volador", "Fisico", 75, 95, {{"retroceso", 30}}, {}, {}, 0},
    {"Anillo Igneo", "Fuego", "Especial", 150, 90, {{"esperarturno", 1}}, {}, {}, 0},
    {"Pulso Dragón", "Dragon", "Especial", 90, 100, {}, {}, {}, 0},
    //Exeggutor
    {"Lluevehojas", "Planta", "Especial", 140, 90, {}, {{"SpAttack", -2, 100}}, {}, 0},
    {"Explosion", "Normal", "Fisico", 500, 100, {{"morir", 100}}, {}, {}, 0},
    {"Viento Plata", "Bicho", "Especial", 60, 100, {}, {{"Todas", 1, 10}}, {}, 0},
    //Machamp
    {"Puño Dínamico", "Lucha", "Fisico", 100, 50, {{"confusion", 100}}, {}, {}, 0},
    {"Roca Afilada", "Roca", "Fisico", 100, 80, {}, {}, {}, 0, 12.5},
    {"Atraccion", "Normal", "Stats", 0, 100, {{"enamorar", 100}}, {}, {}, 0},
    {"Terremoto", "Tierra", "Fisico", 100, 100, {}, {}, {}, 0},
    //Arcanine
    {"Colmillo Rayo", "Electrico", "Fisico", 65, 95, {{"paralisis", 10}, {"retroceso", 10}}, {}, {}, 0},
    {"Velocidad Extrema", "Normal", "Fisico", 80, 100, {}, {}, {}, 2, 0},
    //Tyranitar
    {"Avalancha", "Roca", "Fisico", 75, 90, {{"retroceso", 30}}, {}, {}, 0},
    {"Colmillo Fuego", "Fuego", "Fisico", 65, 95, {{"quemar", 10}, {"retroceso", 10}}, {}, {}, 0},
    {"Danza Dragón", "Dragon", "Stats", 0, 100, {}, {{"Attack", 1, 100}, {"Speed", 1, 100}}, {}, 0},
    //Rhyperior
    {"Megacuerno", "Bicho", "Fisico", 120, 85, {}, {}, {}, 0},
    //Pidgeot
    {"Retribucion", "Normal", "Fisico", 102, 100, {}, {}, {}, 0},
    {"Ala de Acero", "Acero", "Fisico", 70, 90, {}, {{"Defence", 1, 100}}, {}, 0},
    {"Doble Equipo", "Normal", "Stats", 0, 100, {}, {{"Evasion", 1, 100}}, {}, 0}
};
#endif