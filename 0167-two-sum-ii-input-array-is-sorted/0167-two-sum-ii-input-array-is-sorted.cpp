class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idx1=0, idx2=1;
        int res;
        bool isFind=false;


        vector<int> result;
        for (idx1;idx1<numbers.size();idx1++){
            res = target-numbers[idx1];
            if(idx1>=1 && numbers[idx1]==numbers[idx1-1]){
                continue;
            }
            idx2=idx1+1;
            for(idx2;idx2<numbers.size();idx2++){
                if(numbers[idx2]==res){
                    isFind=true;
                    break;
                }
            }
            if(isFind==true){
                break;
            }
        }
        result.push_back(idx1+1);
        result.push_back(idx2+1);
        return result;
    }
};