#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "bibliotecas.h"

class Grafo{
    private:
        vector <No> listaNos;

    public:
        Grafo();
        ~Grafo();
        bool orderAux(const No& a, const No& b);
        void adcionarNo(int  id,float pesoNo);
        void removerNo(int id);
        void readFile(char **path);
        void writeFile(string path);
        void showInfo();
        bool noEstaNoGrafo(int index);
        int getOrdemGrafo();
        bool grafoTrivial();
        bool grafoNulo();
        void printSequenciaGraus();
        int getGrauNo(int id);
        bool grafoEKRegular(int k);
        void mostrarVizinhacaAberta(int id);
        void mostrarVizinhacaFechada(int id);
        bool multigrafo();
        bool vizinho(int id1, int id2);
        bool grafoCompleto();
        void removeAresta(int id1, int id2);
        void adicionaAresta(int id1,int id2, float peso);
        bool bipartido();
        bool tenta2ColorirGrafo(int id,int collorArr[]);
        bool existeAresta(int id1, int id2);
};


#endif // GRAFO_H_INCLUDED
