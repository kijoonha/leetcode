class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> sortedNums;
        for (int i=0; i<nums.size(); i++){
            sortedNums.insert(nums[i]);
        }       
        int cnt = 0;
        int mcnt = 0;
        set<int>::iterator it;
        int preval = 0;
        
        //[]비어있을 경우
        if (nums.empty()){
            return (int)0;}
        
        for (it=sortedNums.begin(); it!=sortedNums.end(); it++){
            //첫번째 값의 경우
            if (it==sortedNums.begin()){
                preval = *it;
                mcnt = cnt;
            }
            //2번째 값부터 앞의 값과 비교
            else{
                if (*it==preval+1){

                    cnt++;
                    if (mcnt<cnt)
                        {mcnt = cnt;}
                }
                else{
                    cnt = 0;
                }
                preval = *it;
            }  
        }
        mcnt++;
        return mcnt;
    }
};