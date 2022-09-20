#include <iostream>
using namespace std;

int sudoku[9][9];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }

    return 0;
}

void DFS() {

}

bool deployable() {

}