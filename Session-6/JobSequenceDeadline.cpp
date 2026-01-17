#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    string job;
    int profit;
    int deadline;
};

int main() {
    vector<Item> items;
    int m;
    cin >> m;

    for(int i=0;i<m;i++) {
        Item temp;
        cin>>temp.job>>temp.profit>>temp.deadline;
        items.push_back(temp);
    }

    int n;
    cout<<"Enter the number of slots:";
    cin>>n;

    sort(items.begin(),items.end(),
         [](const Item& a,const Item& b) {
             return a.profit>b.profit;
         });
    vector<Item*> slot(n,nullptr);
    for(int i = 0;i<items.size();i++) {
        for(int j=items[i].deadline-1;j>=0;j--) {
            if(j<n && slot[j]==nullptr) {
                slot[j]=&items[i];
                break;
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(slot[i] != nullptr) {
            cout<<slot[i]->job<<"  "<<slot[i]->profit<<endl;
        }
    }
    return 0;
}
