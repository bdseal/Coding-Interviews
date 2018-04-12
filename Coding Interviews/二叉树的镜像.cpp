//操作给定的二叉树，将其变换为源二叉树的镜像。
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
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
