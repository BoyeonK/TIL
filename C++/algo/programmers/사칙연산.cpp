#include <vector>
#include <string>
using namespace std;

vector<vector<int>> mxm;
vector<vector<int>> mnm;
vector<bool> ops;

int dpmnm(int l, int r);

int dpmxm(int l, int r) {
    if (mxm[l][r] != -2147483647)
        return mxm[l][r];
    for (int i = l; i < r; i++) {
        int nxt = (ops[i]) ? dpmxm(l, i) + dpmxm(i + 1, r) : dpmxm(l, i) - dpmnm(i + 1, r);
        mxm[l][r] = max(mxm[l][r], nxt);
    }
    return mxm[l][r];
}

int dpmnm(int l, int r) {
    if (mnm[l][r] != 2147483647)
        return mnm[l][r];
    for (int i = l; i < r; i++) {
        int nxt = (ops[i]) ? dpmnm(l, i) + dpmnm(i + 1, r) : dpmnm(l, i) - dpmxm(i + 1, r);
        mnm[l][r] = min(mnm[l][r], nxt);
    }
    return mnm[l][r];
}

int solution(vector<string> arr) {
    int n = (arr.size() + 1) / 2;
    for (int i = 0; i < n; i++) {
        vector<int> a(n, -2147483647);
        vector<int> b(n, 2147483647);
        mxm.push_back(a);
        mnm.push_back(b);
    }
    vector<int> nums;
    nums.push_back(stoi(arr[0]));
    for (int i = 1; i < n; i++) {
        nums.push_back(stoi(arr[2 * i]));
        ops.push_back(arr[2 * i - 1] == "+");
    }
    for (int i = 0; i < n; i++) {
        mxm[i][i] = nums[i];
        mnm[i][i] = nums[i];
    }
    int answer = dpmxm(0, n - 1);
    return answer;
}