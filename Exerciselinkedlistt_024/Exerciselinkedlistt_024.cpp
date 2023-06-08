#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int rollNumber;
    string name;
    Node* next;
};

class CircularLinkedList {
private:
    Node* LAST;

public:
    CircularLinkedList() {
        LAST = NULL;
    }

    void addNode();
    bool search(int rollno, Node** previous, Node** current);
    bool listEmpty();
    bool delNode();
    void traverse();
};

void CircularLinkedList::addNode() {
    Node* newNode = new Node();
    cout << "Enter roll number: ";
    cin >> newNode->rollNumber;
    cout << "Enter name: ";
    cin >> newNode->name;

    if (listEmpty()) {  // List is empty
        newNode->next = newNode;
        LAST = newNode;
    }
    else {
        Node* current = LAST->next;  // Start with the first node
        Node* previous = NULL;

        while (current != LAST && current->rollNumber < newNode->rollNumber) {
            previous = current;
            current = current->next;
        }

        if (current == LAST && current->rollNumber < newNode->rollNumber) {  // Insert at the end
            newNode->next = LAST->next;
            LAST->next = newNode;
            LAST = newNode;
        }
        else {  // Insert in between
            newNode->next = current;
            if (previous == NULL) {
                LAST->next = newNode;
            }
            else {
                previous->next = newNode;
            }
        }
    }
}

bool CircularLinkedList::delNode() {
    if (listEmpty()) {
        return false;  // List is empty, no record to delete
    }

    cout << "Enter the roll number of the record to be deleted: ";
    int rollno;
    cin >> rollno;

    Node* previous = LAST;
    Node* current = LAST->next;

    if (current == LAST && current->rollNumber == rollno) {  // Only one node in the list
        delete current;
        LAST = NULL;
        return true;  // Record deleted successfully
    }

    while (current != LAST) {
        if (current->rollNumber == rollno) {
            previous->next = current->next;
            if (current == LAST->next) {
                LAST->next = current->next;
            }
            delete current;
            return true;  // Record deleted successfully
        }
        previous = current;
        current = current->next;
    }

    if (current == LAST && current->rollNumber == rollno) {  // Last node in the list
        previous->next = current->next;
        LAST = previous;
        delete current;
        return true;  // Record deleted successfully
    }

    return false;  // Record not found
}

void CircularLinkedList::traverse() {
    if (listEmpty()) {
        cout << "\nList is empty\n";
    }
    else {
        cout << "\nRecords in the list are:\n";
        Node* currentNode = LAST->next;
        while (currentNode != LAST) {
            cout << currentNode->rollNumber << " " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
        cout << LAST->rollNumber << " " << LAST->name << endl;
    }
}

bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
    *previous = LAST;
    *current = LAST->next;

}