#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <climits>

using namespace std;

/*
 * tag, id순 입력
 * 인접리스트 생성 후 인접리스트 별로 정렬
 */

const int MAX_NEWS = 10000;
const int MAX_CLUSTER = 100;

vector<int> newsList;
vector<int> answerIdTagList(MAX_NEWS);
vector<int> targetIdTagList(MAX_NEWS);
vector<vector<int>> answerTagIdList(MAX_CLUSTER);
vector<vector<int>> targetTagIdList(MAX_CLUSTER);
bool visited[MAX_NEWS][MAX_NEWS];
int answerTagCount = 0;
int minId = INT_MAX;

void findMinVal(string path[]) {
    ifstream inStream;
    inStream.open(path[0]);

    while (!inStream.eof()) {
        int tag, id;
        inStream >> tag >> id;
        minId = min(minId, id);
    }
}

void input(string path[]) {
    ifstream inStream;

    inStream.open(path[0]);
    while (!inStream.eof()) {
        int tag, id;
        inStream >> tag >> id;

        answerTagCount = max(answerTagCount, tag);
        newsList.push_back(id - minId);
        answerIdTagList[id - minId] = tag;
        answerTagIdList[tag + 1].push_back(id - minId);
    }
    inStream.close();

    inStream.open(path[1]);
    while (!inStream.eof()) {
        int tag, id;
        inStream >> tag >> id;

        targetIdTagList[id - minId] = tag;
        targetTagIdList[tag + 1].push_back(id - minId);
    }
    inStream.close();
}

void run() {
    int tp = 0;
    int fp = 0;
    int tn = 0;
    int fn = 0;

    double answerEdgeCount = 0;
    double equalEdgeCount = 0;
    
    for (int i = 0; i <= answerTagCount; i++) {
        double vertexes = answerTagIdList[i].size();
        if (vertexes == 2) {
            answerEdgeCount++;
        } else if (vertexes > 2) {
            answerEdgeCount += (vertexes + (vertexes * (vertexes - 3)) / 2);
        }
    }

    for (int id : newsList) {
        int answerTag = answerIdTagList[id];
        int targetTag = targetIdTagList[id];

        if (answerTag == -1 && targetTag == -1) {
            tn++;
        } else if (answerTag == -1) {
            fp++;
        }

        bool find = false;
        for (int answerDestId: answerTagIdList[answerTag + 1]) {
            for (int targetDestId: targetTagIdList[targetTag + 1]) {
                if (targetDestId == answerDestId) {
                    if (id != targetDestId && !visited[id][targetDestId]) {
                        visited[id][targetDestId] = true;
                        visited[targetDestId][id] = true;
                        equalEdgeCount++;
                        find = true;
                    }
                    break;
                }
            }
        }

        if (find) {
            tp++;
        } else {
            fn++;
        }
    }

    cout << equalEdgeCount / answerEdgeCount << '\n';
    cout << setw(5) << tp << "   " << setw(5) << fn << '\n';
    cout << setw(5) << fp << "   " << setw(5) << tn << '\n';
}

int main() {
    string path[2];

    cout << "Answer File Name : ";
    cin >> path[0];
    cout << "Target File Name : ";
    cin >> path[1];

    findMinVal(path);
    input(path);
    run();

    return 0;
}
