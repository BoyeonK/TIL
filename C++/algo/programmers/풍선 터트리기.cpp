#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int n=a.size();
    int r=2147483647, l=2147483647;
    vector<int> R(n);
    vector<int> L(n);
    for(int i=0; i<n; i++) {
        if(l > a[i]) l = a[i];
        if(r > a[n-1-i]) r = a[n-1-i];
        L[i] = l;
        R[n-i-1] = r;
    }
    int answer=0;
    for (int i=0; i<n; i++){
        if(L[i] == a[i] or R[i] ==a[i]) answer+=1;
    }
    return answer;
}