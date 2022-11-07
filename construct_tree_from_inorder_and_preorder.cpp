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

void printPostOrder(Node* root)
{
    if(root == NULL)
    {
        return ;
    }

    printPostOrder(root->left);
    printPostOrder(root->right);

    cout<<root->data<<" ";
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


    Node* solve(int inorder[] , int preorder[] , int &index ,
                 int inorderStart , int inorderEnd , int n , map<int,int> &nodeToIndex)
    {   
        // base case
        if (index >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }

        // create a root node for element
        int element = preorder[index++];
        Node* root = new Node(element);

        // find element's index in inorder
        int position = nodeToIndex[element];


        // recursive calls 

        root->left = solve(inorder , preorder , index , inorderStart , position-1 , n , nodeToIndex);
        root->right = solve(inorder , preorder , index , position+1 , inorderEnd , n , nodeToIndex);

        return root; 

    }



    Node* buildTree(int inorder[] , int preorder[] , int n)
    {
        int preOrderIndex = 0;
        map<int,int> nodeToIndex;

        // create nodes to index mapping
        createMapping(inorder , nodeToIndex , n);

        Node* ans = solve(inorder , preorder , preOrderIndex , 0 , n-1 , n , nodeToIndex);
        return ans; 
    }
};


int main()
{
    int n;
    cin>>n;

    int inorder[n] , preorder[n];
    for(int i=0; i<n; i++)
    cin>>inorder[i];
    
    for(int i=0; i<n; i++)
    cin>>preorder[i];
    
    Solution obj;
    Node* root = obj.buildTree(inorder , preorder , n);
    printPostOrder(root);

    cout<<endl;

    return 0;
}