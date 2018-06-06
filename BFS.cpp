#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Grafo{

  int V; // num de arestas
  list<int> *adj;

public:

  Grafo(int V); // Construtor
  void adicionaAresta(int v1, int v2);

  void bfs(int v);
};

Grafo::Grafo(int V){
  this->V = V;
  adj = new list<int>[V];
}

void Grafo::adicionaAresta(int v1, int v2){
  adj[v1].push_back(v2);
}

void Grafo::bfs(int v){

  queue<int> fila;
  bool visitados[V];

  for (int i = 0; i < V; i++) {
    visitados[i] = false;
  }

  while (true) {

    list<int>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); it++) {
      if(!visitados[*it]){
        std::cout << "Visitando vértice " << *it << '\n';
        visitados[*it] = true;
        fila.push(*it);
      }
    }
    if (!fila.empty()) {
      v = fila.front();
      fila.pop();
    }else{
      break;
    }
  }
}


int main(int argc, char const *argv[]) {

  int V = 8;

	Grafo grafo(V);

	// adicionando as arestas
  grafo.adicionaAresta(0, 1);
  grafo.adicionaAresta(0, 2);
	grafo.adicionaAresta(1, 3);
	grafo.adicionaAresta(1, 4);
	grafo.adicionaAresta(2, 5);
	grafo.adicionaAresta(2, 6);
	grafo.adicionaAresta(6, 7);

	grafo.bfs(0);

  return 0;
}
