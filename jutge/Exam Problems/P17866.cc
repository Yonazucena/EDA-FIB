//P17866 The hungry knight

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

vector<pair<int, int>> dirs = {{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {1, 2}, {2, 1}};
int infinite = numeric_limits<int>::max();

bool validPos(const vector<vector<char>>& map, const int& x, const int& y) {
    int rows = map.size();
    int cols = map[0].size();
    return x >= 0 and y >= 0 and x < rows and y < cols and map[x][y] != 'X';
}

int findSteps(const vector<vector<char>>& map, const int& iniR, const int& iniC) {
    int rows = map.size();
    int cols = map[0].size();

    vector<vector<bool>> visitat(rows, vector<bool>(cols, false));
    vector<vector<int>> dist(rows, vector<int>(cols, infinite));

    queue<pair<int, int>> Q;
    Q.push({iniR, iniC});
    dist[iniR][iniC] = 0;
    while (not Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if (map[x][y] == 'p') return dist[x][y];
        if (not visitat[x][y]) {
            visitat[x][y] = true;
            for (int i = 0; i < dirs.size(); ++i) {
                int xx = x + dirs[i].first;
                int yy = y + dirs[i].second;
                if (validPos(map, xx, yy)) {
                    Q.push({xx, yy});
                    dist[xx][yy] = dist[x][y] + 1;
                }
            }
        }
    }
    return -1;
}

int main() {
    int f, c;
    while(cin >> f >> c) {
        //read map
        vector<vector<char>> map(f, vector<char>(c));
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> map[i][j];
            }
        }

        //reads initial position
        int iniR, iniC;
        cin >> iniR >> iniC;

        //print result
        int res = findSteps(map, iniR-1, iniC-1);
        if (res == -1) cout << "no" << endl;
        else cout << res << endl;
    }
}