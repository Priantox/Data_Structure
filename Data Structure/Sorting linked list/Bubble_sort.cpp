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
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = head;

    for (int i = 0; i < count - 1; i++)
    {

        int flag = 0;
        struct node *ptr = temp;

        for (int j = 0; j < count - 1 - i; j++)
        {

            if (ptr->data > ptr->next->data)
            {
                int x = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = x;
                flag = -1;
            }

             ptr = ptr->next;
        }
        if (flag == 0){
            break;
        }

        temp = temp->next;
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