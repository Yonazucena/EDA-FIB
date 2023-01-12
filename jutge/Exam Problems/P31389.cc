//P31389 Rooks inside a rectangle

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(vector<bool> visited, vector<int> list, const int& r, const int& c, int idx) {
    if (idx == r) {
        for (int x : list) {
            for (int i = 0; i < c; ++i) {
                if (i == x) cout << "R";
                else cout << ".";
            }
            cout << endl;
        }
        cout << endl;
        
    }
    else {
        for (int i = 0; i < c; ++i) {
            if (!visited[i]) {
                list[idx] = i;
                visited[i] = true;
                dfs(visited, list, r, c, idx+1);
                visited[i] = false;
            }
        }
    }
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<bool> visited(c, false);
    vector<int> list(r);
    dfs(visited, list, r, c, 0);
}