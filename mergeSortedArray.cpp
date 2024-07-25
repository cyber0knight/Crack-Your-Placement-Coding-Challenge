class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = n+m;
        n--; m--;
        int i=size-1;
        for(i;i>=0;i--){
            if(m<0 || n<0){
                break;
            }
            if(nums1[m] < nums2[n] ){
                nums1[i] = nums2[n];
                n--;
            }else{
                nums1[i] = nums1[m];
                m--;
            }
        }
        if(m<0){
            while(i>=0){
                nums1[i--] = nums2[n--];
            }
        }
    }
};