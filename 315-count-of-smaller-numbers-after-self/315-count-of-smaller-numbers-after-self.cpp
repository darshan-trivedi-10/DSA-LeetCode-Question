class Solution {
    
    void merge(vector<pair<int,int>> &v,vector<int> &count, int  l, int mid, int r){
        
        vector<pair<int,int>> temp(r-l+1);
        int i = l;
        int j = mid+1;
        int k = 0;
        
        while(i<=mid and j<=r){
            if(v[i].first<=v[j].first){
                temp[k++] = v[j++];
            }else{
                count[v[i].second] += r-j+1;
                temp[k++] = v[i++];
            }
        }
        
        while(i<=mid){
            temp[k++] = v[i++];
        }
        
        while(j<=r){
            temp[k++] = v[j++];
        }
        
        for(int i = l; i<=r;i++){
            v[i] = temp[i-l];
        }
        
    }
    
    void megerSort(vector<pair<int,int>> &v,vector<int> &count, int  l, int r){
        if(l>=r){
            return;
        }
        
        int mid = (l+r)/2;
        megerSort(v,count,l,mid);
        megerSort(v,count,mid+1,r);
        merge(v,count,l,mid,r);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        for(int i = 0; i<n; i++){
            v[i] = {nums[i],i};
        }
        
        vector<int> count(n,0);
        megerSort(v,count,0,n-1);
        
        return count;
    }
};
