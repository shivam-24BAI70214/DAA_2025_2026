#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
    int weight;
    int value;
    double ratio;
};
int main() {
    int n=3;
    double capacity=50;
    vector<Item>items={
        {10, 60, 0},
        {20, 100, 0},
        {30, 120, 0}
    };
    for (int i=0;i<n;i++) {
        items[i].ratio=(double)items[i].value/items[i].weight;
    }
    sort(items.begin(),items.end(),[](Item a, Item b) {
        return a.ratio > b.ratio;
    });
    double curr_wt = 0;
    double curr_value = 0;
    for (int i = 0; i < n; i++) {
        if (curr_wt + items[i].weight <= capacity) {
            curr_wt += items[i].weight;
            curr_value += items[i].value;
        } else {
            double remaining = capacity - curr_wt;
            curr_value+=items[i].value * (remaining / items[i].weight);
            break;
        }
    }
    cout<<"Maximum value in knapsack = "<<curr_value<<endl;
    return 0;
}
