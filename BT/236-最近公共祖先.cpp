#include <stdio.h>
#include <vector>
//�����㷨�� ��P�ڵ��·����Q�ڵ��·������·�������һ����ͬ�Ľڵ� 
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(int x) : val(x), left(NULL), right(NULL){
		
	} 
};


//�Ӹ��ڵ���� ���ýڵ㣬�ҵ��ýڵ�֮��ͽ�������
// �����������������Ľڵ㰴��˳��洢���� 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> path; //�����������õ���ʱջ 
        std::vector<TreeNode*> node_p_path;
		std::vector<TreeNode*> node_q_path; 
		int finish = 0;
		
		preorder(root, p, path, node_p_path, finish);
		path.clear();
		finish = 0;
		preorder(root, q, path, node_q_path, finish);
		int path_len = 0; // ��ȡ·���ĳ���
		
		if(node_p_path.size() < node_q_path.size()) {
			path_len = node_p_path.size();
		} else {
			path_len = node_q_path.size();
		}
		
		TreeNode *result = 0; //ͬʱ��������p,q�����ڵ��·���ϵĽڵ�
		for(int i = 0; i < path_len; i++) {
			if(node_p_path[i] == node_q_path[i]) {
				result = node_p_path[i]; //�ҵ��� 
			}
		} 
		return result; 
    }
    
    void preorder(TreeNode *node, TreeNode *search, 
					std::vector<TreeNode*> &path,
    				std::vector<TreeNode*> &result, int &finish) {
				    	if(!node || finish) {
	    					return;
	    				}
	    				path.push_back(node);
	    				if(node == search) {
				    		finish = 1;
				    		result = path;
				    	}
				    	preorder(node->left, search, path, result, finish);
				    	preorder(node->right, search, path, result, finish);
				    	path.pop_back();
				    }
	 
};