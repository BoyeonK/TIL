#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> dp(15);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<i; j++){
            dp[i]+=dp[i-j-1]*dp[j];
        }
    }
    return dp[n];
}