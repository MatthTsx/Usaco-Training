#include<bits/stdc++.h>

using namespace std;

vector<int> vt (pow(10,9), 0);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    int menor = INT32_MAX, maior = INT32_MIN;
    vector<int> resp;

    while(N--){
        int a, b, v;
        cin >> a >> b >> v;
        vt[a] += v;
        vt[b] -= v;
        menor = min(a, menor);
        maior = max(b, maior);
    }

    if(maior == INT32_MIN) maior = vt.size();
    for(int i = 1; i < min((int) vt.size(),maior); i++) vt[i] += vt[i-1];


    while(Q--){
        
    }

    return 0;
}
