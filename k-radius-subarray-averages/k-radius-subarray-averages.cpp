class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        const int size = nums.size();

        int left = 0, right = 0;
        vector<int> averages(size, -1);

        long long front = 0, back = 0;

        for(int i = 0; i < k; i++){
            if(i < size){
                back += nums[i];
            }
        }

        for(int i = 0; i < size; i++){
            if(i > k){
                front += nums[i] - nums[i-k-1];
            }else{
                front += nums[i];
            }

            if(i + k < size){
                cout<<endl;
                // cout<<nums[i]<<" "<<nums[i+k]<<" "<<back<<" ";
                back = back - nums[i] + nums[i+k]; 
            }

            if(i >= k && i + k < size){
                // cout<<i<<" "<<front<<" "<<back<<endl;
                averages[i] = (front + back)/(2*k + 1);
            }

        }

        return averages;
    }
};