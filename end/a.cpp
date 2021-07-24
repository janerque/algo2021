#include <bits/stdc++.h>
using namespace std;
int k;
struct line {
    line *l, *r;
    int val;
    line (int x) {
        l = NULL;
        r = NULL;
        val = x;
    }
};
void insert(line *cur, int p) {
    if (cur -> val > p) {
        if (cur -> l == NULL) {
            line *v = new line(p);
            cur -> l = v;
        } 
        else insert(cur -> l, p);
    } 
    else {
        if (cur -> r == NULL) {
            line *v = new line(p);
            cur -> r = v;
        } 
        else insert(cur -> r, p);
    }
}

void ans(line *cur, int x) {
    if (x == 1) cout << cur->val << " ";
    if (k == cur -> val) {
        cout << cur -> val<< " ";
        x = 1;
    }
    if (cur -> l != NULL) ans(cur -> l, x);
    if (cur -> r != NULL) ans(cur -> r, x);
    
}

int main() {
    int n;
    cin >> n;
    int a[100005];
    for (int i = 1; i <= n; i++) cin >> a[i];
    line *head = new line(a[1]);
    cin >> k;
    for (int i = 2; i <= n; i++) {
        insert(head, a[i]);
    }
    ans(head, 0);
}