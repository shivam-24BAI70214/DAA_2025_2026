#include<iostream>
#include<vector>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;
vector<vector<int>>adjList;
vector<int>path;
vector<bool>vis;
int v=5;
bool hasEdge(int u,int v){
    for(int x:adjList[u]){
        if(x==v){
            return true;
        }
    }
    return false;
}
bool solve(int u,int count){
    if(count==v){
        return hasEdge(u,path[0]);
    }
    for(int v:adjList[u]){
        if(!vis[v]){
            vis[v]=true;
            path.push_back(v);
            if(solve(v,count+1)){
                return true;
            }
            vis[v]=false;
            path.pop_back();
        }
    }
    return false;
}

int main(){
    fastio;
    int t=1;
    while(t--){
        adjList={
            {1,3},
            {0,2,3,4},
            {1,4},
            {0,1,4},
            {1,2,3}
        };
        vis.assign(v,false);
        path.push_back(0);
        vis[0]=true;
        if (solve(0, 1)){
        cout<<"Hamiltonian Cycle exists:\n";
        for (int x :path){
        cout<<x<< " ";
        }
        cout<<path[0]<<"\n";
        } 
        else{
        cout<<"No Hamiltonian Cycle\n";
        }
    }
    return 0;
}
