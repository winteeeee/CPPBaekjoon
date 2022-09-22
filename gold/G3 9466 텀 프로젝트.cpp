#include <iostream>
using namespace std;

int count;
bool selected = false;
void DFS(int cur, bool visited[], int student[], int start);
int main() {
    int t;
    cin >> t;

    for(int l = 0; l < t; l++) {
        int student[100001];
        bool visited[100001] = {false};
        count = 0;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> student[i];
        }

        for(int i = 1; i <= n; i++) {
            selected = false;
            if(!visited[i])
                DFS(i, visited, student, i);
        }

        cout << n - count << "\n";
    }

    return 0;
}

void DFS(int cur, bool visited[], int student[], int start) {
    visited[cur] = true;
    count++;

    if(student[cur] == start) {
        selected = true;
        return;
    }

    if(!visited[student[cur]]) {
        DFS(student[cur], visited, student, start);
    }

    if(!selected) {
        visited[cur] = false;
        count--;
    }
}