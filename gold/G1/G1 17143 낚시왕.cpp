/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class shark {
public:
    pair<int, int> pos;
    int speed;
    int direction;
    int size;

    shark(int r, int c, int s, int d, int z) {
        pos = {r, c};
        speed = s;
        direction = d;
        size = z;
    }

    bool operator<(const shark s) const {
        if(this->pos.first == s.pos.first) {
            return this->size > s.size;
        }

        return this->pos.first > s.pos.first;
    }
};

const int UP = 1;
const int DOWN = 2;
const int RIGHT = 3;
const int LEFT = 4;
int R, C, M;
priority_queue<shark> h[101];

void input() {
    cin >> R >> C >> M;

    for(int i = 1; i <= M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        h[c].push(shark(r, c, s, d, z));
    }
}

void changeDirection(shark &s) {
    if(s.direction == UP) {
        s.direction = DOWN;
    } else if(s.direction == DOWN) {
        s.direction = UP;
    } else if(s.direction == RIGHT) {
        s.direction = LEFT;
    } else {
        s.direction = RIGHT;
    }
}

void moving() {
    vector<shark> temp;

    for(int i = 1; i <= C; i++) {
        while(!h[i].empty()) {
            shark cur = h[i].top(); h[i].pop();

            int leftBlock = cur.speed;
            int movableBlock;
            pair<int, int> curPos = cur.pos;
            while(leftBlock > 0) {
                if (cur.direction == UP) {
                    movableBlock = curPos.first - 1;

                    if(movableBlock > leftBlock) {
                        curPos.first -= leftBlock;
                    } else {
                        curPos.first -= movableBlock;
                        changeDirection(cur);
                    }
                } else if (cur.direction == DOWN) {
                    movableBlock = R - curPos.first;

                    if(movableBlock > leftBlock) {
                        curPos.first += leftBlock;
                    } else {
                        curPos.first += movableBlock;
                        changeDirection(cur);
                    }
                } else if (cur.direction == RIGHT) {
                    movableBlock = C - curPos.second;

                    if(movableBlock > leftBlock) {
                        curPos.second += leftBlock;
                    } else {
                        curPos.second += movableBlock;
                        changeDirection(cur);
                    }
                } else {
                    movableBlock = curPos.second - 1;

                    if(movableBlock > leftBlock) {
                        curPos.second -= leftBlock;
                    } else {
                        curPos.second -= movableBlock;
                        changeDirection(cur);
                    }
                }
                leftBlock -= movableBlock;
            }

            cur.pos = curPos;
            temp.push_back(cur);
        }
    }


    for(int i = 0; i < temp.size(); i++) {
        h[temp[i].pos.second].push(temp[i]);
    }

    for(int i = 1; i <= C; i++) {
        vector<shark> temp2;

        while(!h[i].empty()) {
            temp2.push_back(h[i].top());
            h[i].pop();
        }

        for(int j = 1; j <= temp2.size(); j++) {
            if(j == temp2.size() ||
            !(temp2[j - 1].pos.first == temp2[j].pos.first && temp2[j - 1].pos.second == temp2[j].pos.second)) {
                h[i].push(temp2[j - 1]);
            }
        }
    }
}

void solve() {
    int sum = 0;

    for(int i = 1; i <= C; i++) {
        if(!h[i].empty()) {
            shark gotIt = h[i].top();

            sum += gotIt.size;
            h[i].pop();
        }
        moving();
    }

    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();
}*/
