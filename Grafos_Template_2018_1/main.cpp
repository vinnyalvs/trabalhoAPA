#include "headers/bibliotecas.h"

/*
Grupo: Eduardo Vieira 201665554AC
       Matheus Brinati 201665564C
       Vinicius Alves 201665558AC
*/


int main(int argc, char **argv)
{
    Grafo grafo = Grafo();//instancia o gr�fico.
    grafo.readFile(argv[1]); //Faz a leitura da inst�ncia.
    grafo.output = argv[2];
    int a = grafo.cliqueMaximaForcaBruta();
     //Exibe o valor da maior clique encontrada pelo algoritmo.
    grafo.reduzSat(a); //Faz a redu��o para SAT com um valor K de clique. Al�m disso, exibe todas as cl�usulas da CNF e inscreve no arquivo saida.txt as informa��es necess�rias
    //para o minisat verificar a satisfatibilidade.
    cout << a << endl;
    return 0;//encerra o programa.
}


