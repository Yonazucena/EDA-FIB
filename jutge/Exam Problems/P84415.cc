//P84415 Bag of words

#include <iostream>
#include <map>
#include <string>
using namespace std;

void add_word(map<string, int> &bag, const string& word) {
    map<string, int>::iterator it = bag.find(word);
    if (it != bag.end()) {
        it->second += 1;
    }
    else bag.insert(make_pair(word, 1));
}

void delete_word(map<string, int> &bag, const string& word) {
    map<string, int>::iterator it = bag.find(word);
    if (it != bag.end()) {
        it->second -= 1;
    }
    if (it->second == 0) bag.erase(word);
}

int main() {
    map<string, int> bag;
    string command;
    while (cin >> command) {
        if (command == "minimum?") {
            if (bag.size() == 0) cout << "indefinite minimum" << endl;
            else {
                map<string, int>::iterator it = bag.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        if (command == "maximum?") {
            if (bag.size() == 0) cout << "indefinite maximum" << endl;
            else {
                map<string, int>::iterator it = bag.end();
                it--;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        if (command == "store") {
            string word;
            cin >> word;
            add_word(bag, word);
        }
        if (command == "delete") {
            string word;
            cin >> word;
            delete_word(bag, word);
        }
    }
}