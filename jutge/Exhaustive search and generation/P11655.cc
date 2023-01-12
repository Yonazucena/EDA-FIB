//P11655 Equal sums (3)

#include <iostream>
#include <vector>
#include <set>
using namespace std;

void escriu(const vector<int>& vec, const vector<bool>& visitat) {
    bool first = false;
    cout << "{";
    for (int i = 0; i < vec.size(); ++i) {
        if (visitat[i]) {
            if (!first) {
                first = true;
                cout << vec[i];
            }
            else cout << ", " << vec[i];
        }
    }
    cout << "}" << endl;
}

void escriu_permutacions(const vector<int>& vec, vector<bool>& visitat, int idx, int sum, const int& target, int total) {
    if (sum > target || sum + total < target) return;
    if (idx == vec.size()) escriu(vec, visitat);
    visitat[idx] = 0;
    escriu_permutacions(vec, visitat, idx+1, sum, target, total-vec[idx]);
    visitat[idx] = 1;
    escriu_permutacions(vec, visitat, idx+1, sum+vec[idx], target, total-vec[idx]);
}

int main() {
    int s, n; 
    cin >> s >> n;
    vector<int> vec(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        total += vec[i];
    }
    vector<bool> visitat(n);
    escriu_permutacions(vec, visitat, 0, 0, s, total);
}