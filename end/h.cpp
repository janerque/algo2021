#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int cnt = 0;
void check(string& a, string& b) {
    string p = a + '#' + b;
    int n = p.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }
        if (p[i] == p[j]) {
            j++;
        }
        pi[i] = j;
    }
    for (int i = a.size(); i < n; i++) {
        if (pi[i] == a.size()) {
            cnt++;
            return;
        }
    }
 
}
int main() {
    string a, b;
    cin >> a >> b;
    map<string, bool> x;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = i; j < n; j++) {
            s += a[j];
            if (x[s] == false) {
                check(s, b);
                x[s] =true;
            }
        }
    }
    cout << cnt;
}