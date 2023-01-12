//P69781 Collatz pseudo-sequences (2)

#include <iostream>
#include <vector>
using namespace std;

bool find_cycle(const vector<int>& sequence, const int& n, int& count) {
    for (int i = 0; i < sequence.size(); ++i) {
        if (sequence[i] == n) {
            count = sequence.size() - i;
            return true;
        }
    }
    return false;
}

int main() {
    int x, y, n;
    while (cin >> x >> y >> n) {
        vector<int> sequence;
        bool found = false;
        int count = 0;
        while (n <= 100000000 and found == false) {
            if (!(n%2)) n = n/2 + x;
            else n = 3*n + y;
            found = find_cycle(sequence, n, count);
            sequence.push_back(n);
        }
        if (found) cout << count << endl;
        else cout << n << endl;
    }
} 