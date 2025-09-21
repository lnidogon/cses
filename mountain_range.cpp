#include<bits/stdc++.h>
#define breturn return
using namespace std;
/**
 * Each mountain has exactly two 'parents' (left and right), apart from that pretty standard dynamic. 
 * The parent can be easily found with a monotone stack
 */

int dpf(int x, vector<int> &dp, vector<int> &par_r, vector<int> &par_l) {
    if(!~x) return 0;
    if(~dp[x]) return dp[x];
    dp[x] = 1;
    return dp[x] += max(dpf(par_r[x], dp, par_r, par_l), dpf(par_l[x], dp, par_r, par_l));   
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<int> vm;
    vector<int> par_r(n, -1), par_l(n, -1);
    vector<int> dp(n, -1); 
    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < n; i++) {
            while(vm.size() && v[i] >= v[j?n-1-vm.back():vm.back()]) vm.pop_back();
            if(vm.size()) (j?par_r[n - i - 1]:par_l[i]) = vm.back();
            vm.push_back(j?n - i - 1:i);
        }
        vm.clear();
        reverse(v.begin(), v.end());
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dpf(i, dp, par_r, par_l));
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    solve();
}