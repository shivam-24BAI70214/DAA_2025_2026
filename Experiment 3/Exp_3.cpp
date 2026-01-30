class Solution {
  public:
  bool checking(int node,vector<vector<int>>&adj,vector<bool>&vis,int count,int n){
      if(count==n){
         return true;
     }
      for(int u:adj[node]) {
            if(!vis[u]) {
                vis[u]=true;
                if(checking(u,adj,vis,count+1,n))
                    return true;
                vis[u]=false;
            }
        }
        return false;
    }
  bool check(int n,int m,vector<vector<int>>edges){
      vector<vector<int>>adj(n);
        for(auto e:edges) {
            int u=e[0]-1;
            int v=e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            vis[i]=true;
            if(checking(i,adj,vis,1,n))
                return true;
        }
        return false;
    }
};
