#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static int count = 0;

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
        if(this->pos.second == s.pos.second) {
            return this->size < s.size;
        } else {
            return this->pos.second > s.pos.second;
        }
    }
};

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
    if(s.direction == 1) {
        s.direction = 2;
    } else if(s.direction == 2) {
        s.direction = 1;
    } else if(s.direction == 3) {
        s.direction = 4;
    } else {
        s.direction = 3;
    }
}

void moving() {
    vector<shark> temp;

    for(int i = 1; i <= C; i++) {
        while(!h[i].empty()) {
            shark cur = h[i].top(); h[i].pop();

            if(cur.direction == 1) {

            } else if(cur.direction == 2) {

            } else if(cur.direction == 3) {

            } else {

            }

            temp.push_back(cur);
        }
    }

    for(int i = 0; i < temp.size(); i++) {
        if(h[temp[i].pos.second].size()) {
            while(h[temp[i].pos.second].top().pos.first == temp[i].pos.first) {
                h[temp[i].pos.second].pop();
            }
        }

        h[temp[i].pos.second].push(temp[i]);
    }
}

void solve() {
    int sum = 0;

    for(int i = 1; i <= C; i++) {
        sum += h[i].top().size;
        if(h[i].size()) {
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
}