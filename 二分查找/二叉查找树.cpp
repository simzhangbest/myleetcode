//
// Created by simzhang on 2019/2/2.
//
#include <stdio.h>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};


// 二叉查找树，插入节点

void BST_insert(TreeNode *node, TreeNode *insert_node) {
    if (insert_node->val < node->val) {
        if (node->left) {
            BST_insert(node->left, insert_node);
        } else {
            node->left = insert_node;
        }
    } else {
        if (node->right) {
            BST_insert(node->right, insert_node);
        } else {
            node->right = insert_node;
        }
    }
}

bool BST_search(TreeNode *node, int value) {
    if (value == node->val) {
        return true;
    }
    if (value < node->val) {
        if (node->left) {
            return BST_search(node->left, value);
        } else {
            return false;
        }
    } else {
        if (node->right) {
            return BST_search(node->right, value);
        } else {
            return false;
        }
    }
}
void preorder_print(TreeNode *node, int layer){
    if (!node) {
        return;
    }
    for (int i = 0; i < layer; i++) {
        printf("-----");
    }
    printf("[%d]\n", node->val);
    preorder_print(node->left, layer + 1);
    preorder_print(node->right, layer + 1);
}

int main() {
    TreeNode root(8);
    std::vector<TreeNode *> node_vec;
    int test[] = { 3, 10, 1, 6, 15};
    for (int i = 0; i < 5; i++) {
        node_vec.push_back(new TreeNode(test[i]));
    }
    for (int j = 0; j < node_vec.size() ; ++j) {
        BST_insert(&root, node_vec[j]);
    }
    preorder_print(&root, 0);
    printf("--------------test BST_search-------------\n");
    for (int l = 0; l < 20; ++l) {
        if (BST_search(&root, l)) {
            printf("%d is in the BST.\n", l);
        } else {
            printf("%d is not in the BST.\n", l);
        }
    }

    for (int k = 0; k < node_vec.size(); ++k) {
        delete node_vec[k];
    }
}