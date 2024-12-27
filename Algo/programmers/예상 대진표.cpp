#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    a-=1;
    b-=1;
    while( !(( (a&1) and (a-1==b) ) or ( !(a&1) and (a+1==b) )) ) {
        a = a>>1;
        b = b>>1;
        answer++;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << answer << endl;

    return answer;
}