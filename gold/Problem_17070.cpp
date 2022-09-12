/*
#include <iostream>
#include <queue>
using namespace std;

class pipe {    //1 -> 가로 2 -> 세로 3 -> 대각선
private:
    pair<int, int> position;
    int status;

public:
    pipe(int r, int c, int s) {
        position = {r, c};
        status = s;
    }

    pair<int, int> getPosition(){
        return position;
    }

    int getStatus() {
        return status;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    int house[n + 1][n + 1];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &house[i][j]);
        }
    }

    queue<pipe> q;
    q.push(pipe(1, 2, 1));
    int count = 0;

    while(!q.empty()) {
        pipe cur = q.front(); q.pop();
        int curR = cur.getPosition().first;
        int curC = cur.getPosition().second;
        bool rightCheck = curC + 1 <= n && house[curR][curC + 1] != 1;
        bool downCheck = curR + 1 <= n && house[curR + 1][curC] != 1;
        bool diagonalCheck = curR + 1 <= n && curC + 1 <= n && house[curR][curC + 1] != 1 && house[curR + 1][curC + 1] != 1 && house[curR + 1][curC] != 1;
        if(curR == n && curC == n)
            count++;

        if(cur.getStatus() == 1) {
            if(rightCheck) {
                q.push(pipe(curR, curC + 1, 1));
            }
        }

        else if(cur.getStatus() == 2) {
            if(downCheck) {
                q.push(pipe(curR + 1, curC, 2));
            }
        }

        else {
            if(rightCheck) {
                q.push(pipe(curR, curC + 1, 1));
            }

            if(downCheck) {
                q.push(pipe(curR + 1, curC, 2));
            }
        }

        if(diagonalCheck) {
            q.push(pipe(curR + 1, curC + 1, 3));
        }
    }

    printf("%d", count);
    return 0;
}*/
