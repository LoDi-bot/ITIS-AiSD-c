#include<iostream>

using namespace std;

struct element {
    int value;
    element* next;
};

element* add(element* head, int x) {
    element* temp = new element;
    temp->value =  x;
    temp->next = head;
    return temp;
}

element* emptyList() {
    return NULL;
}

void printList(element* head) {
    element* temp = head;
    while (temp) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, counter = 0, i = 2;
    cin >> n;
    element* head = emptyList();
    while (counter < n) {
        bool prime = true;
        if (i != 2) {
            element* list = head;
            while (list) {
                if (i % list->value == 0) {
                    prime  = false;
                    break;
                }
                list = list->next;
            }
        }
        if (prime) {
            head = add(head, i);
            counter++;
        }
        i++;
    }
    printList(head);
    return 0;
}