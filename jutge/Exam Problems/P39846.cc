//P39846 Treasures in a map (4)

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int infinite = numeric_limits<int>::max();

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool valid(int x, int y, const vector<vector<char>>& map) {
    return x >= 0 && x < map.size() && y >= 0 && y < map[0].size() && map[x][y] != 'X';
}

int furthest(const vector<vector<char>>& map, int inix, int iniy) {
    int rows = map.size();
    int cols = map[0].size();

    vector<vector<bool>> visitat(rows, vector<bool>(cols, false));
    vector<vector<int>> dist(rows, vector<int>(cols, infinite));

    queue<pair<int, int>> Q;
    Q.push({inix, iniy});
    dist[inix][iniy] = 0;

    int last_treasure = -1;

    while(!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if (map[x][y] == 't') {
            last_treasure = dist[x][y];
        }
        if (!visitat[x][y]) {
            visitat[x][y] = true;
            for (int i = 0; i < dirs.size(); ++i) {
                int xx = x + dirs[i].first;
                int yy = y + dirs[i].second;
                if (valid(xx, yy, map) && !visitat[xx][yy]) {
                    Q.push({xx, yy});
                    dist[xx][yy] = dist[x][y]+1;
                }
            }
        }
    }
    return last_treasure;
}

int main() {
    //read map
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }

    //read initial position
    int iniI, iniJ;
    cin >> iniI >> iniJ;

    //solve
    int res = furthest(map, iniI-1, iniJ-1);
    if (res == -1) cout << "no treasure can be reached" << endl;
    else cout << "maximum distance: " << res << endl;
}