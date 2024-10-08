class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edj, vector<double>& s, int l, int r) {
        vector<pair<int,double>> adj[n];
        for(int i = 0; i < edj.size(); i++){
            adj[edj[i][0]].push_back({edj[i][1], s[i]});
            adj[edj[i][1]].push_back({edj[i][0], s[i]});
        }

        vector<float> dis(n);
        priority_queue<pair<int,float>> pq;
        pq.push({l,1});
        dis[l] = 1;

        while(!pq.empty()){
            pair<int, float> a = pq.top();
            pq.pop();

            for(auto it: adj[a.first]){
                if(it.second * a.second > dis[it.first]){
                    dis[it.first] = it.second * a.second;
                    pq.push({it.first,it.second * a.second});
                }
            }
        }
        return dis[r];
    }
};