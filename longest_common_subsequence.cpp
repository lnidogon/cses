#include<bits/stdc++.h>
#define breturn return
using namespace std;
int dpf(int x, int y, vector<int> &v1, vector<int> &v2, vector<vector<int> > &dp, vector<vector<pair<pair<int, int>, bool> > > &par) {
    if(x == v1.size() || y == v2.size()) return 0;
    if(!~dp[x][y]) {
        dp[x][y] = dpf(x + 1, y, v1, v2, dp, par);
        par[x][y] = {{x + 1, y}, 0};
        int retv = dpf(x, y + 1, v1, v2, dp, par);
        if(retv > dp[x][y]) dp[x][y] = retv, par[x][y] = {{x, y + 1}, 0};
        if(v1[x] == v2[y]) {
            retv = 1 + dpf(x + 1, y + 1, v1, v2, dp, par);
            if(retv > dp[x][y]) dp[x][y] = retv, par[x][y] = {{x + 1, y + 1}, 1};
        }
    }
    return dp[x][y];
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> temp(m, -1);
    vector<pair<pair<int, int>, bool> > temp2(m);
    vector<vector<int> > dp(n, temp);
    vector<vector<pair<pair<int, int>, bool> > > par(n, temp2);
    vector<int> v1(n), v2(m);
    for(int i = 0; i < n; i++) cin >> v1[i]; 
    for(int i = 0; i < m; i++) cin >> v2[i]; 
    dpf(0, 0, v1, v2, dp, par);
    int x = 0, y = 0;
    vector<int> ans;
    while(x < v1.size() && y < v2.size()) {
        pair<int, int> p = par[x][y].first;
        if(par[x][y].second) ans.push_back(v1[x]);
        x = p.first;
        y = p.second;
    }
    cout << ans.size() << '\n';
    for(auto t:ans) cout << t << " ";
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    solve();
}