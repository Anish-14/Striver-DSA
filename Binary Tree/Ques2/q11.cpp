#include<iostream>
using namespace std;
#include "syntax.h"

// Children sum property
// we have to tell how much +1 we've to do to each node to satisfy a given BT the children sum property
// we have to change the BT 

// this solution works in O(n) but it doesn't guarantee minimum use of +1 operations 

void changeTree(Node* root){
    if(root == NULL)    return;

    int child = 0;
    if(root->left)  child += root->left->val;
    if(root->right) child += root->right->val;

    if(child >= root->val){
        root->val = child;
    }
    else{
        if(root->left)  root->left->val = root->val;
        if(root->right) root->right->val = root->val;
    }

    // call left and right function calls
    changeTree(root->left);
    changeTree(root->right);

    // here we're guaranteed that the children are individually greater than the parent
    // so the only possiblity is that the sum will be greater than the parent and hence
    // we have to assign it to parent
    int tot = 0;
    if(root->left)  tot += root->left->val;
    if(root->right) tot += root->right->val;

    // assign this to the root node if it is has atleast one children
    if(root->left || root->right)   root->val = tot;

}











// for minimum +1 operations a solution comes in my mind where we can track the height of the tree 
// along with and then transfrom it into something keepting the lower nodes in ming but that would 
// be complex and I don't know whether it works or not 🙁


