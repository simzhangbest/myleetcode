#include <stdio.h>
#include <vector>
//最终算法： 求P节点的路径，Q节点的路径，两路径上最后一个相同的节点 
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(int x) : val(x), left(NULL), right(NULL){
		
	} 
};


//从根节点遍历 至该节点，找到该节点之后就结束搜索
// 将遍历过程中遇到的节点按照顺序存储起来 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> path; //申明遍历调用的临时栈 
        std::vector<TreeNode*> node_p_path;
		std::vector<TreeNode*> node_q_path; 
		int finish = 0;
		
		preorder(root, p, path, node_p_path, finish);
		path.clear();
		finish = 0;
		preorder(root, q, path, node_q_path, finish);
		int path_len = 0; // 获取路径的长度
		
		if(node_p_path.size() < node_q_path.size()) {
			path_len = node_p_path.size();
		} else {
			path_len = node_q_path.size();
		}
		
		TreeNode *result = 0; //同时遍历根到p,q两个节点的路径上的节点
		for(int i = 0; i < path_len; i++) {
			if(node_p_path[i] == node_q_path[i]) {
				result = node_p_path[i]; //找到了 
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