//Pokemon v2

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;


// Estructuras y constantes por ids
struct AllPokes {
    int level;
    string name;
    vector<string> type;
    int Ps, atk, spa, def, spd, spe;
};

struct AllAttacks {
    string name, type, category;
    int power, accuracy;
    vector<pair<string, int>> effect;
    vector<tuple<string, int, int>> stats;
    bool autoDamage, priority;
    float criticChance;
};

struct team {
    int pokemon;
    int mov1, mov2, mov3, mov4;
};

const AllPokes All_Pokes[12] = {
    {88, "Pikachu", {"Electrico"}, 35, 110, 40, 100, 50, 90},
    {84, "Charizard", {"Fuego", "Volador"}, 130, 111, 130, 85, 100, 100},
    {84, "Blastoise", {"Agua"}, 79, 103, 120, 135, 115, 78},
    {84, "Venasaur", {"Planta", "Veneno"}, 80, 100, 123, 122, 120, 80},
    {82, "Snorlax", {"Normal"}, 160, 110, 65, 65, 110, 30},
    {80, "Lapras", {"Agua", "Hielo"}, 130, 85, 80, 85, 95, 60},
    {88, "Exeggutor", {"Planta", "Psiquico"}, 95, 95, 85, 125, 65, 55},
    {82, "Machamp", {"Lucha"}, 90, 130, 80, 65, 85, 55},
    {84, "Arcanine", {"Fuego"}, 90, 110, 80, 100, 80, 95},
    {80, "Tyranitar", {"Roca", "Siniestro"}, 100, 134, 110, 95, 100, 61},
    {84, "Rhyperior", {"Tierra", "Roca"}, 115, 140, 130, 55, 55, 40},
    {84, "Pidgeot", {"Normal", "Volador"}, 83, 80, 80, 135, 80, 121}
};


const AllAttacks All_Attacks[38] = {
    {"Placaje Electrico", "Electrico", "Fisico", 120, 100, {{"paralisis", 10}}, {}, true, 0, 0.04},
    {"Cola Ferrea", "Acero", "Fisico", 100, 75, {}, {{"Defense", -1, 30}}, false, false, 0.04},
    {"Ataque Rapido", "Normal", "Fisico", 40, 100, {}, {}, false, true, 0.04},
    {"Rayo", "Electrico", "Especial", 90, 100, {{"paralisis", 10}}, {}, false, false, 0.04},
    {"Bola Sombra", "Fantasma", "Especial", 80, 100, {}, {{"SpDefense", -1, 20}}, false, false, 0.04},
    {"Triturar", "Siniestro", "Fisico", 80, 100, {}, {{"Defense", -1, 20}}, false, false, 0.04},
    {"Ventisca", "Hielo", "Especial", 110, 70, {{"congelar", 10}}, {}, false, false, 0.04},
    {"Gigaimpacto", "Normal", "Fisico", 150, 90, {}, {}, false, false, 0.04},
    {"Bomba Lodo", "Veneno", "Especial", 90, 100, {{"veneno", 30}}, {}, false, false, 0.04},
    {"Gigadrenado", "Planta", "Especial", 75, 100, {{"robovida", 50}}, {}, false, false, 0.04},
    {"Somnifero", "Planta", "Fisico", 0, 75, {{"dormir", 100}}, {}, false, false, 0.04},
    {"Planta Feroz", "Planta", "Especial", 150, 90, {{"esperarturno", 1}}, {}, false, false, 0.04},
    {"Salmuera", "Agua", "Especial", 65, 100, {}, {}, false, false, 0.04},
    {"Psíquico", "Psiquico", "Especial", 90, 100, {}, {{"SpDefense", -1, 10}}, false, false, 0.04},
    {"Golpe Cuerpo", "Normal", "Fisico", 80, 100, {{"paralisis", 30}}, {}, false, false, 0.04},
    {"Honda Certera", "Lucha", "Especial", 120, 70, {}, {{"SpDefense", -1, 10}}, false, false, 0.04},
    {"Hidrocañón", "Agua", "Especial", 150, 90, {{"esperarturno", 1}}, {}, false, false, 0.04},
    {"Foco Resplandor", "Acero", "Especial", 80, 100, {}, {{"SpDefense", -1, 10}}, false, false, 0.04},
    {"Envite Igneo", "Fuego", "Fisico", 120, 100, {{"quemar", 10}}, {}, true, false, 0.04},
    {"Tajo Aereo", "Volador", "Fisico", 75, 95, {{"retroceso", 30}}, {}, false, false, 0.04},
    {"Anillo Igneo", "Fuego", "Especial", 150, 90, {{"esperarturno", 1}}, {}, false, false, 0.04},
    {"Pulso Dragón", "Dragon", "Especial", 90, 100, {}, {}, false, false, 0.04},
    {"Lluevehojas", "Planta", "Especial", 140, 90, {}, {{"SpAttack", -2, 100}}, false, false, 0.04},
    {"Explosion", "Normal", "Fisico", 500, 100, {{"morir", 100}}, {}, false, false, 0.04},
    {"Viento Plata", "Bicho", "Especial", 60, 100, {}, {{"Attack", 1, 10}}, false, false, 0.04},
    {"Puño Dínamico", "Lucha", "Fisico", 100, 50, {}, {}, false, false, 0.04},
    {"Roca Afilada", "Roca", "Fisico", 100, 80, {}, {}, false, false, 0.125},
    {"Terremoto", "Tierra", "Fisico", 100, 100, {}, {}, false, false, 0.04},
    {"Colmillo Rayo", "Electrico", "Fisico", 65, 95, {{"paralisis", 10}, {"retroceso", 10}}, {}, false, false, 0.04},
    {"Velocidad Extrema", "Normal", "Fisico", 80, 100, {}, {}, false, true, 0.04},
    {"Avalancha", "Roca", "Fisico", 75, 90, {{"retroceso", 30}}, {}, false, false, 0.04},
    {"Colmillo Fuego", "Fuego", "Fisico", 65, 95, {{"quemar", 10}, {"retroceso", 10}}, {}, false, false, 0.04},
    {"Danza Dragón", "Dragon", "Fisico", 0, 100, {}, {{"Attack", 1, 100}, {"Speed", 1, 100}}, false, false, 0.04},
    {"Megacuerno", "Bicho", "Fisico", 120, 85, {}, {}, false, false, 0.04},
    {"Retribucion", "Normal", "Fisico", 102, 100, {}, {}, false, false, 0.04},
    {"Ala de Acero", "Acero", "Fisico", 70, 90, {}, {{"Defense", 1, 100}}, false, false, 0.04},
    {"Brave Bird", "Volador", "Fisico", 120, 100, {}, {}, true, false, 0.04}
};

// EQUIPOS

const team red[6] = {
    {0, 0, 1, 2, 3}, {4, 4, 5, 6, 7}, {3, 8, 9, 10, 11},
    {5, 12, 13, 14, 6}, {2, 15, 16, 17, 6}, {1, 18, 19, 20, 21}
};

const team blue[6] = {
    {6, 22, 23, 24, 13}, {7, 25, 26, 27, 15}, {8, 29, 30, 18, 5},
    {9, 31, 32, 33, 28}, {10, 34, 28, 29, 26}, {11, 35, 36, 2, 19}
};
// EFECTIVIDAD 
const map<string, map<string, float>> tablaTipos = {
    {"Normal", {{"Roca", 0.5f}, {"Fantasma", 0.0f}, {"Acero", 0.5f}}},
    {"Fuego", {{"Fuego", 0.5f}, {"Agua", 0.5f}, {"Planta", 2.0f}, {"Hielo", 2.0f}, {"Bicho", 2.0f}, {"Roca", 0.5f}, {"Dragon", 0.5f}, {"Acero", 2.0f}}},
    {"Agua", {{"Fuego", 2.0f}, {"Agua", 0.5f}, {"Planta", 0.5f}, {"Tierra", 2.0f}, {"Roca", 2.0f}, {"Dragon", 0.5f}}},
    {"Planta", {{"Fuego", 0.5f}, {"Agua", 2.0f}, {"Planta", 0.5f}, {"Veneno", 0.5f}, {"Tierra", 2.0f}, {"Volador", 0.5f}, {"Bicho", 0.5f}, {"Roca", 2.0f}, {"Dragon", 0.5f}, {"Acero", 0.5f}}},
    {"Electrico", {{"Agua", 2.0f}, {"Planta", 0.5f}, {"Electrico", 0.5f}, {"Tierra", 0.0f}, {"Volador", 2.0f}, {"Dragon", 0.5f}}},
    {"Hielo", {{"Fuego", 0.5f}, {"Agua", 0.5f}, {"Planta", 2.0f}, {"Tierra", 2.0f}, {"Volador", 2.0f}, {"Dragon", 2.0f}, {"Acero", 0.5f}}},
    {"Lucha", {{"Normal", 2.0f}, {"Hielo", 2.0f}, {"Roca", 2.0f}, {"Siniestro", 2.0f}, {"Acero", 2.0f}, {"Veneno", 0.5f}, {"Volador", 0.5f}, {"Psiquico", 0.5f}, {"Bicho", 0.5f}, {"Fantasma", 0.0f}}},
    {"Veneno", {{"Planta", 2.0f}, {"Veneno", 0.5f}, {"Tierra", 0.5f}, {"Roca", 0.5f}, {"Fantasma", 0.5f}, {"Acero", 0.0f}}},
    {"Tierra", {{"Fuego", 2.0f}, {"Electrico", 2.0f}, {"Planta", 0.5f}, {"Veneno", 2.0f}, {"Volador", 0.0f}, {"Roca", 2.0f}, {"Acero", 2.0f}, {"Bicho", 0.5f}}},
    {"Volador", {{"Electrico", 0.5f}, {"Planta", 2.0f}, {"Lucha", 2.0f}, {"Bicho", 2.0f}, {"Roca", 0.5f}, {"Acero", 0.5f}}},
    {"Psiquico", {{"Lucha", 2.0f}, {"Veneno", 2.0f}, {"Psiquico", 0.5f}, {"Acero", 0.5f}, {"Siniestro", 0.0f}}},
    {"Bicho", {{"Fuego", 0.5f}, {"Planta", 2.0f}, {"Lucha", 0.5f}, {"Veneno", 0.5f}, {"Volador", 0.5f}, {"Psiquico", 2.0f}, {"Fantasma", 0.5f}, {"Siniestro", 2.0f}, {"Acero", 0.5f}}},
    {"Roca", {{"Fuego", 2.0f}, {"Hielo", 2.0f}, {"Lucha", 0.5f}, {"Tierra", 0.5f}, {"Volador", 2.0f}, {"Bicho", 2.0f}, {"Acero", 0.5f}}},
    {"Fantasma", {{"Normal", 0.0f}, {"Psiquico", 2.0f}, {"Fantasma", 2.0f}, {"Siniestro", 0.5f}}},
    {"Dragon", {{"Dragon", 2.0f}, {"Acero", 0.5f}}},
    {"Siniestro", {{"Lucha", 0.5f}, {"Psiquico", 2.0f}, {"Fantasma", 2.0f}, {"Siniestro", 0.5f}}},
    {"Acero", {{"Fuego", 0.5f}, {"Agua", 0.5f}, {"Electrico", 0.5f}, {"Hielo", 2.0f}, {"Roca", 2.0f}, {"Acero", 0.5f}}}
};

float obtenerEfectividad(const string& tipoAtaque, const vector<string>& tiposObjetivo) {
    float multiplicador = 1.0f;
    for (const string& tipoDefensor : tiposObjetivo) {
        auto it = tablaTipos.find(tipoAtaque);
        if (it != tablaTipos.end()) {
            auto it2 = it->second.find(tipoDefensor);
            if (it2 != it->second.end()) {
                multiplicador *= it2->second;
            }
        }
    }
    return multiplicador;
}

// CLASES 

enum Estadistica { ATAQUE, SP_ATAQUE, DEFENSA, SP_DEFENSA, VELOCIDAD, EVASION };

class Ataque {
private:
    const AllAttacks& info;
public:
    Ataque(int id) : info(All_Attacks[id]) {
        if (id < 0 || id >= 38) {
            cerr << "ID de ataque inválido\n";
            exit(1);
        }
        static bool semilla = false;
        if (!semilla) {
            srand(static_cast<unsigned>(time(nullptr)));
            semilla = true;
        }
    }
    string getNombre() const { return info.name; }
    string getTipo() const { return info.type; }
    string getCategoria() const { return info.category; }
    int getPoder() const { return info.power; }
    int getPrecision() const { return info.accuracy; }
    float getCriticChance() const { return (info.criticChance > 0) ? info.criticChance : 0.04f; }
    bool tienePrioridad() const { return info.priority; }
    const vector<pair<string, int>>& getEfectos() const { return info.effect; }
    bool tieneAutoDaño() const { return info.autoDamage; }
    bool acierta() const { return (rand() % 100) < info.accuracy; }
};

class Pokemon {
private:
    int idBase, nivel, psActual;
    int psBase, atkBase, spaBase, defBase, spdBase, speBase;
    int etapas[6]{};
    string nombre, estado;
    vector<string> tipos;
    vector<Ataque> movimientos;
    bool perderTurno = false;
    bool esperarTurno = false;

public:
    Pokemon(int id, const vector<int>& ataques) : idBase(id), nivel(All_Pokes[id].level) {
        const AllPokes& base = All_Pokes[id];
        nombre = base.name;
        psBase = base.Ps; atkBase = base.atk; spaBase = base.spa;
        defBase = base.def; spdBase = base.spd; speBase = base.spe;
        tipos = base.type;
        psActual = calcularVida();
        for (int idAtk : ataques) movimientos.emplace_back(idAtk);
    }
    int calcularVida() const { return ((2 * psBase * nivel) / 100) + nivel + 10; }
    int getPS() const { return psActual; }
    int getStat(Estadistica stat) const {
        float mult[] = {atkBase, spaBase, defBase, spdBase, speBase, 1};
        float tabla[13] = {0.25f, 0.29f, 0.33f, 0.4f, 0.5f, 0.67f, 1.0f, 1.5f, 2.0f, 2.5f, 3.0f, 3.5f, 4.0f};
        return static_cast<int>(mult[stat] * tabla[etapas[stat] + 6]);
    }
    
    string getNombre() const { return nombre; }
    const vector<string>& getTipos() const { return tipos; }
    int getVelocidad() const { return getStat(VELOCIDAD); }
    bool estaDebilitado() const { return psActual <= 0; }
    int getAtk() const {return atkBase;}
    int getSpAtk() const {return spaBase;}
    int getSpDef() const {return spdBase;}
    int getDef() const {return defBase;}
    int getlvl() const {return nivel;}
    void recibirDaño(int cantidad) {
        psActual -= cantidad;
        if (psActual < 0) psActual = 0;
        cout << nombre << " recibió " << cantidad << " puntos de daño.\n";
    }

    void mostrarResumen() const {
        cout << nombre << " (PS: " << psActual << "/" << calcularVida() << ")\n";
        for (int i = 0; i < movimientos.size(); ++i)
            cout << i + 1 << ". " << movimientos[i].getNombre() << "\n";
    }
    void usarMovimiento(int slot, Pokemon& objetivo) {
        Ataque& atk = movimientos[slot - 1];
        cout << nombre << " usa " << atk.getNombre() << "!\n";
        if (!atk.acierta()) { cout << "¡Falló!\n"; return; }
        int A = (atk.getCategoria() == "Fisico") ? getAtk() : getSpAtk();
        int D = (atk.getCategoria() == "Fisico") ? objetivo.getDef() : objetivo.getSpDef();
        float P = atk.getPoder();
        int nivel = getlvl();
        float B = obtenerEfectividad(atk.getTipo(), objetivo.getTipos());
        int daño =  ((nivel * P * A) / (D * 40)) * B ;
        if ((rand() % 100) < (atk.getCriticChance() * 100)) {
            daño *= 1.5f;
            cout << "¡Golpe crítico!\n";
        }
        if (B > 1.0f) cout << "¡Es super efectivo!\n";
        else if (B < 1.0f) cout << "No es muy efectivo...\n";
        objetivo.recibirDaño(static_cast<int>(daño));
    }
};

class Jugador {
private:
    string nombre;
    vector<Pokemon> equipo;
    int indiceActivo = 0;

public:
    Jugador(const string& nombreJugador, const team equipos[6]) : nombre(nombreJugador) {
        for (int i = 0; i < 6; i++) {
            vector<int> m = {equipos[i].mov1, equipos[i].mov2, equipos[i].mov3, equipos[i].mov4};
            equipo.emplace_back(equipos[i].pokemon, m);
        }
    }
    Pokemon& getPokemonActivo() { return equipo[indiceActivo]; }
    bool tienePokemonsDisponibles() const {
        for (auto& p : equipo) if (!p.estaDebilitado()) return true;
        return false;
    }
    void mostrarEquipo() const {
    for (int i = 0; i < equipo.size(); i++) {
        cout << i + 1 << ". ";
        equipo[i].mostrarResumen();
    }
}
    void cambiarPokemon(int indice) {
        if (indice > 0 && indice <= equipo.size() && !equipo[indice - 1].estaDebilitado()) {
            indiceActivo = indice - 1;
            cout << "¡Cambiando a " << getPokemonActivo().getNombre() << "!\n";

        } else {
        cout << "No se puede cambiar a ese Pokémon.\n";
        }
}
const vector<Pokemon>& getEquipo() const { return equipo; }
    string getNombre() const { return nombre; }
};


class Combate {
private:
    Jugador& jugador1;
    Jugador& jugador2;

public:
    Combate(Jugador& j1, Jugador& j2) : jugador1(j1), jugador2(j2) {}
    void forzarCambio(Jugador& jugador) {
    cout << jugador.getNombre() << ", tu Pokémon está debilitado. Debes cambiarlo.\n";
    jugador.mostrarEquipo();
    int nuevo;
    do {
        cout << "Selecciona un Pokémon válido: ";
        cin >> nuevo;
    } while (nuevo < 1 || nuevo > 6 || jugador.getEquipo()[nuevo - 1].estaDebilitado());
    jugador.cambiarPokemon(nuevo);
}
    void turno(Jugador& j, Jugador& rival) {
        if (j.getPokemonActivo().estaDebilitado()) {
            forzarCambio(j);
            return;
        }

        int opcion, mov;
        cout << j.getNombre() << ", elige acción: 1. Atacar 2. Cambiar\n> ";
        cin >> opcion;
        if (opcion == 2) {
            j.mostrarEquipo();
            cout << "Elige número de Pokémon: ";
            int idx; cin >> idx;
            j.cambiarPokemon(idx);
        } else {
            cout << "Elige movimiento (1-4): ";
            cin >> mov;
            if (!rival.getPokemonActivo().estaDebilitado()) {
                j.getPokemonActivo().usarMovimiento(mov, rival.getPokemonActivo());
            } else {
                cout << "El Pokémon rival está debilitado. Debe ser cambiado.\n";
                forzarCambio(rival);
            }
        }
    }

    void iniciarCombate() {
        while (jugador1.tienePokemonsDisponibles() && jugador2.tienePokemonsDisponibles()) {
            cout << "\n" << jugador1.getNombre() << " (" << jugador1.getPokemonActivo().getNombre() << ") vs "
                 << jugador2.getNombre() << " (" << jugador2.getPokemonActivo().getNombre() << ")\n";

            if (jugador1.getPokemonActivo().estaDebilitado()) forzarCambio(jugador1);
            if (jugador2.getPokemonActivo().estaDebilitado()) forzarCambio(jugador2);

            bool j1Rapido = jugador1.getPokemonActivo().getVelocidad() >= jugador2.getPokemonActivo().getVelocidad();

            if (j1Rapido) {
                turno(jugador1, jugador2);
                if (jugador2.getPokemonActivo().estaDebilitado() && jugador2.tienePokemonsDisponibles()) {
                    forzarCambio(jugador2);
                } else if (jugador2.tienePokemonsDisponibles()) {
                    turno(jugador2, jugador1);
                }
            } else {
                turno(jugador2, jugador1);
                if (jugador1.getPokemonActivo().estaDebilitado() && jugador1.tienePokemonsDisponibles()) {
                    forzarCambio(jugador1);
                } else if (jugador1.tienePokemonsDisponibles()) {
                    turno(jugador1, jugador2);
                }
            }
        }
        cout << "\n¡Combate finalizado!\nGanador: " << (jugador1.tienePokemonsDisponibles() ? jugador1.getNombre() : jugador2.getNombre()) << endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Jugador redPlayer("Red", red);
    Jugador bluePlayer("Blue", blue);
    Combate combate(redPlayer, bluePlayer);
    combate.iniciarCombate();
    return 0;
}
