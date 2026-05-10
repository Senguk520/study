// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();
//         int left = 0;
//         int all = 0;
//         int count = n+1;
//         for(int right =0 ;right<n;right++){
//             all +=  nums[right];
//             while(all>= target){
//                 count = min (count , right - left +1);
//                 all -= nums[left];
//                 left++;
//             }   
//         }
//         return (count <= n?count : 0);
//     }
// };
