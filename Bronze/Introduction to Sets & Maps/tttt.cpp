#include<bits/stdc++.h>
// http://www.usaco.org/index.php?page=viewproblem2&cpid=831
using namespace std;
#define FOR(i,N) for(int i=0;i<N;i++)

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);


    vector<set<int>> st_rows (3);
    vector<set<int>> st_cols (3);
    vector<set<int>> st_dig  (2);

    FOR(i, 3){
        string s;
        cin >> s;
        FOR(j, 3){
            st_rows[i].insert(s[j]);
            st_cols[j].insert(s[j]);
            if(i == j){
                st_dig[0].insert(s[j]);
            }
            if(2 - i == j){
                st_dig[1].insert(s[j]);
            }
        }
    }


    // cout << st_dig[1].size() << " " << st_dig[0].size() << endl;
    int resp1=0, resp2=0;
    map<int,bool> monoWin;
    map<pair<int,int>, bool> groupWin;

    FOR(i, 3){
        auto rowBegin = st_rows[i].begin();
        auto colBegin = st_cols[i].begin();

        if(st_rows[i].size() == 1 && !monoWin[*rowBegin]) {
            resp1++;
            monoWin[*rowBegin] = true;
        }
        else if(st_rows[i].size() == 2){
            pair<int,int> cord = {*rowBegin, *(++rowBegin)};
            if(!groupWin[cord]){
                resp2++;
                groupWin[cord] = true;
            }
        }

        if(st_cols[i].size() == 1 && !monoWin[*colBegin]) {
            resp1++;
            monoWin[*colBegin] = true;
        }
        else if(st_cols[i].size() == 2){
            pair<int,int> cord = {*colBegin, *(++colBegin)};
            if(!groupWin[cord]){
                resp2++;
                groupWin[cord] = true;
            }
        }

        // cout << st_cols[i].size() << " " << st_rows[i].size() << endl;
    }

    FOR(i, 2){
        auto beg = st_dig[i].begin();
        if(st_dig[i].size() == 1 && !monoWin[*beg]) {
            resp1++;
            monoWin[*beg] = true;
        }
        else if(st_dig[i].size() == 2) {
            pair<int,int> cord = {*beg, *(++beg)};
            if(!groupWin[cord]){
                resp2++;
                groupWin[cord] = true;
            }
        }
    }


    cout << resp1 << "\n" << resp2;
    return 0;
}
