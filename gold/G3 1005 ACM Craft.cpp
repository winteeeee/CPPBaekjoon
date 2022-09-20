/*
#include <iostream>
#include <vector>
#include <stack>
#include <memory.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        int n, k;
        scanf("%d %d", &n, &k);

        int buildingTime[n + 1];
        int sumOfBuildTime[n + 1];
        for(int j = 1; j <= n; j++) {
            scanf("%d", &buildingTime[j]);
            sumOfBuildTime[j] = buildingTime[j];
        }

        vector<int> buildOrder[n + 1];
        vector<int> buildOrderReverse[n + 1];
        int inDegree[n + 1];
        memset(inDegree, 0, sizeof(inDegree));
        for(int j = 0; j < k; j++) {
            int temp, temp2;
            scanf("%d %d", &temp, &temp2);
            buildOrder[temp].push_back(temp2);
            buildOrderReverse[temp2].push_back(temp);
            inDegree[temp2]++;
        }

        int w;
        scanf("%d", &w);

        vector<int> start;
        for(int j = 1; j <= n; j++) {
            if(inDegree[j] == 0) {
                start.push_back(j);
            }
        }

        for(int j = 0; j < start.size(); j++) {
            stack<int> s;
            s.push(start.at(j));
            while (!s.empty()) {
                int curIdx = s.top();
                s.pop();
                int maxTime = 0;
                for (int k = 0; k < buildOrderReverse[curIdx].size(); k++) {
                    int revereIdx = buildOrderReverse[curIdx].at(k);
                    maxTime = max(maxTime, sumOfBuildTime[revereIdx]);
                }
                sumOfBuildTime[curIdx] = maxTime + buildingTime[curIdx];

                for (int k = 0; k < buildOrder[curIdx].size(); k++) {
                    int nextIdx = buildOrder[curIdx].at(k);
                    inDegree[nextIdx]--;

                    if (inDegree[nextIdx] == 0) {
                        s.push(nextIdx);
                    }
                }
            }
        }
        printf("%d\n", sumOfBuildTime[w]);
    }

    return 0;
}*/
