#include <string>
#include <vector>
#include <map>

using namespace std;

int answer = 0;

class Node {
public:
    Node(bool isLast) : _isLast(isLast) { }
    ~Node() {
        for (auto p : _childs)
            delete p.second;
    }
    void changeToLast() {
        _isLast = true;
    }
    void beCounted() {
        _count = true;
    }
    Node* addNew(char c, bool isLast) {
        if (_childs.find(c) == _childs.end()) {
            Node* pN = new Node(isLast);
            _childs[c] = pN;
        }
        else {
            _childs[c]->beCounted();
            if (isLast) _childs[c]->changeToLast();
        }
        return _childs[c];
    }
    void solve(int key) {
        if (_isLast)
            answer += key;
        if (_count)
            key++;
        for (auto p : _childs)
            p.second->solve(key);
    }
private:
    bool _count = false;
    bool _isLast;
    map<char, Node*> _childs;
};

Node* pTopNode = new Node(false);

void dfs(string& word, Node* pN, int idx, int n) {
    if (idx == n)
        return;
    char c = word[idx];
    bool isLast = (idx == n - 1) ? true : false;
    dfs(word, pN->addNew(c, isLast), idx + 1, n);
}

int solution(vector<string> words) {
    for (auto word : words)
        dfs(word, pTopNode, 0, word.size());
    pTopNode->solve(1);
    delete pTopNode;
    return answer;
}