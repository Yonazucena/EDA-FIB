//P12828 Zeros and ones (1)

#include <iostream>
#include <vector>
using namespace std;

void escriu(vector<int>& A) {
    cout << A[0];
    for (int i = 1; i < A.size(); ++i) {
        cout << ' ' << A[i];
    }
    cout << endl;
}

void combinations(vector<int>& A, int i) {
    if (i == A.size()) {
        escriu(A);
        return;
    }
    else {
        A[i] = 0;
        combinations(A, i+1);
        A[i] = 1;
        combinations(A, i+1);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    combinations(A, 0);
}