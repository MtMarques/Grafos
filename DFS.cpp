#include <iostream>
#include <stack>
#include <list>

using namespace std;

class Grafo{

  int V; // num de arestas
  list<int> *adj;

public:
  Grafo(int V); // Construtor
  void adicionaAresta(int v1, int v2);

  void dfs(int v);
  };

Grafo::Grafo(int V){
  this->V = V;
  adj = new list<int>[V];
}

void Grafo::adicionaAresta(int v1, int v2){
  adj[v1].push_back(v2);
}

void Grafo::dfs(int v){

    stack<int> pilha;
    bool visitados[V];

    //marca todos como não visitados
    for (int i = 0; i < V; i++) {
      visitados[i] = false;
    }

    while (true) {
      if(!visitados[v]){
        std::cout << "Visitando o Vertice " << v << "...\n";
        visitados[v] = true; // MARCA COMO VISITADO
        pilha.push(v); // INSERE NA PILHA DA DFS
      }

      bool achou = false;

      list<int>::iterator it;

      for (it = adj[v].begin(); it != adj[v].end(); it++) {
        if (!visitados[*it]) {
          achou = true;
          break;
        }
      }

      if (achou) {
        v = *it;
      }else{
        pilha.pop();
        if (pilha.empty()) {
          break;
        }
        v = pilha.top();
      }
    }
}

int main(int argc, char const *argv[]) {

  int V = 8;

  Grafo grafo(V);

  grafo.adicionaAresta(0,1);
  grafo.adicionaAresta(0,2);
  grafo.adicionaAresta(1,3);
  grafo.adicionaAresta(1,4);
  grafo.adicionaAresta(2,5);
  grafo.adicionaAresta(2,6);
  grafo.adicionaAresta(6,7);

  grafo.dfs(0);

  return 0;
}
