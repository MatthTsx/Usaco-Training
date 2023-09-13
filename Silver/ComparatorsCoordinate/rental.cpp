#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=787

using namespace std;
using ll = long long;

struct Shop{
    int val, qnt, total;
    bool operator<(Shop &s){return s.val < val;};
};

bool reverse (int &a, int &b) { return b < a;}


int main(int argc, char const *argv[])
{
    freopen("rental.in", "r", stdin);
    int N, M, R;
    cin >> N >> M >> R;

    vector<Shop> shops;
    vector<int> cows (N);
    vector<int> vend (R);

    ll resp = 0;

    for(int i = 0; i < N; i++) cin >> cows[i];
    for(int i = 0; i < M; i++) {
        int qnt, vl;
        cin >> qnt >> vl;
        shops.push_back({vl, qnt, vl * qnt});
    }
    for(int i = 0; i < R; i++) cin >> vend[i];

    sort(shops.begin(), shops.end());
    sort(vend.begin(), vend.end(), [](int &a, int &b){return b < a;});
    sort(cows.begin(), cows.end(), [](int &a, int &b){return b < a;});

    int atual_vend = 0, atual_shop = 0;

    for(int i = 0; i < N; i++){
        int nwAtualShop = atual_shop;
        vector<pair<int,int>> menus;
        Shop sh = shops[atual_shop];
        int cow = cows[i];
        int qnt = min(cow,sh.qnt);
        int vl = sh.val * qnt;
        cow -= qnt;
        menus.push_back({nwAtualShop, qnt});

        while(cow > 0 && nwAtualShop++ < M){
            sh = shops[nwAtualShop];
            qnt = min(cow, sh.qnt);
            vl += sh.val * qnt;
            cow -= qnt;
            menus.push_back({nwAtualShop, qnt});
        }
        bool doStuff = false;

        if(N - i <= R){
            doStuff = true;
        }else if (vl > vend[N-i-1]) doStuff = true;

        if(doStuff){
            resp += vl;
            for (auto &&i : menus) shops[i.first].qnt -= i.second;
        }else{
            resp += vend[N-i-1];
        }
    }


    freopen("rental.out", "w", stdout);

    for (auto &&i : shops)
    {
        cout << "{ " << i.val << ", " << i.qnt << " } ";
    }
    cout << endl << endl << "Vend: " << endl;
    for (auto &&i : vend)
    {
        cout << "{ " << i << " } ";
    }
    cout << endl << endl << "vacas: " << endl;
    for (auto &&i : cows)
    {
        cout << "{ " << i << " } ";
    }
    

    return 0;
}
