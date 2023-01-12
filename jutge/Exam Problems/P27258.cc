//P27258 Monstres en un mapa

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool valid(int i, int j, const vector<vector<char>>& map) {
    int rows = map.size();
    int cols = map[0].size();
    if (i < 0 || j < 0 || i >= rows || j >= cols) return false;
    if (map[i][j] == 'M') return false;
    for (int k = 0; k < dirs.size(); ++k) {
        int x = i + dirs[k].first;
        int y = j + dirs[k].second;
        if (x >= 0 && y >= 0 && x < rows && y < cols)
            if (map[x][y] == 'M') return false;
    }
    return true;
}

bool bfs(vector<vector<char>> map, int iniI, int iniJ) {
    int n = map.size();
    int m = map[0].size();
    vector<vector<bool>> visitat(n, vector<bool>(m, false));
    queue<pair<int, int>> Q;
    Q.push({iniI, iniJ});
    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if (valid(x, y, map) && !visitat[x][y]) {
            if (map[x][y] == 'F') return true;
            visitat[x][y] = true;
            for (int i = 0; i < dirs.size(); ++i) {
                int xx = x + dirs[i].first;
                int yy = y + dirs[i].second;
                Q.push({xx, yy});
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        int iniI, iniJ;
        //read map
        vector<vector<char>> map(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> map[i][j];
                
                if (map[i][j] == 'I') { //find starting point
                    iniI = i;
                    iniJ = j;
                }
            }
        }
        if (bfs(map, iniI, iniJ)) cout << "SI" << endl;
        else cout << "NO" << endl;
    }
}