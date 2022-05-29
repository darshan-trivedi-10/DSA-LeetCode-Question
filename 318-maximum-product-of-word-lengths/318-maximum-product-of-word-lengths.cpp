class Solution {
    void setBit(int &num, int ind){
        num = num | (1<<ind);
    }
    
public:
    int maxProduct(vector<string>& arr) {
        int n = arr.size();
        int mask[n];
        memset(mask, 0, sizeof mask);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<arr[i].size(); j++){
                int ind = (int(arr[i][j]-'a'));
                setBit(mask[i], ind);
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if((mask[i]&mask[j])==0){
                    if((arr[i].size()*arr[j].size())>ans){
                        ans = arr[i].size()*arr[j].size();
                    }
                }
            }
        }
        
        return ans;
        
        
        
        
        
        
        return 5;
        
        
        
        
        
        
    }
};