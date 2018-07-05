#include "headers/bibliotecas.h"



int main(int argc, char *argv[])
{
    string path = "instancias/instancia.txt" ;
    ofstream f(path);
    int n = 32;
    if(f.is_open()){
        f << n;
        f << "\n";
        for(int i=1;i<=n;i++){
            for ( int j=1;j<=n;j++){
                if(j!=i && i<j){
                    f << i;
                    f << " ";
                    f << j;
                    f << " ";
                    f << 0;
                    f << "\n";
                }
            }

    }
    } else {
        cerr << "Couldn't open file!" << endl;
    }
    Grafo grafo = Grafo();
    grafo.readFile("instancias/K24.txt");
    //grafo.showInfo();
    //grafo.readFile2("instancias/brock200_2.txt");

    //grafo.acharCliqueMaxima();
    cout << grafo.cliqueMaximaForcaBruta() << endl;
    grafo.reduzSat(5);

    return 0;
}


