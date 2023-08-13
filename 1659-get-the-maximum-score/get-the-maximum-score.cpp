class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long s1 = 0, s2 = 0;
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();

        long res = 0;
        while(i < n and j < m){
            if(nums1[i] < nums2[j]){
                s1 += nums1[i];
                i++;
            }else if(nums2[j] < nums1[i]){
                s2 += nums2[j];
                j++;
            }else{
                res += max(s1, s2) + nums1[i];
                i++, j++;
                s1 = 0, s2 = 0;
            }
        }


        while(i < n){
            s1 += nums1[i];
            i++;
        }

        while(j < m){
            s2 += nums2[j];
            j++;
        }

        return (max(s1, s2) + res) % 1000000007;
    }
};