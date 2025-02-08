#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    unordered_map<long long, long long> rooms;
    unordered_map<long long, long long>::iterator it;
    vector<long long> answer;

    long long roomNum, now, nxt;
    vector<long long>childs;
    for (int i = 0; i < room_number.size(); i++) {
        roomNum = room_number[i];
        it = rooms.find(roomNum);
        if (it == rooms.end()) {
            rooms[roomNum] = roomNum + 1;
            answer.push_back(roomNum);
        }
        else {
            now = it->first;
            nxt = it->second;
            childs.push_back(now);
            while (rooms.find(nxt) != rooms.end()) {
                childs.push_back(nxt);
                nxt = rooms.find(nxt)->second;
            }
            rooms[nxt] = nxt + 1;
            for (auto child : childs)
                rooms[child] = nxt + 1;
            childs.clear();
            answer.push_back(nxt);
        }
    }

    return answer;
}