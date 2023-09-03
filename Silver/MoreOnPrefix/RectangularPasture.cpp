#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1063

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    map<int,int> mp_x;
    map<int,int> mp_y;

    // compactar a matrix
    vector<pair<int,int>> coords (N);
    vector<int> vt_x (N);
    vector<int> vt_y (N);

    for(int i = 0; i < N; i++){
        cin >> vt_x[i];
        cin >> vt_y[i];
        coords[i] = pair<int,int> (vt_x[i], vt_y[i]);
    }
    sort(vt_x.begin(), vt_x.end());
    sort(vt_y.begin(), vt_y.end());

    for(int i = 0; i < N; i++){
        mp_x[vt_x[i]] = i;
        mp_y[vt_y[i]] = i;
    }
    // setup da matrix final
    vector<vector<int>> vt (vt_y.size(), vector<int> (vt_x.size(), 0));

    for(auto c : coords){
        vt[mp_y[c.second]][mp_x[c.first]]++;
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            if(i) vt[i][j] += vt[i-1][j];
            if(j) vt[i][j] += vt[i][j-1];
            if(i && j) vt[i][j] -= vt[i-1][j-1];
        }
    // TODO: remove / O(3 * N) até agr
    // for (auto &&i : vt)
    // {
    //     for (auto &&j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }

    int resp = 0;
    for(int i = 0; i < N; i++){
        pair<int,int> co = coords[i];
        int x1 = mp_x[co.first], y1 = mp_y[co.second];

        for(int j = i+1; j < N; j++){
            int top = 0;
            int bottom = 0;
            pair<int,int> co2 = coords[j];
            int x2 = mp_x[co2.first], y2 = mp_y[co2.second];
            int x = max(x1,x2), t = min(y1,y2), b = max(y1,y2), l = min(x1,x2);

            top += vt[t][x] -( l-1 >= 0 ? vt[t][l-1] : 0);

            bottom += vt[N-1][x] -( l-1 >= 0 ? vt[N-1][l-1] : 0) - (b-1 >= 0 ? vt[b-1][x] : 0);
            if(b-1 >= 0 && l-1 >= 0) bottom += vt[b-1][l-1];

            resp += top * bottom;
        }
    }
    resp += N + 1;
    cout << resp;
    return 0;
}
