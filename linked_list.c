#include <stdio.h>
#include <stdlib.h>
// Node structure
struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;

// Insert at beginning
void insertBeginning() {
    int x;
    printf("Enter value: ");
    scanf("%d", &x);
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = x;
    nn->next = head;
    head = nn;
}

// Insert at end
void insertEnd() {
    int x;
    printf("Enter value: ");
    scanf("%d", &x);
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = x;
    nn->next = NULL;
    if (head == NULL) {
        head = nn;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
    }
}

// Delete by value
void deleteNode() {
    int x;
    printf("Enter value to delete: ");
    scanf("%d", &x);
    struct node *temp = head, *prev = NULL;
    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Delete at position
void deleteAtPosition() {
    int pos, i;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head, *prev = NULL;
    if (pos == 1) {
        head = temp->next;
        free(temp);
        return;
    }
    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Display
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse
void reverse() {
    struct node *prev = NULL, *curr = head, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed\n");
}

// Palindrome check
void palindrome() {
    int arr[100], i = 0, j;
    struct node* temp = head;
    if(i >= 100) 
    {
    printf("List too large\n");
    return;
    }
    while (temp != NULL) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    for (j = 0; j < i / 2; j++) {
        if (arr[j] != arr[i - j - 1]) {
            printf("Palindrome: false\n");
            return;
        }
    }
    printf("Palindrome: true\n");
}

// Search
void search() {
    int x, pos = 1;
    printf("Enter value to search: ");
    scanf("%d", &x);
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == x) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Delete by Value\n4.Delete at Position\n5.Display\n6.Reverse\n7.Palindrome\n8.Search\n9.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: deleteNode(); break;
            case 4: deleteAtPosition(); break;
            case 5: display(); break;
            case 6: reverse(); break;
            case 7: palindrome(); break;
            case 8: search(); break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}
