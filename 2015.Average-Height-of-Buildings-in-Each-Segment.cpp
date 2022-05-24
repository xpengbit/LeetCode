class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) 
    {
        map<int, pair<int, int>> Map;   //pos -> {diffheight, diffcount}
        for(auto& b : buildings){
            int s = b[0], e = b[1], h = b[2];
            Map[s].first += h;
            Map[s].second += 1;
            Map[e].first -= h;
            Map[e].second -= 1;
        }
        
        vector<pair<int, int>> ave;
        int totalH = 0, totalC = 0;
        for(auto& [p, kv] : Map){
            totalH += kv.first;
            totalC += kv.second;
            int avrage = totalH == 0 ? 0 : totalH / totalC;

            ave.push_back({p, avrage});
        }
    
        vector<vector<int>> res;
        for(int i = 0; i < ave.size(); ++i){
            if(ave[i].second == 0) continue;
            int j = i;
            while(j < ave.size() && ave[j].second == ave[i].second) j++;
            res.push_back({ave[i].first, ave[j].first, ave[i].second});
            i = j - 1;
        }
        return res;
    }
};