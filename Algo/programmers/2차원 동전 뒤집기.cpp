#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int answer = -1, mxi, mxj;
    mxi = target.size();
    mxj = target[0].size();
    
    vector<bool> bi, bj;
    for (int i = 0; i < mxi; i++)
        bi.push_back(beginning[i][0] == target[i][0]);
    for (int j = 0; j < mxj; j++)
        bj.push_back(beginning[0][j] == target[0][j]);

    int pi = 0, ci = 0;
    bool pure = true;
    bool change = true;
    for (int i = 0; i < mxi; i++)
        if (bi[i]) {
            pi += 1;
            ci += 1;
        }
    for (int j = 0; j < mxj; j++) {
        if (bj[j])
            pi += 1;
        else
            ci += 1;
    }
    pi = min(mxi + mxj - pi, pi);
    ci = min(mxi + mxj - ci, ci);

    bool is;
    for (int i = 0; i < mxi; i++) {
        for (int j = 0; j < mxj; j++) {
            is = (bi[i] == bj[j]);
            if(is != (beginning[i][j] == target[i][j]))
                pure = false;
            if (is == (beginning[i][j] == target[i][j]))
                change = false;
        }
    }
    if (pure)
        answer = pi;
    if (change)
        answer = ci;

    return answer;
}