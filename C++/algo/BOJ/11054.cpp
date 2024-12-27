#include <iostream>

using namespace std;

int main() {
    int N, mxm=0, now;
    cin >> N;
    int arr[N], DP[N], PD[N];
    for(int i=0; i<N; i++) cin >> arr[i];
    for(int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i]>arr[j] && DP[j]>mxm) mxm=DP[j];
        }
        DP[i] = mxm+1;
        mxm=0;
    }
    for(int i=N-1; i>=0; i--) {
        for (int j=N-1; j>i; j--) {
            if (arr[i]>arr[j] && PD[j]>mxm) mxm=PD[j];
        }
        PD[i] = mxm+1;
        mxm=0;
    }
    for(int i=0; i<N; i++) {
        now = DP[i] + PD[i];
        if (now > mxm) mxm = now;
    }
    cout << mxm-1;
}