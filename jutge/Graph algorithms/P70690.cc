//P70690 Treasures in a map (1)

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool find_treasure(vector<vector<char>>& map, const int i_row, const int i_col, const int row, const int col) {
    if (i_row < 0 or i_col < 0 or i_row >= row or i_col >= col or map[i_row][i_col] == 'X') return false;
    if (map[i_row][i_col] == 't') return true;
    
    map[i_row][i_col] = 'X';
    for (int i = 0; i < dirs.size(); ++i) {
        int x = i_row + dirs[i].first;
        int y = i_col + dirs[i].second;
        if (find_treasure(map, x, y, row, col)) return true;
    }
    return false;
}

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<char>> map(row, vector<char>(col));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            char pos;
            cin >> pos;
            map[i][j] = pos;
        }
    }
    int i_row, i_col;
    cin >> i_row >> i_col;
    i_row -= 1;
    i_col -=1;

    if (find_treasure(map, i_row, i_col, row, col)) cout << "yes" << endl;
    else cout << "no" << endl;
}