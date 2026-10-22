#include<iostream>
using namespace std;

// https://leetcode.com/problems/sudoku-solver/ 
// Suduko Solver

class Solution {
public:
    bool isPossible(vector<vector<char>> &board, int ch, int r, int c){
        // row check
        for(int i = 0; i<9; i++){
            if(board[r][i] == ch){
                return false;
            }
        }

        // col check
        for(int i = 0; i<9; i++){
            if(board[i][c] == ch){
                return false;
            }
        }

        // square check
        int sr = (r/3)*3;
        int sc = (c/3)*3;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(board[sr+i][sc+j] == ch){
                    return false;
                }
            }
        }

        return true;
    }
    bool solve(vector<vector<char>> &board){
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j] == '.'){
                    for(int k = 1; k<=9; k++){
                        char ch = '0' + k;
                        if(isPossible(board, ch, i, j)){
                            board[i][j] = ch;
                            if(solve(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};