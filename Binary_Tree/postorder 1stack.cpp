USING ONE STACK

class Solution{
	public:
		vector<int> postorder(TreeNode* root){
	        vector<int> ans;
            if(root==NULL) return ans;
            stack<TreeNode*> st;
            TreeNode* curr = root;

            while(curr!=NULL || !st.empty()){
                if(curr!=NULL){ //keep going left
                    st.push(curr);
                    curr = curr->left;
                }
                else{
                    TreeNode *temp = st.top()->right;
                    if(temp==NULL){ //left and right both null
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->data);

                        while(!st.empty() && temp==st.top()->right){ //if it is equal to tops right then next ele will be top only
                            temp = st.top();
                            st.pop();
                            ans.push_back(temp->data);
                        }
                    }
                    else{ //right is not null.. again go to extreme left
                        curr = temp;
                    }
                }
            }
            return ans;
		}
};