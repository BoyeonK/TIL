class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int answer = 0;
        
        if (n == 1) {
            answer = 1;
        }
        else {
            vector<int> ref(n);
            vector<vector<int>>grp(n);
    
            for (int i = 0; i < n-1; i++) {
                if (ratings[i] > ratings[i + 1]) {
                    ref[i]++;
                    grp[i + 1].push_back(i);
                }  
                else if (ratings[i + 1] > ratings[i]) {
                    ref[i + 1]++;
                    grp[i].push_back(i + 1);
                }      
            }

            queue<int> Q;
            vector<int> v;
            int candy = 1;
            for (int i = 0; i < n; i++) {
                if (ref[i] == 0) {
                    Q.push(i);
                }
            }
            while (!Q.empty()) {
                while (!Q.empty()) {
                    v.push_back(Q.front());
                    Q.pop();
                }
                for (auto idx : v) {
                    answer += candy;
                    for (auto e : grp[idx]) {
                        ref[e]--;
                        if (ref[e] == 0)
                            Q.push(e);
                    }
                }
                v.clear();
                candy += 1;
            }
        }
        return answer;
    }
};