#include <vector>
#include "algobot.h"

using namespace std;

// Headers
bool busquedaLineal(int x, vector<int> vec);


// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    vector<int> res;

    for (int i=0; i<s.size(); i++){
        if (not busquedaLineal(s[i], res)){
            res.push_back(s[i]);
        }
    }

    return res;

}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> sin_repetidos;

    for (int i = 0; i < s.size(); i++){
        sin_repetidos.insert(s[i]);
    }

    return vector<int>(sin_repetidos.begin(), sin_repetidos.end());
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    bool res = true;

    // Chequeo que los elementos de a esten en b
    for (int i = 0; i < a.size(); i++){
        res = res && busquedaLineal(a[i], b);
    }

    // Chequeo que b no tenga otros elementos
    for (int j = 0; j < b.size(); j++){
        res = res && busquedaLineal(b[j], a);
    }

    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> set_a;
    set<int> set_b;

    // Me quedo con los elementos de a y b sin repetidos
    for (int i = 0; i < a.size(); i++){
        set_a.insert(a[i]);
        i++;
    }

    for (int j = 0; j < b.size(), j++){
        set_b.insert(b[j]);
        j++;
    }

    return set_a == set_b;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    // Defino un diccionario vacio
    map<int, int> res;

    for (int i = 0; i < s.size(); i++){
        if (res.contains(i)){// Si el elemento ya existe
            res[s[i]]++;
        }else{// Lo inicializo en caso contrario
            res[s[i]] = 1;
        }
    }
    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {

    vector<int> res;

    map<int, int> apariciones = contar_apariciones(s);

    for (int i = 0; i < s.size() ; ++i) {
        if (apariciones[s[i]] = 1){
            res.push_back(s[i]);
        }
    }

    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    return interseccion(a,b);
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    return map<int, set<int>>();
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    return vector<char>();
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    return true;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}

// Funciones Auxiliares
bool busquedaLineal(int x, vector<int> vec){
    int i = 0;

    while (i<vec.size() && vec[i] != x){
        i++;
    }

    return i < vec.size();
}

//int main(){
//    vector<int> prueba = {1, 1, 3, 5, 5, 5};
//    cout << contar_apariciones(prueba) << endl
//    return 0
//}