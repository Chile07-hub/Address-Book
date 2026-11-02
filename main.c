/*
Name : Vasudev Chile
Date : 25/10/26
Description : Project - Address Book
*/
#include <stdio.h>
#include "contact.h"

int main() 
{
    int choice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do 
    {
        printf("\n");
        printf("============================================\n");
        printf("             ADDRESS BOOK MENU               \n");
        printf("============================================\n\n");
        printf("  1. Create contact\n");
        printf("  2. Search contact\n");
        printf("  3. Edit contact\n");
        printf("  4. Delete contact\n");
        printf("  5. List all contacts\n");
    	printf("  6. Save and Exit\n\n");		
        // printf("7. Exit\n");
        printf("============================================\n");
        printf("  Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            // Clear the invalid input from the input buffer
            while (getchar() != '\n');
            printf("\nInvalid input! Please enter a number between 1 and 6\n");
            continue;
        }
        
        switch (choice) 
        {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook);
                break;
            case 6:
                printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            default:
                printf("Invalid choice Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
