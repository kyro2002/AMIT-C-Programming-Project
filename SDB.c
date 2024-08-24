#include <stdio.h>
#include "SDB.h"

static student database[MAX_STUDENTS];
static uint8 num_students = 0;

// Function checks if the database is full by comparing the used size with the maximum limit.
Bool SDB_IsFull() {
    return num_students >= MAX_STUDENTS;
}

// Function returns the number of students currently stored in the database.
uint8 SDB_GetUsedSize() {
    return num_students;
}

// Function adds a new student entry to the database. It prompts the user for student details.
Bool SDB_AddEntry() {
    if (SDB_IsFull()) {
        printf("Database is full. Cannot add more students.\n\n");
        return False;
    }

    student new_student;

    // Prompting the user for student details.
    printf("Enter Student ID: ");
    scanf("%u", &new_student.Student_ID);
    if (SDB_IsIdExist(new_student.Student_ID)) {
        printf("Student ID already exists.\n\n");
        return False;
    }

    printf("Enter Student Year: ");
    scanf("%u", &new_student.Student_year);
    printf("Enter Course1 ID: ");
    scanf("%u", &new_student.Course1_ID);
    printf("Enter Course1 Grade: ");
    scanf("%u", &new_student.Course1_grade);
    printf("Enter Course2 ID: ");
    scanf("%u", &new_student.Course2_ID);
    printf("Enter Course2 Grade: ");
    scanf("%u", &new_student.Course2_grade);
    printf("Enter Course3 ID: ");
    scanf("%u", &new_student.Course3_ID);
    printf("Enter Course3 Grade: ");
    scanf("%u", &new_student.Course3_grade);

    // Add the new student to the array and increment the used size.
    database[num_students++] = new_student;
    return True;
}

// Function deletes a student entry from the database by ID. Shifts the remaining students up in the array.
void SDB_DeleteEntry(uint32 id) {
    for (uint8 i = 0; i < num_students; ++i) {
        if (database[i].Student_ID == id) {
            for (uint8 j = i; j < num_students - 1; ++j) {
                database[j] = database[j + 1];
            }
            --num_students;
            printf("Student ID %u deleted.\n\n", id);
            return;
        }
    }
    printf("Student ID %u not found.\n\n", id);
}

// Function searches for and prints the details of a student by ID.
Bool SDB_ReadEntry(uint32 id) {
    for (uint8 i = 0; i < num_students; ++i) {
        if (database[i].Student_ID == id) {
            printf("Student ID: %u\n", database[i].Student_ID);
            printf("Student Year: %u\n", database[i].Student_year);
            printf("Course1 ID: %u, Grade: %u\n", database[i].Course1_ID, database[i].Course1_grade);
            printf("Course2 ID: %u, Grade: %u\n", database[i].Course2_ID, database[i].Course2_grade);
            printf("Course3 ID: %u, Grade: %u\n", database[i].Course3_ID, database[i].Course3_grade);
            return True;
        }
    }
    printf("Student ID %u not found.\n\n", id);
    return False;
}

// Function retrieves a list of all student IDs in the database.
void SDB_GetList(uint8 *count, uint32 *list) {
    *count = num_students;
    for (uint8 i = 0; i < num_students; ++i) {
        list[i] = database[i].Student_ID;
    }
}

// Function checks whether a student ID exists in the database.
Bool SDB_IsIdExist (uint32 id) {
    for (uint8 i = 0; i < num_students; ++i) {
        if (database[i].Student_ID == id) {
            return True;
        }
    }
    return False;
}
