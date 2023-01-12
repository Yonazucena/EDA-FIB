//P54070 Rightmost position of insertion

#include <iostream>
#include <vector>
using namespace std;

int middle(const vector<double>& v, int l, int r, double target) {
    if (r == l) return l;
    int m = (l+r)/2;
    if (target < v[m]) return middle(v, l, m, target);
    return middle(v, m+1, r, target);
}

int rightmost(double x, const vector<double>& v) {
    return middle(v, 0, v.size(), x);
}

// int main() {
//     vector<double> v = {12, 22};
//     double x = 23;
//     cout << rightmost(x, v) << endl;
// }