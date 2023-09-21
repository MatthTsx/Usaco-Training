#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=964

using namespace std;
#define FOR(i, N, ini) for(int i = ini; i< N; i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int N, minimo = INT32_MIN;
    cin >> N;
    string str;
    cin >> str;
    // getline(cin, str);

    FOR(i, N, 0){
        string s {""};
        string str2 {str};
        FOR(j, N, i){
            s += str[j];
            str2[j] = '0';
            // cout << "vermelho: " << s << " " << str;
            if(str2.find(s) != string::npos) continue;
                // cout << " ..azul: " << s << endl;
            // if(s.size() <= minimo) continue;
            minimo = max((int) s.size(), minimo);
            // cout << endl;
            break;
        }
    }
    cout << minimo;
    return 0;
}
