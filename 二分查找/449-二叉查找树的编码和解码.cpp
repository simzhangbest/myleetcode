//
// Created by simzhang on 2019/2/2.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stdio.h>
#include <string>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

void change_int_to_string(int val, std::string &str_val) {
    std::string tmp;
    while(val) {                    //遍历 val 每次将val的最低为转换为字符， 添加到tmp的尾部
        tmp += val % 10 + '0';
        val = val / 10;
    }
    for (int i = tmp.length() - 1 ; i >= 0; i--) {
        str_val += tmp[i];          // 逆序将字符串添加到 str_val 中
    }

    str_val += '#';                 // 转换的每个数字后面加 "#"
}

void BST_preoder(TreeNode *node, std::string &data) {
    if (!node) {
        return;
    }
    std::string str_val;
    change_int_to_string(node->val, str_val);
    data += str_val;
    BST_preoder(node->left, data);
    BST_preoder(node->right, data);
}


class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string data;
        BST_preoder(root, data);
        return  data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        if (data.length() == 0) {
            return NULL;
        }

        std::vector < TreeNode * > node_vec;
        int val = 0;
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == '#') {
                node_vec.push_back(new TreeNode(val));
                val = 0;
            } else {
                val = val * 10 + data[i] - '0';
            }
        }

        for (int i = 1; i < node_vec.size(); i++) {
            BST_insert(node_vec[0], node_vec[i]);
        }

        return node_vec[0];
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

//int main() {
//    std::string str = "123#456#10000#1#";
//    int val = 0;
//    for (int i = 0; i < str.length(); i++) {
//        if (str[i] == '#') {
//            printf("val = %d\n", val);
//            val = 0;
//        } else {
//            val = val * 10 + str[i] - '0';
//        }
//    }
//    return 0;
//}

int main () {
    TreeNode a(8);
    TreeNode b(3);
    TreeNode c(10);
    TreeNode d(1);
    TreeNode e(6);
    TreeNode f(15);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    Codec solve;
    std::string data = solve.serialize(&a);
    printf("%s\n", data.c_str());
    TreeNode *root = solve.deserialize(data);
    preorder_print(root, 0);
}