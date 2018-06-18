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
        void readFile(string path);
        void writeFile(string path);
        void showInfo();
        bool noEstaNoGrafo(int index);
        int getOrdemGrafo();
        bool grafoTrivial();
        bool grafoNulo();
        int getGrauNo(int id);
        bool vizinho(int id1, int id2);
        bool grafoCompleto();
        void removeAresta(int id1, int id2);
        void adicionaAresta(int id1,int id2, float peso);
        void acharCliqueMaxima();
};


#endif // GRAFO_H_INCLUDED
