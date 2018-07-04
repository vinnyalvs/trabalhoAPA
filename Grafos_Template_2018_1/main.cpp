#include "headers/bibliotecas.h"



int main(int argc, char *argv[])
{
    Grafo grafo = Grafo();
    grafo.readFile("instancias/10.txt");
    //grafo.showInfo();
    //grafo.readFile2("instancias/brock200_2.txt");

    //grafo.acharCliqueMaxima();
    cout << grafo.cliqueMaximaForcaBruta() << endl;

    return 0;
}


