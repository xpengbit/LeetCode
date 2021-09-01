第一章 编程技巧

判断两个浮点数a和b是否相等， 不用a == b. 应该判断两者之差的绝对值小于某一个阈值。fabs(a - b) < 1e-9.
判断某个数是否为奇数。x % 2 != 0, 不用 x % 2 == 1. 因为 x 有可能为负数。
vector和string 优先于动态分配的数组。

第二章 线性表

2.1 数组
2.1.1 Remove Duplicates from Sorted Array
/*时间复杂度O(n),空间复杂度O(1)*/
Class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.empty()) return 0;
        int index = 0;
        for(int i = 1; i < nums.size(); ++i>){
            if(nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index + 1;
    }
}

/*使用STL，时间复杂度O(n),空间复杂度O(1)*/
Class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
}

2.1.2 Remove Duplicates from Sorted Array II
/*上一题的follow up 最多允许两个重复*/
Class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.size() <= 2>) return nums.size();
        int index = 2;
        for(int i = 2; i < nums.size(); ++i){
            if(nums[i] != nums[index - 2])
                nums[index++] = nums[i];
        }
        return index;
    }
}

Class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int n = nums.size();
        int index = 0;
        for(int i = 0; i < n; ++i){
            if(i > 0 && i < n - 1 && nums[i - 1] == nums[i] && nums[i + 1] == nums[i])
                continue;
            nums[index++] = nums[i];
        } 
    }
}

2.1.3 Search in Rotated Sorted Array
/**/
Class Solution{
public:
    int search(const vector<int>& nums, int target){
        int left = 0, right = nums.size();
        while(left != right){
            const int mid = left + (right - left)/2;
            if(nums[mid] == target) return mid;
            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && nums[mid] > target)
                    right = mid;
                else
                    left = mid + 1;
            }
            else
            {
                if(nums[mid] < target && target <= nums[right - 1])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return -1;
    }

2.1.4 Search in Rotated Sorted Array II
Follow up for 2.1.3, what if duplicates are allows?

Class Solution{
public:
    bool search(const vector<int>& nums, int target){
        if(nums.empty()) return false;
        int left = 0, right = nums.size();
        while(left < right){
            const int mid = left + (right - left)/2;
            if(nums[mid] == target) return true;
            if(nums[left] < nums[mid]){
                if(nums[left] <= target && nums[mid] > target)
                    right = mid;
                else
                    left = mid + 1;
            }
            else if(nums[left] > nums[mid]){
                if(nums[mid]< target && nums[right - 1] >= target)
                    left = mid + 1;
                else
                    right = mid;
            }
            else
                left++;
        }
        return false;
    }

2.1.5 Median of Two Sorted Arrays
/*中位数需要判断长度是奇数or偶数*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size(), n = nums2.size();
        int total = m + n;
        if(total & 0x1)
            return findKth(nums1, 0, nums2, 0, total/2 + 1);
        else
            return (findKth(nums1, 0, nums2, 0, total/2 + 1) + findKth(nums1, 0, nums2, 0, total/2 + 2))/2.0;
    }
preivate:
    static int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        if(i >= nums1.size()) return nums2[j + k - 1];
        if(j >= nums2.size()) return nums1[i + k - 1];
        if(k == 1) return min(nums1[i], nums2[j]);
        int midVal1 = (i + k/2 -1 < nums1.size()) ? nums1[i + k/2 -1] : INT_MAX;
        int midVal2 = (j + k/2 -1 < nums2.size()) ? nums2[j + k/2 -1] : INT_MAX;
        if(midVal1 < midVal2)
            return findKth(nums1, i + k/2, nums2, j, k - k/2);
        else
            return findKth(nums1, i, nums2, j + k/2, k - k/2);
    }

2.1.6 Longest Consecutive Sequence(128)
/*如果是nlogn 的时间复杂度，可以先排序，然后遍历找出连续的子序列
由于序列里的元素是无序的，想到用hashmap*/
class Solution{
public:
    int longestConsecutive(const vector<int>& nums){
        if(nums.empty()) return 0;
        unordered_map<int, bool> used;
        int longest = 0;
        for(auto i : nums) used[i] = false;
        for(auto i : nums){
            if(used[i]) continue;
            length = 1;
            used[i] = true;
            for(int j = i + 1; used.find(j) != used.end(); ++j){
                used[j] = true;
                length++;
            }
            for(int j = i - 1; used.find(j) != used.end(); --j){
                used[j] = true;
                length++;
            }
            longest = max(longest, length);
        }
        return longest;
    }
}
/*Hashset 解法*/
class Solution{
public:
    int longestConsecutive(const vector<int>& nums){
        int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto val : nums){
            if(!s.count(val)) continue;
            s.erase(val);
            int next = val + 1, pre = val - 1;
            while(s.count(pre)) s.erase(pre--);
            while(s.count(next)) s.erase(next++);
            res = max(res, next - pre -1);  
        }
        return res;
    }
}

2.1.7 Two Sum (1)
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i>){
            int diff = target - num;
            if(m.count(diff)) return {m[diff], i};
            m[nums[i]] = i; 
        }
        return {};   
    }
}

2.1.8 3Sum (15)
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3 || nums.front() > 0 || nums.back() < 0) return {};
        for(int k = 0; k < nums.size() - 2; ++k){
            if(nums[k] > 0) break;
            if(k > 0 && nums[k - 1] == nums[k]) continue;
            int target = 0 - nums[k], i = k + 1, j = (int)nums.size() - 1;
            while(i < j){
                if(nums[i] + nums[j] == target){
                    res.push_back({nums[k], nums[i], nums[j]});
                    while(i < j && nums[i] == nums[i + 1]) ++i;
                    while(i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                }
                else if(nums[i] + nums[j] < target)
                    ++i;
                else
                    --j;
            }
        }
        return res;
    }
}

2.1.9 3Sum Colsest (16)
class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target){
        if(nums.empty() || nums.size() < 3) return 0;
        int closest = 0;
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size(); ++k){
            int i = k + 1, j = nums.size() - 1;
            while(i < j){
                int sum = nums[k] + nums[i] + nums[j];
                int newdiff = abs(sum - target);
                if(newdiff < diff){
                    diff = newdiff;
                    closest = sum;
                }
                if(sum < target) i++;
                else j--;
            }   
        }
        return closest;
    }
}

2.1.10 4Sum (18)

先排序，然后两个for loop固定下来两个数，再用i，j从头和尾扫。如果相等把结果存下来。
for循环的过程中需要判断是否有重复元素。
class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        if(nums.empty() || nums.size < 4) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size() - 3; ++k){
            if(k > 0 && nums[k - 1] == nums[k]) continue;
            for(int l = k + 1; l < nums.size() - 2; ++l){
                if(l > k + 1 && nums[l - 1] == nums[l]) continue;
                int i = l + 1, j = nums.size() - 1;
                while(i < j>){
                    int sum = nums[k] + nums[l] + nums[i] + nums[j];
                    if(sum == target){
                        res.push_back({nums[k],nums[l],nums[i],nums[j]});
                        while(i < j && nums[i] == nums[i + 1]) ++i;
                        while(i < j && nums[j] == nums[j - 1]) --j;
                        ++i; --j;
                    }
                    else if(sum < target) ++i;
                    else --j;
                }
            }
        }
        return res;
    }
}

2.1.11 Remove Element (27)
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.


class Solution{
public:
    int removeElement(vector<int>& nums, int target){
        int index = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != target)
                nums[index++] = nums[i];
        }
        return index;
    }
}

2.1.12 Next Permutation (31)

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

思路：先从右到左找到第一个不是递增的元素i，然后从右到左找到第一个大于i的元素j，交换之。然后把i到末尾的元素反转。

class Solution{
public:
    void nextPermutation(vector<int>& nums){
        if(nums.empty()) return;
        int n = nums.size();
        for(int i = n - 2; i >=0; --i){
            if(nums[i] < nums[i + 1]){
                for(int j = n - 1; j > i; --j){
                    if(nums[j] > nums[i]) break;
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
}

2.1.13 Permutation Sequence (60)

这道题是让求出n个数字的第k个排列组合，由于其特殊性，我们不用将所有的排列组合的情况都求出来，然后返回其第k个，这里可以只求出第k个排列组合即可，那么难点就在于如何知道数字的排列顺序，可参见网友喜刷刷的博客，首先要知道当 n = 3 时，其排列组合共有 3! = 6 种，当 n = 4 时，其排列组合共有 4! = 24 种，这里就以 n = 4, k = 17 的情况来分析，所有排列组合情况如下：

1234
1243
1324
1342
1423
1432
2134
2143
2314
2341
2413
2431
3124
3142
3214
3241
3412 <--- k = 17
3421
4123
4132
4213
4231
4312
4321

可以发现，每一位上 1,2,3,4 分别都出现了6次，当最高位上的数字确定了，第二高位每个数字都出现了2次，当第二高位也确定了，第三高位上的数字都只出现了1次，当第三高位确定了，那么第四高位上的数字也只能出现一次，下面来看 k = 17 这种情况的每位数字如何确定，由于 k = 17 是转化为数组下标为 16：

最高位可取 1,2,3,4 中的一个，每个数字出现 3！= 6 次（因为当最高位确定了，后面三位可以任意排列，所以是 3！，那么最高位的数字就会重复 3！次），所以 k = 16 的第一位数字的下标为 16 / 6 = 2，在 "1234" 中即3被取出。这里的k是要求的坐标为k的全排列序列，定义 k' 为当最高位确定后，要求的全排序列在新范围中的位置，同理，k'' 为当第二高为确定后，所要求的全排列序列在新范围中的位置，以此类推，下面来具体看看：

第二位此时从 1,2,4 中取一个，k = 16，则此时的 k' = 16 % (3!) = 4，注意思考这里为何要取余，如果对这 24 个数以6个一组来分，那么 k=16 这个位置就是在第三组（k/6 = 2）中的第五个（k%6 = 4）数字。如下所示，而剩下的每个数字出现 2！= 2 次，所以第二数字的下标为 4 / 2 = 2，在 "124" 中即4被取出。

3124
3142
3214
3241
3412 <--- k' = 4
3421

第三位此时从 1,2 中去一个，k' = 4，则此时的 k'' = 4 % (2!) = 0，如下所示，而剩下的每个数字出现 1！= 1 次，所以第三个数字的下标为 0 / 1 = 0，在 "12" 中即1被取出。

3412 <--- k'' = 0
3421

第四位是从2中取一个，k'' = 0，则此时的 k''' = 0 % (1!) = 0，如下所示，而剩下的每个数字出现 0！= 1 次，所以第四个数字的下标为 0 / 1= 0，在 "2" 中即2被取出。

class solution{
public:
    string getPermutation(int n, int k){
        string res;
        string num = "123456789";
        vector<int> f = (n, 1);
        for(int i = 1; i < n; ++i) f[i] = f[i - 1] * i;
        k--;
        for(int i = n; i >= 1; --i){
            int j = k / f[i - 1];
            k %= f[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res; 
    }
}


2.1.14 Valid Sudoku ()
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

class Solution{
public:
    bool isValidSudoku(vector<vector<char>>& board){
        vector<bool> visited(9);
        for(int i = 0; i < 9; ++i){
            fill(visited.begin(), visited.end(), false);
            for(int j = 0; j < 9; ++j)
                if(!check(board[i][j], visited)) return false;
            
            fill(visited.begin(), visited.end(), false);
            for(int j = 0; j < 9; ++j)
                if(!check(board[j][i], visited)) return false;
        }

        for(int r = 0; r < 3; ++i){
            for(int c = 0; c < 3; ++c){
                fill(visited.begin(), visited.end(), false);
                for(int i = r * 3; i < r * 3 + 3; ++i){
                    for(int j = c * 3; j < c * 3 + 3; ++j){
                        check(!board[i][j], visited) return false;
                    }
                }
            }
        }
        return true;
    }
private:
    bool check(char ch, vector<bool>& visited){
        if(ch == '.') return true;
        if(visited[ch - '1']) return false;
        return visited[ch - '1'] = true;
    }
}

2.1.15 Trapping Rain Water (42)
先从左往右扫找到每一个点左边的最大值， 然后从右往左扫找到右边的最大值。取小的。然后减去当前点的高度。
class Solution{
public:
    int trap(vector<int>& height){
        int res = 0, n = height.size();
        vector<int> leftMaxHeight(n);
        vector<int> rightMaxHegiht(n);
        
        for(int i = 1; i < n; ++i){
            leftMaxHeight[i] = max(leftMaxHeight[i - 1], height[i - 1]);
            rightMaxHeight[n - 1 - i] = max(rightMaxHeight[n -i], height[n - i]); 
        }

        for(int i = 0; i < n; ++i){
            int h = min(leftMaxHeihgt[i], rightMaxHeight[i]);
            if(h > height[i])
                res += h - height[i];
        }
        return res;

    }
}

/*解法2-单调栈*/
/*遍历高度，如果此时栈为空，或者当前高度小于等于栈顶高度，则把当前高度的坐标压入栈，
注意这里不直接把高度压入栈，而是把坐标压入栈，这样方便在后来算水平距离。当遇到比栈顶高度大的时候，
就说明有可能会有坑存在，可以装雨水。此时栈里至少有一个高度，如果只有一个的话，那么不能形成坑，直接跳过，
如果多于一个的话，那么此时把栈顶元素取出来当作坑，新的栈顶元素就是左边界，当前高度是右边界，只要取二者较小的，
减去坑的高度，长度就是右边界坐标减去左边界坐标再减1，二者相乘就是盛水量**/
        stack<int> s;
        int res = 0, n = height.size(), i = 0;
        while(i < n){
            if(s.empty() || height[s.top()] >= height[i]){
                s.push(i++);
            }
            else{
                int t = s.top(); s.pop();
                if(s.empty()) continue;
                res += (min(height[s.top()], height[i]) - height[t]) * (i - s.top() - 1);
            }
        }
        return res;
    }

2.1.16 Rotate Image (48)
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

class Solution{
public:
    void rotate(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0; i < n/2; ++i){
            for(int j = i; j < n - 1- i; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 -i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1- i] = tmp;
            }
        }
    }
}

还有一种解法，首先以从对角线为轴翻转，然后再以x轴中线上下翻转即可得到结果，如下图所示(其中蓝色数字表示翻转轴)：
1  2  3　　　 　　 9  6  3　　　　　     7  4  1

4  5  6　　-->　　 8  5  2　　 -->   　 8  5  2　　

7  8  9 　　　 　　7  4  1　　　　　     9  6  3
 

解法二：

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1- j][n - 1 - i]);
            }
        }
        reverse(matrix.begin(), matrix.end());
    }
};

最后再来看一种方法，这种方法首先对原数组取其转置矩阵，然后把每行的数字翻转可得到结果，如下所示（其中蓝色数字表示翻转轴，
1  2  3　　　 　　 1  4  7　　　　　     7  4  1

4  5  6　　-->　　 2  5  8　　 -->  　  8  5  2　　

7  8  9 　　　 　　3  6  9　　　　       9  6  3
 

解法三：
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

2.1.17 Plus One(66)
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0) return {};
        int n = digits.size();
        int c = 1;
        for(int i = n - 1; i >= 0; --i){
            int num = digits[i] + c;
            c = num / 10;
            digits[i] = num % 10;
            if(c == 0) break;
        }
        if(c > 0) digits.insert(digits.begin(), 1);
        return digits;   
    }
};

2.1.18 Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:
    int climbStairs(int n) {
        /*if(n < 3) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <=n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];*/

        memo = vector<int>(n + 1, 0);
        return helper(n);
        
private:
    vector<int> memo;
    int helper(int n){
        if(n <= 2) return n;
        if(memo[n] != 0) return memo[n];
        return memo[n] = helper(n - 1) + helper(n - 2);
    }
};

2.1.19 Gray Code
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
// Binary to grey code
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < pow(2,n); ++i) {
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};

2.1.20 Set Matrix Zeros (73)
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.
You must do it in place.
/*方法1，申请两个数组代表行，列； 如果有0，置为true.再遍历行，列，如果为true，置整行，整列为0*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i = 0; i < m; ++i){
            if(row[i])
                fill(matrix[i].begin(), matrix[i].end(), 0);
        }
        for(int j = 0; j < n; ++j){
            if(col[j]){
                for(int i = 0; i < m; ++i)
                    matrix[i][j] = 0;
            }
        }        
    }
}

/*方法2：利用第一行，第一列。先保留第一行第一列状态（是否有0）。然后从第二行第二列开始遍历matrix，如果有0， 置第一行，第一列为0，再遍历一次，如果第一行第一列相应位置为0，则置matrix[i][j] = 0. 最后根据预先保留的标志位设置第一行，第一列。这个方法的空间复杂度为 O(1)*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        bool firstRow = false, firstCol = false;
        for(int i = 0; i < m; ++i){
            if(matrix[i][0] == 0) firstCol = true;
        }
        for(int j = 0; j < n; ++j){
            if(matrix[0][j] == 0) firstRow = true;
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(firstRow == true){
            for(int j = 0; j < n; ++j) matrix[0][j] = 0;
        }
        if(firstCol == true){
            for(int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};

2.1.21 Gas Station (134)
我们首先要知道能走完整个环的前提是gas的总量要大于cost的总量，这样才会有起点的存在。假设开始设置起点start = 0, 并从这里出发，如果当前的gas值大于cost值，就可以继续前进，此时到下一个站点，剩余的gas加上当前的gas再减去cost，看是否大于0，若大于0，则继续前进。当到达某一站点时，若这个值小于0了，则说明从起点到这个点中间的任何一个点都不能作为起点，则把起点设为下一个点，继续遍历。当遍历完整个环时，当前保存的起点即为所求。
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const size_t n = gas.size();
        int sum = 0, total = 0, start = 0;
        for(int i = 0; i < n; ++i){
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(sum < 0){
                start = i + 1;
                sum = 0;
            }
        }
        return total < 0 ? -1 : start;
    }
};

2.1.22 Candy
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

class Solution {
public:
    int candy(vector<int>& ratings) {
        /*首先初始化每个人一个糖果，然后这个算法需要遍历两遍，第一遍从左向右遍历，
        如果右边的小盆友的等级高，等加一个糖果，这样保证了一个方向上高等级的糖果多。
        然后再从右向左遍历一遍，如果相邻两个左边的等级高，而左边的糖果又少的话，
        则左边糖果数为右边糖果数加一。最后再把所有小盆友的糖果数都加起来返回即可*/
        const size_t n = ratings.size();
        int total = 0;
        vector<int> res(n, 1);
        for(int i = 0; i < n - 1; ++i){
            if(ratings[i + 1] > ratings[i]) res[i + 1] = res[i] + 1;
        }
        for(int i = n - 1; i > 0; --i){
            if(ratings[i - 1] > ratings[i]) res[i - 1] = max(res[i - 1], res[i] + 1 );
        }
        for(int num : res){
            total += num;
        }
        return total;
    }
};

2.1.23 Single Number (136)
Given an array of integers, every element appears twice except for one. Find that single one.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using
extra memory?

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*使用异或。只要是偶数次，都可以清零*/
        int x = 0;
        for(auto num : nums)
            x ^= num;
        return x;

        /*return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());*/
    }
};

2.1.24 Single Number II (137)
Given an array of integers, every element appears three times except for one. Find that single one.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using
extra memory?

/*这道题就是除了一个单独的数字之外，数组中其他的数字都出现了三次，还是要利用位操作 Bit Manipulation 来解。可以建立一个 32 位的数字，来统计每一位上1出现的个数，如果某一位上为1的话，那么如果该整数出现了三次，对3取余为0，这样把每个数的对应位都加起来对3取余，最终剩下来的那个数就是单独的数字。*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum += (nums[j] >> i) & 1;
            }
            res |= (sum % 3) << i;
        }
        return res;
    }
};




2.2 单链表
单链表节点定义如下：
struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x) : val = x, next(nullptr){}
};

2.2.1 Add Two Numbers ()
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse
order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * Dummy = new ListNode(0);
        ListNode * cur = Dummy;
        int carrier = 0;

        while(l1 != NULL || l2 != NULL || carrier > 0){
            int num = carrier;
            if(l1 != NULL){
                num += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                num += l2->val;
                l2 = l2->next;
            }

            cur->next = new ListNode(num % 10);
            cur = cur->next;
            carrier = num / 10;
        }
        return Dummy->next;
    }
}

2.2.2 Reverse Linked List II (92)
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example: Given 1->2->3->4->5->nullptr, m = 2 and n = 4,
return 1->4->3->2->5->nullptr.
Note: Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        /*if(head == NULL || left == right) return head;
        ListNode* Dummy = new ListNode(-1, head);
        ListNode* cur = Dummy->next, *pre = Dummy;
        int i = 1;
        while(i++ < left){
            cur = cur->next;
            pre = pre->next;
        } 
        ListNode* node = pre;
        while(i++ <= right){
            ListNode* n = cur->next;
            cur->next = pre;
            pre = cur;
            cur = n;
        }
        node->next->next = cur;
        node->next = pre;

        return Dummy->next;*/

        /*另外一种反转方法，以此把要反转的元素插入pre的后面*/
        ListNode* Dummy = new ListNode(-1, head);
        ListNode* pre = Dummy;
        int i = 1;
        while(i++ < left) pre = pre->next;
        ListNode* cur = pre->next;
        while(i++ <= right){
            ListNode* t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }

        return Dummy->next;
    }
};


2.2.3 Partition List ()
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater
than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example, Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lDummy = new ListNode(-1);
        ListNode* gDummy = new ListNode(-1);
        ListNode* less = lDummy;
        ListNode* greater = gDummy;
        ListNode* cur = head;

        while(cur != NULL){
            if(cur->val < x){
                less->next = cur;
                less = less->next;
            }
            else{
                greater->next = cur;
                greater = greater->next;
            }
            cur = cur->next;
        }

        greater->next = nullptr;
        less->next = gDummy->next;

        return lDummy->next;
    }
};


2.2.4 Remove Duplicates from Sorted List (83)
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        for(ListNode* pre = head, *cur = pre->next; cur; cur = pre->next){
            if(pre->val == cur->val){
                pre->next = cur->next;
                del cur;
            }
            else
                pre = cur;
        }
        return head;
    }
};

2.2.5 Remove Duplicates from Sorted List II (82)
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers
from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* Dummy = new ListNode(-1);
        Dummy->next = head;
        ListNode* pre = Dummy, *cur = head;
        while(cur != NULL && cur->next != NULL){
            if(cur->val == cur->next->val){
                int tmp = cur->val;
                while(cur != NULL && cur->val == tmp) cur = cur->next;
                pre->next = cur;
            }
            else{
                cur = cur->next;
                pre = pre->next;
            }
        }

        return Dummy->next;
    }
};


2.2.6 Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.
For example: Given 1->2->3->4->5->nullptr and k = 2, return 4->5->1->2->3->nullptr.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) retur head;
        int len = listLength(head);
        len = k % len;
        for(int i = 0; i < len; ++i)
            head = deleteTail(head);
        return head;    
    }
private:
    int listLength(ListNode* head){
        ListNode* cur = head;
        int length = 0;
        while(cur != NULL){
            length++;
            cur = cur->next;
        }
        return length;
    }

    ListNode* deleteTail(ListNode* head){
        ListNode* cur = head;
        while(cur->next->next != NULL) cur = cur->next;
        ListNode* nx = cur->next;
        cur->next = NULL;
        nx->next = head;
        head = nx;
        return head;
    }
};

/*解法2： 遍历链表得到长度。然后把尾跟头相接。再往后走 n - k% n 步*/
class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k){
        if(head == NULL || k == 0) return head;
        ListNode* cur = head;
        int len = 1;
        while(cur->next){
            len++;
            cur = cur->next;
        }
        cur->next = head;
        int n = len - k % len;
        for(int i = 0; i < n; ++i){
            cur = cur->next;
        }
        ListNode* newhead = cur->next;
        cur->next = NULL;
        return newhead;
    }
}

/*解法3： 使用快慢指针。 fast先走k步。然后快慢同时走。快指针到达末尾时，慢指针的next就是新的头。*/


2.2.7 Remove Nth Node From End of List (19)
Given a linked list, remove the nth node from the end of list and return its head.
For example, Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
• Given n will always be valid.
• Try to do this in one pass.

/*首先要考虑的是，如何找到倒数第N个节点，由于只允许一次遍历，所以不能用一次完整的遍历来统计链表中元素的个数，而是遍历到对应位置就应该移除了。那么就需要用两个指针来帮助解题，pre 和 cur 指针。首先 cur 指针先向前走N步，如果此时 cur 指向空，说明N为链表的长度，则需要移除的为首元素，那么此时返回 head->next 即可，如果 cur 存在，再继续往下走，此时 pre 指针也跟着走，直到 cur 为最后一个元素时停止，此时 pre 指向要移除元素的前一个元素，再修改指针跳过需要移除的元素即可*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return NULL;
        ListNode* fast = head, *slow = head;
        for(int i = 1; i <= n； ++i) fast = fast->next;
        if(!fast) return head->next; /*此时n为list长度。删除头，返回第二个元素*/
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};


2.2.8 Swap Nodes in Pairs ()
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed.
Example:
Given 
1->2->3->4
, you should return the list as 
2->1->4->3

/*方法1：iterative*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* Dummy = new ListNode(-1), *pre = Dummy;
        Dummy->next = head;
        while(pre->next && pre->next->next ){
            ListNode* t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = t->next;
        }
        return Dummy->next;
    }
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* Dummy = new ListNode(-1);
        Dummy->next = head;
        ListNode* pre = Dummy, *cur = Dummy->next, *next = cur->next;
        for(; cur; pre = cur, cur = cur->next, next = cur ? cur->next : nullptr){
            pre->next = next;
            cur->next = next->next;
            next->next = cur;
        }
        return Dummy->next;
    }
};

/*方法2： 递归*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* t = head->next;
        head->next = swapParis(head->next->next);
        t->next = head;
        return t;
    }
}


2.2.9 Reverse Node in K-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
For example, Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

/*方法1：迭代法*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy, *cur = dummy->next;
        dummy->next = head;
        int num = 1;
        while(cur = cur->next) ++num;
        while(num >= k){
            cur = pre->next;
            for(int i = 1; i < k; ++i){
                ListNode* t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
            }
            num -= k;
            pre = cur;
        }
        return dummy->next;
    }
};

/*方法2：递归解法*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for(int i = 0; i < k; ++i){
            if(!cur) return head;
            cur = cur->next;
        }
        ListNode* new_head = reverse(head, cur);
        head->next = reverseKGroup(cur, k);
        return new_head;
    }
private:
    ListNode* reverse(ListNode* head, ListNode* tail){
        ListNode* new_head = tail;
        while(head != tail){
            ListNode* t = head->next;
            head->next = new_head;
            new_head = head;
            head = t;
        }
        return new_head;
    }
};


2.2.10 Copy List with Random Pointer (138)
A linked list is given such that each node contains an additional random pointer which could point to
any node in the list or null.
Return a deep copy of the list.
/*这道链表的深度拷贝题的难点就在于如何处理随机指针的问题，由于每一个节点都有一个随机指针，这个指针可以为空，也可以指向链表的任意一个节点，如果在每生成一个新节点给其随机指针赋值时，都要去遍历原链表的话，OJ 上肯定会超时，所以可以考虑用 HashMap 来缩短查找时间，第一遍遍历生成所有新节点时同时建立一个原节点和新节点的 HashMap，第二遍给随机指针赋值时，查找时间是常数级*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* cur = head;
        while(cur != NULL){
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        for(cur = head; cur != NULL; cur = cur->next){
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
        }
        return mp[head];
    }
};


2.2.11 Linked List Circle
Given a linked list, determine if it has a cycle in it.
Follow up: Can you solve it without using extra space?

class Solution{
public:
    bool hasCircle(ListNode* head){
        ListNode* slow = head, fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
}


2.2.12 Linked List Circle II
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Follow up: Can you solve it without using extra space?
/*这里还是要设快慢指针，不过这次要记录两个指针相遇的位置，当两个指针相遇了后，让其中一个指针从链表头开始，此时再相遇的位置就是链表中环的起始位置，为啥是这样呢，因为快指针每次走2，慢指针每次走1，快指针走的距离是慢指针的两倍。而快指针又比慢指针多走了一圈。所以 head 到环的起点+环的起点到他们相遇的点的距离 与 环一圈的距离相等。现在重新开始，head 运行到环起点 和 相遇点到环起点 的距离也是相等的，相当于他们同时减掉了 环的起点到他们相遇的点的距离。*/
class Solution{
public:
    bool detectCircle(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode* slow2 = head;
                while(slow2 != slow){
                    slow2 = slow2->next;
                    slow = slow->next;
                }
                return slow2;
            }
        }
        return nullptr; 
    }
}

2.2.13 Reorder List (143)
Given a singly linked list L : L0 → L1 → · · · → Ln−1 → Ln , reorder it to: L0 → Ln → L1 →
Ln−1 → L2 → Ln−2 → · · ·
You must do this in-place without altering the nodes’ values.
For example, Given {1,2,3,4}, reorder it to {1,4,2,3}.

class Solution{
public:
    void reorderList(ListNode* head){
        if(!head || !head->next || !head->next->next) return;
        ListNode* slow = head, *fast = head;
        /*先找到list的中点*/
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        /*反转后半部分*/
        ListNode* cur = mid, pre = nullptr;
        while(cur){
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        /*把后半部分插入first part*/
        while(head && pre){
            ListNode* nxt = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = nxt;
            head = nxt;
        }
    }
}

/*解法2： 用栈来实现*/
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) return;
        stack<ListNode*> s;
        ListNode* cur = head;
        while(cur){
            s.push(cur);
            cur = cur->next;
        }
        int cnt = ((int)s.size() - 1) / 2;
        cur = head;
        while(cnt-- > 0){
            auto tmp = s.top(); s.pop();
            ListNode* nxt = cur->next;
            cur->next = tmp;
            tmp->next = nxt;
            cur = nxt;
        }
        s.top()->next = nullptr;
    }
};


2.2.14 LRU Cache
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the
following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise
return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its
capacity, it should invalidate the least recently used item before inserting a new item.

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;    
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end()) return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()) l.erase(it->second);
        l.push_front(make_pair(key, val));
        m[key] = l.begin();
        if(m.size() > cap){
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }    
    }
private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


第三章 字符串

3.1 Valid Palindrome (125)
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring
cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Note: Have you consider that the string might be empty? This is a good question to ask during an
interview.
For the purpose of this problem, we define empty string as valid palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(!isalnum(s[left])) ++left;
            else if(!isalnum(s[right])) --right;
            else if((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32) return fase;
            else{
                ++left;
                --right;
            }
        }
        return true;    
    }
private:
    bool isAlphaNum(char &ch){
        if(ch >= 'a' && ch <= 'z') return true; 
        if(ch >= 'A' && ch <= 'Z') return true; 
        if(ch >= '0' && ch <= '9') return true;
        return false; 
    }
};


3.2 Implement strStr() (28)
 Implement strStr().
Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

class Solution {
public:
    int strStr(string haystack, string needle) {
        /*brute force 解法。O(M*N)*/
        if(needle.empty()) return 0;
        const int m = haystack.size(), n = needle.size();
        if(m < n) return -1;
        for(int i = 0; i <= m - n; ++i){
            int j = 0;
            for(j = 0; j < n; ++j){
                if(haystack[i + j] != needle[j]) break;
            }
            if(j == n) return i;
        }
        return -1; 
    }
};


3.3 String to Integer(atoi) (8)
Implement atoi to convert a string to an integer.
class Solution {
public:
    int myAtoi(string s) {
        int sum = 0;
        const size_t n = s.length();
        int sign = 1, i = 0;
        while(i < n && s[i] == ' ') ++i;
        if(i < n && (s[i] == '+' || s[i] == '-'))
            sign = s[i++] == '+' ? 1 : -1;
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            if(sum > INT_MAX / 10 || (sum == INT_MAX / 10 && s[i] - '0' > 7))
                return sign == 1 ? INT_MAX : INT_MIN;
            sum = sum * 10 + (s[i++] - '0');
        }
        return sum * sign;
    }
};


3.4 Add Binary (67)
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while(m >= 0 || n >= 0){
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
};


3.5 Longest Palindromic Substring (5)
Given a string s, return the longest palindromic substring in s.

class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.length();
        if(n < 2) return s;
        int maxLen = 0, start = 0;
        for(int i = 0; i <  n; ){
            if((n - i) <= maxLen / 2) break;
            int left = i, right = i;
            while(right < n && s[right] == s[right + 1]) right++;
            i = right + 1;
            while(left > 0 && right < n && s[left] == s[right]){
                left--; right++;
            }
            if(maxLen < right - left + 1){
                maxLen = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, maxLen);        
    }
};

/*解法2: DP*/
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.length();
        int dp[n][n];  /*dp[i][j] 表示i --j 是回文*/
        memset(dp, 0, sizeof(dp));
        int len = 1, left = 0;
        for(int i = 0; i < n; ++i){
            dp[i][i] = 1;
            for(int j = 0; j < i; ++j){
                dp[j][i] = (s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1]))
                if(dp[j][i] && len < (i - j + 1)){
                    left = j;
                    len = i - j + 1;
                }
            }
        }
        return s.substr(left, len);
    }
};


3.6 Regular Expression Matching (10)
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character. '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
/*解题思路：
需要用递归 Recursion 来解，大概思路如下：
- 若p为空，若s也为空，返回 true，反之返回 false。
- 若p的长度为1，若s长度也为1，且相同或是p为 '.' 则返回 true，反之返回 false。
- 若p的第二个字符不为*，若此时s为空返回 false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配。
- 若p的第二个字符为*，进行下列循环，条件是若s不为空且首字符匹配（包括 p[0] 为点），调用递归函数匹配s和去掉前两个字符的p（这样做的原因是假设此时的星号的作用是让前面的字符出现0次，验证是否匹配），若匹配返回 true，否则s去掉首字母（因为此时首字母匹配了，我们可以去掉s的首字母，而p由于星号的作用，可以有任意个首字母，所以不需要去掉），继续进行循环。
- 返回调用递归函数匹配s和去掉前两个字符的p的结果（这么做的原因是处理星号无法匹配的内容，比如 s="ab", p="a*b"，直接进入 while 循环后，我们发现 "ab" 和 "b" 不匹配，所以s变成 "b"，那么此时跳出循环后，就到最后的 return 来比较 "b" 和 "b" 了，返回 true。再举个例子，比如 s="", p="a*"，由于s为空，不会进入任何的 if 和 while，只能到最后的 return 来比较了，返回 true，正确）。*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p.size() == 1) return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        if(p[1] != '*'){
            if(s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)); 
        }
        while(!s.empty() && (s[0] == p[0] || p[0] == '.')){
            if(isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));         
    }
};

/*我们也可以用 DP 来解，定义一个二维的 DP 数组，其中 dp[i][j] 表示 s[0,i) 和 p[0,j) 是否 match，然后有下面三种情况
1.  P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
2.  P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
3.  P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.*/


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(j > 1 && p[j - 1] == '*'){
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
                else{
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];        
    }
};


3.7 WildCard Matching (44)
Implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character. '*' Matches any sequence of characters (including the empty se-
quence).
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size(), n = p.size();
        int istar = -1, jstar = -1, i = 0, j = 0;
        while(i < m){
            if(j < n && s[i] == p[j]){
                ++i; ++j;
            }
            else if(j < n && p[j] == '*'){
                istar = i;
                jstar = j;
                ++j;
            }
            else if(istar >= 0){
                i = ++istar;
                j = jstar + 1;
            }
            else return false;
        }
        if(j < n && p[j] == '*') ++j;
        return j == n;
    }
};


3.8 Longest Common Prefix (14)
Write a function to find the longest common prefix string amongst an array of strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*纵向扫描*/
        if(str.empty()) return "";
        for(int indx = 0; indx < strs[0].size(); ++indx){
            for(int j = 1; j < strs.size(); ++j){
                if(strs[0][indx] != strs[i][indx]) return strs[0].substr(0, indx);
            }
        }
        return strs[0];
    }
};

 /*解法2：这种方法给输入字符串数组排了个序，想想这样做有什么好处？既然是按字母顺序排序的话，
那么有共同字母多的两个字符串会被排到一起，而跟大家相同的字母越少的字符串会被挤到首尾两端，
那么如果有共同前缀的话，一定会出现在首尾两端的字符串中，所以只需要找首尾字母串的共同前缀即可。
比如例子1排序后为 ["flight", "flow", "flower"]，例子2排序后为 ["cat", "dog", "racecar"]，
虽然例子2没有共同前缀，但也可以认为共同前缀是空串，且出现在首尾两端的字符串中。由于是按字母顺序排的，
而不是按长度，所以首尾字母的长度关系不知道，为了防止溢出错误，只遍历而这种较短的那个的长度，找出共同前缀返回即可，
参见代码如下：*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        int i = 0, len = min(strs[0].size(), strs.back().size());
        while(i < len && strs[0][i] == strs.back()[i]) ++i;
        return strs[0].substr(0, i);
    }
};

3.9 Valid Number (65)
Validate if a given string is numeric.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up
front before implementing one.
/*首先，从题目中给的一些例子可以分析出来，我们所需要关注的除了数字以外的特殊字符有空格 ‘ ’， 小数点 '.', 自然数 'e/E', 还要加上正负号 '+/-"， 除了这些字符需要考虑意外，出现了任何其他的字符，可以马上判定不是数字。下面我们来一一分析这些出现了也可能是数字的特殊字符：
1. 空格 ‘ ’： 空格分为两种情况需要考虑，一种是出现在开头和末尾的空格，一种是出现在中间的字符。出现在开头和末尾的空格不影响数字，而一旦中间出现了空格，则立马不是数字。解决方法：预处理时去掉字符的首位空格，中间再检测到空格，则判定不是数字。
2. 小数点 '.'：小数点需要分的情况较多，首先的是小数点只能出现一次，但是小数点可以出现在任何位置，开头(".3"), 中间("1.e2"), 以及结尾("1." ), 而且需要注意的是，小数点不能出现在自然数 'e/E' 之后，如 "1e.1" false, "1e1.1" false。还有，当小数点位于末尾时，前面必须是数字，如 "1."  true，" -." false。解决方法：开头中间结尾三个位置分开讨论情况。
3. 自然数 'e/E'：自然数的前后必须有数字，即自然数不能出现在开头和结尾，如 "e" false,  ".e1" false, "3.e" false, "3.e1" true。而且小数点只能出现在自然数之前，还有就是自然数前面不能是符号，如 "+e1" false, "1+e" false. 解决方法：开头中间结尾三个位置分开讨论情况。
4. 正负号 '+/-"，正负号可以再开头出现，可以再自然数e之后出现，但不能是最后一个字符，后面得有数字，如  "+1.e+5" true。解决方法：开头中间结尾三个位置分开讨论情况。*/

/*下面我们开始正式分开头中间结尾三个位置来讨论情况：
1. 在讨论三个位置之前做预处理，去掉字符串首尾的空格，可以采用两个指针分别指向开头和结尾，遇到空格则跳过，分别指向开头结尾非空格的字符。
2. 对首字符处理，首字符只能为数字或者正负号 '+/-"，我们需要定义三个flag在标示我们是否之前检测到过小数点，自然数和正负号。首字符如为数字或正负号，则标记对应的flag，若不是，直接返回false。
3. 对中间字符的处理，中间字符会出现五种情况，数字，小数点，自然数，正负号和其他字符。
若是数字，标记flag并通过。
若是自然数，则必须是第一次出现自然数，并且前一个字符不能是正负号，而且之前一定要出现过数字，才能标记flag通过。
若是正负号，则之前的字符必须是自然数e，才能标记flag通过。
若是小数点，则必须是第一次出现小数点并且自然数没有出现过，才能标记flag通过。
若是其他，返回false。
4. 对尾字符处理，最后一个字符只能是数字或小数点，其他字符都返回false。
若是数字，返回true。
若是小数点，则必须是第一次出现小数点并且自然数没有出现过，还有前面必须是数字，才能返回true。*/

class Solution {
public:
    bool isNumber(string s) {
        
    }
};

class Solution {
public:
    bool isNumber(string s) {
        
    }
};

