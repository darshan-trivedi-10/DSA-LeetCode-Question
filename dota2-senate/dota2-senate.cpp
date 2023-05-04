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