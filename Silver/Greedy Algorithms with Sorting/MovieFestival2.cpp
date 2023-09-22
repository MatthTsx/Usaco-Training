#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1632
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)

struct Film{
    int start, end;
    bool operator<(const Film& other) const { return end < other.end;}
};

int N, M;

vector<Film> films;
multiset<int> mts; // guardar os ends ( o momento que os amigos estão livres )
int resp = 0;

void solve(){
    cin >> N >> M;
    films = vector<Film>(N);
    FOR(i,N,0){
        cin >> films[i].start >> films[i].end;
    }

    sort(films.begin(), films.end());
    FOR(i,N,0){
        auto t = mts.upper_bound(films[i].start);
        if(t == mts.begin()){
            if(mts.size() >= M) continue;
            mts.insert(films[i].end);
            resp++;
            continue;
        }
        --t;
        mts.erase(mts.find(*t));
        mts.insert(films[i].end);
        resp++;
    }
    cout << resp;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
