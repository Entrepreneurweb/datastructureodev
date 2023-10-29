#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// we define the structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
// our function to add numbers to the begining
void addToBeginning(int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = number;
    newNode->next = head;
    head = newNode;
}
// our function to add numbers to the end
void addToEnd(int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = number;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
// the function check if the number is odd or even and add it to the end or begining of the list accordingly
void addNumbersToList() {
    int number;
    printf("Enter numbers (-1 to stop):\n");

    while (1) {
        scanf("%d", &number);
        if (number == -1) {
            break;
        }

        if (number % 2 == 1) {
            addToBeginning(number); // Add odd numbers to the beginning of the list
        } else {
            addToEnd(number); // Add even numbers to the end of the list
        }
    }
}
//  function to add randomly generated numbers
void addRandomNumbers() {
    for (int i = 0; i < 100; i++) {
        int number = rand() % 50 * 2 + 54; // Generate random even numbers between 54 and 152
        addToEnd(number);
    }
}

// we create a function to sort our list
void sortList() {
    Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data < j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
// function to display our list
void printList() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf("->");
        } else {
            printf("\n");
        }
        temp = temp->next;
    }
}

int main() {
    // Seed for random number generation
    srand(time(NULL));

    // Step 1: Add numbers based on user input
    addNumbersToList();

    // Step 2: Add 100 randomly generated numbers to the list
    addRandomNumbers();

    // Step 3: Sort the list in descending order
    sortList();

    // Step 4: Print the list
    printf("Sorted List: ");
    printList();

    // Step 5: Free allocated memory
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

