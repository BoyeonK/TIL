#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int sO = money[0]+money[2];
    int sX = money[0];
    
    int eO = money[2];
    int eX = money[1];


    int size = money.size();
    int sNO, sNX, eNO, eNX;
    for (int i = 3; i < size-1; i++) {
        sNO = sX + money[i];
        sNX = max(sX, sO);

        eNO = eX + money[i];
        eNX = max(eX, eO);

        sO = sNO;
        sX = sNX;
        eO = eNO;
        eX = eNX;
    }
    if (size > 3) {
        eX += money[size - 1];
    }
    int s = max(sO, sX);
    int e = max(eO, eX);
    return max(s, e);
}