class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        unordered_set<int> dups;//skip duplicates in the outer loop
        unordered_map<int,int> seen;
        for(int i=0;i<nums.size();i++){//O(n)
            if(dups.insert(nums[i]).second){
                for(int j=i+1;j<nums.size();j++){
                    int complement=-nums[i]-nums[j];
                    auto it=seen.find(complement);
                    if(it!=end(seen)&&it->second==i){
                        vector<int>triplet={nums[i],nums[j],complement};
                        sort(begin(triplet),end(triplet));
                        res.insert(triplet);
                    }
                    seen[nums[j]]=i;
                }
            }
        }
        return vector<vector<int>>(begin(res),end(res));
    }
};//O(n^2)