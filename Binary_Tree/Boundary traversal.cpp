class Solution{
public:

    bool isLeaf(TreeNode *root){
        return root->left==NULL && root->right==NULL;
    }

    void Addleftboundary(TreeNode *root, vector<int> &res){
        TreeNode *temp = root->left;
        while(temp){
            if(!isLeaf(temp)) res.push_back(temp->data);
            if(temp->left) temp=temp->left;
            else temp = temp->right;
        }
    }

    void Addleaf(TreeNode *root, vector<int> &res){
        if(isLeaf(root)){
          res.push_back(root->data);
          return;
        }
        
        if(root->left) Addleaf(root->left,res);
        if(root->right) Addleaf(root->right,res);
    }

    void AddRightboundary(TreeNode *root, vector<int> &res){
        TreeNode *temp = root->right;
        vector<int> tmp;
        while(temp){
            if(!isLeaf(temp)) tmp.push_back(temp->data);
            if(temp->right) temp=temp->right;
            else temp = temp->left;
        }

        for(int i=tmp.size()-1; i>=0; i--){
            res.push_back(tmp[i]);
        }
    }

    vector <int> boundary(TreeNode* root){
    	vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);

        Addleftboundary(root,res);
        Addleaf(root,res);
        AddRightboundary(root,res);

        return res;
    }
};