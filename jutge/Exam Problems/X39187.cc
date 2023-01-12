//X39187 Buying shares

#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<char>& vec) {
    for (int i = 0; i < vec.size(); i++) cout << vec[i];
    cout << endl;
    return;
}

void operations(vector<char> vec, int nTrans, int coins, int shares) {
    if (vec.size() == nTrans) escriu(vec);
    else {
        if (coins) {
            vec.push_back('b');
            operations(vec, nTrans, coins-1, shares+1);
            vec.pop_back();
        }
        if (shares) {
            vec.push_back('s');
            operations(vec, nTrans, coins+1, shares-1);
            vec.pop_back();
        }
    }
}

int main() {
    int n, c;
    cin >> n >> c;

    vector<char> Vec;
    operations(Vec, n, c, 0);
}