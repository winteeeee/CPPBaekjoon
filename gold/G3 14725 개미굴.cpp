/*
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Node {
public:
    string id;
    vector<Node*> children;
    Node(string i) {
        id = i;
    }
};

int n;
Node root = {"root"};
stack<Node*> s;

void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int count;
        cin >> count;

        Node* curNode = &root;
        for (int j = 0; j < count; j++) {
            string temp;
            cin >> temp;

            bool isFind = false;
            for (int k = 0; k < curNode->children.size(); k++) {
                if (curNode->children[k]->id == temp) {
                    isFind = true;
                    curNode = curNode->children[k];
                    break;
                }
            }

            if (!isFind) {
                Node* newNode = new Node(temp);
                curNode->children.push_back(newNode);
                curNode = newNode;
            }
        }
    }
}

bool comparator(const Node* a, const Node* b) {
    return a->id < b->id;
}

void treePrint(Node* n) {
    sort(n->children.begin(), n->children.end(), comparator);

    for (int i = 0; i < n->children.size(); i++) {
        for (int j = 0; !s.empty() && j < s.size(); j++) {
            cout << "--";
        }
        cout << n->children[i]->id << '\n';
        s.push(n->children[i]);
        treePrint(n->children[i]);
        s.pop();
    }
}

void solve() {
    treePrint(&root);
}

int main() {
    input();
    solve();

    return 0;
}
*/
