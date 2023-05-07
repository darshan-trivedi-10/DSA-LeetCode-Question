bool lex_cmp(int &a, int &b) {
    string str_a = to_string(a);
    string str_b = to_string(b);  
    return str_a + str_b > str_b + str_a;
}

class Solution {    
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), lex_cmp);
        string ans = "";
        if(nums[0] == 0){
            return "0";
        }
        for(int i = 0; i < nums.size(); i++){
            ans = ans + to_string(nums[i]);
        }

        return ans;
    }
};