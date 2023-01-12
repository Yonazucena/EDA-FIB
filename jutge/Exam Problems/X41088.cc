//X41088 Sequences with no wells

#include <iostream>
#include <vector>
using namespace std;

void escriu(vector<int> A) {
    cout << '(' << A[0];
    for (int i = 1; i < A.size(); ++i) {
        cout << ',' << A[i];
    }
    cout << ')' << endl;
}

void escriuPermutations(vector<int>& A, int idx, vector<bool>& usat) {
    if (idx == A.size()) escriu(A);
    else {
        for (int i = 1; i <= A.size(); ++i) {
            if (not usat[i]) {
                A[idx] = i;
                if (idx <= 1 or (idx > 1 and ((A[idx-2] + A[idx]) <= (2*A[idx-1])))) {
                    usat[i] = true;
                    escriuPermutations(A, idx+1, usat);
                    usat[i] = false;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    vector<bool> usat(n+1, false);
    escriuPermutations(A, 0, usat);
}