#include "headers/bibliotecas.h"



int main(int argc, char *argv[])
{
    Grafo grafo = Grafo();
    grafo.readFile("entrada.txt");
    grafo.acharCliqueMaxima();
        //grafo.showInfo();
    return 0;
}


