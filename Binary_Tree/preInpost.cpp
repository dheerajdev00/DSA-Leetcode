class Solution{
	public:
		vector<vector<int>> treeTraversal(TreeNode* root){
			vector<vector<int>> ans;
            if(root==NULL) return ans;

            stack<pair<TreeNode*, int>>st;
            vector<int> pre,In,post;
            st.push({root,1});

            while(!st.empty()){
                auto it = st.top();
                st.pop();


                if(it.second==1){
                    pre.push_back(it.first->data);
                    it.second++;
                    st.push(it);

                    if(it.first->left != NULL){
                        st.push({it.first->left, 1});
                    }

                }
                else if(it.second==2){
                    In.push_back(it.first->data);
                    it.second++;
                    st.push(it);

                    if(it.first->right != NULL){
                        st.push({it.first->right,1});
                    }
                }
                else{//dont push it back again
                    post.push_back(it.first->data);
                }
            }
            ans.push_back(In);
            ans.push_back(pre);
            ans.push_back(post);

            return ans;
		}
};