#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
// struct

class linkedList
{
    node *head, *tail;

public:
    linkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void addNode();
    void front();
    node *gethead()
    {
        return head;
    }

    static void display(node *head)
    {
        if (head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->data << endl;
            display(head->next);
        }
    }

    static void concatenate(node *a, node *b)
    {
        if (a != NULL && b != NULL)
        {
            if (a->next == NULL)
                a->next = b;
            else
                concatenate(a->next, b);
        }
        else
        {
            cout << "Either a or b is NULL\n";
        }
    }

    void del(node *before_del)
    {

        node *temp;
        temp = before_del->next;
        before_del->next = temp->next;
        delete temp;
    }
    void after(node *a, int value)
    {
        node *p = new node;
        p->data = value;
        p->next = a->next;
        a->next = p;
    }
};
// class

void linkedList::addNode()
{
    int n;
    cout << "Enter the number of nodes you want to add: " << endl;
    cin >> n;
    node *tmp = new node;
    tmp->data = n;
    tmp->next = NULL;
    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

void linkedList::front()
{
    int n;
    cout << "Enter the value you want to add at the front: " << endl;
    cin >> n;
    node *tmp = new node;
    tmp->data = n;
    tmp->next = head;
    head = tmp;
}

// methods
int menu()
{
    int n;
    system("cls");
    cout << "1)addNode\n2)addFront\n3)DeleteNode\n4)addAfter\n5)DisplayNode\n6)exit\n--------------------------\nplease select\n";
    cin >> n;
    return n;
}
void how(linkedList a)
{
    int index;
    cout << "Enter the index of the node you want to delete: ";
    cin >> index;
    // Find the node at the specified index
    node *temp = a.gethead();
    for (int i = 1; i < index; i++)
    {
        if (temp == NULL)
        {
            cout << "Invalid index" << endl;
            break;
        }
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL)
    {
        a.del(temp);
    }
    else
    {
        cout << "Invalid index" << endl;
    }
}
void how2(linkedList a)
{
    int index,value;
    cout << "Enter the index of the node you want to add and enter value: ";
    cin >> index>>value;
    node *temp = a.gethead();
    for (int i = 1; i < index; i++)
    {
        if (temp == NULL)
        {
            cout << "Invalid index" << endl;
            break;
        }
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL)
    {
        a.after(temp,value);
    }
    else
    {
        cout << "Invalid index" << endl;
    }
}
int main()
{
    system("cls");
    linkedList a;
    int menu_Num;
    while (true)
    {
        menu_Num = menu();
        switch (menu_Num)
        {
        case 1:
            a.addNode();
            break;
        case 2:
            a.front();
            break;
        case 3: 
            how(a);
            break;
        case 4:
            how2(a);
            break;
        case 5:
            linkedList::display(a.gethead());
            system("pause");
            break;
        case 6:
            exit(0);

        default:
            cout << "Invalid option" << endl;
        }
    }
    // a.after(a.gethead()->next->next->next, 10);
    // a.del(a.gethead()->next);
    system("pause");
    return 0;
}

