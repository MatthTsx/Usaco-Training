#include<bits/stdc++.h>

using namespace std;

int N;
unordered_map<int,bool> visited;
vector<unordered_map<int,bool>> adjs;

void dfs(int c){
    visited[c] = true;

    for (auto &&i : adjs[c])
    {
        if(i.second && !visited[i.first]) {
            visited[i.first] = true;
            dfs(i.first);
        };
    }
}

void bfs(){

    auto bfs_ = [&](int start){
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int c = q.front();
            q.pop();
            // stuff, functions, etc
            for (auto &&i : adjs[c])
                if(!visited[i.first] && i.second){
                    visited[i.first] = true;
                    q.push(i.first);
                }
        }
    };

    for (int i = 0; i < N; i++)
        if(!visited[i]){
            visited[i] = true;
            bfs_(i);
        }
}