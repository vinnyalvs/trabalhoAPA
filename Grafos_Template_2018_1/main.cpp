#include "headers/bibliotecas.h"

/*
Grupo: Eduardo Vieira
       Matheus Brinati
       Vinicius Alves
*/


int main(int argc, char *argv[])
{
    Grafo grafo = Grafo();//instancia o gráfico.
    grafo.readFile("instancias/K32_2.txt"); //Faz a leitura da instância.
    cout << grafo.cliqueMaximaForcaBruta() << endl; //Exibe o valor da maior clique encontrada pelo algoritmo.
    grafo.reduzSat(5); //Faz a redução para SAT com um valor K de clique. Além disso, exibe todas as cláusulas da CNF e inscreve no arquivo saida.txt as informações necessárias
    //para o minisat verificar a satisfatibilidade.
    return 0;//encerra o programa.
}


