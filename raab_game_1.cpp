#include<bits/stdc++.h>
using namespace std;
/**
    For n, the maximal difference that can be achieved is n - 2 and the other person has to get at least one 
*/
void solve() {
    int n, a, b, sw = 0;
    int oga, ogb;
    cin >> n >> a >> b;
    oga = a, ogb = b;
    if(!(a == 0 && b == 0) && 
    (
        a + b > n
        || abs(a - b) > n - 2
        || ((!!a) ^ (!!b))
    )
    ) { 
        cout << "NO\n";
        return;
    }
    vector<int> v1, v2;
    if(a < b) {
        sw = 1;
        swap(a, b);
    }
    int dif = a - b;
    int li = 0;
    if(dif) { 
        for(int i = 0; i <= dif; i++) {
            v1.push_back(i + 1);
            v2.push_back(i);
        }
        v1.push_back(0);
        v2.push_back(dif + 1);
        li = dif + 2;
        a -= dif + 1;
    }
    while(a > 0) {
        v1.push_back(li), v1.push_back(li + 1);
        v2.push_back(li + 1), v2.push_back(li);
        li += 2;
        a--;
    }
    while(li < n) {
        v1.push_back(li);
        v2.push_back(li);
        li++;
    }
    if(sw) swap(v1, v2);
    cout << "YES\n";
    for(auto t:v1) cout << t + 1 << " "; 
    cout << '\n';
    for(auto t:v2) cout << t + 1 << " ";
    cout << '\n';
    int ta = 0, tb = 0;
    for(int i = 0; i < n; i++) {
        if(v1[i] > v2[i]) ta++;
        else if(v1[i] < v2[i]) tb++;
    }
}
int main() {
    int t;
    for(cin >> t; t--;) solve();
}
