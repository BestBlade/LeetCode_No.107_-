/* ------------------------------------------------------------------|
给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层序遍历为：

[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了91.91%的用户
*	内存消耗：11.7 MB, 在所有 C++ 提交中击败了59.48%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    queue<TreeNode*> q;
    if (!root) {
        return {};
    }
    q.emplace(root);
    vector<vector<int>> res;
    while(!q.empty()) {
        int len = q.size();
        vector<int> tmp;
        while (len--) {
            TreeNode* curr = q.front();
            q.pop();
            tmp.emplace_back(curr->val);
            if (curr->left) {
                q.emplace(curr->left);
            }
            if (curr->right) {
                q.emplace(curr->right);
            }
        }
        res.emplace_back(tmp);
    }
    reverse(res.begin(), res.end());
    return res;
}