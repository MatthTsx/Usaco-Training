#include<bits/stdc++.h>
// https://codeforces.com/contest/762/problem/B
using namespace std;
#define FOR(i,N,ini) for(int i=ini;i<N;i++)
#define FORR(i,N) for(auto&& i : N)
using ll = long long;

enum Tipo{
    USB,
    P2
};

struct Shop{
    int vl;
    Tipo tipo;
    bool operator<(const Shop& other) const {return vl < other.vl;}
};

vector<int> qnt (3);
int M, qntd_ = 0;
string usb = "USB";
ll final_price = 0;
multiset<Shop> mts;

void solve(){
    cin >> qnt[0] >> qnt[1] >> qnt[2] >> M;
    FOR(i,M,0){
        int vl;
        string type;
        cin >> vl >> type;
        mts.insert({vl, type == usb ? USB : P2});
    }

    FORR(i,mts){
        if(qnt[0] + qnt[1] + qnt[2] == 0) break;
        bool foi = false;
        FOR(j,2,0)
            if(qnt[j] > 0 && i.tipo == j){
                qnt[j]--;
                qntd_++;
                final_price += i.vl;
                foi = true;
                break;
            }
        if(qnt[2] > 0 && !foi){
            qnt[2]--;
            qntd_++;
            final_price += i.vl;
        }
    }
    cout << qntd_ << " " << final_price;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
