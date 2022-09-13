#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<int, int>> cord;
vector<bool> picked;
double minV = 0;

double getSize(pair<int, int> a, pair<int, int> b);
void dfs(int start, int cur, int n);
int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        minV = 0;
        int n;
        scanf("%d", &n);

        for(int j = 0; j < n; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            cord.push_back({x, y});
            picked.push_back(false);
        }

        dfs(0, 0, 2 / n);
        printf("%lf\n", minV);
    }

    return 0;
}

void dfs(int start, int cur, int n) {
    if(cur == n) {
        int sumOfX = 0;
        int sumOfY = 0;
        for(int i = 0; i < cord.size(); i++) {
            if(picked[i]) {
                sumOfX += cord[i].first;
                sumOfY += cord[i].second;
            }

            else {
                sumOfX -= cord[i].first;
                sumOfY -= cord[i].second;
            }
        }

        double temp = getSize({0, 0}, {sumOfX, sumOfY});

        if(minV > temp)
            minV = temp;
    }

    for(int i = start; i < cord.size(); i++) {
        picked[i] = true;
        dfs(i + 1, cur + 1, n);
        picked[i] = false;
    }
}

double getSize(pair<int, int> a, pair<int, int> b) {
    int xDiffer = abs(a.first - b.first);
    int yDiffer = abs(a.second - b.second);
    xDiffer = pow(xDiffer, 2);
    yDiffer = pow(yDiffer, 2);

    return sqrt(xDiffer + yDiffer);
}
