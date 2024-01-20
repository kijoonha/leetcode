class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int i=0; i<stones.size(); i++){
            pq.push(stones[i]);
        }
        int num1;
        int num2;
        while (true){
            num1 = pq.top();
            pq.pop();
            if(pq.empty()){
                break;
            }
            else{
                num2 = pq.top();
                pq.pop();
                if(num1==num2){
                    if(pq.empty()){
                        return 0;
                    }
                    else{
                        continue;
                    }
                }
                else{
                    pq.push(max(num1-num2, num2-num1));
                }
            }
        }
        return num1;
    }
};