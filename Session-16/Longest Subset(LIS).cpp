#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<int> dp(n,1), parent(n,-1);
    int maxLen=1, lastIndex=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                parent[i]=j;
            }
        }
        if(dp[i]>maxLen){
            maxLen=dp[i];
            lastIndex=i;
        }
    }
    vector<int> lis;
    while(lastIndex!=-1){
        lis.push_back(arr[lastIndex]);
        lastIndex=parent[lastIndex];
    }
    for(int i=lis.size()-1;i>=0;i--)
        cout<<lis[i]<<" ";
    cout<<endl<<maxLen;

    return 0;
}
