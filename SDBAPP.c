#include <stdio.h>
#include "STD.h"
#include "SDB.h"

// Function executes an action based on the user's choice. Calls the corresponding database function.
void SDB_Action(uint8 choice) {
    uint32 id;
    uint8 count;
    uint32 list[MAX_STUDENTS];

    switch (choice) {
        case 0:
            // Exit the Entry menu and program.
            printf("Exiting...\n\n");
            break;
        case 1:
            // Add a new student entry.
            if (SDB_AddEntry()) {
                printf("Student added successfully.\n\n");
            } else {
                printf("Failed to add student.\n\n");
            }
            break;
        case 2:
            // Display the used size of the database.
            printf("Number of students in the database: %u\n\n", SDB_GetUsedSize());
            break;
        case 3:
            // Read and display student data by ID.
            printf("Enter Student ID to read: ");
            scanf("%u", &id);
            SDB_ReadEntry(id);
            break;
        case 4:
            // Get and display the list of all student IDs.
            SDB_GetList(&count, list);
            printf("List of student IDs:\n");
            for (uint8 i = 0; i < count; ++i) {
                printf("%u\n\n", list[i]);
            }
            break;
        case 5:
            // Check if a student ID exists in the database.
            printf("Enter Student ID to check existence: ");
            scanf("%u", &id);
            if (SDB_IsIdExist(id)) {
                printf("Student ID %u exists.\n\n", id);
            } else {
                printf("Student ID %u does not exist.\n\n", id);
            }
            break;
        case 6:
            // Delete a student entry by ID.
            printf("Enter Student ID to delete: ");
            scanf("%u", &id);
            SDB_DeleteEntry(id);
            break;
        case 7:
            // Check if the database is full.
            if (SDB_IsFull()) {
                printf("Database is full.\n\n");
            } else {
                printf("Database is not full.\n\n");
            }
            break;
        default:
            // Handle invalid menu choices.
            printf("Invalid choice.\n\n");
            break;
    }
}

// Function
void SDB_APP() {
    uint8 choice;
    do {
        // Display the menu of options.
        printf("1. To add entry                           Enter 1\n");
        printf("2. To get used size in database           Enter 2\n");
        printf("3. To read student data                   Enter 3\n");
        printf("4. To get the list of all student IDs     Enter 4\n");
        printf("5. To check if ID exists                  Enter 5\n");
        printf("6. To delete student data                 Enter 6\n");
        printf("7. To check if database is full           Enter 7\n");
        printf("8. To exit                                Enter 0\n");
        printf("Enter your choice: ");
        scanf("%u", &choice);
        SDB_Action(choice); // Perform the entered action.
    } while (choice != 0);  // Repeat the loop until the user chooses to exit.
}
