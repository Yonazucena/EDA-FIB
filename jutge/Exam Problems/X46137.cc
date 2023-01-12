//X46137 Compensated words

#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<char>& vec) {
    for (int i = 0; i < vec.size(); i++) cout << vec[i];
    cout << endl;
}

void compensation(vector<char> vec, const int& n, int as, int bs) {
    if (vec.size() == n) {
        escriu(vec);
        return;
    }
    else {
        if (abs((as+1)-bs) <= 2) {
            vec.push_back('a');
            compensation(vec, n, as+1, bs);
            vec.pop_back();
        }
        
        if (abs(as-(bs+1)) <= 2) {
            vec.push_back('b');
            compensation(vec, n, as, bs+1);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<char> vec;
    compensation(vec, n, 0, 0);
}