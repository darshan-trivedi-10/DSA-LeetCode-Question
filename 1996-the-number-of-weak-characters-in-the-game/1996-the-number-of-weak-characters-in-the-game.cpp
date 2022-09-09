class Solution {
    
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {              
        int n = properties.size(), ans = 0;
        sort(properties.begin(), properties.end(), cmp);
        
        int maxDefense = INT_MIN;
        for(int i = n-1; i>=0; i--){
            int currDefence = properties[i][1];
            if(currDefence<maxDefense){  
                ans++;
            }
            maxDefense = max(maxDefense, currDefence);
        }        
        return ans;
    }
};