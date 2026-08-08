
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=quUIQ2pw5EU
    Leetcode Link               : https://leetcode.com/problems/count-number-of-bad-pairs
*/

/*

Video Summary :
Transforming the Array:

Modify nums[i] to nums[i] - i so that the problem reduces to finding equal values instead of explicitly checking pair conditions.
This transformation helps identify "good pairs" efficiently.
Using a HashMap for Frequency Counting:

Maintain a frequency map to track occurrences of transformed values.
If a value has appeared before, it contributes to "good pairs," reducing the need for brute force comparison.
Calculating Bad Pairs Efficiently:

Instead of iterating over all pairs, compute the total possible pairs (j, i) implicitly.
Use the count of previously seen values to determine how many pairs are "good," and subtract from the total to get "bad pairs."
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        long long result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(j-i != nums[j] - nums[i]) {
                    result++;
                }
            }
        }

        return result;
    }
};


//Approach-2 (Using hashmap)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        long long result = 0;
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i]-i;
        }

        unordered_map<int, int> mp;
        mp[nums[0]] = 1;

        for(int j = 1; j < n; j++) {
            int countOfNumsj = mp[nums[j]];

            int totalNumsBeforej = j;

            int badPairs = totalNumsBeforej - countOfNumsj;

            result += badPairs;

            mp[nums[j]]++;
        }

        return result;
    }
};


//Approach-3 (Using hashmap)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        long long result = 0;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) {
            int diff = nums[i] - i;

            int totalPairsTillIndex = i;
            int goodPairs           = mp[diff];

            result += (totalPairsTillIndex - goodPairs);

            mp[diff]++; 
        }

        return result;
    }
};


