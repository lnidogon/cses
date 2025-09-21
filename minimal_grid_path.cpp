#include<bits/stdc++.h>
#define breturn return
using namespace std;
/**
 * A greedy solution, just keep track of branches that are minimal possible and always branch only to the minimal ones
 */
void solve() {
    int n;
    vector<string> v;
    cin >> n;
    vector<int> temp(n);
    vector<vector<int> > bio(n, temp);
    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    vector<pair<int, int> > ol = {{0,0}}, ne;
    string ans; 
    ans.push_back((v[0][0]));
    while((int)ans.size() < 2 * n - 1) { 
        ans.push_back('Z');
        for(auto t:ol) { 
            int x = t.first, y = t.second, xx = t.first + 1, yy = t.second + 1;
            if(xx < n && !bio[xx][y]) {
                if(v[xx][y] < ans.back()) {
                    bio[xx][y] = 1;
                    ne = {{xx, y}};
                    ans.back() = v[xx][y];
                } else if(v[xx][y] == ans.back()) bio[xx][y] = 1, ne.push_back({xx, y}); 
            } 
            if(yy < n && !bio[x][yy]) {
                if(v[x][yy] < ans.back()) {
                    ne = {{x, yy}};
                    bio[x][yy] = 1;
                    ans.back() = v[x][yy];
                } else if(v[x][yy] == ans.back()) bio[x][yy] = 1, ne.push_back({x, yy}); 
            }
        }
        ol = ne;

    }
    cout << ans << '\n';

}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    solve();    
}