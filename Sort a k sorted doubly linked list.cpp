// C++ program to find a pair with given sum x.
#include <bits/stdc++.h>
using namespace std;

// structure of node of doubly linked list
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void printlist(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insert(struct Node **head, int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

struct compare
{
    bool operator()(Node *p1, Node *p2)
    {
        return (p1->data > p2->data);
    }
};

void sortbyheap(Node **head, int k)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    priority_queue<Node *, vector<Node *>, compare> pq;

    Node *newhead = NULL, *last;

    for (int i = 0; head != NULL and i <= k; i++)
    {
        pq.push(*head);
        *head = (*head)->next;
    }

    while (!pq.empty())
    {
        if (newhead == NULL)
        {
            newhead = pq.top();
            newhead->prev = NULL;
            last = newhead;
        }
        else
        {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
        pq.pop();

        if ((*head) != NULL)
        {
            pq.push(*head);
            *head = (*head)->next;
        }
    }

    last->next = NULL;
    *head = newhead;
}

// Driver program
int main()
{

    Node *head = NULL;
    int x = 2;

    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 7);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    printlist(head);
    sortbyheap(&head, x);
    printlist(head);

    return 0;
}
