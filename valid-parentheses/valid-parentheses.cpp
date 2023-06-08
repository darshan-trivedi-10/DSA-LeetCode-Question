class Solution {
public:
    bool isValid(const std::string& str) {
        int size = str.size();
        std::stack<char> brackets;
        std::unordered_map<char, char> matchingBrackets = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (int i = 0; i < size; i++) {
            char currentChar = str[i];
            if (isOpeningBracket(currentChar)) {
                brackets.push(currentChar);
            } else {
                if (brackets.empty()) {
                    return false;
                }
                char topChar = brackets.top();
                if (matchingBrackets[currentChar] != topChar) {
                    return false;
                }
                brackets.pop();
            }
        }

        return brackets.empty();
    }

private:
    bool isOpeningBracket(char ch) {
        return ch == '(' || ch == '{' || ch == '[';
    }
};
