#include<bits/stdc++.h>
// https://usaco.guide/bronze/intro-sorting?lang=cpp
using namespace std;

int Sum(vector<int> vt, int fin){
    int resp = 0;
    for(int i = 0; i < fin; i++) resp += vt[i];
    return resp;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, resp = INT32_MAX;
    cin >> N;
    N *= 2;
    vector<int> vls (N);
    for(int i = 0; i < N; i++) cin >> vls[i];
    sort(vls.begin(), vls.end());

    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++){
            vector<int> p;
            for(int k = 0; k < N; k++){
                if(k == i || k == j) continue;
                p.push_back(vls[k]);
            }
            int vl = 0;
            for(int k = 0; k < p.size() - 1; k+=2){
                vl += p[k+1] - p[k];
            }
            resp = min(resp, vl);
        }

    cout << resp;
    return 0;
}
