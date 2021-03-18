#include<iostream>

using namespace std;

struct element {
    int value;
    element* next;
};

struct list {
    element* head;
    element* last;
};

list add_last(list l, int x) {
    element* temp = new element;
    temp->value = x;
    temp->next = nullptr;
    if (l.last) {
        l.last->next = temp;
    }
    if (!l.head) {
        l.head = temp;
    }
    l.last = temp;
    return l;
}

void printList(list l) {
    element* temp = l.head;
    while (temp) {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

int main() {
    int n, counter = 0, i = 2;
    cin >> n;
    list l;
    l.last = nullptr;
    l.head = nullptr;
    while (counter < n) {
        bool prime = true;
        if (i != 2) {
            element* list = l.head;
            while (list) {
                if (i % list->value == 0) {
                    prime  = false;
                    break;
                }
                list = list->next;
            }
        }
        if (prime) {
            l = add_last(l, i);
            counter++;
        }
        i++;
    }
    printList(l);
    return 0;
}