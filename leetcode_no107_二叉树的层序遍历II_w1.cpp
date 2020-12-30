/* ------------------------------------------------------------------|
����һ����������������ڵ�ֵ�Ե����ϵĲ�������� ��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����

���磺
���������� [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
�������Ե����ϵĲ������Ϊ��

[
  [15,7],
  [9,20],
  [3]
]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������|
-------------------------------------------------------------------*/

/*
*
*	ִ����ʱ��4 ms, ������ C++ �ύ�л�����91.91%���û�
*	�ڴ����ģ�11.7 MB, ������ C++ �ύ�л�����59.48%���û�
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