#include<bits/stdc++.h>
// https://cses.fi/problemset/task/1164

using namespace std;

#define FOR(i,N) for(int i=0; i<N; i++)

struct client{
    pair<int,int> Entra_sai;
    int room, id;

    bool operator<(client& c){return Entra_sai.first < c.Entra_sai.first;}
};

bool sortById(client& c1, client& c2){return c1.id < c2.id;}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, last_index = 0;
    cin >> N;

    vector<client> vt (N);
    multiset<pair<int,int>> mts;

    FOR(i, N) {
        int v1, v2;
        cin >> v1 >> v2;
        vt[i].Entra_sai.first = v1;
        vt[i].Entra_sai.second = v2;
        vt[i].id = i;
    }
    sort(vt.begin(), vt.end());

    for (auto &&i : vt)
    {
        if(mts.empty()){
            mts.insert({i.Entra_sai.second, ++last_index});
            i.room = last_index;
            continue;
        }
        auto tt = mts.upper_bound({i.Entra_sai.first, -INFINITY});
        if(tt == mts.begin()){
            mts.insert({i.Entra_sai.second, ++last_index});
            i.room = last_index;
            continue;
        }
        --tt;
        auto mts_room = mts.find(*tt);
        mts.erase(mts_room);
        mts.insert({i.Entra_sai.second, mts_room->second});
        i.room = mts_room->second;
    }
    
    sort(vt.begin(), vt.end(), sortById);

    cout << mts.size() << endl;

    for (auto &&i : vt)
    {
        cout << i.room << " ";
    }
    

    return 0;
}
