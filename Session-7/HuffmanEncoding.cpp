#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node{
    char ch;
    int freq;
    Node *left,*right;
    Node(char c,int f){
        ch=c;
        freq=f;
        left=right=nullptr;
    }
};
struct Compare{
    bool operator()(Node* l,Node* r){
        return l->freq>r->freq;
    }
};
void printCodes(Node* root,string code){
    if(!root)return;
    if(!root->left&&!root->right)
        cout<<root->ch<<" : "<<code<<endl;
    printCodes(root->left,code+"0");
    printCodes(root->right,code+"1");
}
void huffmanEncoding(vector<char>& chars,vector<int>& freq){
    priority_queue<Node*,vector<Node*>,Compare> pq;
    for(int i=0;i<chars.size();i++)
        pq.push(new Node(chars[i],freq[i]));
    while(pq.size()>1){
        Node* left=pq.top();pq.pop();
        Node* right=pq.top();pq.pop();
        Node* newNode=new Node('$',left->freq+right->freq);
        newNode->left=left;
        newNode->right=right;
        pq.push(newNode);
    }
    Node* root=pq.top();
    cout<<"Huffman Codes:\n";
    printCodes(root,"");
}
int main(){
    int n;
    cout<<"Enter number of characters: ";
    cin>>n;
    vector<char> chars(n);
    vector<int> freq(n);
    cout<<"Enter characters:\n";
    for(int i=0;i<n;i++)
        cin>>chars[i];
    cout<<"Enter frequencies:\n";
    for(int i=0;i<n;i++)
        cin>>freq[i];
    huffmanEncoding(chars,freq);
    return 0;
}
