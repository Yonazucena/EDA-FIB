//P65553 Boardgames

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        map<string, int> collection;
        int total = n;
        for(int i = 0; i < n; ++i) {
            string type;
            cin >> type;
            map<string, int>::iterator it = collection.find(type);
            if (it == collection.end()) {
                collection.insert({type, 1});
            }
            else {
                it->second++;
            }
        }

        int g; cin >> g;
        for(int i = 0; i < g; ++i) {
            string type;
            cin >> type;
            map<string, int>::iterator it = collection.find(type);
            if (it == collection.end()) {
                collection.insert({type, 1});
                total++;
            }
            else {
                if (it->second+1 <= (total+1)/2) {
                    it->second++;
                    total++;
                }
            }
        }

        for (auto it : collection) {
            cout << it.first << " " << it.second << endl;
        }
        cout << "--------------------" << endl; 
    }
}