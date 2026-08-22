class Solution{
    public:
    vector<int> topView(TreeNode *root){
        vector<int> ans;
        if(root==NULL) return ans;

        map<int,int>mpp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode *node = it.first;
            int vertical = it.second;

            if(mpp.find(vertical) == mpp.end()) mpp[vertical] = node->data;

            if(node->left) q.push({node->left,vertical-1});
            if(node->right) q.push({node->right,vertical+1});

        }

        for(auto it : mpp){
            ans.push_back(it.second);
        }

        return ans;

    }
};