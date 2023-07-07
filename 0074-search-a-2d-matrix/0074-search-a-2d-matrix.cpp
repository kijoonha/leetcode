class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int start = 0;
    int end = m*n-1;
    int mid;
 
    while (end - start >= 0) {
        mid = (start + end) / 2;    //중앙 값
        int mm = mid/n;
        int nn = mid%n;
        if (matrix[mm][nn] == target) {    //key값을 찾았을때
            return true; 
        } else if (matrix[mm][nn] > target) {   //key값이 mid의 값보다 작을때 (왼쪽으로)
            end = mid - 1;
        } else {  //key값이 mid의 값보다 클때 (오른쪽으로)
            start = mid + 1;
        }
    }

    return false;
};



    
    
};