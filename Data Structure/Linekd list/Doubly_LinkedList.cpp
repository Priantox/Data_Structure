#include <iostream>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head;

void add_to_empty(int data)
{
    struct node *ptr = new node();
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    head = ptr;
}

void add_at_beginning(int data)
{
    if (head == NULL)
    {
        add_to_empty(data);
        return;
    }

    struct node *temp = new node();
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    temp->next = head;
    head->prev = temp;
    head = temp;
}

void add_at_end(int data)
{
    if (head == NULL)
    {
        add_to_empty(data);
        return;
    }

    struct node *temp = new node();
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    struct node *ptr = head;

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;
    temp->prev = ptr;
}

void add_after_position(int data, int pos)
{

    if (head == NULL)
    {
        cout << "Sorry no nodes";
        return;
    }

    struct node *newNode = new node();
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    struct node *temp = head;
    struct node *temp2 = NULL;

    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }

    if (temp->next == NULL)
    {
        temp->next = newNode;
        newNode->prev = temp;
    }
    else
    {
        temp2 = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = temp2;
        temp2->prev = newNode;
    }
}

void add_before_position(int data, int pos)
{
    if (head == NULL)
    {
        cout << "Sorry" << endl;
        return;
    }

    struct node *dnode = new node();
    dnode->prev = NULL;
    dnode->data = data;
    dnode->next = NULL;

    struct node *temp = head;
    struct node *temp2 = NULL;

    while (pos > 2)
    {
        temp = temp->next;
        pos--;
    }

    if (pos == 1)
    {
        add_at_beginning(data);
    }
    else
    {
        temp2 = temp->next;
        dnode->prev = temp;
        temp->next = dnode;
        dnode->next = temp2;
        temp2->prev = dnode;
    }
}

void delete_first()
{

    if (head == NULL)
    {
        return;
    }

    head = head->next;
    free(head->prev);
    head->prev = NULL;
}

void delete_last()
{

    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        delete_first();
        return;
    }

    struct node *temp = head;
    struct node *temp2 = NULL;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
    temp = NULL;
}

void delete_at_certain(int pos)
{

    if (head == NULL)
    {
        cout << "No node";
        return;
    }
    else if (pos == 1)
    {
        delete_first();
        return;
    }

    struct node *temp = head;
    struct node *temp2 = NULL;

    while (pos > 1)
    {
        temp = temp->next;
        pos--;
    }

    if (temp->next == NULL)
        delete_last();
    
    else
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
    }
}

void print_data()
{
    if (head == NULL)
    {
        return;
    }

    struct node *ptr = head;

    cout << "The data:" << endl;
    while (ptr != NULL)
    {
        cout << "[" << ptr->data << "]" << endl;
        ptr = ptr->next;
    }
}

int main()
{

    int n, data, pos;

    while (1)
    {
        cout << endl;
        cout << "1. Add to data" << endl
             << "2. Add to beginning" << endl
             << "3. Add to end" << endl
             << "4. Add after position" << endl
             << "5. Add before position" << endl
             << "6. Delete first node" << endl
             << "7. Delete last node" << endl
             << "8. Delete a certain node" << endl;
        cout << endl;
        cin >> n;
        cout << endl;

        if (n == 1)
        {
            cin >> data;
            add_at_end(data);
            cout << endl;
            print_data();
        }
        else if (n == 2)
        {
            cin >> data;
            add_at_beginning(data);
            cout << endl;
            print_data();
        }
        else if (n == 3)
        {
            cin >> data;
            add_at_end(data);
            cout << endl;
            print_data();
        }
        else if (n == 4)
        {
            cin >> data;
            cin >> pos;
            add_after_position(data, pos);
            cout << endl;
            print_data();
        }
        else if (n == 5)
        {
            cin >> data;
            cin >> pos;
            add_before_position(data, pos);
            cout << endl
                 << endl;
            print_data();
        }
        else if (n == 6)
        {

            delete_first();
            cout << endl;
            print_data();
        }
        else if (n == 7)
        {

            delete_last();
            cout << endl;
            print_data();
        }
        else if (n == 8)
        {
            cin >> pos;
            delete_at_certain(pos);
            cout << endl;
            print_data();
        }
        else
        {
            cout << "Wrong number" << endl;
        }
    }
}