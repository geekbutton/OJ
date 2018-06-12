// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
105. ��ǰ��������������й��������
https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

����һ������ǰ�������������������������
ע��:
	����Լ�������û���ظ���Ԫ�ء�
*/

/*����˼·�� :	���õݹ���뷨���������ǰ���������Ԫ�ؼ�Ϊ��Ԫ�ء�������������ҵ���Ԫ�أ�
����ߵ�����Ԫ��Ϊ�ýڵ���������Ľڵ㣬��Ԫ��Ϊ�ýڵ���������Ľڵ㣬ͬʱǰ������ȱ�����
�ýڵ���������ϵ����нڵ㣬�ڱ����������ϵ����нڵ㡣��˿��Ը���������������������ڵ����Ŀ
�ҵ��������ҽڵ��Ԫ�أ������Ϊ�����µ��������к�ǰ�����У��ݹ����ֱ��������ֻ��һ��Ԫ�أ�
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0)
			return NULL;
		return BuildTree(preorder, inorder);
	}
};

TreeNode* BuildTree(vector<int>&preorder, vector<int>& inorder) {
	//����ֻ����һ��Ԫ�أ���ΪҶ�ڵ㣬����Ҷ�ڵ�󷵻�
	if (preorder.size() == 1) {
		TreeNode* node = new TreeNode(preorder[0]);
		return node;
	}
	TreeNode* root = new TreeNode(preorder[0]);			//���ε����ĸ��ڵ㣬��Ӧ��Ҷ�ڵ�
	auto iter_in = find(inorder.begin(), inorder.end(), preorder[0]);	//�ҵ���Ԫ�ص�λ��
	//��������������������ȡ������������������
	if (iter_in != inorder.begin()) {
		//������Ԫ�ظ�Ԫ����������λ�õ���ߣ������Ÿ�Ԫ����ǰ�����еĺ���
		vector<int> left_in(inorder.begin(), iter_in);
		vector<int> left_pre(preorder.begin() + 1, preorder.begin() + 1 + left_in.size());
		root->left = BuildTree(left_pre, left_in);
	}//������������������ȡ������������������
	if (iter_in != inorder.end() - 1) {
		//������Ԫ�ظ�Ԫ����������λ�õ��ұߣ��ɴ�ǰ�����е�������Ԫ����Ŀ����
		vector<int> right_in(iter_in + 1, inorder.end());
		vector<int> right_pre(preorder.end() - right_in.size(), preorder.end());
		root->right = BuildTree(right_pre, right_in);
	}
	return root;
}