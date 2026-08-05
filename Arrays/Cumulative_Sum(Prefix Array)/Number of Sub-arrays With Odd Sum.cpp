
/*
    YOUTUBE:                         https://www.youtube.com/watch?v=_tAArozuTwA
    Leetcode Link               : https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum
*/



/*
Approach-1 (Brute Force): This method considers all possible subarrays and checks if their sum is odd. Due to its O(n³) complexity, it is highly inefficient for large inputs.
*/
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    const int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += arr[k];
                }
                if (sum % 2 != 0) {
                    count++;
                }
            }
        }
        
        return count % M;
    }
};





//Approach-2 (Better Brute Force): Instead of recalculating sums for each subarray from scratch, it maintains a running sum. This reduces the time complexity to O(n²), making it slightly better but still suboptimal.
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    const int M = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum % 2 != 0) {
                    count = (count+1)%M;
                }
            }
        }
        
        return count % M;
    }
};



//Approach-3 (Optimal using Prefix Sum Array):
/* The idea is to use a prefix sum to track cumulative sums efficiently. Instead of checking each subarray individually, we count how many prefix sums are odd or even.
        If the current prefix sum is even, the number of valid subarrays is equal to the count of odd prefix sums encountered so far.
If the prefix sum is odd, the valid subarrays count is derived from the even prefix sums seen previously.
This approach helps us count odd-sum subarrays efficiently in O(n) time using additional space for prefix sums.
*/
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        vector<int> prefix(n, 0);
        prefix[0] = arr[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
        }

        int count = 0;
        int odd = 0;
        int even = 1;

        for(int i = 0; i < n; i++) {
            if(prefix[i]%2 == 0) { //odd + even = odd
                count = (count + odd) % M;
                even++;
            } else { //even + odd = odd
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }
};





/*
Approach-4 (Optimal using Constant Space): Instead of maintaining a prefix sum array, we only track two values: the count of odd and even prefix sums seen so far. This allows us to achieve O(n) time and O(1) space, making it the most efficient approach.
*/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        int count = 0;
        int odd = 0;
        int even = 1;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += arr[i];

            if(sum%2 == 0) { //odd + even = odd
                count = (count + odd) % M;
                even++;
            } else { //even + odd = odd
                count = (count + even) % M;
                odd++;
            }
        }

        return count;
    }
};



