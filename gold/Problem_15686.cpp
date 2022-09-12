#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int chickenDistanceOfCity = 0;
int result = INT_MAX;
vector<pair<int, int>> house;
vector<pair<int, int>> chickenHouse;
vector<pair<int, int>> surviveChickenHouse;

int findChickenDistance(int r, int c);
void shutDown(int shutDownCount, int idx, int m) {
    if(shutDownCount == m) {
        for(int i = 0; i < house.size(); i++) {
            int houseR = house.at(i).first;
            int houseC = house.at(i).second;
            chickenDistanceOfCity += findChickenDistance(houseR, houseC);
        }

        if(result > chickenDistanceOfCity) {
            result = chickenDistanceOfCity;
        }
        chickenDistanceOfCity = 0;
        return;
    }

    for(int i = idx; i < chickenHouse.size(); i++) {
        int curR = chickenHouse.at(i).first;
        int curC = chickenHouse.at(i).second;
        surviveChickenHouse.push_back(make_pair(curR, curC));
        shutDown(shutDownCount + 1, i + 1, m);
        surviveChickenHouse.pop_back();
    }
}

int findChickenDistance(int r, int c) {
    int chickenDistance = INT_MAX;

    for(int i = 0; i < surviveChickenHouse.size(); i++) {
        int curR = surviveChickenHouse.at(i).first;
        int curC = surviveChickenHouse.at(i).second;
        chickenDistance = min(chickenDistance, abs(r - curR) + abs(c - curC));
    }

    return chickenDistance;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int chickenHouseCount = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int temp;
            scanf("%d", &temp);

            if(temp == 2) {
                chickenHouse.push_back(make_pair(i, j));
                chickenHouseCount++;
            }

            else if (temp == 1)
                house.push_back(make_pair(i, j));
        }
    }

    shutDown(0, 0, m);
    printf("%d", result);

    return 0;
}