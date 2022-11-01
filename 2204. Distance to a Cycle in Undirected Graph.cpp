class solution{
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges){
        vector<vector<int>> adj(n);
        vector<int> degree(n);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> q;
        for(int i = 0;  i < n; ++i){
            if(degree[i] == 1)
                q.push(i);
        }
        
        vector<int> res(n, 0);
        while(!q.empty()){
            int cur = q.top(); q.pop();
            res[cur] = -1;            
            for(int nxt : adj[cur]){
                degree[nxt]--;
                if(degree[nxt] == 1)
                    q.push(nxt);
            }
        }

        queue<int> q2;
        for(int i = 0; i < n; ++i){
            if(res[i] == 0)
                q2.push(i);
        }

        while(!q2.empty()){
            int cur = q2.top(); q2.pop();
            for(int nxt : adj[cur]){
                if(res[nxt] != -1) continue;
                res[nxt] = res[cur] + 1;
                q2.push(nxt);
            }
        }

        return res;
    }
};