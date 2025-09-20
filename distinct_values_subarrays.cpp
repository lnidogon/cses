#include<bits/stdc++.h>
#define breturn return
using namespace std;
void solve() {
    int n;
    vector<int> v(n);
    set<int> s;
    map<int, vector<int> > m;
    cin >> n;
    s.insert(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        m[x].push_back(i);
    }
    for(auto t:m) {
        reverse(t.second.begin(), t.second.end());
    }
    for(auto t:m) {
        t.second.pop_back();
        if(t.second.size()) s.insert(t.second.back());
    }
    long long ans = 0;
    for(int i = 0; i < n;i ++) {
        int mn = *s.begin();
        ans += mn - i;
        int x = v[i];
        s.erase(m[x].back());
        m[x].pop_back();
        if(m[x].size())s.insert(m[x].back());
    }
    cout << ans;

}
int main() {
    solve();
}