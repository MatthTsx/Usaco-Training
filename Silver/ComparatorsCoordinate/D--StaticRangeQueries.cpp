#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<pair<int,pair<int,int>>> vt;
    int maior = INT32_MIN, menor = INT32_MAX;

    while(N--){
        int ini, fin, vl;
        cin >> ini >> fin >> vl;
        vt.push_back({ini, {fin, vl}});
        maior = max(maior, fin);
        menor = min(menor, ini);
    }

    int diff = maior - menor;
    vector<int> vt2 (maior - menor + 1, 0);
}
