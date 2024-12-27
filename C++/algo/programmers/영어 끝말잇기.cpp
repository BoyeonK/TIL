#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, bool> WtoB;
    int idx=0;
    char lw = 'A';
    for(string& word:words){
        if(WtoB[word] or (word[0] != lw and idx!=0))
            break;
        WtoB[word] = true;
        lw = word[word.size()-1];
        idx++;
    }
    int num=0, seq=0;
    if (idx!=words.size()) {
        num=(idx+1)%n;
        if(!num) num=n;
        seq = (idx/n) + 1;
    }
    answer.push_back(num);
    answer.push_back(seq);
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    cout << "[" <<num << ", " << seq<< "]" << endl;

    return answer;
}