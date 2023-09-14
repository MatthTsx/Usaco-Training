#include<bits/stdc++.h>

using namespace std;
#define FOR(i, n) for (int i = 1; i <= n; i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> books (N+1);

    FOR(i, N){
        cin >> books[i];
        books[i] += books[i-1];
    }

    int ini = 0, fin = 1, qnt = 0, resp = 0;

    while(fin <= N){
        if(books[fin] - books[ini] > K){
            ini++;
            if(ini + 1 >= fin) fin++;
            continue;
        }
        resp = max(fin - ini, resp);
        qnt++;
        fin++;
    }

    cout << resp;
    return 0;
}
