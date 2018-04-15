//操作给定的二叉树，将其变换为源二叉树的镜像。
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    void Mirror(TreeNode *p) {
    if(p){
            swap(p -> left, p -> right);
            Mirror(p -> left);
            Mirror(p -> right);
        }
    }
};
*/
 
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        //递归实现
        /*if(pRoot==NULL)
            return;
        TreeNode *ptemp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=ptemp;
        if(pRoot->left)
            Mirror(pRoot->left);
        if(pRoot->right)
            Mirror(pRoot->right);*/
        //非递归实现
        if(pRoot==NULL) return;
        stack<TreeNode*> stk;
        stk.push(pRoot);
        while(!stk.empty()){
            TreeNode* tree=stk.top();
            stk.pop();
            if(tree->left!=NULL || tree->right!=NULL){
                TreeNode *ptemp=tree->left;
                tree->left=tree->right;
                tree->right=ptemp;
            }
            if(tree->left)
                stk.push(tree->left);
            if(tree->right)
                stk.push(tree->right);
        }
    }
};