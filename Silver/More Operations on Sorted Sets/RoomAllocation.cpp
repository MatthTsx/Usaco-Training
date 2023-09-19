#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1164

using namespace std;

#define FOR(i,N) for(int i=0; i<N; i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    multiset<pair<int,int>> roomsOcuparion { {0,-INFINITY} };
    set<pair<int,int>> mp;
    int index = 0;

    FOR(i,N){
        int v1, v2;
        cin >> v1 >> v2;
        auto tt = roomsOcuparion.upper_bound(make_pair(v1, -INFINITY));
        --tt;
        if(tt == roomsOcuparion.begin()){
            roomsOcuparion.insert({v2, ++index});
            mp.insert({i, index});
            continue;
        }
        auto room = roomsOcuparion.find(*tt);
        roomsOcuparion.erase(room);
        roomsOcuparion.insert({v2, room->second});
        mp.insert({i, room->second});
    }

    cout << (roomsOcuparion.size() - 1) << endl;
    for (auto &&i : mp) cout << i.second << " ";
    
    return 0;
}
