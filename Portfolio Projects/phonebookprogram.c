#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define FILE_NAME "phonebook.txt"

// Structure to represent a contact
struct Contact {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

// Function to add a new contact
void addContact(struct Contact contacts[], int* numContacts) {
    if (*numContacts >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add more contacts.\n");
        return;
    }

    struct Contact newContact;

    printf("Enter name: ");
    scanf("%s", newContact.name);

    printf("Enter phone number: ");
    scanf("%s", newContact.phone);

    printf("Enter email: ");
    scanf("%s", newContact.email);

    contacts[*numContacts] = newContact;
    (*numContacts)++;

    printf("Contact added successfully.\n");
}

// Function to display all contacts
void displayContacts(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < numContacts; i++) {
        printf("%d. Name: %s, Phone: %s, Email: %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

// Function to search for a contact by name
void searchContact(struct Contact contacts[], int numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numContacts; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact found:\nName: %s, Phone: %s, Email: %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to delete a contact by name
void deleteContact(struct Contact contacts[], int* numContacts) {
    if (numContacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char deleteName[MAX_NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", deleteName);

    int found = 0;
    for (int i = 0; i < *numContacts; i++) {
        if (strcmp(contacts[i].name, deleteName) == 0) {
            for (int j = i; j < *numContacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*numContacts)--;
            found = 1;
            printf("Contact deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Function to save contacts to a file
void saveContacts(struct Contact contacts[], int numContacts) {
    FILE *fp = fopen(FILE_NAME, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numContacts; i++) {
        fprintf(fp, "%s %s %s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }

    fclose(fp);
    printf("Contacts saved successfully.\n");
}

// Function to load contacts from a file
void loadContacts(struct Contact contacts[], int* numContacts) {
    FILE *fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        printf("No saved contacts found.\n");
        return;
    }

    *numContacts = 0;
    while (fscanf(fp, "%s %s %s", contacts[*numContacts].name, contacts[*numContacts].phone, contacts[*numContacts].email) != EOF) {
        (*numContacts)++;
    }

    fclose(fp);
    printf("Contacts loaded successfully.\n");
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int numContacts = 0;
    int choice;

    loadContacts(contacts, &numContacts);

    while (1) {
        printf("\nPhone Book Manager\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Save Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &numContacts);
                break;
            case 2:
                displayContacts(contacts, numContacts);
                break;
            case 3:
                searchContact(contacts, numContacts);
                break;
            case 4:
                deleteContact(contacts, &numContacts);
                break;
            case 5:
                saveContacts(contacts, numContacts);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}