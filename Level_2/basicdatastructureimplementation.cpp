#include <iostream>
using namespace std;

//------------ Stack Node ------------
struct StackNode
{
    int data;
    StackNode *next;
};

StackNode *top = NULL;

//------------ Queue Node ------------
struct QueueNode
{
    int data;
    QueueNode *next;
};

QueueNode *front = NULL;
QueueNode *rear = NULL;

//------------ Stack Functions ------------
void push()
{
    int value;
    cout << "Enter Value: ";
    cin >> value;

    StackNode *newNode = new StackNode;
    newNode->data = value;
    newNode->next = top;
    top = newNode;

    cout << "Element Pushed Successfully.\n";
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack is Empty.\n";
        return;
    }

    StackNode *temp = top;
    cout << "Deleted Element: " << top->data << endl;
    top = top->next;
    delete temp;
}

void displayStack()
{
    if (top == NULL)
    {
        cout << "Stack is Empty.\n";
        return;
    }

    StackNode *temp = top;

    cout << "\nStack Elements:\n";
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

//------------ Queue Functions ------------
void enqueue()
{
    int value;
    cout << "Enter Value: ";
    cin >> value;

    QueueNode *newNode = new QueueNode;
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "Element Enqueued Successfully.\n";
}

void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is Empty.\n";
        return;
    }

    QueueNode *temp = front;
    cout << "Deleted Element: " << front->data << endl;

    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
}

void displayQueue()
{
    if (front == NULL)
    {
        cout << "Queue is Empty.\n";
        return;
    }

    QueueNode *temp = front;

    cout << "\nQueue Elements:\n";
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

//------------ Main Function ------------
int main()
{
    int choice;

    do
    {
        cout << "\n========== DATA STRUCTURE ==========\n";
        cout << "1. Push (Stack)\n";
        cout << "2. Pop (Stack)\n";
        cout << "3. Display Stack\n";
        cout << "4. Enqueue (Queue)\n";
        cout << "5. Dequeue (Queue)\n";
        cout << "6. Display Queue\n";
        cout << "7. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            displayStack();
            break;

        case 4:
            enqueue();
            break;

        case 5:
            dequeue();
            break;

        case 6:
            displayQueue();
            break;

        case 7:
            cout << "Program Ended Successfully.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}