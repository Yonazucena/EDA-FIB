//P81966 Dichotomic search

#include <iostream>
#include <vector>
using namespace std;

int position(double x, const vector<double>& v, int esq, int dre) {
    if (esq > dre) return -1;
    int mid = (esq+dre)/2;
    if (x < v[mid]) return position(x, v, esq, mid-1);
    if (x > v[mid]) return position(x, v, mid+1, dre);
    return mid;
}

/*
int main() {
    vector<double> v{1, 2, 4, 4, 4, 4, 4, 5, 6, 6, 6, 6};
    cout << position(4, v, 1, 6) << endl;
}
*/