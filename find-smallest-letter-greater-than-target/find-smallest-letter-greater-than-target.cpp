class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char greaterLetter = letters[0];
        for(auto ch : letters){
            if(ch > target){
                greaterLetter = ch;
                break;
            }
        }

        return greaterLetter;
    }
};