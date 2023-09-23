#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=810
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)
using ll = long long;

ll L, N, vB, vF, last = 0;
ll resp = 0, xTime = 0;
int p_1, p_2; // placeholders

auto comp = [](const pair<int,int>& a, const pair<int,int>& b) {return a.second > b.second;};

multiset<pair<int,int>, bool(*)(const pair<int,int>&a, const pair<int,int>& b)> stop_stations (comp);

void solve(){
    cin >> L >> N >> vF >> vB;
    FOR(i,N,0){
        cin >> p_1 >> p_2;
        stop_stations.insert({p_1, p_2});
    }

    for (auto &&i : stop_stations)
    {
        ll v = i.first - last;
        if(v <= 0) continue;
        xTime += v * vB;
        ll dif = i.first * vF - xTime;
        // cout << dif << " " << i.first << " " << i.second << endl;
        if(dif <= 0) continue;
        resp += dif * i.second;
        xTime += dif;
        last = i.first;
    }
    cout << resp;
}

int main(int argc, char const *argv[])
{
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
