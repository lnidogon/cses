#include<bits/stdc++.h>
#define breturn return
using namespace std;
int mat[101][101];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            set<int> nums;
            for(int k = 0; k < i; k++) nums.insert(mat[k][j]);  
            for(int k = 0; k < j; k++) nums.insert(mat[i][k]);  
            while(nums.find(mat[i][j]) != nums.end()) ++mat[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n;j ++) {
            cout << mat[i][j] << " ";
        }
        cout << '\n';
    }
}