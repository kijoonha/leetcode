class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int nn = nums1.size()+nums2.size();
        int median= (nn-1)/2;
        int i=0, j=0, k=0;
        int n1 = nums1.size(), n2 = nums2.size();
        int arr[nn];
        
        
        while (i<n1 && j<n2){
            if (nums1[i]<nums2[j]) arr[k++] = nums1[i++];
            else arr[k++] = nums2[j++];
            }
        
        while (i<n1){
            arr[k++] = nums1[i++];
        }
            
        while (j<n2){
            arr[k++] = nums2[j++];
        }
         
    
        if (nn%2==0){   //총 개수가 짝수개 ii, ii+1인덱스 구해야 함
            return static_cast<double>(arr[median]+arr[median+1])/static_cast<double>(2);
        }
        else return static_cast<double>(arr[median]);
    }


};
