#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    string name;
    vector<Node> child;
    int depth;

    int findChildIdx(const string& n) const {
        for (int i = 0; i < child.size(); i++) {
            if (child[i].name == n) {
                return i;
            }
        }

        return -1;
    }
};

int n;
Node root = {"root", {}, 0};

void input();
void makeTree();
void printTree(const Node& node);

int main() {
    /*
     * [풀이]
     * 딱히 풀이랄 것도 없이 트리를 만들고 DFS로 순회하는 문제
     * 사전순으로 정렬해야하는 조건도 있는데 그냥 적절한 때에 sort 쓰면 된다.
     *
     * 이런 식의 자료구조 문제가 그렇듯 진짜 삽질을 하는게 아닌 이상 시간초과는 나지 않는다.
     * 시간복잡도는 자세히 계산해보진 않았지만 sort가 들어가있어서 O(NlogN) 일듯
     */

    input();
    makeTree();
    printTree(root);

    return 0;
}

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
}

int cmp(const Node& a, const Node& b) {
    return a.name < b.name;
}

void process(Node& node, const vector<string>& names, int vectorIdx) {
    if (vectorIdx >= names.size()) {
        return;
    }

    int idx = node.findChildIdx(names[vectorIdx]);
    if (idx != -1) {
        process(node.child[idx], names, ++vectorIdx);
    } else {
        node.child.push_back({names[vectorIdx], {}, node.depth + 1});
        process(node.child[node.child.size() - 1], names, ++vectorIdx);
        sort(node.child.begin(), node.child.end(), cmp);
    }
}

void makeTree() {
    string path;
    for (int i = 0; i < n; i++) {
        cin >> path;

        istringstream iss(path);
        string buffer;
        vector<string> names;

        while (getline(iss, buffer, '\\')) {
            names.push_back(buffer);
        }

        process(root, names, 0);
    }
}

void printTree(const Node& node) {
    for (int i = 0; i < node.depth - 1; i++) {
        cout << ' ';
    }

    if (node.name != "root")
        cout << node.name << '\n';

    for (const Node& c : node.child) {
        printTree(c);
    }
}