#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1091

using namespace std;
#define FOR(i,N) for(int i = 0; i < N; i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K, h;
    cin >> N >> K;

    multiset<int> mset;
    vector<int> resp (K);

    FOR(i, N) {
        cin >> h;
        mset.insert(h);
    }

    FOR(i, K){
        int vl;
        cin >> vl;
        auto ij = mset.upper_bound(vl);
        if(ij != mset.begin()){
            cout << *(--ij) << endl;    
            mset.erase(ij);
        }else  cout << "-1" << endl;
    }

    return 0;
}
