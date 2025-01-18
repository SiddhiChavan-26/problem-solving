#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list node
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// Function to create a new node
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to detect the cycle in a linked list
ListNode* detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    bool isCycle = false;

    // Detect cycle using Floyd's cycle detection algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            isCycle = true;
            break;
        }
    }

    // If no cycle is detected, return NULL
    if (!isCycle) {
        return NULL;
    }

    // Find the entry point of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// Function to create a cycle in the linked list
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;

    ListNode* temp = head;
    ListNode* cycleNode = NULL;
    int index = 0;

    while (temp->next != NULL) {
        if (index == pos) {
            cycleNode = temp;
        }
        temp = temp->next;
        index++;
    }
    temp->next = cycleNode; // Create a cycle
}

// Function to free the linked list
void freeList(ListNode* head) {
    ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to test detectCycle
int main() {
    // Create linked list: 3 -> 2 -> 0 -> -4
    ListNode* head = createNode(3);
    head->next = createNode(2);
    head->next->next = createNode(0);
    head->next->next->next = createNode(-4);

    // Create a cycle (connect -4 to the second node (pos = 1))
    createCycle(head, 1);

    // Detect cycle
    ListNode* cycleNode = detectCycle(head);
    if (cycleNode != NULL) {
        printf("Cycle detected at node with value: %d\n", cycleNode->val);
    } else {
        printf("No cycle detected.\n");
    }

    // Break the cycle manually to free memory safely
    head->next->next->next->next = NULL;

    // Free the linked list
    freeList(head);
    return 0;
}

