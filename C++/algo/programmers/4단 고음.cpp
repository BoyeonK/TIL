// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
#include <cmath>

int nn = 0;

void dfs(int star, int platina, int oraora) {
    if (oraora < pow(3, (platina - 2 * star) / 2))
        return;
    if (star * 2 > platina)
        return;
    if (oraora < 3)
        return;

    if (oraora == 3 and (star + 1) * 2 == platina) {
        nn += 1;
        return;
    }
    if ((oraora % 3) == 0)
        dfs(star + 1, platina, oraora / 3);
    dfs(star, platina + 1, oraora - 1);
}

int solution(int n) {
    nn=0;
    dfs(0, 2, n - 2);
    return nn;
}