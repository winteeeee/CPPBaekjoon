/*
#include <iostream>
#include <queue>
using namespace std;

int n, m;
char map[10][10];
bool visited[10][10][10][10];
class Condition {
public:
    pair<int, int> redPosition;
    pair<int, int> bluePosition;
    int count;
};

void moveLeft(Condition cur, queue<Condition> &q);
void moveRight(Condition cur, queue<Condition> &q);
void moveUp(Condition cur, queue<Condition> &q);
void moveDown(Condition cur, queue<Condition> &q);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    pair<int, int> redPosition;
    pair<int, int> bluePosition;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for(int j = 0; j < m; j++) {
            map[i][j] = temp[j];

            if(map[i][j] == 'R') {
                map[i][j] = '.';
                redPosition = {i, j};
            }

            else if(map[i][j] == 'B') {
                map[i][j] = '.';
                bluePosition = {i, j};
            }
        }
    }

    queue<Condition> q;
    q.push({redPosition, bluePosition, 0});
    visited[redPosition.first][redPosition.second][bluePosition.first][bluePosition.second] = true;

    while(!q.empty()) {
        Condition cur = q.front(); q.pop();
        if(cur.count > 9)
            break;

        moveLeft(cur, q);
        moveRight(cur, q);
        moveUp(cur, q);
        moveDown(cur, q);
    }

    cout << "0";
    return 0;
}

void moveLeft(Condition cur, queue<Condition> &q) {
    pair<int, int> nextRed;
    pair<int, int> nextBlue;
    bool redHole = false;
    bool blueHole = false;
    bool fail = false;

    for (int i = cur.redPosition.second - 1; i >= 0; i--) {
        if (map[cur.redPosition.first][i] == '#') {
            nextRed = {cur.redPosition.first, i + 1};
            break;
        }

        else if (map[cur.redPosition.first][i] == 'O') {
            redHole = true; break;
        }
    }

    for (int i = cur.bluePosition.second - 1; i >= 0; i--) {
        if (map[cur.bluePosition.first][i] == '#') {
            nextBlue = {cur.bluePosition.first, i + 1};
            break;
        }

        else if (map[cur.bluePosition.first][i] == 'O') {
            blueHole = true; break;
        }
    }

    if(nextRed.first == nextBlue.first && nextRed.second == nextBlue.second) {
        if(cur.redPosition.second < cur.bluePosition.second)
            nextBlue.second++;
        else
            nextRed.second++;
    }


    if(redHole && !blueHole) {
        cout << 1;
        exit(0);
    }

    else if((redHole && blueHole) || (!redHole && blueHole))
        fail = true;

    if(!fail && !visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second]) {
        q.push({nextRed, nextBlue, cur.count + 1});
        visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second] = true;
    }
}

void moveRight(Condition cur, queue<Condition> &q) {
    pair<int, int> nextRed;
    pair<int, int> nextBlue;
    bool redHole = false;
    bool blueHole = false;
    bool fail = false;

    for (int i = cur.redPosition.second + 1; i < m; i++) {
        if (map[cur.redPosition.first][i] == '#') {
            nextRed = {cur.redPosition.first, i - 1};
            break;
        }

        else if (map[cur.redPosition.first][i] == 'O') {
            redHole = true; break;
        }
    }

    for (int i = cur.bluePosition.second + 1; i < m; i++) {
        if (map[cur.bluePosition.first][i] == '#') {
            nextBlue = {cur.bluePosition.first, i - 1};
            break;
        }

        else if (map[cur.bluePosition.first][i] == 'O') {
            blueHole = true; break;
        }
    }

    if(nextRed.first == nextBlue.first && nextRed.second == nextBlue.second) {
        if(cur.redPosition.second < cur.bluePosition.second)
            nextRed.second--;
        else
            nextBlue.second--;
    }


    if(redHole && !blueHole) {
        cout << 1;
        exit(0);
    }

    else if((redHole && blueHole) || (!redHole && blueHole))
        fail = true;

    if(!fail && !visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second]) {
        q.push({nextRed, nextBlue, cur.count + 1});
        visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second] = true;
    }
}

void moveUp(Condition cur, queue<Condition> &q) {
    pair<int, int> nextRed;
    pair<int, int> nextBlue;
    bool redHole = false;
    bool blueHole = false;
    bool fail = false;

    for (int i = cur.redPosition.first - 1; i >= 0; i--) {
        if (map[i][cur.redPosition.second] == '#') {
            nextRed = {i + 1, cur.redPosition.second};
            break;
        }

        else if (map[i][cur.redPosition.second] == 'O') {
            redHole = true; break;
        }
    }

    for (int i = cur.bluePosition.first - 1; i >= 0; i--) {
        if (map[i][cur.bluePosition.second] == '#') {
            nextBlue = {i + 1, cur.bluePosition.second};
            break;
        }

        else if (map[i][cur.bluePosition.second] == 'O') {
            blueHole = true; break;
        }
    }

    if(nextRed.first == nextBlue.first && nextRed.second == nextBlue.second) {
        if(cur.redPosition.first < cur.bluePosition.first)
            nextBlue.first++;
        else
            nextRed.first++;
    }


    if(redHole && !blueHole) {
        cout << 1;
        exit(0);
    }

    else if((redHole && blueHole) || (!redHole && blueHole))
        fail = true;

    if(!fail && !visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second]) {
        q.push({nextRed, nextBlue, cur.count + 1});
        visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second] = true;
    }
}

void moveDown(Condition cur, queue<Condition> &q) {
    pair<int, int> nextRed;
    pair<int, int> nextBlue;
    bool redHole = false;
    bool blueHole = false;
    bool fail = false;

    for (int i = cur.redPosition.first + 1; i < n; i++) {
        if (map[i][cur.redPosition.second] == '#') {
            nextRed = {i - 1, cur.redPosition.second};
            break;
        }

        else if (map[i][cur.redPosition.second] == 'O') {
            redHole = true;
            break;
        }
    }

    for (int i = cur.bluePosition.first + 1; i < n; i++) {
        if (map[i][cur.bluePosition.second] == '#') {
            nextBlue = {i - 1, cur.bluePosition.second};
            break;
        }

        else if (map[i][cur.bluePosition.second] == 'O') {
            blueHole = true;
            break;
        }
    }

    if(nextRed.first == nextBlue.first && nextRed.second == nextBlue.second) {
        if(cur.redPosition.first < cur.bluePosition.first)
            nextRed.first--;
        else
            nextBlue.first--;
    }


    if(redHole && !blueHole) {
        cout << 1;
        exit(0);
    }

    else if((redHole && blueHole) || (!redHole && blueHole))
        fail = true;

    if(!fail && !visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second]) {
        q.push({nextRed, nextBlue, cur.count + 1});
        visited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second] = true;
    }
}*/
