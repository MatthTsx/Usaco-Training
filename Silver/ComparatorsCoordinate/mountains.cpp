#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=896

using namespace std;

bool ss(pair<int,int> v1, pair<int,int> v2){
    return v1.second < v2.second;
}

int main(int argc, char const *argv[])
{
    freopen("mountains.in", "r", stdin);
    int N, resp = 0;
    cin >> N;
    vector<pair<int,int>> vt (N, {0,0});

    for(int i = 0; i < N; i++) cin >> vt[i].first >> vt[i].second;
    sort(vt.begin(), vt.end(), ss);

    for(int i = 1; i < N; i++){
        bool vai = true;
        for(int j = i -1; j >= 0; j--)
            if(vt[i].second <= vt[j].second - abs(vt[j].first - vt[i].first)) {
                vai = false;
                break;
            }
        if(vai) resp++;
    }

    freopen("mountains.out", "w", stdout);
    cout << resp;
    return 0;
}
