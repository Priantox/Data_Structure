#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

struct node *create()
{
    int data;
    struct node *ptr = new node();

    cout << "Enter data: " << endl;
    cin >> data;

    if (data == -1)
        return NULL;

    ptr->data = data;
    cout << "Enter left child of " << data << endl;
    ptr->left = create();

    cout << "Enter right child of " << data << endl;
    ptr->right = create();

    return ptr;
}

void preorder(struct node *root)
{

    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{

    root = create();

    cout << endl
         << "Pre order:" << endl;
    preorder(root);
    cout << endl
         << "In order:" << endl;
    inorder(root);
    cout << endl
         << "Post order:" << endl;
    postorder(root);
}