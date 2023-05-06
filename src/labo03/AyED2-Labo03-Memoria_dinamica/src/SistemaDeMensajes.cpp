#include "SistemaDeMensajes.h"
#include "ConexionJugador.h"

using namespace std;

SistemaDeMensajes::SistemaDeMensajes() : _conns() {
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (int id = 0; id < 4; id++) {
        delete _conns[id];
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    _conns[id] = new ConexionJugador(ip);
}


bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    _conns[id]->enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

