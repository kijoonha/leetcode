class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        
        int len = nums.size();
        return BinarySearch(nums, 0, len-1, target);
        }

private:

    int BinarySearch(vector<int>& nums, int start, int end, int target) {

        int firstNum = nums[0];
        cout<<"start: "<<start<<" and end: "<<end;
        if (start>end) return -1;
        int mid = (start+end)/2;

        
        if (target==firstNum) return 0;
        else if (target>firstNum){
            if (nums[mid]<firstNum) return BinarySearch(nums, start, mid-1, target); //[1,3] case에서는 등호x
            else {
                if (target>nums[mid]) return BinarySearch(nums, mid+1, end, target);
                else if (target<nums[mid]) return BinarySearch(nums, start, mid-1, target);
                else return mid;
            }
        }

        else {
            //   [3,1] case해결하려면 아래에서 등호 필요
            if (nums[mid]>=firstNum) {cout<<"case 1 : mid"<< mid; return BinarySearch(nums, mid+1, end, target);}
            else{
                if (target>nums[mid]) return BinarySearch(nums, mid+1, end, target);
                else if (target<nums[mid]) return BinarySearch(nums, start, mid-1, target);
                else return mid;
            }
            }

        }
};