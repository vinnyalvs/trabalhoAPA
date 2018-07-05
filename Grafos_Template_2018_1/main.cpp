#include "headers/bibliotecas.h"

/*
Grupo: Eduardo Vieira
       Matheus Brinati
       Vinicius Alves
*/


int main(int argc, char *argv[])
{
    Grafo grafo = Grafo();//instancia o gr�fico.
    grafo.readFile("instancias/K32_2.txt"); //Faz a leitura da inst�ncia.
    cout << grafo.cliqueMaximaForcaBruta() << endl; //Exibe o valor da maior clique encontrada pelo algoritmo.
    grafo.reduzSat(5); //Faz a redu��o para SAT com um valor K de clique. Al�m disso, exibe todas as cl�usulas da CNF e inscreve no arquivo saida.txt as informa��es necess�rias
    //para o minisat verificar a satisfatibilidade.
    return 0;//encerra o programa.
}


