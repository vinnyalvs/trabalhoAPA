#include "../headers/bibliotecas.h"
#include <vector>

Grafo::Grafo()
{

}

Grafo::~Grafo()
{

}


void Grafo::adcionarNo(int id, float pesoNo)
{
    No no = No();
    no.setID(id);
    no.setPeso(pesoNo);
    listaNos.push_back(no);
}

void Grafo::removerNo (int id)
{
    vector <No>::iterator it;
    vector <Aresta>::iterator a;
    int i=0,j=0;
    for(it = listaNos.begin() ; it != listaNos.end(); ++it, i++ ){
        if ( it->getID() == id ){
            listaNos.erase( listaNos.begin() + i  );
        }
    }
    i =0;
    for(it = listaNos.begin(); it != listaNos.end(); ++it,i++){
            j = 0;
        for(std::vector<Aresta>::iterator a = listaNos[i].listaAresta.begin(); a != listaNos[i].listaAresta.end() && j < listaNos[i].listaAresta.size() ;   ++a){
                if(a->getIDNo() == id) {
                    listaNos[i].listaAresta.erase( listaNos[i].listaAresta.begin() + j );
                }
                j++;
        }
    }
}

void Grafo::showInfo(){
    int i=0;
    for (std::vector<No>::iterator it = listaNos.begin(); it != listaNos.end(); ++it) {
            cout << "No: " << it->getID() << endl;
			for(std::vector<Aresta>::iterator a = listaNos[i].listaAresta.begin(); a != listaNos[i].listaAresta.end(); ++a){
                cout << a->getIDNo() << endl;
			}
			i++;

    }
    cout << "size: " << listaNos.size() << endl;

}

bool Grafo::noEstaNoGrafo(int index)
{
    for (std::vector<No>::iterator it = listaNos.begin(); it != listaNos.end(); ++it) {
        if( it->getID() == index ){
            return true;
        }
    }
    return false;
}

 void Grafo::writeFile(string path)
{
    ofstream f(path.c_str());
    if(f.is_open()){
        f << listaNos.size();
        f << "\n";
        for (std::vector<No>::iterator it = listaNos.begin(); it != listaNos.end(); ++it) {
			for(std::vector<Aresta>::iterator a = it->listaAresta.begin(); a != it->listaAresta.end(); ++a){
                f << it->getID();
                f << " " ;
                f << a->getIDNo();
                f << " ";
                f << a->getPesoAresta();
                f << "\n";
        }


    }
    } else {
        cerr << "Couldn't open file!" << endl;
    }


}


void Grafo::readFile(string path)
{
	int m;
	int count = 0;
	ifstream f;
	int id=0;
	int id_destino;
	f.open(path.c_str());
	if (f.is_open()) {
		f >> m;
		while (true) {
			double value;
			if(count > 2){
                count = 0;
			}
            if (!(f >> value)) {
                break;
            }
            else {
                if (count == 0) {
                    id = value;
                    if(!noEstaNoGrafo(id)){ // Nó está mo grafo?
                        adcionarNo(id,0);
                    }
                }
                else if (count == 1) {
                    id_destino = value;
                    if(!noEstaNoGrafo(id_destino)){ // Nó está mo grafo?
                        adcionarNo(id_destino,0);
                    }
                }
                else if( count == 2){
                    for (std::vector<No>::iterator it = listaNos.begin(); it != listaNos.end(); ++it) {
                            if( it->getID() == id )
                                    it->adicionaAresta(id_destino,false,value);
                            if( it->getID() == id_destino )
                                    it->adicionaAresta(id,false,value);
                    }


                }
                }
				count++;
		}
            cout << "Arquivo lido com sucesso" << endl;

    }
	else {
		cerr << "Couldn't open file!" << endl;
	}

}



void Grafo::acharCliqueMaxima()
{
    sort(listaNos.begin(),listaNos.end()); // Ordena nós pelo grau com base no operator < definido em No.h
    vector <No> nosNaSolucao;
    nosNaSolucao.push_back(*listaNos.begin());
    for(vector <No>::iterator it = (listaNos.begin() + 1); it != listaNos.end() ; it++ ){
        bool e_vizinho = true;
        for(vector <No>::iterator n = nosNaSolucao.begin(); n != nosNaSolucao.end() ; n++)
            if(!vizinho(it->getID(),n->getID())){
                e_vizinho = false;
                break;
            }
            if(e_vizinho){
                nosNaSolucao.push_back(*it);
            }
        }
    for(vector <No>::iterator n = nosNaSolucao.begin(); n != nosNaSolucao.end() ; n++)
        cout << n->getID() << endl;

}


int Grafo::getOrdemGrafo()
{
    return listaNos.size();
}

bool Grafo::grafoTrivial()
{
    if(listaNos.size() == 1){
        if(listaNos[0].listaAresta.size() == 0 )
            return true;
    }
    return false;
}
bool Grafo::grafoNulo()
{
    if(listaNos.size() == 0 ){
        return true;
    } else {
        return false;
    }
}

int Grafo::getGrauNo(int id)
{
    for (std::vector<No>::iterator it = listaNos.begin(); it != listaNos.end(); ++it) {
         if( it->getID() == id )
                 return it->getGrau();
    }
    return -1;
}

bool Grafo::grafoCompleto()
{
    int N = getOrdemGrafo();
    int num_arestas = 0;
    for(int i = 0; i < N; i++) {
        num_arestas += listaNos[i].getGrau();
    }
    if(num_arestas == N*(N-1)) //seria N(N-1)/2, mas o num_arestas está sendo incrementado duas vezes a cada aresta
        return true;
    return false;
}

void Grafo::removeAresta(int id1,int id2)
{
    if(noEstaNoGrafo(id1) && noEstaNoGrafo(id2)){
        if(vizinho(id1,id2)){
        for (std::vector<No>::iterator it = listaNos.begin(); it != listaNos.end(); ++it) {
             if( it->getID() == id1 )
                    it->removeAresta(id2,false);
             if( it->getID() == id2)
                    it->adicionaAresta(id1,false);
        }
           }

    } else {
         cout << "Nao e possivel remover aresta devido aos nos nao existirem" << endl;
    }

}




void Grafo::adicionaAresta(int id1, int id2, float peso)
{
    if(noEstaNoGrafo(id1) && noEstaNoGrafo(id2)){
        for (std::vector<No>::iterator it = listaNos.begin(); it != listaNos.end(); ++it) {
             if( it->getID() == id1 )
                    it->adicionaAresta(id2,false,peso);
             if( it->getID() == id2)
                    it->adicionaAresta(id1,false,peso);
        }
    } else {
        cout << "Nao e possivel adcionar aresta devido aos nos nao existirem" << endl;
    }
}

bool Grafo::vizinho(int id1, int id2)
{
    for (std::vector<No>::iterator it = listaNos.begin(); it != listaNos.end(); ++it){
        if(it->getID() == id1 ){
            return it->eVizinho(id2);
        }
        if(it->getID() == id2 ){
            return it->eVizinho(id1);
        }
    }
    return false;
}

void Grafo::reduzSat(int k)
{
int n = getOrdemGrafo();
int i,j,x,z,numLiterais;
int numClausulas = 0;
numLiterais = n*k;
for (i = 1;i <= k; i++)
{
    for (j = 1;j <= n; j++)
        cout <<((i-1)*n)+j <<" ";
    cout << "0" << endl;
    numClausulas++;
}
for (j = 1;j <= n; j++)
    for (i = 1;i <= k; i++)
        for (x = i+1;x <= k;x++)
        {
            cout << (-1)*(((i-1)*n)+j) << " " << (-1)*(((x-1)*n)+j) << " 0" << endl;
            numClausulas++;
        }
for (j = 1;j <= n; j++)
    for (z = j+1;z <= n; z++)
        if (!vizinho(j,z))
            for (i = 1;i <= k; i++)
                for (x = i+1;x <= k;x++)
                {
                    cout << (-1)*(((i-1)*n)+j) << " " << (-1)*(((x-1)*n)+z) << " 0" << endl;
                    numClausulas++;
                    cout << (-1)*(((x-1)*n)+j) << " " << (-1)*(((i-1)*n)+z) << " 0" << endl;
                    numClausulas++;
                }
cout << numClausulas << " " << numLiterais;
}
