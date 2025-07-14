/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push( {root, 0} );
        map<int, int> m;    // (root->val , y)
        if(root == NULL){
            return {};
        }
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int y=q.front().second;
            q.pop();

            if(m.find(y) == m.end()){ // not found
                m[y] = curr->val;
            }

            if(curr->right){
                q.push({curr->right, y+1});
            }
            if(curr->left){
                q.push({curr->left, y+1});
            }
        }

        vector<int>ans;
        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};
