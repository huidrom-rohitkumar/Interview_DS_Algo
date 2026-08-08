
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Lye_llDcSuI
    Leetcode Link               : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k
*/


/************************************************************ C++ ************************************************/
//Approach-(simple remainder maths)
//T.C : O(n + k)
//S.C : O(k)
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k, 0); //O(K)
        //mp[r] = x
        //remainder r has frequency x

        for(int &num : arr) {
            int rem = (num % k + k) % k; //handling negative remainders
            mp[rem]++;
        }

        // Check if the frequency of numbers with 0 remainder is even
        if(mp[0] % 2 != 0)    // handle edge cases like arr=[5,10,15,3],k=5
        {
            return false;
        }

        // Check if each remainder has a complement remainder with matching frequency
        for(int rem = 1; rem <= k/2; rem++) {
            int counterHalf = k - rem;
            if(mp[counterHalf] != mp[rem]) {
                return false;
            }
        }

        return true;
    }
};

/*
Summary :
The approach uses remainder arithmetic to solve the problem of determining if the array can be rearranged into pairs whose sums are divisible by a given integer k. Here's a brief summary of the method:

Calculate Remainder Frequencies:

Traverse through the array and compute the remainders when each element is divided by k.
Use an array mp of size k to count the frequency of these remainders, handling negative remainders correctly.
Check Conditions for Valid Pairing:

For elements with a remainder of 0, their frequency must be even to ensure they can be paired.
For other remainders rem, ensure that mp[rem] (frequency of rem) matches mp[k - rem] (frequency of its complement remainder) to allow pairing.
Return Result:

If all conditions are met, return true; otherwise, return false.
*/

