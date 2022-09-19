/*
#include <iostream>
using namespace std;

int n;
int chess[10][10];
bool deployed[10][10] = {false};
int whiteNum = 0;
int blackNum = 0;

void DFSWhite(int iStart, int jStart, int bishop);
void DFSBlack(int iStart, int jStart, int bishop);
bool deployable(int i, int j);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> chess[i][j];
        }
    }

    DFSWhite(0, 0, 0);
    DFSBlack(0, 1, 0);
    cout << whiteNum + blackNum;
    return 0;
}

void DFSWhite(int iStart, int jStart, int bishop) {
    if(whiteNum < bishop)
        whiteNum = bishop;

    for(int i = iStart; i < n; i++) {
        int j;
        if(i == iStart)
            j = jStart;

        else
            j = (i & 1) ? 1 : 0;
        for(; j < n; j += 2) {
            if(chess[i][j] && deployable(i, j)) {
                deployed[i][j] = true;
                if (j + 2 >= n) {
                    DFSWhite(i + 1, ((i + 1) & 1) ? 1 : 0, bishop + 1);
                }

                else {
                    DFSWhite(i, j + 2, bishop + 1);
                }
                deployed[i][j] = false;
            }
        }
    }
}

void DFSBlack(int iStart, int jStart, int bishop) {
    if(blackNum < bishop)
        blackNum = bishop;

    for(int i = iStart; i < n; i++) {
        int j;
        if(i == iStart)
            j = jStart;

        else
            j = (i & 1) ? 0 : 1;
        for(; j < n; j += 2) {
            if(chess[i][j] && deployable(i, j)) {
                deployed[i][j] = true;
                if (j + 2 >= n) {
                    DFSBlack(i + 1, ((i + 1) & 1) ? 0 : 1, bishop + 1);
                }

                else {
                    DFSBlack(i, j + 2, bishop + 1);
                }
                deployed[i][j] = false;
            }
        }
    }
}

bool deployable(int i, int j) {
    for(int k = 0; k < n; k++) {
        if(i - k >= 0 && j + k < n) {
            if(deployed[i - k][j + k])
                return false;
        }

        if(i + k < n && j + k < n) {
            if(deployed[i + k][j + k])
                return false;
        }

        if(i - k >= 0 && j - k >= 0) {
            if(deployed[i - k][j - k])
                return false;
        }

        if(i + k < n && j - k >= 0) {
            if(deployed[i + k][j - k])
                return false;
        }
    }

    return true;
}*/
