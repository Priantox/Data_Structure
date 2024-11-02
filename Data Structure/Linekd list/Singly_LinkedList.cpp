#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void addempty(int data)
{
    struct node *temp = new node();
    temp->data = data;
    temp->next = NULL;

    head = temp;
}

void add_at_end(int data)
{
    if (head == NULL)
    {
        addempty(data);
        return;
    }

    struct node *temp = new node();
    temp->data = data;
    temp->next = NULL;

    struct node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
}

void insert_head(int data)
{
    if (head == NULL)
    {
        addempty(data);
        return;
    }

    struct node *temp = new node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

void add_after(int data, int pos)
{
    if (head == NULL)
    {
        cout << "Empty";
        return;
    }

    struct node *temp = new node();
    temp->data = data;
    temp->next = NULL;

    struct node *ptr = head;

    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

void add_before(int data, int pos)
{
    if (head == NULL)
    {
        cout << "Sorry" << endl;
        return;
    }

    struct node *ptr = head;
    struct node *temp = new node();
    temp->data = data;
    temp->next = NULL;

    while (pos > 2)
    {
        ptr = ptr->next;
        pos--;
    }

    if (pos == 1)
    {
        insert_head(data);
    }
    else
    {
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void search_data(int data)
{
    if (head == NULL) 
    {
        cout << "No data";
        return;
    }

    int i = 0;
    int flag = 0;
    struct node *ptr = head;

    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            cout << "Data is found at " << i << " location" << endl;
            flag = -1;
        }

        ptr = ptr->next;
        i++;
    }

    if (flag == 0)
        cout << "Data not found" << endl;
}

void delete_first()
{
    if (head == NULL)
    {
        cout << "No data";
        return;
    }

    struct node *ptr = head;
    head = head->next;
    free(ptr);
    ptr = NULL;
}

void delete_last()
{
    if (head == NULL)
    {
        cout << "No data" << endl;
        return;
    }
    else if (head->next == NULL)
    {
        delete_first();
        return;
    }

    struct node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}

void delete_certain(int pos)
{
    if (head == NULL)
    {
        cout << "Sorry no data" << endl;
        return;
    }
    else if (pos == 1)
    {
        delete_first();
        return;
    }

    struct node *prev = head;
    struct node *current = head;
    while (pos != 1)
    {
        prev = current;
        current = current->next;
        pos--;
    }
    prev->next = current->next;
    free(current);
    current = NULL;
}

void delete_all_data()
{
    if (head == NULL)
    {
        cout << "There is no data" << endl;
        return;
    }

    struct node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        free(head);
        head = temp;
    }
}

void reverse_data(){
    
    if (head == NULL)
    {
        cout << "No data";
        return;
    }

    struct node *temp = NULL;
    struct node *temp2 = NULL;

    while (head != NULL)
    {
        temp2 = head -> next;
        head -> next = temp;
        temp = head;
        head = temp2;
    }
    head = temp;
}

void print_data()
{
    if (head == NULL)
    {
        cout << "No data" << endl;
        return;
    }

    struct node *ptr = head;
    cout << "All data: " << endl;
    while (ptr)
    {
        cout << "<" << ptr->data << ">" << endl;
        ptr = ptr->next;
    }
}

int main()
{

    int n, pos, data;

    while (1)
    {

        cout << endl;
        cout << "1. Add data" << endl
             << "2. Add data at beginning" << endl
             << "3. Add data at the end" << endl
             << "4. Add after position" << endl
             << "5. Add before position" << endl
             << "6. Seach data" << endl
             << "7. Delete first data" << endl
             << "8. Delete last data" << endl
             << "9. Delete a certain data" << endl
             << "10. Delete all data" << endl
             << "11. Reverse data" << endl
             << "12. Print all data" << endl;

        cout << endl;
        cin >> n;

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
            insert_head(data);
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
            add_after(data, pos);
            cout << endl;
            print_data();
        }
        else if (n == 5)
        {
            cin >> data;
            cin >> pos;
            add_before(data, pos);
            cout << endl;
            print_data();
        }
        else if (n == 6)
        {
            cin >> data;
            search_data(data);
            cout << endl;
        }
        else if (n == 7)
        {
            delete_first();
            cout << endl;
            print_data();
        }
        else if (n == 8)
        {
            delete_last();
            cout << endl;
            print_data();
        }
        else if (n == 9)
        {
            cin >> pos;
            delete_certain(pos);
            cout << endl;
            print_data();
        }
        else if (n == 10)
        {
            delete_all_data();
            cout << endl;
            print_data();
        }
        else if(n == 11){
            reverse_data();
            cout<<endl;
            print_data();
        }
        else if (n == 12)
        {
            print_data();
        }
        else
        {
            cout << "Wrong number.Please try again" << endl;
        }
    }
}