// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
106. �����������������й��������
https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

����һ��������������������������������
ע��:
	����Լ�������û���ظ���Ԫ�ء�
*/

/*����˼·�� :	���õݹ���뷨��������ں��������βԪ�ؼ�Ϊ��Ԫ�ء�������������ҵ���Ԫ�أ�
����ߵ�����Ԫ��Ϊ�ýڵ���������Ľڵ㣬��Ԫ��Ϊ�ýڵ���������Ľڵ㣬ͬʱ��������ȱ�����
�ýڵ���������ϵ����нڵ㣬�ڱ����������ϵ����нڵ㡣��˿��Ը���������������������ڵ����Ŀ
�ҵ��������ҽڵ��Ԫ�أ������Ϊ�����µ��������кͺ������У��ݹ������������ֻ��һ��Ԫ�أ�
��ʱ��Ϊ��Ԫ��ΪҶ�ӽڵ㣬���ء�
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
TreeNode* BuildTree(vector<int>&, vector<int>&);
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0)
			return NULL;
		return BuildTree(inorder, postorder);
	}
};

TreeNode* BuildTree(vector<int>& inorder, vector<int>& postorder) {
	int num = postorder.size();
	TreeNode* root = new TreeNode(postorder[num - 1]);
	if (inorder.size() == 1) {
		return root;
	}
	auto iter = find(inorder.begin(), inorder.end(), root->val);
	if (iter != inorder.begin()) {
		vector<int> left_in(inorder.begin(), iter);
		//��ǰ�������������������Ԫ���ǴӺ������е�ͷ��ʼ��
		vector<int> left_post(postorder.begin(), postorder.begin() + left_in.size());
		root->left = BuildTree(left_in, left_post);
	}
	if (iter != inorder.end() - 1) {
		vector<int> right_in(iter + 1, inorder.end());
		//��ǰ�������������������Ԫ�ؽ�ֹ�ú������е�βԪ��֮ǰ
		vector<int> right_post(postorder.end() - right_in.size() - 1, postorder.end() - 1);
		root->right = BuildTree(right_in, right_post);
	}
	return root;
}