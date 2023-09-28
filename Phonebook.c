#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a contact
struct Contact {
    char name[50];
    char phoneNumber[20];
    char email[50];
};

// Function to add a new contact
void addContact(struct Contact contacts[], int *contactCount) {
    if (*contactCount < 100) {  // Assuming a maximum of 100 contacts
        struct Contact newContact;

        printf("Enter name: ");
        scanf(" %49[^\n]", newContact.name);  // Read the name

        printf("Enter phone number: ");
        scanf(" %19[^\n]", newContact.phoneNumber);  // Read the phone number

        printf("Enter email: ");
        scanf(" %49[^\n]", newContact.email);  // Read the email

        contacts[*contactCount] = newContact;
        (*contactCount)++;

        printf("Contact added successfully.\n");
    } else {
        printf("Contact list is full. Cannot add more contacts.\n");
    }
}

// Function to view all contacts
void viewContacts(struct Contact contacts[], int contactCount) {
    printf("Contacts:\n");
    for (int i = 0; i < contactCount; i++) {
        printf("%d. Name: %s, Phone: %s, Email: %s\n", i + 1,
               contacts[i].name, contacts[i].phoneNumber, contacts[i].email);
    }
}

// Function to search for a contact by name
void searchContact(struct Contact contacts[], int contactCount) {
    char searchName[50];
    printf("Enter name to search: ");
    scanf(" %49[^\n]", searchName);

    printf("Search Results:\n");
    for (int i = 0; i < contactCount; i++) {
        if (strstr(contacts[i].name, searchName) != NULL) {
            printf("Name: %s, Phone: %s, Email: %s\n",
                   contacts[i].name, contacts[i].phoneNumber, contacts[i].email);
        }
    }
}

// Implement other functions: updateContact, deleteContact, saveToFile, loadFromFile, etc.

int main() {
    struct Contact contacts[100];
    int contactCount = 0;
    int choice;

    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                viewContacts(contacts, contactCount);
                break;
            case 3:
                searchContact(contacts, contactCount);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
