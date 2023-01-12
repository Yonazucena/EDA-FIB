//P29212 Modular exponentiation

#include <iostream>
using namespace std;

int elevat(int n, const int k, const int m) {
    if (k == 0) return 1;
    int x = elevat(n, k/2, m);
    x = (x*x)%m;
    if (k%2) x = (x*n)%m;
    return x;
}

int main() {
    int n, k, m;
    while(cin >> n >> k >> m) {
        cout << elevat(n, k, m) << endl;
    }
}