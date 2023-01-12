//X22314 Donations

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> M;
    char c;

    while (cin >> c) {
        if (c == 'N') {
            cout << "number: " << M.size() << endl;
        }
        else if (c == 'D') {
            string nif;
            int money;
            cin >> nif >> money;
            map<string, int>::iterator it = M.find(nif);
            if (it == M.end()) {
                M.insert({nif, money});
            }
            else {
                it->second += money;
            }
        }
        else if (c == 'Q') {
            string nif;
            cin >> nif;
            map<string, int>::iterator it = M.find(nif);
            if (it == M.end()) cout << -1 << endl;
            else cout << it->second << endl;
        }
        else if (c == 'P') {
            bool separation = false;
            for (map<string, int>::iterator it = M.begin(); it != M.end(); ++it) {
                if (not (it->first[7]%2)) {
                    if (separation) cout << " ";
                    cout << it->first;
                    separation = true;
                }
            }
            cout << endl;
        }
        else {
            if (M.size() == 0) cout << "NO LAST NIF" << endl;
            else {
                map<string, int>::iterator it = M.end();
                it--;
                cout << it->first << " " << it->second << endl;
            }
        }
    }
}