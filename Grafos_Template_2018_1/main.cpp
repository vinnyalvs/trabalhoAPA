#include "headers/bibliotecas.h"



int main(int argc, char *argv[])
{
    Grafo grafo = Grafo();
    grafo.readFile("instancias/K24.txt");
    //grafo.showInfo();
    //grafo.readFile2("instancias/brock200_2.txt");

    //grafo.acharCliqueMaxima();
    cout << grafo.cliqueMaximaForcaBruta() << endl;
    grafo.reduzSat(5);

    return 0;
}


