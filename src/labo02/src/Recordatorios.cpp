#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes, int dia);
    int mes();
    int dia();

    string toString();

    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif

    void incrementar_dia();

  private:
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia) : mes_(mes), dia_(dia){};

int Fecha::mes() {
    return mes_;
}

int Fecha::dia() {
    return dia_;
}

string Fecha::toString() {
    return to_string(dia_) + "/" + to_string(mes_);
}

ostream& operator<<(ostream& os, Fecha date){
    os << date.toString();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia && igual_mes;
}
#endif

void Fecha::incrementar_dia() {
    if (dia_ < dias_en_mes(mes_)){ // Dentro del mes
        dia_++;
    }else if(mes_ < 12){ // Fin de mes, pero no de año
        dia_ = 1;
        mes_++;
    }else { // Si es el 31/12
        dia_ = 1;
        mes_ = 1;
    }
}

// Ejercicio 11, 12

// Clase Horario
class Horario {
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();

    bool operator==(Horario h);

    bool operator<(Horario h);

private:
    uint hora_;
    uint min_;
};

Horario::Horario(uint hora, uint min): hora_(hora), min_(min) {};

uint Horario::hora(){
    return hora_;
}

uint Horario::min(){
    return min_;
}

bool Horario::operator==(Horario h) {
    bool igual_hora = hora_ == h.hora();
    bool igual_min = min_ == h.min();

    return igual_hora && igual_min;
}

bool Horario::operator<(Horario h) {
    // Condiciones para que sea menor hora
    bool menor_hora = this->hora_ < h.hora();
    bool igual_hora_menor_min = this->hora_ == h.hora() && this->min_ < h.min();

    return (menor_hora || igual_hora_menor_min);

}

ostream& operator<<(ostream& os, Horario h){
    os << h.hora() << ":" << h.min();
    return os;
}

// Ejercicio 13

class Recordatorio {
public:
    Recordatorio(Fecha fecha, Horario hor, string mensaje);
    string mensaje();
    Fecha fecha();
    Horario horario();

    bool operator<(Recordatorio);

private:
    string mensaje_;
    Fecha fecha_;
    Horario hor_;
};

Recordatorio::Recordatorio(Fecha fecha, Horario hor, std::string mensaje) :
                            fecha_(fecha), hor_(hor), mensaje_(mensaje) {};

string Recordatorio::mensaje() {
    return mensaje_;
}

Fecha Recordatorio::fecha() {
    return fecha_;
}

Horario Recordatorio::horario() {
    return hor_;
}

// cout overload
ostream& operator<<(ostream& os, Recordatorio rec){
    os << rec.mensaje() << " @ " << rec.fecha() << " " << rec.horario();
    return os;
}

bool Recordatorio::operator<(Recordatorio r) {
    return this->horario() < r.horario();
}


// Ejercicio 14
class Agenda {
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();

private:
    Fecha fecha_actual_;
    map<string, list<Recordatorio>> recordatorios_por_fecha_;
};

Agenda::Agenda(Fecha fecha_inicial) : fecha_actual_(fecha_inicial), recordatorios_por_fecha_({}) {};

void Agenda::agregar_recordatorio(Recordatorio rec) {
    recordatorios_por_fecha_[rec.fecha().toString()].push_back(rec);
}

void Agenda::incrementar_dia() {
    fecha_actual_.incrementar_dia();
}

Fecha Agenda::hoy() {
    return fecha_actual_;
}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    return recordatorios_por_fecha_[fecha_actual_.toString()];
}

ostream& operator<<(ostream& os, Agenda a){
    // Ordenamos los recordatorios por horario
    list<Recordatorio> recordatorios = a.recordatorios_de_hoy();
    recordatorios.sort();

    // Printeamos la fecha
    os << a.hoy() << "\n" << "=====" <<"\n";

    // Printeamos los recordatorios
    for (auto const &rec: recordatorios) {
        os << rec << "\n";
    }

    return os;
}
