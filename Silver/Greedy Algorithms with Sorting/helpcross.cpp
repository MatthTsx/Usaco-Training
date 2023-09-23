#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=714
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)

struct Cows{
    int start, end;
};

int C, N, resp = 0;
int p_1,p_2; //placeholders

multiset<Cows> cows;
multiset<int> chickens;

void getInputs(){
    FOR(i,C,0){
        cin >> p_1;
        chickens.insert(p_1);
    }
    FOR(i,N,0){
        cin >> p_1 >> p_2;
        cows.insert({p_1,p_2});
    }
}

void solve(){
    cin >> C >> N;
    getInputs();
    for (auto &&i : cows)
    {
        cout << i.start << " " << i.end;
    }
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    freopen("helpcross.in", "r", stdin);
    solve();
    return 0;
}
