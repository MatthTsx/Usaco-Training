#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1666
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)

int N, M;
int p_1, p_2, city1, city2; // placeholders
vector<set<int>> vt (N);

void findCities(){
    FOR(i,vt.size(),0)
    {
        auto j = vt[i];
        auto lw1 = j.lower_bound(p_1);
        auto lw2 = j.lower_bound(p_2);
        if(*lw1 == p_1) city1 = i;
        if(*lw2 == p_2) city2 = i;
    }
}

void solve(){
    cin >> N >> M;
    vt = vector<set<int>> (N);
    FOR(i, N, 0){
        vt[i].insert(i+1);
    }
    
    FOR(i,M,0){
        cin >> p_1 >> p_2;
        findCities();
        if(city1 == city2) continue;
        vt[city1].insert(vt[city2].begin(), vt[city2].end());
        auto __city2 = vt.begin();
        advance(__city2, city2);
        vt.erase(__city2);
    }
    cout << (vt.size() - 1) << "\n";

    FOR(i,vt.size() - 1,0){
        cout << *vt[i].begin() << " " << *vt[i+1].begin() << "\n";
    }
    

    // cout << endl << endl;
    // for (auto &&i : vt)
    // {
    //     for (auto &&j : i)
    //         cout << j << ' ';
    //     cout << endl;
    // }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
