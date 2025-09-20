#include<bits/stdc++.h>
using namespace std;
char mat[501][501];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] > 'B') {
                if((i + j)%2) cout << "A";
                else cout << "B";
            } else {
                if((i+j)%2) cout << "C";
                else cout << "D";
            }
        }
        cout << '\n';
    }
}