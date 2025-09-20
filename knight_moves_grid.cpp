#include<bits/stdc++.h>
using namespace std;
int dis[1001][1001];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int main() {
    int n;
    cin >> n;
    memset(dis, -1, sizeof(dis));
    queue<pair<int, int> > q;
    q.push({0, 0});
    dis[0][0] = 0;
    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i <8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || yy < 0 || xx >= n || yy >= n || ~dis[xx][yy]) continue;
            q.push({xx, yy});
            dis[xx][yy] = dis[x][y] + 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << dis[i][j] << " ";
        }
        cout << '\n';
    }
}