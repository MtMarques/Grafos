#include <iostream>
#include <stack> //Pilha do DFS
#include <list> //Lista de adj

using namespace std;

class Grafo{

  int V; // num de arestas
  list<int> *adj;

public:

  Grafo(int V); // Construtor
  void adicionaAresta(int v1, int v2);

  bool dfs(int v); //Faz um DFS partindo de um vertice verificando se tem ciclo

  bool temCiclo(); //verifica se tem ciclo
};

Grafo::Grafo(int V){
  this->V = V;
  adj = new list<int>[V];
}

void Grafo::adicionaAresta(int v1, int v2){
  adj[v1].push_back(v2);
}

bool Grafo::dfs(int v){

  stack<int> pilha;
  bool visitados[V], pilha_rec[V];

  for (int i = 0; i < V; i++) {
    visitados[i] = pilha_rec[i] = false;
  }

  while (true) {

    bool achou_vizinho = false;
    list<int>::iterator it;

    if (!visitados[v]) {
      pilha.push(v);
      visitados[v] = pilha_rec[v] = true;
    }

    for (it = adj[v].begin(); it != adj[v].end(); it++) {
      if (pilha_rec[*it]) { //SE VIZINHO ESTÁ NA PILHA CONTEM CICLO
        return true;
      }else if (!visitados[*it]) { // SE NÃO ESTÁ NA PILHA E NÃO FOI VISITADO INDICA QUE ACHOU
        achou_vizinho = true;
        break;
      }
    }

    if (!achou_vizinho) {
      pilha_rec[pilha.top()] = false;
      pilha.pop();

      if (pilha.empty()) {
        break;
      }
      v = pilha.top();
    }else{
        v = *it;
    }

    return false;
  }
}

int main(int argc, char const *argv[]) {

  int V = 4;
  Grafo grafo(V);

  // adicionando as arestas
  grafo.adicionaAresta(0, 1);
  grafo.adicionaAresta(0, 2);
  grafo.adicionaAresta(1, 3);
  grafo.adicionaAresta(3, 0);

  if (grafo.dfs(0)) {
    std::cout << "CONTEM ciclo" << '\n';
  }else{
    std::cout << "NÃO CONTEM ciclo" << '\n';
  }


  return 0;
}
