//X20680 Words with x, y and z

#include <iostream>
#include <vector>
using namespace std;

void backtracking(vector<char> list, int max_c, int idx, char lastLetter, int count) {
    if (count > max_c) return;

    if (idx == list.size()) {
        if (count <= max_c) {
            for (char l : list) cout << l;
            cout << endl;
        }
    }
    else {
        int temp = count;

        list[idx] = 'x';
        if ('x' == lastLetter) temp = count+1;
        else temp = 1;
        backtracking(list, max_c, idx+1, 'x', temp);

        list[idx] = 'y';
        temp = count;
        if ('y' == lastLetter) temp = count+1;
        else temp = 1;
        backtracking(list, max_c, idx+1, 'y', temp);

        list[idx] = 'z';
        temp = count;
        if ('z' == lastLetter) temp = count+1;
        else temp = 1;
        backtracking(list, max_c, idx+1, 'z', temp);
    }
}

int main() {
    int n, c;
    while(cin >> n >> c) {
        vector<char> list(n);
        backtracking(list, c, 0, -1, 1);
        cout << "--------------------" << endl;
    }
}