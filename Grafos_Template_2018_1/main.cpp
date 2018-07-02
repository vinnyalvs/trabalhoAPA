#include "headers/bibliotecas.h"



int main(int argc, char *argv[])
{
    Grafo grafo = Grafo();
    grafo.readFile2("instancias/phat300-1.txt");
    //grafo.showInfo();
    //grafo.readFile("entrada.txt");

    grafo.acharCliqueMaxima();

        //grafo.showInfo();
    return 0;
}


