//P49889 Consonants and vowels

#include <iostream>
#include <vector>
using namespace std;

void read_letters(int n, vector<char>& vec) {
    while(n--) {
        char letter; cin >> letter;
        vec.push_back(letter);
    }
}

void write_vec(const vector<int>& order, const vector<char>& consonants, const vector<char>& vowels) {
    for (int i = 0; i < order.size(); ++i) {
        if (order[i] < consonants.size()) {
            cout << consonants[order[i]];
        }
        else cout << vowels[order[i]-consonants.size()];
    }
    cout << endl;
}

bool are_opposites(int a, int b, int change) {
    if (a >= change && b < change) return true;
    else if (a < change && b >= change) return true;
    return false;
}

void write_combinations(const int& n, const vector<char>& consonants, const vector<char>& vowels, vector<int> order, int idx, vector<bool> visitat) {
    if (idx == (n*2)) {
        write_vec(order, consonants, vowels);
    }

    else {
        for (int i = 0; i < n*2; ++i) {
            if (!visitat[i]) {
                visitat[i] = true;
                order[idx] = i;
                if (idx == 0 || order[0] < n && are_opposites(order[idx-1], order[idx], n)) write_combinations(n, consonants, vowels, order, idx+1, visitat);
                visitat[i] = false;
            }
        }
    }
}

int main() {
    int n; cin >> n;
    vector<char> consonants;
    vector<char> vowels;
    read_letters(n, consonants);
    read_letters(n, vowels);

    vector<int> order(n*2, -1);
    vector<bool> visitat(n*2, false);
    write_combinations(n, consonants, vowels, order, 0, visitat);
}