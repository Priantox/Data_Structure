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

void sort()
{

    struct node *temp = head;

    while (temp != NULL)
    {

        struct node *min = temp;
        struct node *r = temp->next;

        while (r != NULL)
        {
            if (min->data > r->data)
                min = r;

            r = r->next;
        }

        if (min != temp)
        {

            int x = min->data;
            min->data = temp->data;
            temp->data = x;
        }
        temp = temp -> next;
    }
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

    sort();

    print();
}