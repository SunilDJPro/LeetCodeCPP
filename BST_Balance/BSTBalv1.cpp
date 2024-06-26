#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {} //null default constructor
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {} //parametrized single param construct
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} //parametrized value (3 param) construct

};


class Solution {
    public:
        TreeNode* balanceBST(TreeNode* root) {
            vector<int> nodes;
            inorderTraversal(root, nodes);
            return buildBalancedBST(nodes, 0, nodes.size() - 1);
        }

    private:
        void inorderTraversal(TreeNode* root, vector<int>& nodes) {
            if (root == nullptr) return;
            inorderTraversal(root->left, nodes);
            nodes.push_back(root->val); //push back the current root value to the node vector<int>
            inorderTraversal(root->right, nodes);
        }

        TreeNode* buildBalancedBST(const vector<int>& nodes, int left, int right) {
            if(left > right) return nullptr;
            int mid = left + (right - left) / 2;
            TreeNode* root = new TreeNode(nodes[mid]);
            root->left = buildBalancedBST(nodes, left, mid -1);
            root->right = buildBalancedBST(nodes, mid + 1, right);
            return root;
        }
};


void printLevelOrder(TreeNode* root) {
    if (!root) return;
    vector<TreeNode*> currentLevel{root};
    while (!currentLevel.empty()) {
        vector<TreeNode*> nextLevel;
        for (TreeNode* node : currentLevel) {
            if (node) {
                cout << node->val << " ";
                nextLevel.push_back(node->left);
                nextLevel.push_back(node->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
        currentLevel = nextLevel;
    }
}

int main() {
    Solution solution;

    // Test case 1
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->right = new TreeNode(3);
    root1->right->right->right = new TreeNode(4);
    TreeNode* balancedRoot1 = solution.balanceBST(root1);
    cout << "Balanced BST for test case 1:" << endl;
    printLevelOrder(balancedRoot1);

    // Test case 2
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    TreeNode* balancedRoot2 = solution.balanceBST(root2);
    cout << "Balanced BST for test case 2:" << endl;
    printLevelOrder(balancedRoot2);

    return 0;
}