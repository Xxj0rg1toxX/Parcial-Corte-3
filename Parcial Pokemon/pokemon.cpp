#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum TipoAtaque { ofensivo, defensivo };
enum Estado { ninguno, quemado };

class Ataque {
public:
    string nombre;
    TipoAtaque tipo;
    int poder;
    int precision;
    int critico;
    bool drenado;
    int quemar;
    int retroceder;
    int bprecision;

    Ataque(string n, TipoAtaque t, int p, int prec = 100, int crit = 0, bool d = false, int quemarProb = 0, int retro = 0, int bajarPrec = 0)
        : nombre(n), tipo(t), poder(p), precision(prec), critico(crit), drenado(d), quemar(quemarProb), retroceder(retro), bprecision(bajarPrec) {}
};

class Pokemon {
public:
    string nombre;
    int vida;
    int vidaMax;
    Estado estado;
    bool retrocedido = false;
    int modPrecision = 100;
    Ataque ataque1;
    Ataque ataque2;
    Ataque ataque3;

    Pokemon(string n, int v, Ataque a1, Ataque a2, Ataque a3)
        : nombre(n), vida(v), vidaMax(v), estado(ninguno), ataque1(a1), ataque2(a2), ataque3(a3) {}

    void aplicarEfectoEstado() {
        if (estado == quemado) {
            int dañoQuemadura = vidaMax * 0.1;
            vida -= dañoQuemadura;
            if (vida < 0) vida = 0;
            cout << nombre << " sufre por la quemadura y pierde " << dañoQuemadura << " HP.\n";
            cout << nombre << " tiene ahora " << vida << " HP.\n";
            if (vida <= 0) {
                cout << nombre << " ha sido derrotado por la quemadura.\n";
                estado = ninguno; 
            }
        }
    }

    void usarAtaque(Pokemon& enemigo, int opcion) {
        Ataque a = (opcion == 1) ? ataque1 :
                    (opcion == 2) ? ataque2 :
                                    ataque3; 
        cout << nombre << " usa " << a.nombre << "...\n";

        int suerte = rand() % 100;

        if (a.tipo == ofensivo) {
            if (suerte >= a.precision) {
                cout << "¡El ataque falló!\n\n";
                return;
            }

            bool critico = (rand() % 100) < a.critico; 
            int dañoFinal = critico ? a.poder * 2 : a.poder;

            enemigo.vida -= dañoFinal;
            if (enemigo.vida < 0) enemigo.vida = 0;

            cout << (critico ? "¡Golpe crítico! " : "")
                 << enemigo.nombre << " recibió " << dañoFinal << " de daño.\n";

            if (a.drenado) {
                int cura = dañoFinal * 0.5;
                vida += cura;
                if (vida > vidaMax) vida = vidaMax;
                cout << nombre << " recuperó " << cura << " HP gracias a Gigadrenado.\n";
                cout << nombre << " tiene ahora " << vida << " HP.\n";
            }

            if (a.quemar > 0 && enemigo.estado == ninguno) {
                int prob = rand() % 100;
                if (prob < a.quemar) {
                    enemigo.estado = quemado;
                    cout << enemigo.nombre << " ha sido quemado.\n";
                }
            }
            if (a.retroceder > 0 && enemigo.estado == ninguno) {
                int prob = rand() % 100;
                if (prob < a.retroceder) {
                    enemigo.estado = Estado::ninguno; 
                    enemigo.retrocedido = true;
                    cout << enemigo.nombre << " retrocedió.\n";
                }
            }
            if (a.bprecision > 0) {
                enemigo.modPrecision -= a.bprecision;
                if (enemigo.modPrecision < 10) enemigo.modPrecision = 10; 
                cout << enemigo.nombre << " Ha bajado su precision .\n";
            }
            

        } else if (a.tipo == defensivo) {
            vida += a.poder;
            if (vida > vidaMax) vida = vidaMax;
            cout << nombre << " recuperó " << a.poder << " puntos de vida.\n";
            cout << nombre << " tiene ahora " << vida << " HP.\n";
        }

        cout << enemigo.nombre << " tiene " << enemigo.vida << " HP restante.\n\n";
    }
};

void menu(Pokemon& atacante, Pokemon& defensor) {
    if (atacante.retrocedido) {
        cout << atacante.nombre << " retrocedió y no puede atacar este turno.\n\n";
        atacante.retrocedido = false;
        return;
    }
    int opcion;
    cout << "Turno de " << atacante.nombre << "\n";
    cout << "1. " << atacante.ataque1.nombre << "\n";
    cout << "2. " << atacante.ataque2.nombre << "\n";
    cout << "3. " << atacante.ataque3.nombre << "\n";
    cout << "Selecciona un ataque (1 - 3): ";
    cin >> opcion;

    while (opcion < 1 || opcion > 3) {
        cout << "Opción inválida. Elige entre 1 y 3: ";
        cin >> opcion;
    }

    atacante.usarAtaque(defensor, opcion);
    defensor.aplicarEfectoEstado(); 
}

int main() {
    srand(time(0));

    // Definir ataques
    Ataque ascuas("Ascuas", ofensivo, 20, 85, 20, false, 15);
    Ataque mordisco("Mordisco", ofensivo, 25, 90, 15, false, 0, 30);
    Ataque curar("Recuperar", defensivo, 15);
    Ataque drenado("Gigadrenado", ofensivo, 30, 90, 10, true);
    Ataque descanso("Descanso", defensivo, 20);
    Ataque bofeton("Bofetón Lodo", ofensivo, 15, 100, 0, false, 0, 0, 15);

    // Crear Pokémon
    Pokemon blaziken("torchic", 100, ascuas, curar, mordisco);
    Pokemon slaking("slaking", 100, drenado, descanso, bofeton);

    // Ciclo de combate
    bool turno1 = true;
    cout << "¡Combate Pokémon!\n\n";

    while (blaziken.vida > 0 && slaking.vida > 0) {
        if (turno1) menu(, slaking);
        else menu(slaking, blaziken);

        turno1 = !turno1;
    }

    cout << "¡El combate ha terminado!\n";
    if (blaziken.vida <= 0)
        cout << slaking.nombre << " ha ganado.\n";
    else
        cout << blaziken.nombre << " ha ganado.\n";

    return 0;
}
