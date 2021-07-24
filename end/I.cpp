#include <bits/stdc++.h>
using namespace std;


vector<int> my_function(string s) {
    int n = s.size();
    vector<int> vec(n);
    for (int i = 1; i < n; i++) {
        long long j = vec[i-1];
        while (j > 0 && s[i] != s[j]){
            j = vec[j-1];
        }
        if (s[i] == s[j]){
            j++;
            vec[i] = j;
        }
    }
    return vec;
}

int main(){
    string s1,s2, s, t;
    cin >> s ;
    cin >> t;
    vector<int> v1 = my_function(s + '#' + t);
    vector<int> v2 = my_function(t + "#" + s);
    cout << max(v1[v1.size() - 1], v2[v2.size() - 1]);
    
    return 0;
}