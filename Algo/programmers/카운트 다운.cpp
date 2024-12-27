#include <string>
#include <vector>

using namespace std;

vector<int> solution(int target) {
    vector<int> seq(target + 1, -1);
    vector<int> score(target + 1);
    seq[0] = 0;
    vector<int> s;
    vector<int> d{ 21,22,24,26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 51, 54, 57, 60 };
    for (int i = 1; i <= 20; i++)
        s.push_back(i);
    s.push_back(50);
    for (auto i : s) {
        if (i > target)
            break;
        seq[i] = 1;
        score[i] = 1;
    }
    for (auto i : d) {
        if (i > target)
            break;
        seq[i] = 1;
        score[i] = 0;
    }
    int idx = 0, nseq, nscore;
    while (seq[target] == -1) {
        idx++;
        if (seq[idx] != -1)
            continue;
        nseq = 100000;
        for (int i : s) {
            if (idx - i < 0)
                break;
            if (nseq < seq[idx - i])
                continue;
            else if (nseq == seq[idx - i]) {
                if ((score[idx - i] + 1) > nscore)
                    nscore = score[idx - i] + 1;
            }
            else {
                nseq = seq[idx - i];
                nscore = score[idx - i] + 1;
            }
        }
        for (int i : d) {
            if (idx - i < 0)
                break;
            if (nseq < seq[idx - i])
                continue;
            else if (nseq == seq[idx - i]) {
                if (score[idx - i] > nscore)
                    nscore = score[idx - idx];
            }
            else {
                nseq = seq[idx - i];
                nscore = score[idx - i];
            }

        }
        seq[idx] = nseq + 1;
        score[idx] = nscore;
    }
    vector<int> answer;
    answer = { seq[target], score[target] };
    return answer;
}