//P71701 Peaceful kings

#include <iostream>
#include <vector>
using namespace std;

bool threatens(const vector<vector<bool>>& board, int row, int col) {

    if (col > 0 && board[row][col-1] == true) return true; //left
    if (row > 0 && board[row-1][col] == true) return true; //up
    if (col > 0 && row > 0 && board[row-1][col-1] == true) return true; //diagonal left
    if (col < board.size()-1 && row > 0 && board[row-1][col+1] == true) { //diagonal right
        return true;
    }

    return false;
}

void permutations(const int& nKings, vector<vector<bool>>& board, int idx, int sum) {
    if (sum > nKings) return;
    if (idx == board.size()*board.size()) { 
        if (sum == nKings) {
            for (int i = 0; i < board.size(); ++i) {
                for (int j = 0; j < board.size(); ++j) {
                    if (board[i][j] == true) cout << "K";
                    else cout << ".";
                }
                cout << endl;
            }
            cout << "----------" << endl;
        }
    }
    else {
        
        int row = idx/board.size();
        int col = idx%board.size();

        if (!threatens(board, row, col)) {
            board[row][col] = true;
            permutations(nKings, board, idx+1, sum+1);
        }

        board[row][col] = false;
        permutations(nKings, board, idx+1, sum);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<bool>> board(n, vector<bool>(n));
    permutations(k, board, 0, 0);
}