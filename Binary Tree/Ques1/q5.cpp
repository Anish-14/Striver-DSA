#include<iostream>
using namespace std;
#include "syntax.h"

//  pre,in,post order traversal in one go 

// this is how we can save every traversal in one go using only one stack
// dry run to understand this
vector<int> preInPostTraversal(TreeNode* root){
    if(root == NULL)    return {};
    stack<pair<TreeNode*, int> > st;
    st.push({root, 1});         // 1 --> pre, 2 --> in, 3 --> post
    vector<int> pre, in , post;  
    
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){     // it belongs to the preOrder traversal
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left != NULL){
                st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2){      // it belongs to the inOrder Traversal now
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right != NULL){
                st.push({it.first->right, 1});
            }
        }
        else{                   // here we have to do nothing as we just go back in postOrder after saving the value of the node
            post.push_back(it.first->val);      
        }
    }

    return in,pre,post;
}





