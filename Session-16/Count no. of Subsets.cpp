#include <iostream>
#include <vector>
using namespace std;
void findSubsets(vector<int>& arr, vector<int>& subset, int index, int& count){
    cout<<"{ ";
    for(int x:subset) cout<<x<<" ";
    cout<<"}"<<endl;
    count++;
    for(int i=index;i<arr.size();i++){
        subset.push_back(arr[i]);
        findSubsets(arr,subset,i+1,count);
        subset.pop_back();
    }
}
int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> subset;
    int count=0;
    cout<<"\nSubsets are:\n";
    findSubsets(arr,subset,0,count);
    cout<<"\nTotal number of subsets: "<<count<<endl;
    return 0;
}
