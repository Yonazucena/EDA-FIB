//P71496 Cuts

#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

int infinit = numeric_limits<int>::max();

void dijkstra(const vector<vector<pair<int, int>>>& G, int s, int& sum) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    for (int i = 0; i < G[0].size(); ++i) Q.push(G[0][i]);
    vector<bool> visitat(G.size(), false);
    visitat[0] = true;
    int count = 0;
    
    while ((count+1) < G.size()) {
        int vertex = Q.top().second;
        int cost = Q.top().first;
        Q.pop();
        if (!visitat[vertex]) {
            visitat[vertex] = true;
            sum += cost;
            for (int i = 0; i < G[vertex].size(); ++i) Q.push(G[vertex][i]);
            count++;
        }
    }
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<vector<pair<int, int>>> paths(n);
        int total = 0;
        while (m--) {
            int x, y, c;
            cin >> x >> y >> c;
            paths[x].push_back({c, y});
            paths[y].push_back({c, x});
            total += c;
        }
        int sum = 0;
        dijkstra(paths, 0, sum);
        cout << total - sum << endl;
    }
}