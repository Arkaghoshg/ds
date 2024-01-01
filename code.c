#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollNumber;
    char name[50];
    char course[50];
    float marks;
    struct Student* next;
    struct Student* prev;
};

struct Student *head = NULL;

// Function to create a new student record
struct Student* createStudent(int rollNumber, char name[], char course[], float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNumber = rollNumber;
    strcpy(newStudent->name, name);
    strcpy(newStudent->course, course);
    newStudent->marks = marks;
    newStudent->next = NULL;
    newStudent->prev = NULL;
    return newStudent;
}
// Function to insert a student record at the end of the list

struct Student* insertFromLast(struct Student* head, int rollNumber, char name[], char course[], float marks) {

    if (head == NULL) {
        return newStudent;
    }

    struct Student* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newStudent;
    newStudent->prev = temp;

    return head;
}

// Function to delete a student record from the front of the list
struct Student* deleteFromFront(struct Student* head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Student* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
         }

    free(temp);
    printf("Student record deleted from the front.\n");

    return head;
}

// Function to display the student record at the front of the list
void showFront(struct Student* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Student Record at the Front:\n");
    printf("Roll Number: %d\n", head->rollNumber);
    printf("Name: %s\n", head->name);
    printf("Course: %s\n", head->course);
    printf("Marks: %.2f\n", head->marks);
}

// Function to search and display the student record at a given position
void searchRecordAtPosition(struct Student* head, int position) {
    if (head == NULL) {
        printf("List is empty. No records to search.\n");
        return;
    }

    struct Student* temp = head;
      int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp != NULL) {
        printf("Record at position %d:\n", position);
        printf("Roll Number: %d, Name: %s, Course: %s, Marks: %.2f\n",
               temp->rollNumber, temp->name, temp->course, temp->marks);
    } else {
        printf("Position %d exceeds the length of the list.\n", position);
    }
}

// Function to update a student record with a given position
void updateRecord(struct Student** head, int position, char name[], int rollNumber, char course[], int marks) {
    if (*head == NULL) {
        printf("List is empty. No records to update.\n");
        return;
    }

    struct Student *temp = *head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
      if (temp != NULL) {
        strcpy(temp->name, name);
        temp->rollNumber = rollNumber;
        strcpy(temp->course, course);
        temp->marks = marks;
        printf("Record at position %d updated successfully.\n", position);
    } else {
        printf("Position %d exceeds the length of the list.\n", position);
    }
}

void updateRecordname(struct Student** head, int position, char name[]) {
    if (*head == NULL) {
        printf("List is empty. No records to update.\n");
        return;
    }

    struct Student *temp = *head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
      if (temp != NULL) {
        strcpy(temp->name, name);
        printf("Record at position %d updated successfully.\n", position);
    } else {
        printf("Position %d exceeds the length of the list.\n", position);
    }
}

void updateRecordroll(struct Student** head, int position, int rollNumber) {
    if (*head == NULL) {
        printf("List is empty. No records to update.\n");
        return;
    }

    struct Student *temp = *head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
      if (temp != NULL) {
        temp->rollNumber = rollNumber;
        printf("Record at position %d updated successfully.\n", position);
    } else {
        printf("Position %d exceeds the length of the list.\n", position);
    }
}

void updateRecordcourse(struct Student** head, int position, char course[]) {
    if (*head == NULL) {
        printf("List is empty. No records to update.\n");
        return;
    }

    struct Student *temp = *head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
      if (temp != NULL) {
        strcpy(temp->course, course);
        printf("Record at position %d updated successfully.\n", position);
    } else {
        printf("Position %d exceeds the length of the list.\n", position);
    }
}

void updateRecordmark(struct Student** head, int position, int marks) {
    if (*head == NULL) {
        printf("List is empty. No records to update.\n");
        return;
    }

    struct Student *temp = *head;
    int count = 1;

    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
      if (temp != NULL) {
        temp->marks = marks;
        printf("Record at position %d updated successfully.\n", position);
    } else {
        printf("Position %d exceeds the length of the list.\n", position);
    }
}
// Function to display all student records in the list
void display(struct Student* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Student* temp = head;

    printf("Student Records:\n");
    while (temp != NULL) {
        printf("Roll Number: %d, Name: %s, Course: %s, Marks: %.2f\n",
               temp->rollNumber, temp->name, temp->course, temp->marks);
        temp = temp->next;
    }
}
int main() {
    int choice, rollNumber, position;
    float marks;
    char name[50], course[50];
    struct Student* head = NULL;

    do {
        printf("\nStudent Record Management System Menu:\n");
        printf("0. Create Student Record\n");
        printf("1. Insert Student Record from Last\n");
        printf("2. Delete Student Record from Front\n");
        printf("3. Show Student Record (Front)\n");
        printf("4. Search Student Record by Position\n");
        printf("5. Update Student Record\n");
        printf("6. Display All Student Records\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &rollNumber);
                printf("Enter Name: ");
                getchar(); 
                fgets(name, sizeof(name), stdin); 
                name[strcspn(name, "\n")] = '\0';
                printf("Enter Course (CSE/AIML/DS/IT/ECE)): ");
                scanf("%s", course);  
                printf("Enter Marks: ");
                
                scanf("%f", &marks);
                head = insertFromLast(head, rollNumber, name, course, marks);
                break;

            case 2:
                head = deleteFromFront(head);
                break;

            case 3:
                showFront(head);
                break;

            case 4:
                printf("Enter Position to Search: ");
                scanf("%d", &position);
                searchRecordAtPosition(head, position);
                break;
            case 5:
    printf("Enter position to Update: ");
    scanf("%d", &position);
    int choicex;
    do {
        printf("\nWhat do you want to update?:\n");
        printf("1. Name\n");
        printf("2. Roll Number\n");
        printf("3. Course\n");
        printf("4. Marks\n");
        printf("Enter your choice: ");
        scanf("%d", &choicex);
        switch (choicex) {
            case 1:
                printf("Enter the name: ");
                getchar(); 
                fgets(name, sizeof(name), stdin); 
                name[strcspn(name, "\n")] = '\0';
                updateRecordname(&head, position, name);
                break;
            case 2:
                printf("Enter the new Roll Number: ");
                scanf("%d", &rollNumber);
                updateRecordroll(&head, position, rollNumber);
                break;
            case 3:
                printf("Enter new course (CSE/AIML/DS/IT/ECE): ");
                scanf("%s", course);
                updateRecordcourse(&head, position, course);
                break;
            case 4:
                printf("Enter new marks: ");
                scanf("%f", &marks);
                updateRecordmark(&head, position, marks);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choicex < 1 || choicex > 4);
    break;
                    
                
                

            case 6:
                display(head);
                break;

            case 7:
                printf("Exiting program.\n");
                break;
            case 0:
                struct Student* newStudent = createStudent(rollNumber, name, course, marks);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
