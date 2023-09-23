#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=835
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)

int N;

struct Cow{
    int max;
    bool operator<(const Cow& other) const {
        if(this->max > N) return true;
        if(other.max > N) return false;
        return this->max > other.max;
    }
};

multiset<Cow> mts;

void solve(){
    cin >> N;
    FOR(i,N,0){
        int vl;
        cin >> vl;
        mts.insert({vl});
    }
    int resp = 0, index = 0;
    for (auto &&i : mts)
    {
        if(i.max < index) break;
        index++;
        resp++;
        // cout << i.max << endl;
    }
    cout << resp;
}

int main(int argc, char const *argv[])
{
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
