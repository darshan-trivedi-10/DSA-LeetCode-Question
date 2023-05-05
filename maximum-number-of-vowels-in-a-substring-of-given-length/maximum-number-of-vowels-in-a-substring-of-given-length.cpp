// Solution 1 - O(N), O(N)
class Solution {
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'); 
    }
public:
    int maxVowels(string s, int k) {
        const int n = s.size();
        
        vector<int> vowelCount(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(isVowel(s[i])){
                if(i==0){
                    vowelCount[i] = 1;
                }else{
                    vowelCount[i] += vowelCount[i-1] + 1;
                }
            }else{
                if(i != 0){
                    vowelCount[i] += vowelCount[i-1];
                }
            }
            if(i < k){
                ans = max(ans, vowelCount[i]);
            }else{
                ans = max(ans, vowelCount[i] - vowelCount[i-k]);
            }
        }

        return ans;
    }
};

// Solution 2 - O(N), O(1)
class Solution {
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'); 
    }
public:
    int maxVowels(string s, int k) {
        int vowelCount = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                vowelCount++;
            }
            if(i >= k && isVowel(s[i-k])){
                vowelCount--;
            }
            if(i >= k-1){
                ans = max(ans, vowelCount);
            }
        }
        return ans;
    }
};
