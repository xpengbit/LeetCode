/*
 * @lc app=leetcode id=505 lang=cpp
 *
 * [505] The Maze II
 * 
 * There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.
The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
Example 1:
Input 1: a maze represented by a 2D array
0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0
Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (4, 4)
Output: 12
Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
             The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
Example 2:
Input 1: a maze represented by a 2D array
0 0 1 0 0
0 0 0 0 0
0 0 0 1 0
1 1 0 1 1
0 0 0 0 0
Input 2: start coordinate (rowStart, colStart) = (0, 4)
Input 3: destination coordinate (rowDest, colDest) = (3, 2)
Output: -1
Explanation: There is no way for the ball to stop at the destination.
Note:
There is only one ball and one destination in the maze.
Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.*/
class Solution {
public:
    struct compare{
        bool operator()(vector<int> a, vector<int> b){
            return a[3] > b[3];
        }
    }
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool shortestPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>> q;
        distance[start[0]][start[1]] = 0;
        q.push({start[0], start[1], 0});
        while(!q.empty()){
            vector<int> tmp = q.front();
            q.pop();
            for(auto d : dir){
                int x = tmp[0] + d[0];
                int y = tmp[1] + d[1];
                int count = 0;
                while(x >=0 and y >=0 and x < m and y < n and maze[x][y] == 0){
                    x += d[0];
                    y += d[1];
                    count++;
                }
                x -= d[0];
                y -= d[1];
                if(distance[tmp[0]][tmp[1]] + count < distance[x][y]){
                    distance[x][y] = disctance[tmp[0]][tmp[1]] + count;
                    q.push({x, y, distance[x][y]});
                }
            }
        }
        return distance[destionation[0]][distionation[1]] == INT_MAX ? -1 : distance[destionation[0]][destionation[1]];  
    }
};

