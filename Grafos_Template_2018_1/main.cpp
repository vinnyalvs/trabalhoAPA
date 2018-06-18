#include "headers/bibliotecas.h"



int main(int argc, char **argv)
{
    Grafo grafo = Grafo();
    grafo.readFile(argv);
    return 0;
}


