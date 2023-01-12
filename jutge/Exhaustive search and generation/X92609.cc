//X92609 Two coins of each kind (3)

#include <iostream>
#include <vector>
using namespace std;

int backtracking(const vector<int>& vec, const int& target, int idx, int sum, vector<int>& visited) {
    int total = 0;

    if (sum > target) return 0; //not possible
    if (sum == target) return 1; //found combination
    else {
        for (int i = idx; i < vec.size(); ++i) {
            if (visited[i] < 2) {
                visited[i] += 1;
                total += backtracking(vec, target, i, sum+vec[i], visited);
                visited[i] -= 1;
            }
        }
    }
    return total;
}

int main() {
    int x, n;
    while (cin >> x >> n) {
        //read cases
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) cin >> vec[i];

        //find combination
        vector<int> visited(vec.size(), 0);
        cout << backtracking(vec, x, 0, 0, visited) << endl;
    }
}