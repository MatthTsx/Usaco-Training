#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=592

using namespace std;
#define FOR(i,N) for(int i=0; i < N; i++)
using ll = long long;

enum Direction{
    LEFT,
    RIGHT
};

set<int> cows;
// TODO: FIX THIS
int chain(int id, int qnt, Direction D, int vl = 0){
    if(D == LEFT) {
        auto curr = cows.lower_bound(id);
        if(curr == cows.begin()) return vl;
        --curr;
        cout << id << " " << qnt << " " << *curr << endl;
        if(id - *curr <= qnt) return chain(*curr, qnt+1, D, vl+1);
        return qnt;
    }else{
        auto curr = cows.lower_bound(id);
        if(curr == --cows.end()) {
            // if(abs(*curr - id) <= qnt) return vl + 1;
            return vl;
        }
        ++curr;
        cout << id << " " << qnt << " " << *curr << endl;
        if(*curr - id <= qnt) return chain(*curr, qnt+1, D, vl+1);
        return vl;
    }
}

int main(int argc, char const *argv[])
{
    freopen("angry.in", "r", stdin);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    int N, maxVl = 0;
    cin >> N;

    FOR(i, N) {
        int vl;
        cin >> vl;
        cows.insert(vl);
    }

    freopen("angry.out", "w", stdout);
    for (auto &&i : cows){
        // maxVl = max(maxVl, chain(i, 1, LEFT) + chain(i,1,RIGHT));
        int r = chain(i,1,RIGHT);
        int l = chain(i,1,LEFT);
        cout << "\n\n[ " << l << " " << r << " ]\n\n";
    }
        // maxVl = max(maxVl, min(chain(i, 1, LEFT), chain(i,1,RIGHT)) * 2 - 1);
    cout << maxVl;
    return 0;
}
