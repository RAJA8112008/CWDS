#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

// Function to create linked list (append at end)
Node* createLL(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

class Solution {
public:
    Node* cloneLinkedList(Node* head) {
        if (head == NULL) return NULL;

        // Step 1: Create new list with next pointers
        Node* NewHead = new Node(head->data);
        Node* Oldtemp = head->next;
        Node* Newtemp = NewHead;

        while (Oldtemp != NULL) {
            Node* newNode = new Node(Oldtemp->data);
            Newtemp->next = newNode;

            Oldtemp = Oldtemp->next;
            Newtemp = Newtemp->next;
        }

        // Step 2: Map old nodes to new nodes
        unordered_map<Node*, Node*> mp;
        Oldtemp = head;
        Newtemp = NewHead;

        while (Oldtemp != NULL) {
            mp[Oldtemp] = Newtemp;
            Oldtemp = Oldtemp->next;
            Newtemp = Newtemp->next;
        }

        // Step 3: Copy random pointers
        Oldtemp = head;
        Newtemp = NewHead;

        while (Oldtemp != NULL) {
            if (Oldtemp->random != NULL)
                Newtemp->random = mp[Oldtemp->random];
            else
                Newtemp->random = NULL;

            Oldtemp = Oldtemp->next;
            Newtemp = Newtemp->next;
        }

        return NewHead;
    }
};

// Print list with random pointers
void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main() {
    Node* head = NULL;

    // Creating list using createLL
    head = createLL(head, 1);
    head = createLL(head, 2);
    head = createLL(head, 3);
    head = createLL(head, 4);

    // Setting random pointers manually
    head->random = head->next->next;              
    head->next->random = head;                    
    head->next->next->random = head->next->next;  
    head->next->next->next->random = head->next;  

    cout << "Original List:\n";
    printLL(head);

    Solution sol;
    Node* clonedHead = sol.cloneLinkedList(head);

    cout << "\nCloned List:\n";
    printLL(clonedHead);

    return 0;
}
