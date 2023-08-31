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
    int N;
    cin >> N;
    vector<int> vls (N*2), res (N, 0), re2 (N, 0);
    for(int i = 0; i < N*2; i++) cin >> vls[i];
    sort(vls.begin(), vls.end());

    for(int i = 0; i < N*2; i++)
        for(int j = i+1; j < N*2; i++){

            
        }

    
    return 0;
}
