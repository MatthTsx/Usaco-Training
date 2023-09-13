#include<bits/stdc++.h>
// https://cses.fi/problemset/result/7078364/

using namespace std;

int main(int argc, char const *argv[])
{   // tests
    // freopen("test.in", "r", stdin); 
    // freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, resp = 0, i_n;
    cin >> N;
    i_n = N;

    vector<pair<int,int>> vt;
    vector<int> vt2;

    while(i_n--){
        int ini, fin;
        cin >> ini >> fin;
        vt.push_back({ini,fin});
        vt2.push_back(ini);
        vt2.push_back(fin);
    }
    sort(vt2.begin(), vt2.end());
    map<int,int> pos;
    for(int i = 0; i < N*2; i++){
        pos[vt2[i]] = i+1;
    }
    vector<int> prefix_vt (N*2+1, 0);

    for(auto i : vt){
        prefix_vt[pos[i.first]]++;
        prefix_vt[pos[i.second]]--;
    }

    for(int i = 1; i <= N*2; i++){
        prefix_vt[i] += prefix_vt[i-1];
        resp = max(prefix_vt[i], resp);
    }

    cout << resp;
    return 0;
}
