#include<bits/stdc++.h>
#define breturn return
using namespace std;
const int MOD = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    for(int i = 0;i < n; i++) {
        int x;
        cin >> x;
        m[x]++;
    }
    long long ans = 1;
    for(auto t:m) {
        ans *= (t.second + 1);
        ans %= MOD;
    }
    ans --;
    ans = (ans + MOD)%MOD;
    cout << ans << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    solve();
}