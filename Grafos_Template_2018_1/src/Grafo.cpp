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
			/*for(std::vector<Aresta>::iterator a = listaNos[i].listaAresta.begin(); a != listaNos[i].listaAresta.end(); ++a){
                cout << a->getIDNo() << endl;
			}*/
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


;

    }
	else {
		cerr << "Couldn't open file!" << endl;
	}

}


void Grafo::readFile2(string path)
{
	int m,n;
	int count = 0;
	ifstream f;
	int id=0;
	int id_destino;
	f.open(path.c_str());
	if (f.is_open()) {
		f >> m;
		f >> n;
		while (true) {
			double value;
			string aux;
			if(count > 2)
                count = 0;
            if (count == 0) {
                    if (!(f >> aux)) {
                            break;
                    }
                }
                else if (  count == 1) {
                    if (!(f >> value)) {
                            break;
                    }
                    id = value;
                    if(!noEstaNoGrafo(id)){ // Nó está mo grafo?
                        adcionarNo(id,0);
                    }
                }
                else if(count == 2){
                    if (!(f >> value)) {
                            break;
                    }
                    id_destino = value;
                    if(!noEstaNoGrafo(id_destino)){ // Nó está mo grafo?
                        adcionarNo(id_destino,0);
                    }
                    for (std::vector<No>::iterator it = listaNos.begin(); it != listaNos.end(); ++it) {
                            if( it->getID() == id )
                                    it->adicionaAresta(id_destino,false,0);
                            if( it->getID() == id_destino )
                                    it->adicionaAresta(id,false,0);
                    }
                }
				count++;
		}
		 cout << "Arquivo lido com sucesso" << endl;
		} else {
            cerr << "Couldn't open file!" << endl;
        }

}



void Grafo::acharCliqueMaxima()
{
    sort(listaNos.begin(),listaNos.end()); // Ordena nós pelo grau com base no operator < definido em No.h
    vector <No> nosNaSolucao;
    nosNaSolucao.push_back(*listaNos.begin());
    for(vector <No>::iterator it = (listaNos.begin() + 1); it != listaNos.end() ; it++ ){
            if(formaClique(nosNaSolucao,*it))
                nosNaSolucao.push_back(*it);
    }
    /*for(vector <No>::iterator n = nosNaSolucao.begin(); n != nosNaSolucao.end() ; n++)
        cout << n->getID() << endl; */
    cout << "Tamanho da clique encontrada" << endl;
    cout << nosNaSolucao.size() << endl;
    /*cout << "-----------------" <<endl;
    if(verificaSolucao(nosNaSolucao))
        cout << "1" ;
    else
        cout << "0";*/


}

bool Grafo::formaClique(vector<No>nosNaSolucao, No noCandidato)
{
     for(vector <No>::iterator n = nosNaSolucao.begin(); n != nosNaSolucao.end() ; n++)
            if(!vizinho(n->getID(),noCandidato.getID())){
                return false;
            }
     return true;

}

bool Grafo::verificaSolucao(vector<No> nosNaSolucao)
{
    for (std::vector<No>::iterator it = nosNaSolucao.begin(); it != nosNaSolucao.end(); ++it){
            for(std::vector<No>::iterator it2 = it+1; it2 != nosNaSolucao.end(); ++it2){
                if(!vizinho(it->getID(),it2->getID())){
                    return false;
                }
            }
    }
   return true;
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


}

/*
Reduzir para sat:
k = numero de vertices da clique
n = numero de nos
for i = 1 ate k
    cria clausula
    for j = 1 ate n
        cria um literal Vij
    fecha clausula
for j = 1 ate n
    for i = 1 ate k
        for x = i+1 ate k
            cria uma clausula com dois literais ~Vij e ~Vxj
            fecha clausula
for j = 1 ate n
    for z = j ate n
        if z nao for vizinho de j
            for i = 1 ate k
                for x = i+1 ate k
                cria uma clausula com dois literais ~Vij e ~Vxz
                fecha clausula
 esse seria as tres formas de gerar clausula agora so temos que decidir qual Sat solver a gente vai usar para saber que tipo de entrada ele aceita para podermos caracterizar mais as partes de criar clausula e literal

*/

