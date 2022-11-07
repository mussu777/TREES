#include<iostream>
#include<queue>
using namespace std;



class BinaryTreeNode {
    public:
        int data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

    BinaryTreeNode(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
    

void inorder(BinaryTreeNode* root, int &count) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, count);
   	
    //leaf node
    if(root->left == NULL && root->right == NULL) {
        count++;
    }
    
    inorder(root->right, count);

}


int noOfLeafNodes(BinaryTreeNode* root){
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}