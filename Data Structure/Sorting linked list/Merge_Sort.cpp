#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void add_data(int data)
{

    struct node *temp = new node();
    temp->data = data;
    temp->next = NULL;

    struct node *ptr = head;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

struct node* merge(struct node *p1, struct node *p2)
{
    struct node *dummy = new node();
    dummy->data = -1;
    struct node *p3 = dummy;

    while (p1 != NULL && p2 != NULL)
    {

        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    dummy = dummy -> next;
    return dummy;
}

struct node *findmid()
{
    struct node *slow = head;
    struct node *fast = head->next;

    if (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct node* merge_sort(struct node *ptr)
{

    if (ptr == NULL || ptr->next == NULL)
        return ptr;

    struct node *mid = findmid();

    struct node *left = ptr;
    struct node *right = mid->next;
    mid->next = NULL;

    left = merge_sort(left);
    right = merge_sort(right);

    struct node* result = merge(left, right);
    return result;
}

void print()
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{

    int n, data;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> data;
        add_data(data);
    }
    struct node *ptr = head;

    struct node* x = merge_sort(ptr);
    head = x;

    print();
}