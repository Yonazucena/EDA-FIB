//P84219 First occurrence

#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre) {
    if (esq > dre) return -1;
    int m = (esq+dre)/2;
    if(v[m]==x) {
        if(v[m-1] == x and m-1 >= esq) return posicio(x, v, esq, m-1);
        else return m;
    }
    if (x < v[m]) return posicio(x, v, esq, m-1);
    else return posicio(x, v, m+1, dre);
}

int first_occurrence(double x, const vector<double>& v) {
    return posicio(x, v, 0, v.size()-1);
}

/*
int main() {
    vector<double> v{1, 2, 3, 4, 4, 4, 4, 5, 6};
    cout << first_occurrence(8, v) << endl;
}
*/