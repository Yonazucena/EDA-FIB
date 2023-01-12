//P40902 Casino

#include <iostream>
#include <map>
using namespace std;

int main() {
    string name;
    map<string, int> Players;
    while (cin >> name) {
        auto it = Players.find(name);
        string op;
        cin >> op;
        if (op == "enters") {
            if (it != Players.end()) cout << name << " is already in the casino" << endl;
            else Players.insert({name, 0});
        }
        if (op == "wins") {
            int num;
            cin >> num;
            if (it == Players.end()) cout << name << " is not in the casino" << endl;
            else it->second += num;
        }
        if (op == "leaves") {
            if (it == Players.end()) cout << name << " is not in the casino" << endl;
            else {
                cout << it->first << " has won " << it->second << endl;
                Players.erase(it);
            }
        }
    }
    cout << "----------" << endl;
    for (auto it = Players.begin(); it != Players.end(); ++it) {
        cout << it->first << " is winning " << it->second << endl;
    }
}