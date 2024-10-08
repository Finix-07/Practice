#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& adj, 
                unordered_set<TreeNode*>& st) {

    if(root == NULL) {
        return;
    }

    if(root->left == NULL && root->right == NULL) { //LEAF NODE
        st.insert(root);
    }

    if(prev != NULL) {
        adj[root].push_back(prev);
        adj[prev].push_back(root);
    }

    makeGraph(root->left, root, adj, st);
    makeGraph(root->right, root, adj, st);

}

int countPairs(TreeNode* root, int distance) {
    unordered_map<TreeNode*, vector<TreeNode*>> adj; //Graph
    unordered_set<TreeNode*> st; //leaf nodes

    makeGraph(root, NULL, adj, st);

    int count = 0; //count of good node pairs

    for(auto &leaf : st) {

        //BFS hit karo and see if you can find another leaf nodes within distance
        queue<TreeNode*> que;
        unordered_set<TreeNode*> visited;
        que.push(leaf);
        visited.insert(leaf);


        for(int level = 0; level <= distance; level++) { //only go till level <= distance
            int size = que.size();
            while(size--) { //level processed
                TreeNode* curr = que.front();
                que.pop();

                if(curr != leaf && st.count(curr)) { 
                    count++;
                }

                for(auto &ngbr : adj[curr]) {
                    if(!visited.count(ngbr)) {
                        que.push(ngbr);
                        visited.insert(ngbr);
                    }
                }
            }
        }
    }
    return count/2;
}

int main(){

    return 0;
}