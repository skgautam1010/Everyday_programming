
//to check: bipartite graph or not

class Solution {
public:
    
    bool bipartite(vector<vector<int>>&graph ,int src,vector<int>color)
    {
        queue<int>q;
        q.push(src);
        color[src]=1;
        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            for(auto u:graph[current])
            {
                if(color[u]==-1)
                {
                    color[u]=color[current]^1;
                    q.push(u);
                }
                else if(color[u]==color[current])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!bipartite(graph,i,color))
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};