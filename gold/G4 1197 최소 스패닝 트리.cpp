/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge {
private:
    pair<int, int> vertex;
    int weight;

public:
    Edge(pair<int, int> v, int w) {
        vertex = v;
        weight = w;
    }

    pair<int, int> getVertex() {
        return vertex;
    }

    int getWeight() {
        return weight;
    }
};

class Weight {
public:
    bool operator()(Edge a, Edge b) {
        return a.getWeight() > b.getWeight();
    }
};

void addMST(int a, int b, int MST[]);
int find(int a, int MST[]);
bool isCycle(int a, int b, int MST[]);
int main() {
    int v, e, sumOfWeight;
    scanf("%d %d", &v, &e);

    priority_queue<Edge, vector<Edge>, Weight> h;
    int MST[10001];
    for(int i = 1; i < 10001; i++) {
        MST[i] = i;
    }

    for(int i = 0; i < e; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        h.push({{a, b}, c});
    }

    while(!h.empty()) {
        Edge cur = h.top(); h.pop();
        int firstVertex = cur.getVertex().first;
        int secondVertex = cur.getVertex().second;

        if(!isCycle(firstVertex, secondVertex, MST)) {
            addMST(firstVertex, secondVertex, MST);
            sumOfWeight += cur.getWeight();
        }
    }

    printf("%d", sumOfWeight);
    return 0;
}

void addMST(int a, int b, int MST[]) {
    int parentA = find(a, MST);
    int parentB = find(b, MST);

    if(parentA < parentB)
        MST[parentB] = parentA;

    else
        MST[parentA] = parentB;
}

int find(int a, int MST[]) {
    if(a == MST[a])
        return a;
    else
        return find(MST[a], MST);
}

bool isCycle(int a, int b, int MST[]) {
    int parentA = find(a, MST);
    int parentB = find(b, MST);

    return parentA == parentB;
}*/
