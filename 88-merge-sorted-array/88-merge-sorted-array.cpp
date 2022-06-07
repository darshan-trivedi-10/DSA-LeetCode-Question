class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        
        while(j<n){
            nums1[m+j] = nums2[j];
            j++;
        }
        
        sort(nums1.begin(),nums1.end());
        
    }
};