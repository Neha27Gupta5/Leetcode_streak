class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int l=0,r=0;
        int subarray_count=0;
        unordered_map<int,int>m;
        while(r<nums.size()){
           m[nums[r]]++;
           while(m.size()>k){
            m[nums[l]]--;
            if(m[nums[l]]==0){
                m.erase(nums[l]);
            }
            l++;
           }
           subarray_count+=r-l+1;
           r++;
        }
        return subarray_count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

     int exactly_k=atmost(nums,k)-atmost(nums,k-1);
     return exactly_k;

    }
};