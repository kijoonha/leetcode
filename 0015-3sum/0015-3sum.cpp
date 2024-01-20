class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
  
        sort(nums.begin(),nums.end()); //nums 복사해서 쓰려면?
        int findNum, start, end;
        int size = nums.size();
        vector<int> oneCase;
        vector<vector<int>> result;
        for (int i = 0; i < size-2; i++) {
            int fixNum = nums[i];
            if(i>=1 && nums[i]==nums[i-1] ){
                continue;
            }
            if(nums[i]>0){
                break;
            }
            start=i+1;
            end=size-1;
            while(start<end){
                if(start>i+1 && nums[start]==nums[start-1] ){
                    start++;
                    continue;
                }   
                if(end<size-1 && nums[end]==nums[end+1]){
                    end--;
                    continue;
                }
                if(fixNum+nums[start]+nums[end]<0){
                    start++;
                }
                else if(fixNum+nums[start]+nums[end]>0){
                    end--;
                }
                else{
                    oneCase.push_back(nums[i]);
                    oneCase.push_back(nums[start]);
                    oneCase.push_back(nums[end]);
                    result.push_back(oneCase);
                    oneCase.clear();
                    start++;
                }
            }
        }
        return result;
    }
};

