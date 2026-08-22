
/* THIS IS ROOT TO A GIVEN NODE PATH */
class Solution{
	public:

        bool getPath(TreeNode *root, vector<int> &arr, int x){
            if(!root) return false;

            arr.push_back(root->val);
            if(root->val == x){
                return true;
            }

            if(getPath(root->left,arr,x) || getPath(root->right,arr,x)){
                return true;
            }

            arr.pop_back();
            return false;
        }

		<vector<int> RootToNode(TreeNode* root, int x) {
            vector<int> arr;
            if(root == NULL) return arr;

            getPath(root,arr,x);
            return arr;
		}
};