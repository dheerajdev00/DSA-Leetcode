
class Solution{
	public:
		vector<int> inorder(TreeNode* root){
	        stack<TreeNode*> st;
            TreeNode *node = root;
            vector<int> In;

            while(true){
                if(node != NULL){
                    st.push(node);
                    node = node->left;
                }
                else{
                    if(st.empty()==true) break;
                    node = st.top();
                    st.pop();
                    In.push_back(node->data);
                    node = node->right;
                }
            }
            return In;
		}
};