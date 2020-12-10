// E81
// Yule Zhang

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool esPar(int k) {
    return k % 2 == 0;
}

// funcion que resuelve el problema
void resolver(vector<int>& datos) {
    int k = 0;//puntero
    for (int i = 0; i < datos.size(); i++) {
        if (esPar(k) && esPar(datos[i]) || (!esPar(k) && !esPar(datos[i]))) {
            swap(datos[k], datos[i]);
            k++;
            if (k <= i)
                k++;
        }
    }
    if (!esPar(k))
        k--;
    datos.resize(k);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;//numero de datos
    cin >> n;
    if (!cin)
        return false;
    
    vector<int>datos(n);
    for (int i = 0; i < n; i++) {
        cin >> datos[i];
    }

    resolver(datos);

    // escribir sol
    for (int i = 0; i < datos.size(); i++) {
        cout << datos[i] << " ";
    }
    cout << endl;
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
