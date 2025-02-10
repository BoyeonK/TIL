#include <string>
#include <vector>

using namespace std;

vector<int> deck;
int N;

int solution(int coin, vector<int> cards) {
    N = cards.size();
    vector<bool> hand(N + 1);
    vector<bool> subhand(N + 1);
    int decktop = N / 3;
    int turn = 1;
    int alive = 1;
    for (int i = 0; i < decktop; i++)
        hand[cards[i]] = true;

    for (int i = 0; i < N / 2; i++) {
        if (hand[i + 1] and hand[N - i])
            alive += 1;
    }

    while (true) {
        if (decktop >= N)
            break;
        alive -= 1;

        int draw = cards[decktop];
        if (hand[N + 1 - draw] and coin) {
            alive++;
            coin--;
            hand[draw] = true;
        }
        else {
            subhand[draw] = true;
        }
        decktop++;
        draw = cards[decktop];
        if (hand[N + 1 - draw] and coin) {
            alive++;
            coin--;
            hand[draw] = true;
        }
        else {
            subhand[draw] = true;
        }
        decktop++;

        if (alive == 0) {
            if (coin < 2)
                break;
            else {
                for (int i = 0; i <= N/2; i++) {
                    if (subhand[i] == true and subhand[N + 1 - i] == true) {
                        coin -= 2;
                        alive += 1;
                        subhand[i] = false;
                        subhand[N + 1 - i] = false;
                        break;
                    }
                }
                if (alive == 0)
                    break;
            }
        }
        turn += 1;
    }
    return turn;
}