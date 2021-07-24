#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> list_graph(100001, vector<int>());

vector<int> used(100001);


vector<int> ans;

void dfs(int v) {
    used[v] = 1;

    for(int i = 0; i < list_graph[v].size(); i++) {
        if(used[list_graph[v][i]] == 0) {
            dfs(list_graph[v][i]);
        }
    }
    ans.push_back(v);
}
int main(){
    int n, m;
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x;
        cin >> y;
        list_graph[x].push_back(y);
    }
    dfs(1);
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}