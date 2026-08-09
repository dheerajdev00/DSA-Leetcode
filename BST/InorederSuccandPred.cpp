class Solution{
	public:

        int InSucc(TreeNode *root, int key){
            int succ = -1;

            while(root){
                if(root->data > key){
                    succ = root->data; //this might be possible ans 
                    root = root->left;  //go left and check for smaller val immediately > key
                }
                else{
                    root = root->right;
                }
            }
            return succ;
        }

        int InPred(TreeNode *root, int key){
            int pred = -1;

            while(root){
                if(root->data < key){
                    pred = root->data; //this might be possible ans 
                    root = root->right;  //go right and check for larger val immediately < key
                }
                else{
                    root = root->left;
                }
            }
            return pred;
        }

		vector<int> succPredBST(TreeNode* root,int key){
			return {InPred(root,key), InSucc(root,key)};
		}
};