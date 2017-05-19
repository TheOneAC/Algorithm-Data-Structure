
> 
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
For example, 
Given[0,1,0,2,1,0,1,3,2,1,2,1], return6.
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
```
class Solution {
public:
    int trap(int A[], int n) {
        if( n <= 2)return 0;
        int l = 0, r = n -1, con = 0,h = 0;
        while(l < r){
            for(; l< r && A[l] <= A[r]; l++){
                h = max(h, A[l]);
                con += h - A[l];
            }
            for(; l< r && A[l] > A[r]; r--){
                h = max(h, A[r]);
                con += h - A[r];
            }
        }
        return con;
    }
};
```