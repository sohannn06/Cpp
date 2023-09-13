#include <iostream>

using namespace std;

struct node{

  int data ;
  node* left;
  node* right;


};


 node* Newnode(int item){

  node* temp= new node();

  temp->data=item;
  temp->left=NULL;
  temp->right=NULL;
   return temp;

 }

node* Insert(node* root, int data){

   if(root == NULL){
    root = Newnode(data);

   }

   else if(data < root->data){

    root->left = Insert(root->left,data);
   }
   else {

    root->right = Insert(root->right,data);
   }

   return root;
}

void preOrder(node* root){

 if(root == NULL){
    return;
 }

 cout<<root->data<<" ";
 preOrder(root->left);
 preOrder(root->right);


}

void inOrder(node* root){

 if(root == NULL){
    return;
 }


 inOrder(root->left);
 cout<<root->data<<" ";
 inOrder(root->right);


}

void postOrder(node* root){

 if(root == NULL){
    return;
 }


 postOrder(root->left);
 postOrder(root->right);
  cout<<root->data<<" ";


}
node* FindMin(node* root)
{
    if(root->left == NULL)
        return root;
    else
        return FindMin(root->left);
}

bool search(node*root,int item)
{
    if(root == NULL)
    {

        return false;
    }
    else if(root->data == item)
    {
        return true;
    }
    else if (item<root->data)
    {
        return search(root->left,item);
    }
    else
    {
        return search (root->right,item);
    }
}
int bigger(int h1, int h2)
{
    if(h1>=h2)
        return h1;
    else{return bigger(Height(roor->left),Height(root->right))+1;}
}
node Delete (node* root,int item)
{
    if(root==NULL)
    {
        return root:
    }
    else if(item<root->data)
    {
        root->left = Delete(root->left,item);

            }
            else if (item->root->data)
            {
                root->right = Delete(root->right,item)
            }
            else
            {
                if(root->left == NULL && root ->right == NULL)
                {
                    delete root;
                    root = NULL;

                }
                else  if (root->left == NULL)
                {
                    node * TEMP = root;
                    root = root->right;
                    delete temp;
                }
                else if(root->right == NULL)
                {
                    node*temp = root;
                    root = root->left;
                    delete temp;
                }
                else
                {
                    node* temp = FindMin(root->right)
                    root->data =temp->data;
                    root->right = Delete(root->right,temp->data)
                }
            }
            return root;
}

int main()
{
    node* root = new node();

    root= Insert(root,25);
    root= Insert(root,15);
    root= Insert(root,20);
     root= Insert(root,50);


    preOrder(root);
    cout<<endl;
    inOrder(root);
     cout<<endl;
    postOrder(root);
    cout<<FindMin<<endl

    return 0;
}
