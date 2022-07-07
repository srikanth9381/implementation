#include <bits/stdc++.h> 

using namespace std; 

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int x)
{
    Node* temp= new Node;
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
}
void inorder(Node* x)
{
    if(x->left!=NULL){
    inorder(x->left);}
    cout<<x->data<<" ";
    if(x->right!=NULL){
    inorder(x->right);}
}
void insert(Node* t,int key)
{
    queue<Node*> q;
    q.push(t);
    
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp->left==NULL)
            {
                temp->left=newNode(key);
                break;
            }
        else
        {
            q.push(temp->left);
        
        }
         
        if(temp->right==NULL)
            {
                temp->right=newNode(key);
                break;
            }
        else
        {
            q.push(temp->right);
        }
    }


}
void deletDeepest(struct Node* root, 
                  struct Node* d_node) 
{ 
    queue<struct Node*> q; 
    q.push(root); 
  
    // Do level order traversal until last node 
    struct Node* temp; 
    while (!q.empty()) { 
        temp = q.front(); 
        q.pop(); 
        if (temp == d_node) { 
            temp = NULL; 
            delete (d_node); 
            return; 
        } 
        if (temp->right) { 
            if (temp->right == d_node) { 
                temp->right = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->right); 
        } 
  
        if (temp->left) { 
            if (temp->left == d_node) { 
                temp->left = NULL; 
                delete (d_node); 
                return; 
            } 
            else
                q.push(temp->left); 
        } 
    } 
} 
Node* deletion(Node* t,int key)
{
    if(t==NULL)return NULL;
    if(t->left==NULL&&t->right==NULL)
    {
        if(t->data==key)return NULL;
        else return t;
    }

    queue<Node*> q;
    q.push(t);
    Node* key_node=NULL;
    Node* temp;
    while(!q.empty())
    { 
        temp=q.front();
        q.pop();
        if(temp->data==key)
            {
                key_node=temp;
                
            }
         
        if(temp->left)
            {
                q.push(temp->left);
            }
        if(temp->right)
            {
                q.push(temp->right);
            }
    
    }
    if (key_node != NULL) { 
        int x = temp->data; 
        deletDeepest(t, temp); 
        key_node->data = x; 
    } 
    return t; 





}
int main ()
{
    /*struct Node* root = newNode(11); 
    root->left = newNode(12); 
    root->left->left = newNode(8); 
    root->right = newNode(10); 
    root->right->left = newNode(16); 
    root->right->right = newNode(9); 
    cout << "Inorder traversal before insertion:"; 
    inorder(root); 
  
    int key = 13; 
    insert(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after insertion:"; 
    inorder(root); 
  */


    struct Node* root = newNode(11); 
    root->left = newNode(12); 
    root->left->left = newNode(8); 
    root->left->right = newNode(13); 
    root->right = newNode(10); 
    root->right->left = newNode(16); 
    root->right->right = newNode(9); 
  
    cout << "Inorder traversal before deletion : "; 
    inorder(root); 
  
    int key = 12; 
    root = deletion(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    inorder(root); 
  
    return 0; 

}
