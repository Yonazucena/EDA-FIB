//P96413 Erdős number (2)

#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

int infinity = numeric_limits<int>::max();

vector<int> bfs(const int& n, const vector<vector<int>>& coauthors) {
    queue<int> Q;
    Q.push(0); //erdos
    vector<int> d = vector<int>(n, -1);
    d[0] = 0;
    while(!Q.empty()) { //iteration
        int author = Q.front();
        Q.pop();
        for (int i = 0; i < coauthors[author].size(); ++i) {
            if (d[coauthors[author][i]] == -1) {
                Q.push(coauthors[author][i]);
                d[coauthors[author][i]] = d[author]+1;
            }
        }
    }
    return d;
}

int main() {
    int n, w; 
    while (cin >> n >> w) {
        vector<vector<int>> coauthors(n); //all works
        for (int i = 0; i < w; ++i) {
            int num_authors; cin >> num_authors; // one work
            vector<int> work_coauthors; 

            for (int j = 0; j < num_authors; ++j) {//one author
                int author; cin >> author; 
                work_coauthors.push_back(author);
            }

            //add to graph
            for (int k = 0; k < work_coauthors.size(); ++k) {
                for (int l = 0; l < work_coauthors.size(); ++l) {
                    if (k != l) coauthors[work_coauthors[k]].push_back(work_coauthors[l]);
                }
            }
        }

        vector<int> d = bfs(n, coauthors);
        for (int r = 0; r < d.size(); ++r) {
            cout << r << " : ";
            if (d[r] == -1) cout << "no" << endl;
            else cout << d[r] << endl;
        }
        cout << "----------" << endl;
    }
    
}