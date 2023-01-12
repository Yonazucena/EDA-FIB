//X57029 Up and down

#include <iostream>
#include <vector>
using namespace std;

void path(vector<char> movement, int n, int x, int y) {
    if (movement.size() == n) {
        for (int i = 0; i < movement.size(); i++) cout << movement[i];
        cout << endl;
    }
    else {
        if (y-1 >= 0) {
            movement.push_back('d');
            path(movement, n, x, y-1);
            movement.pop_back();
        }

        movement.push_back('h');
        path(movement, n, x+1, y);
        movement.pop_back();

        movement.push_back('u');
        path(movement, n, x, y+1);
        movement.pop_back();        
    }
}

int main() {
    int n;
    cin >> n;
    vector<char> movement;
    path(movement, n, 0, 0);
}