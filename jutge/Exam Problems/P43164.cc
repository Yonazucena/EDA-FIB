//P43164 Treasures in a map (5)

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef pair<int, int> P;

int INF = numeric_limits<int>::max();

vector<pair<int, int>> adjacent = {{-1,0}, {0, -1}, {1, 0}, {0, 1}};

bool valid(const int& i, const int& j, const vector<vector<char>>& map) {
    return i >= 0 && j >= 0 && i < map.size() && j < map[0].size() && map[i][j] != 'X';
}

int bfs(const vector<vector<char>>& map, int ini_i, int ini_j) {
    int rows = map.size(), cols = map[0].size();
    vector<vector<int>> distance(rows, vector<int>(cols, INF));

    queue<P> Q;
    Q.push({ini_i, ini_j});
    distance[ini_i][ini_j] = 0;

    int dist1 = INF;
    int dist2 = INF;

    while(!Q.empty()) {
        int i = Q.front().first;
        int j = Q.front().second;
        Q.pop();

        if (map[i][j] == 't') {
            dist2 = dist1;
            dist1 = distance[i][j];
        }

        for (int k = 0; k < adjacent.size(); ++k) {
            int adj_i = i + adjacent[k].first;
            int adj_j = j + adjacent[k].second;
            if (valid(adj_i, adj_j, map) && distance[adj_i][adj_j] == INF) {
                Q.push({adj_i, adj_j});
                distance[adj_i][adj_j] = distance[i][j] + 1;
            }
        }
    }
    return dist2;
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

    //read starting position
    int i, j; cin >> i >> j;

    //solve
    int res = bfs(map, i-1, j-1);
    if (res != INF) cout << "second maximum distance: " << res << endl;
    else cout << "we cannot reach two or more treasures" << endl;
}