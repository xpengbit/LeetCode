/*
 * @lc app=leetcode id=490 lang=cpp
 *
 * [490] The Maze
 * 
*There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
Given the maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return true if the ball can stop at the destination, otherwise return false.
You may assume that the borders of the maze are all walls (see examples).

Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
Example 2:
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: false
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
Example 3:
Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: false
Constraints:
1 <= maze.length, maze[i].length <= 100
maze[i][j] is 0 or 1.
start.length == 2
destination.length == 2
0 <= startrow, destinationrow <= maze.length
0 <= startcol, destinationcol <= maze[i].length
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The maze contains at least 2 empty spaces.
*/
class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[start[0]][start[1]] = true;
        queue<vector<int>> q;
        q.push(start);
        while(!q.empty()){
            vector<int> tmp = q.front();
            q.pop();
            if(tmp[0] == destionation[0] and tmp[1] == destionation[1]) return true;
            for(auto d : dir){
                int x = tmp[0] + d[0];
                int y = tmp[1] + d[1];
                while(x >= 0 and y >= 0 and x < m and y < n and maze[x][y] == 0){
                    x += d[0];
                    y += d[1];
                }
                /*从while循环跳出，需要回退一格*/
                x -= d[0];
                y -= d[1];
                if(!visited[x][y]){
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
        return false;
    }
};

// @lc code=start