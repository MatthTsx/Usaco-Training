#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1163

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, K;
    cin >> N >> K;

    set<int> Lights {0, N}; // luzes no final e no inicio
    multiset<int> Distances {N}; // final como maior distancia

    for(int i = 0; i < K; i++){
        int vl;
        cin >> vl;
        auto t1 = Lights.upper_bound(vl); // pegar a luz à direita
        auto t2 = t1; // copia a luz t1
        --t2; // pegar a luz à esquerda
        Distances.erase(Distances.find(*t1 - *t2)); // deletar qualquer indice com a distancia entre t1 e t2
        Distances.insert(*t1 - vl); // colocar nova distancia de Novo => t1
        Distances.insert(vl - *t2); // colocar nova distancia de t2 => Novo
        Lights.insert(vl); // Inserir Luz nova

        auto biggest = Distances.end();
        --biggest; // pegar o maior (lembrando que o ultimo é N)
        cout << *biggest << " "; // imprimindo
    }

    return 0;
}
