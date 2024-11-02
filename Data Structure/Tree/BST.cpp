#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node* parent;
};
struct node *root = NULL;

struct node *insert_into_tree(struct node *ptr, int data)
{
    if (ptr == NULL)
    {
        struct node *ptr = new node();
        ptr->data = data;
        ptr->left = NULL;
        ptr->right = NULL;
        ptr -> parent = NULL;
        return ptr;
    }

    if (ptr->data > data){
        struct node* leftchild = insert_into_tree(ptr->left, data);
        ptr -> left = leftchild;
        leftchild -> parent = ptr;
    }

    else
        struct node* rightchild = insert_into_tree(ptr->right, data);
        ptr -> right = rightchild;
        rightchild -> parent = ptr;

    return ptr;
}

void takeInput()
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insert_into_tree(root, data);
        cin >> data;
    }
}

struct node *search_data(struct node *root, int data)
{
    while (root != NULL)
    {
        if (root->data == data)
            return root;

        else if (root->data > data)
            root = search_data(root->left, data);

        else
            root = search_data(root->right, data);
    }

    return NULL;
}

struct node *minVal(struct node *root)
{
    struct node *temp = root;

    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

struct node *maxVal(struct node *root)
{
    struct node *temp = root;

    while (temp->right != NULL)
        temp = temp->right;

    return temp;
}

struct node* delete_node(struct node* root, int val){

    if(root == NULL)
    return NULL;

    if(root -> data == val){

        if(root -> left == NULL && root -> right == NULL){
            free(root);
            return NULL;
        }

        if(root -> left != NULL && root -> right == NULL){
            struct node* temp = root -> left;
            free(root);
            return temp;
        }

        if(root -> left == NULL && root -> right != NULL){
            struct node* temp = root -> right;
            free(root);
            return temp;
        }

        if(root -> left != NULL && root -> right != NULL){
            int min = minVal(root -> right) -> data;
            root -> data = min;
            root -> right = delete_node(root -> right, min);

            return root;
        }
    }
    else if(root -> data > val)
        root -> left = delete_node(root -> left,val);
    else
    root -> right = delete_node(root -> right, val);

    return root;
    
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{

    cout << "Enter data to create BST: " << endl;
    takeInput();

    if (search_data(root, 10) == NULL)
        cout << "Not found" << endl;
    else
        cout << "Found" << endl;

    delete_node(root, 5);

    cout << endl
         << "Inorder print:" << endl;
    inorder(root);
}