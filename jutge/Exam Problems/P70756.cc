//P70756 Partitions
//also in exhaustive search folder

#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<int>& resultat, const vector<string>& words, int nSubsets) {
    for (int s = 0; s < nSubsets; ++s) {
        cout << "subset " << s+1 << ": {";
        bool first = true;
        for (int j = 0; j < resultat.size(); ++j) {
            if (first && resultat[j] == s) {
                cout << words[j];
                first = false;
            }
            else if (resultat[j] == s) cout << "," << words[j];
        }
        cout << "}" << endl;
    }
    cout << endl;
}

void permutate(const vector<string>& words, vector<int>& resultat, int idx, const int& numSub) {
    if (idx == words.size()) {
        escriu(resultat, words, numSub);
    }
    else {
        for (int i = 0; i < numSub; ++i) {
            resultat[idx] = i;
            permutate(words, resultat, idx+1, numSub);
        }
    }
}

int main() {
    int nWords; cin >> nWords;
    vector<string> words(nWords);
    for (int i = 0; i < nWords; ++i) {
        cin >> words[i];
    }
    int numSub; cin >> numSub;

    vector<int> resultat(nWords);
    permutate(words, resultat, 0, numSub);
}