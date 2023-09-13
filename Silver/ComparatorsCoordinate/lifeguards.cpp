#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=786

using namespace std;

class Vaca{
    public:
        int id;
        int vl;
        bool is_seeing;
        bool operator<(Vaca &a) {return vl < a.vl;}
};


int main(int argc, char const *argv[])
{
    freopen("lifeguards.in", "r", stdin);
    int N;
    cin >> N;

    vector<Vaca> vcs;
    for(int i = 1; i <= N; i++){
        int vl1, vl2;
        cin >> vl1 >> vl2;
        vcs.push_back({i, vl1, true});
        vcs.push_back({i, vl2, false});
    }

    sort(vcs.begin(), vcs.end());

    freopen("lifeguards.out", "w", stdout);

    // for (auto &&i : vcs)
    // {
    //     cout << "{" << i.vl << ", " << (i.is_seeing? 1 : -1) << "} ";
    // }

    set<int> Active;
    vector<int> Time (N, 0);

    int prev = 0, resp = (*vcs.end()).vl, totalTime = 0;

    for(auto& v : vcs){
        int time = v.vl;

        if(Active.size() > 0) totalTime += time - prev;
        if(Active.size() == 1) Time[*Active.begin() -1] += time - prev;

        if(v.is_seeing) Active.insert(v.id);
        else Active.erase(v.id);

        prev = time;
    }

    resp = *min_element(Time.begin(), Time.end());

    cout << (totalTime - resp);
    return 0;
}
