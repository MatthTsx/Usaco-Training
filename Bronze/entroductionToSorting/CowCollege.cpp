#include<bits/stdc++.h>
// http://usaco.org/index.php?page=viewproblem2&cpid=1251

using namespace std;
using ll = long long;
// #define FOR(i,fin, ini) for(int i=ini; i<fin;i++)
#define FOR(i,fin) for(int i=0; i<fin;i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, resp = 0, preco = 0, qnt;
    cin >> N;
    set<pair<int,int>> mts;
    qnt = N;

    FOR(i, N){
        int vl;
        cin >> vl;
        auto t = mts.lower_bound({vl, -INFINITY});
        if(t->first != vl) mts.insert({vl, 1});
        else{
            auto dd = *mts.find(*t);
            mts.erase(dd);
            dd.second++;
            mts.insert(dd);
        }
    }
    
    for (auto &&i : mts)
    {
        ll sum = qnt * i.first;
        if(sum > resp){
            resp = sum;
            preco = i.first;
        }
        qnt -= i.second;
    }
    

    cout << resp << " " << preco;
    return 0;
}
