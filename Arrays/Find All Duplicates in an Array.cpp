
/*
       YOUTUBE VIDEO            : https://www.youtube.com/watch?v=NqadCpaZnkk
    Company Tags                : Pocket Gems, Amazon, Meta
    Leetcode Link               : https://leetcode.com/problems/find-all-duplicates-in-an-array
*/


/*
Note - when values in range like 0-n or 1-n, the values can be used/related as indexes to mark or analyse elements

Approach Summary : 
The given approach is designed to find duplicates in an array of integers efficiently. It works by utilizing the properties of the array itself to mark visited elements.
Here's how the approach works:
1. Iterate through each element of the input array `nums`.
2. For each element `num`, take its absolute value (`abs(nums[i])`) to ensure positive index access.
3. Check if the element at index `num - 1` (assuming 1-based indexing) is negative. If it is negative, it means `num` has been encountered before, so it's a duplicate. In this case, add `num` to the result vector.
4. If the element at index `num - 1` is not negative, mark it as visited by multiplying it by -1 (`nums[num - 1] *= -1`). This indicates that `num` has been encountered.
5. Repeat steps 3-4 for all elements in the array.
6. Return the result vector containing duplicates.
This approach effectively utilizes the sign of the elements in the input array to mark visited elements, making it a space-efficient solution with a time complexity of O(n), where n is the size of the input array.

*/


//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result; 
        for(int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            
            if(nums[num-1] < 0) {
                result.push_back(num);
            } else {
                nums[num-1] *= -1;
            }
        }
        
        return result;
        
    }
};


