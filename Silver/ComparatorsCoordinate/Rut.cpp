#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1064

using namespace std;
using ll = long long;

enum Directions{
    East,
    North
};

struct Cow{
    int x, y;
    vector<Cow> cows_stoped;
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

    while(N--){
        char d;
        int x, y;
        cin >> d >> x >> y;
        if(d == 'E') vtE.push_back({x, y});
        else vtN.push_back({x, y});
    }
    sort(vtE.begin(), vtE.end(), [](Cow &c1, Cow &c2){return c1.x < c2.x;});
    sort(vtN.begin(), vtN.end(), [](Cow &c1, Cow &c2){return c2.x < c1.x;});

    for (auto &&i : vtE)
        cout << "{ " << i.x << ", " << i.y << " } ";
    

    return 0;
}
