class Solution {

    int devide(int start, int end, int k, string &str){

        if(start >= end){
            return 0;
        }

        map<char,int> freq;
        for(int i = start; i < end; i++){
            if(start == 0 && end == 5){
                cout<<str[i]<<" ";
            }
            freq[str[i]]++;
        }
        
        // bbaaa, 
        // 2 , 3

        if(start == 0 && end == 5){
            cout<<"Hey\n";
            for(auto ele : freq){
                cout<<ele.first<<" "<<ele.second<<endl;
            }
        }

        // bb aaa, k = 2
        // 

        int last = start, ans = 0;
        for(int i = start; i < end; i++){
            if(freq[str[i]] < k){
                ans = max(devide(last, i, k, str),ans);
                last = i + 1;
            }
        }

        if(last != start){
            ans = max(devide(last, end, k, str),ans);
        }

        if(last == start){
            return end - start;
        }

        return ans;
    }

public:
    int longestSubstring(string s, int k) {
        const int size = s.size();

        return devide(0, size, k, s);

        /*
        count = 0, map [char, freq]
        abbbbc, k = 2
        a -> 1, 1
        b -> 1, 2
        c -> 2, 3
        b -> 2, 4
        frqu, less than k 
        k = 2
        b cc a c b a b

        */
    
    }
};