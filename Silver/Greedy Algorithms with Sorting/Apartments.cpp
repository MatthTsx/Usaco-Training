#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1084
using namespace std;
#define FOR(i, N, ini) for (int i = ini; i < N; i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, K, resp = 0;
    cin >> N >> M >> K;

    multiset<pair<int,bool>> mtsP;
    vector<int> vtA_sort (M);
    FOR(i,N,0) {
        int vl;
        cin >> vl;
        mtsP.insert({vl, false});
    };
    FOR(i,M,0) cin >> vtA_sort[i];

    sort(vtA_sort.begin(), vtA_sort.end());

    FOR(i,M,0){
        auto findAfter = mtsP.lower_bound({vtA_sort[i], false});
        if(findAfter != mtsP.end() && abs(findAfter->first - vtA_sort[i]) <= K){
            resp++;
            mtsP.erase(mtsP.find(*findAfter));
            mtsP.insert({findAfter->first, true});
            continue;
        }
        --findAfter;
        if(findAfter != --mtsP.begin() && abs(findAfter->first - vtA_sort[i]) <= K){
            resp++;
            mtsP.erase(mtsP.find(*findAfter));
            mtsP.insert({findAfter->first, true});
        }
        // cout << findAfter->first << endl;
    }
    
    cout << resp;
    return 0;
}

