class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<int,string> temp =  {{1,"High Card"}, {2,"Pair"},{3,"Three of a Kind"},
                                         {4,"Flush"}};
        
        char ch = suits[0];
        int rank = 0, suit = 0;
        int arr[14] = {0};
        
        for(int i = 0; i<ranks.size(); i++){
            if(suits[i]==ch){
                suit++;
            }
            
            arr[ranks[i]]++;
            rank = max(rank, arr[ranks[i]]);
        }
        
        if(suit==5){
            return "Flush";
        }
        
        if(rank>=3){
            return "Three of a Kind";
        }
        
        return rank==2?"Pair":"High Card";
    }
};