#include<bits/stdc++.h> 
using namespace std; 


// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node (int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPreOrder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    cout<<root->data<<" ";
    
    printPreOrder(root->left);
    printPreOrder(root->right);


}


class Solution
{
    public :

    void createMapping (int inorder[] , map<int,int> &nodeToIndex , int n)
    {
        for(int i=0; i<n; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }
    }


    Node* solve(int inorder[] , int postOrder[] , int &index ,
                 int inorderStart , int inorderEnd , int n , map<int,int> &nodeToIndex)
    {   
        // base case
        if (index < 0 || inorderStart > inorderEnd)
        {
            return NULL;
        }

        // create a root node for element
        int element = postOrder[index--];
        Node* root = new Node(element);

        // find element's index in inorder
        int position = nodeToIndex[element];


        // recursive calls 

        root->right = solve(inorder , postOrder , index , position+1 , inorderEnd , n , nodeToIndex);
        root->left = solve(inorder , postOrder , index , inorderStart , position-1 , n , nodeToIndex);

        return root; 

    }



    Node* buildTree(int inorder[] , int postOrder[] , int n)
    {
        int postOrderIndex = n-1;
        map<int,int> nodeToIndex;

        // create nodes to index mapping
        createMapping(inorder , nodeToIndex , n);

        Node* ans = solve(inorder , postOrder , postOrderIndex , 0 , n-1 , n , nodeToIndex);
        return ans; 
    }
};


int main()
{
    int n;
    cin>>n;

    int inorder[n] , postOrder[n];
    for(int i=0; i<n; i++)
    cin>>inorder[i];
    
    for(int i=0; i<n; i++)
    cin>>postOrder[i];
    
    Solution obj;
    Node* root = obj.buildTree(inorder , postOrder , n);
    printPreOrder(root);

    cout<<endl;

    return 0;
}