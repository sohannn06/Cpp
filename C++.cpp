#include <iostream>

using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
node* newNode(int item)
{
    node* temp = new node();
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node* Insert(node* root, int item)
{
    if(root == NULL)
    {
        root = newNode(item);
    }
    else if(item<=root->data)
    {
        root->left = Insert(root->left, item);
    }
    else{
        root->right = Insert(root->right, item);
    }
    return root;
}
void PreOrder(node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
node* FindMin(node* root)
{
    if(root->left == NULL)
        return root;
    else
        return FindMin(root->left);
}
bool Search(node* root, int item)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->data == item)
    {
        return true;
    }
    else if(item < root->data)
    {
        return Search(root->left, item);
    }
    else
    {
        return Search(root->right, item);
    }
}
int bigger(int h1, int h2)
{
    if(h1>=h2)
        return h1;
    else
        return h2;
}
int Height(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return bigger(Height(root->left), Height(root->right)) +1;
    }
}
node* Delete(node* root, int item)
{
    if(root == NULL)
    {
        return root;
    }
    else if(item<root->data)
    {
        root->left = Delete(root->left, item);
    }
    else if(item>root->data)
    {
        root->right = Delete(root->right, item);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL)
        {
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            node* temp = root;
            root = root->left;
            delete temp;
        }
        else{
            node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}
int main()
{
    node* root = NULL;
    root = Insert(root,25);
    root = Insert(root,10);
    root = Insert(root,40);
    root = Insert(root,5);
    root = Insert(root,15);
    root = Insert(root,30);
    root = Insert(root,50);
    PreOrder(root);
    cout<<endl;
    cout<<FindMin(root)->data<<endl;
    return 0;
}
