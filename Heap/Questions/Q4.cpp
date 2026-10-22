#include<iostream>
#include<stack>
using namespace std;

// Is Binary Tree a Heap(max)?
// A good basic question
// given a binary tree, you have to tell whether it's a max Heap or not.
// O(n) T.C.   


class Solution {
  public:
    int countNodes(struct Node* tree){
        if(tree == NULL){
            return 0;
        }
        
        int ans = 1 + countNodes(tree->left) + countNodes(tree->right);
        return ans;
    }
    
    bool isCBT(struct Node* tree, int index, int cnt){
        // Do a dry run then this fun will be easy to understand.
        if(tree == NULL){
            return true;
        }
        
        if(index >= cnt){     // imp condn, hum sabko index de denge and we'll check ki vo number of nodes 
            return false;     // se jyada na ho taaki left pehle bharega waali property satisfy ho ske.
        }
        else{
            bool left = isCBT(tree->left, 2*index + 1, cnt);            // this index is for zero based
            bool right = isCBT(tree->right, 2*index + 2, cnt);          // indexing
            return (left && right);
        }
        
    }
    
    bool isMaxOrder(struct Node* root){
        // leaf node.
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        // if right NULL hai then left se compare karo, and return because that's last node by property of CBT.
        // left NULL and right non NULL wala case bn hi nhi skta by property of CBT. 
        if(root->right == NULL){
            return (root->data > root->left->data);
        }
        else{
            bool left = isMaxOrder(root->left);         // left check karke aayo ki maxorder follow ho rha hai na.
            bool right = isMaxOrder(root->right);       // check right.
            
            // check left and right hone chahiye and then present node bhi honi chahiye.
            return (left && right && (root->data > root->left->data) && (root->data > root->right->data));
        }
  
    }
  
    bool isHeap(struct Node* tree) {
        int totalCount = countNodes(tree);          // nodes in binary tree count kar liye.
        
        if(isCBT(tree,0,totalCount) && isMaxOrder(tree)){       // CBT hona chaiye and maxorder of heap satisfy karna chahiye.
            return true;
        }
        else{
            return false;
        }
    }
};
