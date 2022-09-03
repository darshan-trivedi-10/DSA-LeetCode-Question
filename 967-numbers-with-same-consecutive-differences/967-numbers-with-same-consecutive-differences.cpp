class Solution {
    
    vector<int> ans;
    
    void Solve(int len , int &k , int num, int digit)
    {
        // Base Case
        if(len == 0 )
        {
                ans.push_back(num);
           return ;
        }
        
        // Next Possible digits will have range from 0 - 9
        for(int i = 0 ; i<10 ; i++)
        {
            // Checking for given condition 
            if(abs(i-digit) == k)
                Solve(len-1 , k, num*10 + i, i);
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        
        // First Digit will have range from  1 - 9 
        // We have passed digit as 4th variable to have the last inserted digit
        for(int i = 1 ; i<=9 ; i++)
        {
             Solve(n-1 , k, i, i);
        }
        
        return ans;
        
		// Pls Upvote If You Like It !!
    }
};
