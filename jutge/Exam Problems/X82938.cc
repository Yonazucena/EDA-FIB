//X82938 Search in a unimodal vector

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool searchvec(int l, int r, const int& x, const vector<int>& v) {
    int m = (l+r)/2;
    if (v[m] == x || v[l] == x || v[r] == x) return true;
    if (abs(l-r) <= 1) return false;
    if (m+1 < v.size()) {
        if (v[m+1] > v[m]) {//creciente derecha
            if (x > v[m]) return searchvec(m, r, x, v);
            else return searchvec(l, m-1, x, v);
        }
        else { //decreciente izq
            if (x > v[m]) return searchvec(l, m-1, x, v);
            else return searchvec(m, r, x, v);
        }
    }
    return false;
}

int top(const vector<int>& v, int l, int r) {
    if (abs(l-r) <= 1) {
        if (v[l] < v[r]) return r;
        else return l;
    }
    int m = (l+r)/2;
    if (v[m+1] > v[m]) return top(v, m+1, r);
    else return top(v, l, m);
}

bool search(int x, const vector<int>& v) {
    int max = top(v, 0, v.size());
    return searchvec(0, max, x, v) || searchvec(max, v.size()-1, x, v);
}

int main() {
    int x;
    cin >> x;
    vector<int> vec = {0, 2, 5, 7, 6, 5, 4, 3, 1};

    if (search(x, vec)) cout << "found" << endl;
    else cout << "not found" << endl;
}