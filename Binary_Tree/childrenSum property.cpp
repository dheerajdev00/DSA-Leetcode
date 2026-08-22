/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

/* THIS IS FOR CHECKING CHILDREN SUM PROPERTY */

class Solution {
public:
    bool checkChildrenSum(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        //leaf node 
        if(root->left==NULL && root->right==NULL){
            return true;
        }

        int l = (root->left!=NULL) ? root->left->val : 0;
        int r = (root->right!=NULL) ? root->right->val : 0;


        if(root->val != l+r){
            return false;
        }

        return  checkChildrenSum(root->left) && checkChildrenSum(root->right);
    }
};

/* THIS IS FOR MAINTAINING CHILDREN SUM PROPERTY IF IT VIOLATES */

class Solution {
public:
    Void  ChildrenSumProp(TreeNode* root) {
        if(root==NULL) return;

        int child = 0;
        if(root->left) child += root->left->val;
        if(root->right) child += root->right->val;

        if(child >= root->val) root->val = child; // If children have excess, increase parent
        else{
            if(root->left) root->left->val = root->val; // If parent has excess, increase one child
            else if(root->right) root->right->val = root->val;
        }

        ChildrenSumProp(root->left);
        ChildrenSumProp(root->right);

        // Fix parent while coming back
        int tot = 0;
        if(root->left) tot += root->left->val;
        if(root->right) tot += root->right->val;
        if(root->left || root->right) root->val = tot;
    }
};