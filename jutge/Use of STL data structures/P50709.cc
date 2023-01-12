//P50709 Collection of numbers

#include <iostream>
#include <queue>
using namespace std;

int main() {
    char op;
    bool empty = true;
    priority_queue<int> cua;
    while (cin >> op) {
        if (op == 'S') {
            int num;
            cin >> num;
            cua.push(num);
            empty = false;
        }
        if (op == 'A') {
            if (empty) cout << "error!" << endl;
            else cout << cua.top() << endl;
        }
        if (op == 'R') {
            if (empty) cout << "error!" << endl;
            else {
                cua.pop();
                if (cua.size() == 0) empty = true;
            }
        }
        if (op == 'I') {
            int num;
            cin >> num;
            if (empty) cout << "error!" << endl;
            else {
                num += cua.top();
                cua.pop();
                cua.push(num);
            }
        }
        if (op == 'D') {
            int num;
            cin >> num;
            if (empty) cout << "error!" << endl;
            else {
                num = cua.top() - num;
                cua.pop();
                cua.push(num);
            }
        }
    }
}