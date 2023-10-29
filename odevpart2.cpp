#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// the structure definition for a student node in the linked list
typedef struct Node {
    int studentNumber;
    char name[50];
    int age;
    struct Node* next;
} Node;

Node* head = NULL; 

// function to add a student node to the end of the list
void addToEnd(int studentNumber, char name[], int age) {
    // Allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->studentNumber = studentNumber;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;

    // checking If the list is empty, the new node becomes the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Traverse the list and add the new node to the end
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// our  function to traverse and print all student nodes in the list
void traverseAndPrint() {
    Node* temp = head;
    int count = 1;
    while (temp != NULL) {
        printf("%d- %s %d %d\n", count, temp->name, temp->age, temp->studentNumber);
        temp = temp->next;
        count++;
    }
}

// Function to search for a student node by name and return the node
Node* searchByName(char name[]) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL; // Return NULL if the student name is not found
}

// Function to delete the next node after the node with the specified student name
void deleteNextNode(char name[]) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0 && temp->next != NULL) {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete); // Free memory of the node to be deleted
            return;
        }
        temp = temp->next;
    }
}

// Function to print the record with the longest name in the list
void printLongestNameRecord() {
    Node* temp = head;
    int maxLength = 0;
    char longestName[50];

    // Traverse the list to find the longest name
    while (temp != NULL) {
        int currentLength = strlen(temp->name);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            strcpy(longestName, temp->name);
        }
        temp = temp->next;
    }

    // Print the record with the longest name and its length
    printf("The longest name in the list: %s\n", longestName);
    printf("Length: %d\n", maxLength);
}

int main() {
    // Example usage of functions

    // Add student records to the list
    addToEnd(201, "Saliha", 27);
    addToEnd(203, "Ece", 19);

    // Print all student records
    printf("Student Records:\n");
    traverseAndPrint();

    // Search and delete a student record
    char searchName[50] = "Saliha";
    Node* foundNode = searchByName(searchName);
    if (foundNode != NULL) {
        deleteNextNode(searchName);
        printf("\n%s's record deleted.\n", searchName);
    } else {
        printf("\n%s's record not found.\n", searchName);
    }

    // Print the updated student records
    printf("\nUpdated Student Records:\n");
    traverseAndPrint();

    // Print the record with the longest name
    printLongestNameRecord();

    // Free allocated memory
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

