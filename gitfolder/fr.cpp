
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Node inserted successfully!" << endl;
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    cout << "Linked List: ";

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void deleteNode(int value)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->data == value)
    {
        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Node deleted successfully!" << endl;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Value not found!" << endl;
    }
    else
    {
        Node* del = temp->next;
        temp->next = del->next;
        delete del;

        cout << "Node deleted successfully!" << endl;
    }
}

void search(int value)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Value found in the list!" << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Value not found!" << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n--- LINKED LIST MENU ---" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Display List" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Search Node" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                display();
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(value);
                break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;

            case 5:
                cout << "Program ended." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
