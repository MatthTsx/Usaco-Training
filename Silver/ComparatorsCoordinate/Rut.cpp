#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1064

using namespace std;
using ll = long long;

// TODO: https://usaco.guide/problems/usaco-1064-stuck-in-a-rut/solution

enum Directions{
    East,
    North
};

struct Cow{
    int x, y, cows_stoped = 0;
    bool isStopped = false;
    // set<Cow> Bleme;
};

int main(int argc, char const *argv[])
{
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<Cow> vtE;
    vector<Cow> vtN;
    vector<Cow> vt;

    while(N--){
        char d;
        int x, y;
        cin >> d >> x >> y;
        Cow c = {x,y};
        Cow & cc = c;
        if(d == 'E') vtE.push_back(c);
        else vtN.push_back(c);
        vt.push_back(cc);
    }
    sort(vtE.begin(), vtE.end(), [](Cow &c1, Cow &c2){return c2.x < c1.x;});
    sort(vtN.begin(), vtN.end(), [](Cow &c1, Cow &c2){return c2.x < c1.x;});

    for(auto&& e : vtE)
        for (auto &&n : vtN)
        {
            if(n.x < e.x) continue;
            if(n.isStopped) continue; 
            if(n.y > e.y) continue;
            int X = n.x - e.x, Y = e.y - n.y;
            if( X == Y ) continue;
            if( X > Y ){
                n.cows_stoped += 1;
                e.isStopped = true;
                break;
            }else {e.cows_stoped += 1; n.isStopped = true;};
        }

    for (auto &&i : vtE)
        cout << "{ " << i.x << ", " << i.y << ", " << i.cows_stoped << " } ";
    cout << endl << endl;
    for (auto &&i : vtN)
        cout << "{ " << i.x << ", " << i.y << ", " << i.cows_stoped << " } ";
    cout << endl << endl;

    for (auto &&i : vt)
        cout << i.cows_stoped << " ";
    

    return 0;
}
