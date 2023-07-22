

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s1;
        pair<unordered_set<int>::iterator,bool> ret;
        
        for(int i = 0; i < nums.size(); i++){
            ret = s1.insert(nums[i]);
        
        if (!ret.second){
            return nums[i];
            }
        }
        return 0;
    };
};


