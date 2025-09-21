#include<bits/stdc++.h>
#define breturn return
using namespace std;
void solve() {
    int n;
    set<int> s;
    map<int, vector<int> > m;
    cin >> n;
    vector<int> v;
    s.insert(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        if(m.find(x) == m.end()) {
            vector<int> temp;
            m[x] = temp;
        }
        m[x].push_back(i);
    }
    for(auto t:m) {
        reverse(m[t.first].begin(), m[t.first].end());
    }
    for(auto t:m) { 
        m[t.first].pop_back();
        if(m[t.first].size()) s.insert(m[t.first].back());
    }
    long long ans = 0;
    for(int i = 0; i < n; i ++) {
        int mn = *s.begin();
        ans += mn - i;
        int x = v[i];
        if(s.find(m[x].back()) != s.end()) {
            s.erase(m[x].back());
        }
        if(m[x].size()) m[x].pop_back();
        if(m[x].size()) {
            s.insert(m[x].back());
        }
    }
    cout << ans << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    solve();
}