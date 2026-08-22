
class Solution{
	public:
		vector<int> preorder(TreeNode* root){
	       vector<int> pre;
           if(root==NULL) return pre;

           stack<TreeNode*> st;
           st.push(root);

           while(!st.empty()){
            root = st.top();
            st.pop();

            pre.push_back(root->data);

            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
           }

           return pre;
		}
};