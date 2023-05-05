class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(), str.end());

        string first = str[0], last = str[str.size()-1];

        string common_prefix = "";
        for(int i = 0; i<first.size(); i++){
            if(first[i]==last[i]){
                common_prefix.push_back(first[i]);
            }else{
                break;
            }
        }

        return common_prefix;
    }
};