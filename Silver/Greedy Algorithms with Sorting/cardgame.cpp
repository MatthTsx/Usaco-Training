#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=573
using namespace std;
#define FOR(i,N,ini) for(int i=ini; i<N; i++)
using __mts = multiset<int>;

auto cmp_less = [](const int& a, const int&b){return a > b;};


int N, resp = 0;
__mts Cards1SecondHalf, Besie;
multiset<int, bool (*)(const int&, const int&)> Cards1FirstHalf (cmp_less);

void solve(){
    cin >> N;
    vector<int> placeholder (2*N);
    FOR(i,N,0){
        int vl;
        cin >> vl;
        placeholder[vl-1] = -1;
        if(i < N/2) Cards1FirstHalf.insert(vl);
        else Cards1SecondHalf.insert(vl);
    }

    FOR(i, N*2, 0)
        if(placeholder[i] != -1) Besie.insert(i+1);

    for (auto &&i : Cards1FirstHalf)
    {
        auto t = --Besie.end();
        if(*t < i) continue;
        Besie.erase(Besie.find(*t));
        // cout << *t << endl;
        resp++;
    }

    for (auto &&i : Cards1SecondHalf)
    {
        auto t = Besie.lower_bound(i);
        if(t == Besie.begin()) continue;
        Besie.erase(Besie.find(*--t));
        // cout << *t << endl;
        resp++;
    }

    // for (auto &&i : Cards1FirstHalf) cout << i << " ";
    // cout << endl;
    // for (auto &&i : Cards1SecondHalf) cout << i << " ";

    cout << resp;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    solve();
    return 0;
}
