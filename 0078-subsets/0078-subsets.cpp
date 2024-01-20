class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;
        vector<int> vec;
        findsubsets(nums, 0, output, vec, n);
        return output;
    }

private:
    void findsubsets(vector<int>& nums, int k, vector<vector<int>>& output, vector<int> aVec, const int& n){
        
        if(k==n){
            output.push_back(aVec);
            return ;
        }

        for(int i=0; i<2; i++){
            if (i==0){
                findsubsets(nums, k+1, output, aVec, n);
            }
            else{
                aVec.push_back(nums[k]);
                findsubsets(nums, k+1, output, aVec, n);
            }
        }
        
    }

};