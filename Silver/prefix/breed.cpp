#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = ll[100000][3];

vl breeds;
vl answer;

int main(){
    int N, Q;
    cin >> N >> Q;
    breeds[0][0] = 0;
    breeds[0][1] = 0;
    breeds[0][2] = 0;

    for (int i = 1; i <= N; i++)
    {
        int val;
        cin >> val;
        breeds[i][0] = breeds[i-1][0];
        breeds[i][1] = breeds[i-1][1];
        breeds[i][2] = breeds[i-1][2];
        
        if(val == 1) breeds[i][0]++;
        else if(val == 2) breeds[i][1]++;
        else breeds[i][2]++;
    }
    
    for (int i = 0; i < Q; i++)
    {
        int ini, fin;
        cin >> ini >> fin;
        answer[i][0] = breeds[fin][0] - breeds[ini - 1][0];
        answer[i][1] = breeds[fin][1] - breeds[ini - 1][1];
        answer[i][2] = breeds[fin][2] - breeds[ini - 1][2];
    }

    for (int i = 0; i < Q; i++)
    {
        cout << answer[i][0] << " " << answer[i][1] << " " << answer[i][2] << "\n";
    }
    

    return 1;
}