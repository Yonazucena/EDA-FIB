//P76807 Sudoku
//already exists in exhaustive search folder

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sudoku;
vector<vector<bool>> visitat_rows;
vector<vector<bool>> visitat_cols;
vector<vector<vector<bool>>> visitat_cells;

bool resuelve(int i, int j) {
    if (i == 9) return true; //if ended last row
    if (j == 9) return resuelve(i+1, 0); //if ended row, start next one
    if (sudoku[i][j] != -1) return resuelve(i, j+1); //if alr has number assigned go to next
    for (int k = 0; k < 9; ++k) {
        //if its valid currently for the cell
        //(not alr put in the same row/column/cell)
        if (!visitat_rows[i][k] && !visitat_cols[j][k] && !visitat_cells[i/3][j/3][k]) {
            //add to visited in all
            visitat_rows[i][k] = visitat_cols[j][k] = visitat_cells[i/3][j/3][k] = true;
            sudoku[i][j] = k; //change value in sudoku to k
            if (resuelve(i, j+1)) return true; //valid if it works for the rest
            //otherwise imagine youve never been here
            visitat_rows[i][k] = visitat_cols[j][k] = visitat_cells[i/3][j/3][k] = false;
        }
    }
    //if none of them worked then go back
    sudoku[i][j] = -1;
    return false;
}

int main() {
    int n; cin >> n; 
    cout << n << endl;

    while(n--) {

        sudoku = vector<vector<int>>(9, vector<int>(9));
        visitat_rows = vector<vector<bool>>(9, vector<bool>(9, false));
        visitat_cols = vector<vector<bool>>(9, vector<bool>(9, false));
        visitat_cells = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(9, false)));

        //read sudoku
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char digit; cin >> digit;
                if (digit != '.') {
                    int num = digit - '1';
                    sudoku[i][j] = num;
                    visitat_rows[i][num] = true;
                    visitat_cols[j][num] = true;
                    visitat_cells[i/3][j/3][num] = true;
                }
                else sudoku[i][j] = -1;
            }
        }

        if (resuelve(0, 0)) {
            //write solved sudoku
            cout << endl;
            for (int i = 0; i < 9; ++i) {
                cout << sudoku[i][0]+1;
                for (int j = 1; j < 9; ++j) {
                    cout << " " << sudoku[i][j]+1;
                }
                cout << endl;
            }
        }
    }
}