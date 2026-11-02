#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

// listing the contact 
void listContacts(AddressBook *addressBook)
{
    if (addressBook->contactCount == 0)
    {
        printf("\nAddress Book is empty\n");
        return;
    }
    printf("\n");
    printf("+--------------------------------------------------------------------------+\n");
    printf("|                              ADDRESS BOOK                                |\n");
    printf("+----------------------+------------------+--------------------------------+\n");
    printf("| Name                 | Mobile Number    | Email                          |\n");
    printf("+----------------------+------------------+--------------------------------+\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("| %-20.20s | %-16.16s | %-30.30s |\n",
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }

    printf("+----------------------+------------------+--------------------------------+\n");
}


void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    // Check whether the Address Book is full
    if (addressBook->contactCount >= MAX_CONTACTS)
    {
        printf("Address Book is full!\n");
        return;
    }

	//Define the logic to create a Contacts 
    int flag = 0;

    //Enter the validate Name
    printf("\nEnter the Name : ");
    do
    {
        flag = 0;
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].name);
        if(validate_name(addressBook->contacts[addressBook->contactCount].name))
        {
            printf("Enter the valid Name : ");
            flag = 1;
        }

    } while(flag);

    //Enter validate Mobile Number
    
    printf("Enter the Mobile Number : ");
    do
    {
        flag = 0;
        int i;
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].phone);
        if(validate_mobile_no(addressBook->contacts[addressBook->contactCount].phone))
        {
            flag = 1;
        }
        else
        {
            //check whether Mobile number is unique
            for(i = 0; i < addressBook->contactCount; i++)
            {
                if(strcmp(addressBook->contacts[i].phone, addressBook->contacts[addressBook->contactCount].phone) == 0)
                {
                    printf("Enter Unique Mobile Number\n");
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
        {
            printf("Enter the Mobile Number again: ");
        }
    } while(flag);

    // Enter Validate Email
    printf("Enter the Email: ");

    do
    {
        flag = 0;
        int i;
        scanf(" %[^\n]", addressBook->contacts[addressBook->contactCount].email);
        if(validate_email(addressBook->contacts[addressBook->contactCount].email))
        {
            flag = 1;
        }
        else
        {
            //check whether Email is Unique
            for(i = 0; i < addressBook->contactCount; i++)
            {
                if(strcmp(addressBook->contacts[i].email, addressBook->contacts[addressBook->contactCount].email) == 0)
                {
                    printf("Enter Unique Email\n");
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
        {
            printf("Enter the Email agian: ");
        }
    } while(flag);

    
    // increasing conatct count after suuccessfull validation
    addressBook->contactCount++;
    printf("\nContact created Successfully!!\n");    
}

void searchContact(AddressBook *addressBook) 
{
    //Defining the logic for search
    printf("\nSearch by: \n");
    printf("1. Name\n2. Phone no\n3. Email\nEnter the option: ");

    int choice;
    int ind;
    char str[50];

    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            printf("Enter the Name to Search: ");
            scanf(" %[^\n]", str);

            ind = Search_name(str, addressBook);
            if(ind == -1)
            {
                printf("The Contact Not found\n");
            }
            else if(ind >= 0)
            {
                printf("Name: %s\n", addressBook->contacts[ind].name);
                printf("Mobile Number: %s\n", addressBook->contacts[ind].phone);
                printf("Email: %s\n", addressBook->contacts[ind].email);
            }
            else
            {
                printf("Multiple Names Found Enter Mobile Number to search");
                scanf("%s", str);
                ind = Search_mobile_no(str, addressBook);
                if(ind == -1)
                {
                    printf("contact not found\n");
                }
                else
                {
                    printf("Name: %s\n", addressBook->contacts[ind].name);
                    printf("Mobile Number: %s\n", addressBook->contacts[ind].phone);
                    printf("Email: %s\n", addressBook->contacts[ind].email);
                }
            }
            break;

        case 2:
            printf("Enter Mobile Number: ");
            scanf("%s", str);
            ind = Search_mobile_no(str, addressBook);
            if(ind == -1)
            {
                printf("Contact not found\n");
            }
            else
            {
                printf("Name: %s\n", addressBook->contacts[ind].name);
                printf("Mobile Number: %s\n", addressBook->contacts[ind].phone);
                printf("Email: %s\n", addressBook->contacts[ind].email);
                
            }
            break;

        case 3:
            printf("Enter Email: ");
            scanf("%s", str);

            ind = Search_email(str, addressBook);
            if(ind == -1)
            {
                printf("Contact not found\n");
            }
            else
            {
                printf("Name: %s\n", addressBook->contacts[ind].name);
                printf("Mobile Number: %s\n", addressBook->contacts[ind].phone);
                printf("Email: %s\n", addressBook->contacts[ind].email);
            }
            break;
        
        default:
        printf("Invalid Search option\n");
            break;
    }
}

void editContact(AddressBook *addressBook)
{
    int choice;
    int ind;
    int flag;
    int duplicate;
    char str[50];

    printf("\nEdit contact by:\n");
    printf("1. Name\n2. Phone No\n3. Email\nEnter the option: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the Name to Search: ");
            scanf(" %49[^\n]", str);

            ind = Search_name(str, addressBook);

            if (ind == -1)
            {
                printf("Name not found\n");
                return;
            }
            else if (ind == -2)
            {
                printf("Multiple Names found. Enter Mobile Number: ");
                scanf(" %19s", str);

                ind = Search_mobile_no(str, addressBook);

                if (ind == -1)
                {
                    printf("Contact not found\n");
                    return;
                }
            }
            break;

        case 2:
            printf("Enter Mobile Number to Search: ");
            scanf(" %19s", str);

            ind = Search_mobile_no(str, addressBook);

            if (ind == -1)
            {
                printf("Contact not found\n");
                return;
            }
            break;

        case 3:
            printf("Enter Email to Search: ");
            scanf(" %49s", str);

            ind = Search_email(str, addressBook);

            if (ind == -1)
            {
                printf("Contact not found\n");
                return;
            }
            break;

        default:
            printf("Invalid option\n");
            return;
    }

    printf("\nContact Found:\n");
    printf("Name: %s\n", addressBook->contacts[ind].name);
    printf("Mobile Number: %s\n", addressBook->contacts[ind].phone);
    printf("Email: %s\n", addressBook->contacts[ind].email);

    printf("\nWhat do you want to Edit?\n");
    printf("1. Name\n2. Mobile Number\n3. Email\nEnter the option: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            do
            {
                flag = 0;

                printf("Enter New Name: ");
                scanf(" %49[^\n]", str);

                if (validate_name(str))
                {
                    printf("Enter a valid name\n");
                    flag = 1;
                }

            } while (flag);

            strcpy(addressBook->contacts[ind].name, str);
            break;

        case 2:
            do
            {
                flag = 0;
                duplicate = 0;

                printf("Enter New Mobile Number: ");
                scanf(" %19s", str);

                if (validate_mobile_no(str))
                {
                    flag = 1;
                }
                else
                {
                    for (int i = 0; i < addressBook->contactCount; i++)
                    {
                        if (i != ind &&
                            strcmp(addressBook->contacts[i].phone, str) == 0)
                        {
                            printf("Enter Unique Mobile Number\n");
                            duplicate = 1;
                            flag = 1;
                            break;
                        }
                    }
                }

            } while (flag);

            strcpy(addressBook->contacts[ind].phone, str);
            break;

        case 3:
            do
            {
                flag = 0;
                duplicate = 0;

                printf("Enter New Email: ");
                scanf(" %49s", str);

                if (validate_email(str))
                {
                    flag = 1;
                }
                else
                {
                    for (int i = 0; i < addressBook->contactCount; i++)
                    {
                        if (i != ind &&
                            strcmp(addressBook->contacts[i].email, str) == 0)
                        {
                            printf("Enter Unique Email\n");
                            duplicate = 1;
                            flag = 1;
                            break;
                        }
                    }
                }

            } while (flag);

            strcpy(addressBook->contacts[ind].email, str);//Once the number passes validation and the duplicate check, it replaces the selected contact's mobile number.
            break;

        default:
            printf("Invalid Option\n");
            return;
    }

    printf("Contact Updated Successfully!\n");
}

void deleteContact(AddressBook *addressBook)
{
	//Define the logic for deletecontact
    int choice;
    int ind; 
    char str[50];
    char confirm;
    printf("\nSearch the Contact which you want to delete\n");
    printf("Search by: \n1. Name\n2. Mobile Number\n3. Email\nEnter the option: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1: //Name
            printf("Enter Name: ");
            scanf(" %[^\n]", str);

            ind = Search_name(str, addressBook);

            if(ind == -1)
            {
                printf("Contact Not Found\n");
                return;
            }
            else if(ind == -2)
            {
                printf("Multiple Contacts Found Enter Mobile Number: ");
                scanf("%s", str);

                ind = Search_mobile_no(str, addressBook);

                if(ind == -1)
                {
                    printf("Contact Not Found\n");
                    return;
                }
            }
            break;

        case 2://phone no
            printf("Enter Mobile Number: ");
            scanf("%s", str);

            ind = Search_mobile_no(str, addressBook);

            if(ind == -1)
            {
                printf("Contact Not Found\n");
                return;
            }
            break;
        
        case 3://email
            printf("Enter Email: ");
            scanf("%s", str);

            ind = Search_email(str, addressBook);

            if(ind == -1)
            {
                printf("Contact Not Found\n");
                return;
            }
            break;
        
        default:
            printf("Invalid option\n");
            return;
    }
    
    printf("\nContact Found: \n");
    printf("Name: %s\n", addressBook->contacts[ind].name);
    printf("Mobile Number: %s\n", addressBook->contacts[ind].phone);
    printf("Email: %s\n", addressBook->contacts[ind].email);

    printf("\nDo you want to delete this contact? (Y/N): ");
    scanf(" %c", &confirm);

    if(confirm == 'Y' || confirm == 'y')
    {
        //shift the conatact
        for(int i = ind; i < addressBook->contactCount - 1; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }
        addressBook->contactCount--;
        printf("Contact deleted Successfully!\n");
    }
    else if(confirm == 'N' || confirm == 'n')
    {
        printf("Contact deletion Cancelled\n");
    }
    else
    {
        printf("Invalid Confirmation. Conatact not deleted\n");
    }
}

int validate_name(char *str)
{
   int i = 0;
    while (str[i] != '\0')
    {
        if(!((str[i] >= 'A' && str[i] <= 'Z') ||
           (str[i] >= 'a' && str[i] <= 'z') ||
           str[i] == ' '))
        {
            return 1;
        }
        i++;
    }
    return 0;
}

int validate_mobile_no(char *phone)
{
    int i = 0;
    if(strlen(phone) != 10)
    {
        printf("Enter 10 Digit Mobile Number\n");
        return 1;
    }
    while (phone[i] != '\0')
    {
        if(phone[i] < '0' || phone[i] > '9')
        {
            printf("Enter only Digits\n");
            return 1;
        }
        i++;
    }
    return 0;
            
}
int validate_email(char *mail)
{
    int i = 0;
    int len;
    //check whether the Email start with a digit
    if(mail[0] >= '0' && mail[0] <= '9')
    {
        printf("Email should not start with a digit\n");
        return 1;
    }
    //check lowercse letters, digits, @ and dot
    while(mail[i] != '\0')
    {
        if(!((mail[i] >= 'a' && mail[i] <= 'z') ||
            (mail[i] >= '0' && mail[i] <= '9') ||
             mail[i] == '@' || mail[i] == '.'))
        {
            printf("Use Lowercase Letters and Digits Only\n");
            return 1;
        }
        i++;
    }
    //check that @ is present
    if(strchr(mail, '@') == NULL)
    {
        printf("Enter Valid Email: @ is Missing\n");
        return 1;
    }        
    //check that Email Ends with .com
    len = strlen(mail);

    if(len < 5 || strcmp(mail + len - 4, ".com") != 0)
    {
        printf("Email must End with .com\n");
        return 1;
    }
    return 0;
}

int Search_name(char *str, AddressBook *addressBook)
{
    int count = 0;
    int index = -1;

    for(int i = 0; i < addressBook->contactCount; i++)
    {
        if(strcmp(addressBook->contacts[i].name, str) == 0)
        {
            count++;
            index = i;
        }
    }
    if(count == 1)
    {
        return index;
    }
    else if(count == 0)
    {
        return -1;
    }

    return -2;
}

int Search_mobile_no(char *str, AddressBook *addressBook)
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, str) == 0)
        {
            return i;
        }
    }

    return -1;
}

int Search_email(char *str, AddressBook *addressBook)
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].email, str) == 0)
        {
            return i;
        }
    }

    return -1;
}

