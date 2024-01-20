class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;
        vector<int> vec;
        vector<bool> visited(n, false);
        backtracking(n, nums, 1, output, vec, visited);
        return output;
    }

private:
    void backtracking(const int& n, vector<int>& nums, int k, vector<vector<int>>& output, vector<int> vec, vector<bool> visited){
        if(k>n){
            output.push_back(vec);

            return ;
        }
        for(int i=0; i<n; i++){
            std::cout<<"i: "<<i<<std::endl;
            if(visited[i]==false){
                visited[i] = true;
                vec.push_back(nums[i]);
                backtracking(n, nums, k+1, output, vec, visited);
                visited[i] = false;
                vec.pop_back();
            } 
            else{    //필요?
            }
        }
        return ;     //필요?
    }
};