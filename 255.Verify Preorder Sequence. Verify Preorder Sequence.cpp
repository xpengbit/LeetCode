/*[LeetCode] 255. Verify Preorder Sequence in Binary Search Tree
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
You may assume each number in the sequence is unique.
Consider the following binary search tree: 
     5
    / \
   2   6
  / \
 1   3
Example 1:
Input: [5,2,6,1,3]
Output: false
Example 2:

Input: [5,2,1,3,6]
Output: true
Follow up:
Could you do it using only constant space complexity?*/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        stack<int> s;
        for(int c : preorder){
            if(c > low) return false;
            while(!s.empty() && c > s.top()){
                low = s.top(); s.pop();
            }
            s.push(c);
        }
        return true;
    }
};

//Divid && Conquer solution
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return helper(preorder, 0, n - 1, INT_MIN, INT_MAX);
    }

    bool helper(vector<int>& preorder, int start, int end, int Min, int Max){
        if(start > end) return true;
        int val = preorder[start], i = start + 1;
        if(val <= Min || val >= Max) return false;
        while(i < end && preorder[i] < val) ++i;
        return helper(preorder, start + 1, i - 1, Min, val) && helper(preorder, i, end, val, Max);
    }
};