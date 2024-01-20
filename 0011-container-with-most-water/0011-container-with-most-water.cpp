class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0;
        int e=height.size()-1;
        int maxS, maxE;
        int maxV  = min(height[e],height[s]) * (e-s);
        cout<<"maxV : "<<maxV;
        int curr;
        while (s<e){
            if(height[s]>=height[e]){   
                curr = min(height[e],height[s]) * (e-s);
                if(curr>maxV){
                    maxV = curr;
                }
                e--;
                
            }
            else{
                curr = min(height[e],height[s]) * (e-s);
                if(curr>maxV){
                    maxV = curr;
                }
                s++;
            }
        }    

        return maxV;
    };
};