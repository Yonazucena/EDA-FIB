//P12887 Minimum spanning trees
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int mst(const vector<vector<P>>& graph) {
    vector<bool> visitat(graph.size(), false);
    visitat[0] = true;
    priority_queue<P, vector<P>, greater<P>> pq;
    for (P x : graph[0]) pq.push(x);
    int size = 1;
    int sum = 0;
    while (size < graph.size()) {
        int c = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if (!visitat[x]) {
            visitat[x] = true;
            for (P y : graph[x]) pq.push(y);
            sum += c;
            ++size;
        }
    }
    return sum;
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<vector<P>> graph(n); //lista d'adjacencia (cost, vertex)
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u-1].push_back({w, v-1});
            graph[v-1].push_back({w, u-1});
        }
        cout << mst(graph) << endl;
    }
}