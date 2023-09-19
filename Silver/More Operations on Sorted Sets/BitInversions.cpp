#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1188
using namespace std;

#define FOR(i,N) for(int i=0;i<N;i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    
    int N = str.size();


    // parecido cm os das luzes
    set<int> Ones;
    multiset<int> Distances;

    int __distance = 0;
    FOR(i, N){
        if(str[i] == '1'){
            if(!i || !__distance) continue;
            Distances.insert(__distance);
            __distance = 0;
            continue;
        }
        __distance++;
    }
    if(__distance) Distances.insert(__distance);
    
    for (auto &&i : Distances)
    {
        cout << i << " ";
    }
    

    return 0;
}
