#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

int main(){

    int n;
    cin >> n;
    
    int arr[n][n];
    bool used[n];
    int d[n];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> arr[i][j];
            if(arr[i][j] == 0){
                arr[i][j] = INF;
            }
        }
        used[i] = false;
        d[i] = INF;
    }

    int s, t;
    cin >> s >> t;
    s--;
    t--;

    d[s] = 0;


    for(int i = 0; i < n; ++i){
        int v = -1;
        for(int j = 0; j < n; ++j){
            if(!used[j] && (v == -1 || d[v] > d[j])){
                v = j;
            }
        }
        if(d[v] == INF) break;
        used[v] = true;

        for(int j = 0; j < n; ++j){
            if(d[j] > d[v] + arr[v][j]){
                d[j] = d[v] + arr[v][j];
            }
        }
    }

    if (d[t] == INF) cout <<-1; else cout <<d[t];
    return 0;

}