/*
    YOUTUBE VIDEO  : https://www.youtube.com/watch?v=3XYQLHSoew8
    
    Leetcode Link               : https://leetcode.com/problems/bitwise-and-of-numbers-range/


    Approach Summary : 
Approach-1 (Using Shift):

Time Complexity (T.C): O(log(n)), where n is the maximum number of bits needed to represent the given input integers left and right.
Space Complexity (S.C): O(1)
Summary: This approach iteratively right-shifts both left and right until they become equal, counting the number of shifts. The result is obtained by left-shifting left by the count of shifts.
Approach-2 (Using AND Property):

Time Complexity (T.C): O(log(n)), where n is the maximum number of bits needed to represent the given input integers left and right.
Space Complexity (S.C): O(1)
Summary: This approach iteratively applies the bitwise AND operation on right and (right - 1) until right becomes less than or equal to left. The result is the value of right after the loop.
Both approaches aim to find the bitwise AND of a range of integers (left to right), with the first approach using a shift-based method and the second approach utilizing the property that bitwise AND between a number and its predecessor resets the rightmost set bit.
*/

/************************************************************ JAVA ************************************************************/
//Approach-1 (Using shift)
//T.C : O(log(n)), where n is the maximum number of bits needed to represent the given input integers left and right.
//S.C : O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftCount = 0;
        
        while(left != right) {
            left >>= 1;
            right >>= 1;
            shiftCount++;
        }
        
        return left << shiftCount;
    }
};


//Approach-2 (Using AND property)
//T.C : O(log(n)), where n is the maximum number of bits needed to represent the given input integers left and right.
//S.C : O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right > left) {
            right = right & (right-1);
        }
        
        return right;
    }
};


