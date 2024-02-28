/*
#include <iostream>
using namespace std;

int r, c;
char board[20][20];
bool boardVisited[20][20] = {false};
int alphabetVisited[26] = {0};
int maxCount = -1;
int cordX[4] = {0, 0, -1, 1};
int cordY[4] = {1, -1, 0, 0};

void DFS(int y, int x, int cur);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        string temp;
        cin >> temp;

        for(int j = 0; j < temp.size(); j++) {
            board[i][j] = temp[j];
        }
    }

    boardVisited[0][0] = true;
    alphabetVisited[board[0][0] - 65] = true;
    DFS(0, 0, 1);
    cout << maxCount;
    return 0;
}

void DFS(int y, int x, int cur) {
    if(cur > maxCount)
        maxCount = cur;

    for(int i = 0; i < 4; i++) {
        if(y + cordY[i] < r && y + cordY[i] >= 0 && x + cordX[i] < c && x + cordX[i] >= 0) {
            if(!boardVisited[y + cordY[i]][x + cordX[i]] && !alphabetVisited[board[y + cordY[i]][x + cordX[i]] - 65]) {
                boardVisited[y + cordY[i]][x + cordX[i]] = true;
                alphabetVisited[board[y + cordY[i]][x + cordX[i]] - 65] = true;
                DFS(y + cordY[i], x + cordX[i], cur + 1);
                boardVisited[y + cordY[i]][x + cordX[i]] = false;
                alphabetVisited[board[y + cordY[i]][x + cordX[i]] - 65] = false;
            }
        }
    }
}

//A는 65*/
