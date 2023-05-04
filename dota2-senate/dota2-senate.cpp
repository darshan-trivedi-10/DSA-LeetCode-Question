// Solution 1

class Solution {
public:
    string predictPartyVictory(string senate) {
        const int n = senate.size();
        queue<int> dqueue, rqueue;

        for(int i = 0; i < n; i++){
            char ch = senate[i];
            if(ch=='R'){
                rqueue.push(i);
            }else{
                dqueue.push(i);
            }
        }

        while(!dqueue.empty() && !rqueue.empty()){
            int rTurn = rqueue.front(), dTurn = dqueue.front();
            rqueue.pop(), dqueue.pop();

            if(rTurn < dTurn){
                rqueue.push(rTurn + n);
            }else{
                dqueue.push(dTurn + n);
            }

        }

        return rqueue.empty() ? "Dire" : "Radiant";
    }
};

// Solution 2
class Solution {
public:
    string predictPartyVictory(string senate) {

        const string DIRE = "Dire", RADIANT = "Radiant";
        const int n = senate.size();
        
        int rCount = 0, dCount = 0, rBan = 0, dBan = 0;
        queue<char> q;
        for(int i = 0; i < n; i++){
            q.push(senate[i]);
            senate[i]=='R' ? rCount++ : dCount++;
        }

        while(rCount>0 && dCount>0){
            char ch = q.front();
            q.pop();

            if(ch == 'R'){
                if(rBan){
                    rBan--;
                    rCount--;
                }else{
                    dBan++;
                    q.push('R');
                }
            }else{
                if(dBan){
                    dBan--;
                    dCount--;
                }else{
                    rBan++;
                    q.push('D');
                }
            }

        }

        return rCount > 0 ? RADIANT : DIRE;
    }
};
