//X40596 Balanced sequences

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void escriu(const vector<int>& A) {
    cout << '(' << A[0];
    for (int i = 1; i < A.size(); ++i) {
        cout << ',' << A[i];
    }
    cout << ')' << endl;
}

void escriuPermutacio(int n, vector<int>& A, int idx, int d) {
    if (idx == A.size()) escriu(A);
    else {
        for (int k = 1; k < n+1; ++k) {
            bool usat = false;
            for (int i = 0; i < idx and not usat; ++i) {
                if (A[i] == k) usat = true;
            }
            if (not usat) {
                A[idx] = k;
                if (idx == 0 or abs(A[idx-1]-A[idx]) <= d) {
                    escriuPermutacio(n, A, idx+1, d);
                }
            }
        }
    }
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> A(n);
    escriuPermutacio(n, A, 0, d);
}