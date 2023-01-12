//X19647 Cheapest Routes

#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

typedef pair<int, int> PI;
int inf = numeric_limits<int>::max();

int dijkstra(const vector<int>& vWeight, const vector<vector<pair<int, int>>>& arcs, const int& from, const int& to) {
    int n = vWeight.size();
    vector<int> dist(n, inf);
    dist[from] = 0;
    priority_queue<PI, vector<PI>, greater<PI>> Q;
    Q.push({0, from}); //dist primero para ordenar
    while(!Q.empty()) {
        auto vTop = Q.top().second; Q.pop();
        if (vTop == to) return dist[vTop]; //se encuentra al destino
        for(int i = 0; i < arcs[vTop].size(); ++i) {
            int nextVer = arcs[vTop][i].first;
            int nextDist = arcs[vTop][i].second;
            int nextweight = dist[vTop] + nextDist + (nextVer == to ? 0 : vWeight[nextVer]);
            if (dist[nextVer] > nextweight) {
                dist[nextVer] = nextweight;
                Q.push({dist[nextVer], nextVer});
            }
        }
    }
    return -1;
    
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vWeight(n);
    for (int i = 0; i < n; ++i) {
        cin >> vWeight[i];
    }

    vector<vector<pair<int, int>>> arcs(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        arcs[u].push_back({v, w});
        arcs[v].push_back({u, w});
    }

    int from, to;
    while(cin >> from >> to) {
        cout << "c(" << from << "," << to << ") = ";
        int res = dijkstra(vWeight, arcs, from, to);
        if (res == -1) cout << "+oo" << endl;
        else cout << res << endl;
    }
}