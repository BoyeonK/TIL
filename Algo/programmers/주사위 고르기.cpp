#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Dice;
int N, R, total = 1;
int mxmwin = 0;
unsigned int mxmbit = 0;

void cal(unsigned int bit) {
    unsigned int T;
    vector<int> empty(501);
    vector<int> myP(501);
    vector<int> opP(501);
    vector<int> myN(501);
    vector<int> opN(501);
    myP[0] = 1;
    opP[0] = 1;
    for (int i = 0; i < N; i++) {
        T = (1 << i);
        if (bit & T) {
            for (int j = 0; j <= 500; j++) {
                if (myP[j]) {
                    for (auto a : Dice[i]) {
                        myN[j + a] += myP[j];
                    }
                }
            }
            myP = myN;
            myN = empty;
        }
        else {
            for (int j = 0; j <= 500; j++) {
                if (opP[j]) {
                    for (auto a : Dice[i]) {
                        opN[j + a] += opP[j];
                    }
                }
            }
            opP = opN;
            opN = empty;
        }
    }
    int win = 0;
    vector<int> acop(501);
    for (int i = 1; i <= 500; i++) {
        acop[i] = acop[i - 1] + opP[i];
    }
    for (int i = 0; i <= 500; i++) {
        if (myP[i]) {
            win += myP[i] * (acop[i] - opP[i]);
        }
    }
    if (win > mxmwin) {
        mxmwin = win;
        mxmbit = bit;
    }
}

void comb(unsigned int bit, int r, int seq) {
    if (R == r) {
        cal(bit);
        return;
    }
    if (R - r > N - seq)
        return;
    comb(bit | (1 << seq), r + 1, seq + 1);
    comb(bit, r, seq + 1);
}

vector<int> solution(vector<vector<int>> dice) {
    N = dice.size();
    R = N / 2;
    Dice = dice;
    for (int i = 0; i < R; i++)
        total = total * 6;
    comb(0, 0, 0);
    vector<int> answer;
    unsigned int bit = 1;
    for (int i = 0; i < N; i++) {
        if ((bit << i) & mxmbit) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}