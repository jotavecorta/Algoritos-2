#include <utility>

using namespace std;

// Taller 1 - Juego

using Pos = pair<int, int>;

char ARRIBA = '^';
char ABAJO = 'v'; 
char DERECHA = '<';
char IZQUIERDA = '>';

class Juego {
public:
    Juego(uint casilleros, Pos pos_inicial);
    Pos  posicion_jugador();
    uint turno_actual();
    void mover_jugador(char dir);
    void ingerir_pocion(uint movimientos, uint turnos);

private:
    Pos pos_actual_;
    uint casilleros_;
};
