#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> ItoN;
    vector<bool> ELlog;
    vector<string> IDlog;
    for(string& log:record) {
        string cmd;
        stringstream ss(log);
        string ID, Nickname;
        
        ss >> cmd >> ID;
        if (cmd == "Change") {
            ss >> Nickname;
            ItoN[ID] = Nickname;
        }
        else {
            IDlog.push_back(ID);
            if(cmd=="Enter") {
                ss >> Nickname;
                ELlog.push_back(true);
                ItoN[ID] = Nickname;
            }
            else
                ELlog.push_back(false);
        }
    }
    string E = "님이 들어왔습니다.", L = "님이 나갔습니다.";
    string ans;
    for(int i=0; i<ELlog.size(); i++) {
        if(ELlog[i])
            ans = ItoN[IDlog[i]] + E;
        else
            ans = ItoN[IDlog[i]] + L;
        answer.push_back(ans);
    }
    return answer;
}