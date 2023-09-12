class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freq;
        for(auto letter : s){
            freq[letter]++;
        }

        vector<int> arr;
        for(auto it : freq){
            arr.push_back(it.second);
        }

        sort(arr.rbegin(), arr.rend());
        int max = arr[0], ans = 0;
        for(int i = 1; i < arr.size(); i++){
            if(max == 0){
                ans += arr[i];
            }else if(arr[i] == max){
                ans++;
                max = arr[i]-1;
            }else if(arr[i] > max){
                ans += arr[i] - max + 1;
                max = arr[i] - (arr[i] - max + 1);
            }else if(arr[i] < max){
                max = arr[i];
            }
        }

        
        // 4 1 1 1
        // 1 0 1
        // 1 += 1 - 0 + 1
        // 1 

        // "cc e bb aaa"
        //  3 2 2 1
        //  


        return ans;
    }
};