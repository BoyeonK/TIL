#include <string>
#include <vector>

using namespace std;

vector<int> sel;
vector<int> nsel;
vector<vector<int>> grp;

void dfs(int nodenum) {
    vector<int> sels;
    vector<int> nsels;
    int mnm = 2147483647;
    for (int i : grp[nodenum]) {
        dfs(i);
        sels.push_back(sel[i]);
        nsels.push_back(nsel[i]);
    }
    for (int i = 0; i < sels.size(); i++) {
        sel[nodenum] += min(sels[i], nsels[i]);
        nsel[nodenum] += min(sels[i], nsels[i]);
        if (mnm > (sels[i]-nsels[i]))
            mnm = sels[i] - nsels[i];
    }
    if (mnm > 0 and !grp[nodenum].empty())
        nsel[nodenum] += mnm;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int n = sales.size();
    sel.resize(n + 1);
    nsel.resize(n + 1);
    grp.resize(n + 1);
    for (auto&l : links)
        grp[l[0]].push_back(l[1]);
    for (int i = 0; i < n; i++)
        sel[i + 1] = sales[i];
    dfs(1);
    int answer = min(sel[1], nsel[1]);
    return answer;
}