class Solution{	
	public:

        int Floor(TreeNode *root, int key){
            int floor = -1;

            while(root){
                if(root->data == key){
                    return root->data;
                }
                if(root->data < key){
                    floor = root->data; //this might be ans 
                    root = root->right; //go right and check for greater val <key
                }
                else{
                    root = root->left;
                }
            }
            return floor;
        }

        int Ceil(TreeNode *root, int key){
            int ceil = -1;

            while(root){
                if(root->data == key){
                    return root->data;
                }
                if(root->data > key){
                    ceil = root->data; //this might be ans 
                    root = root->left; //go left and check for smaller val > key
                }
                else{
                    root = root->right;
                }
            }
            return ceil;
        }

		vector<int> floorCeilOfBST(TreeNode* root,int key){
			return {Floor(root,key), Ceil(root,key)};
		}
};