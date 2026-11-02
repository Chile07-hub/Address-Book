# Address Book Management System in C
A menu-driven Address Book Management System developed using C programming to manage contact information through a simple console-based interface.

## Overview
The Address Book Management System is a C application designed to organize and manage contact records. It demonstrates how C programming concepts can be used to build a modular application with separate source files, header files, and file-handling functionality. The application is organized into multiple modules to separate contact management, file operations, and contact initialization. This structure makes the code easier to read, maintain, test, and extend.

## Features
1. Add Contacts - Store new contact information.
2. Search Contacts - Find an existing contact using the supported search criteria.
3. View Contacts - Display saved contact information.
4. Edit Contacts - Modify existing contact details.
5. Delete Contacts - Remove unwanted contact records.
6. File Handling - Read or write contact information using file operations.
7. Modular Code Structure - Organize functionality across .c and .h files.
8. Contact Initialization - Use a separate module for initializing or populating contact records.

## Technologies Used
1. C Programming - Application development
2. Standard C Library - Input/output, strings, and other supported operations
3. Structures - Organizing contact information
4. Functions - Separating application functionality
5. Header Files - Sharing declarations between source files
6. File Handling - Managing contact data stored in files
7. GCC Compiler - Compiling the application
8. Git and GitHub - Version control and source-code hosting

## Project Structure
Address-Book/
├── main.c
├── contact.c
├── contact.h
├── file.c
├── file.h
├── populate.c
├── populate.h
├── contacts.txt
└── README.md

## File Descriptions
### main.c 
Contains the main entry point and coordinates program execution
### contact.c 
Contains the implementation of contact-related operations
### contact.h 
Contains declarations and shared definitions related to contact management
# file.c 
Contains file-handling functions for reading or writing contact data
# file.h 
Contains declarations for the file-handling module
# populate.c 
Contains functions for initializing or populating contact records, depending on the implementation
# populate.h 
Contains declarations for the population or initialization functions
# contacts.txt 
A text file used for contact data, if configured by the application
# README.md 
Documents the application, its structure, and instructions for use

## Concepts
1. Structures and arrays
2. Functions and modular programming
3. Header files and source files
4. Loops and conditional statements
5. String handling
6. Searching and updating records
7. File handling and persistent data storage
8. Compilation and linking of multiple source files
9. Debugging and input validation

## Learning Outcomes
1. Designing a menu-driven C application
2. Splitting code into reusable modules
3. Working with header files and multiple source files
4. Managing structured contact records
5. Handling strings and user input
6. Compiling and linking multiple C files
7. Using Git and GitHub to maintain source code

## Author
Developed as a C programming practice application to strengthen programming fundamentals, modular programming, and problem-solving skills.



