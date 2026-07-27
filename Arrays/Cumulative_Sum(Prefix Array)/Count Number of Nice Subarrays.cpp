
/*
    Youtube link:                 https://www.youtube.com/watch?v=JpXlsCAD1kg
    Leetcode Link:                https://leetcode.com/problems/count-number-of-nice-subarrays
*/


/*
Summary :
Approach 1: Using Prefix Sum and Hashmap

Time Complexity (T.C): O(n)
Space Complexity (S.C): O(n)
This approach leverages the prefix sum technique combined with a hashmap to efficiently count subarrays with exactly k odd numbers.

Initialization:

mp (unordered_map) to store the frequency of prefix sums.
Variables: n (length of nums), count (result count), and currSum (current prefix sum).
Iterate Through Array:

For each element, update currSum by adding 1 if the element is odd (nums[i] % 2), else add 0.
Check if currSum - k exists in mp. If it does, increment count by the frequency of currSum - k.
Update mp to include the current currSum.
This method ensures that each subarray's prefix sum is calculated in linear time, and the hashmap provides efficient lookups for the required subarray sums.




Approach 2: Sliding Window (Khandani Template with a Twist)

Time Complexity (T.C): O(n)
Space Complexity (S.C): O(1)
This approach utilizes a sliding window technique to dynamically count subarrays containing exactly k odd numbers.

Initialization:

Variables: n (length of nums), oddCount (number of odd numbers in the current window), count (subarrays ending at the current position), result (total count of valid subarrays), and two pointers i and j (window boundaries).
Sliding Window:

Iterate with j from 0 to n-1. For each element:
If the element is odd, increment oddCount and reset count to 0.
While oddCount equals k, increment count and adjust the window by incrementing i and decreasing oddCount if the element at i is odd.
Add count to result.
This method maintains a sliding window that expands and contracts based on the number of odd numbers, ensuring efficient computation in linear time with constant space.
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Using prefix sum and storing in hashmap)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int n       = nums.size();
        int count   = 0;
        int currSum = 0;
        mp[currSum] = 1;

        for(int i = 0; i < n; i++) {
            currSum += (nums[i]%2); //if odd - 1, even - 0

            if(mp.count(currSum - k)) {
                count += mp[currSum-k];
            }

            mp[currSum]++;
        }

        return count;

    }
};


//Approach-2 (Sliding Window Khandani Template with a slight twist)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int oddCount = 0;
        int count    = 0;
        int result   = 0;

        int i = 0;
        int j = 0;
        //Best example to understand the use of count variable - {2, 1, 2, 1}, output : 6
        while(j < n) {

            if(nums[j] % 2 != 0) { //ODD    Expanding
                oddCount++;
                count    = 0; //We need to reset this to avoid over counting. Example : [1,1,2,1,1], k = 3
            }

            while(oddCount == k) {
                count++;

                if(i < n && nums[i] % 2 == 1) { //ODD   Shrinking
                    oddCount--;
                }
                i++;
            }

            result += count;
            j++;
        }

        return result;
    }
};

