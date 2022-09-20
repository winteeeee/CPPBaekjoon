/*
#include <iostream>
using namespace std;

const int SIZE = 9;
int count = 0;
int sudoku[SIZE][SIZE];
void input();
void solve();
void print();
void DFS(int cur);
bool deployable(int r, int c, int n);
int main() {
    input();
    solve();

    return 0;
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < SIZE; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < SIZE; j++) {
            sudoku[i][j] = (int)temp[j] - 48;

            if(sudoku[i][j] == 0)
                count++;
        }
    }
}

void solve() {
    DFS(0);
}

void print() {
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++) {
            cout << sudoku[i][j];
        }
        cout << "\n";
    }
}

void DFS(int cur) {
    if(cur == count) {
        print();
        exit(0);
    }

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(sudoku[i][j])
                continue;

            bool isSkip = true;
            for(int k = 1; k < 10; k++) {
                if(deployable(i, j, k)) {
                    isSkip = false;
                    sudoku[i][j] = k;
                    DFS(cur + 1);
                    sudoku[i][j] = 0;
                }
            }

            if(isSkip || !sudoku[i][j])
                return;
        }
    }
}

bool deployable(int r, int c, int n) {
    for(int i = 0; i < SIZE; i++) {
        if(sudoku[i][c] == n)
            return false;
    }

    for(int i = 0; i < SIZE; i++) {
        if(sudoku[r][i] == n)
            return false;
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(sudoku[r / 3 * 3 + i][c / 3 * 3 + j] == n)
                return false;
        }
    }

    return true;
}*/
