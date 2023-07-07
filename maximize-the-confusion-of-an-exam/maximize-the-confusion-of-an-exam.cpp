class Solution {

    int findMax(string &s, int n, int k, char ch){
        
        int left = 0, right = 0, ans = 0;
        while(right < n){

            if(k <= 0 && s[right] == ch){
                while(left < right){
                    if(s[left] == ch){
                        left++, k++;
                        break;
                    }
                    left++;
                }
            }

            if(k > 0 && s[right] == ch){
                cout<<"TRUE\n";
                k--;
            }

            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }

public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        return max(findMax(s, n, k, 'T'), findMax(s, n, k, 'F'));
    }
};