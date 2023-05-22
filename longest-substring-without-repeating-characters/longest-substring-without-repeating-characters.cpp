class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        const int stringLength = s.size();
        
        int maxLength = 0, lastIdx = 0;
        unordered_map<char,int> charMap; 
        for(int currentIndex = 0; currentIndex < stringLength; ++currentIndex){
            if(charMap.find(s[currentIndex]) != charMap.end()){
                if(charMap[s[currentIndex]] >= lastIdx){
                    lastIdx = charMap[s[currentIndex]] + 1;
                }
                charMap[s[currentIndex]] = currentIndex;
            }else{
                charMap[s[currentIndex]] = currentIndex;
            }
            maxLength = max(maxLength, currentIndex - lastIdx + 1);
        }
        return maxLength;
    }
};
