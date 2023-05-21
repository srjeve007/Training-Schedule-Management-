#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FACULTIES 100
#define MAX_USERS 100
#define MAX_SCHEDULES 100
#define MAX_BATCH_ID 100
#define MAX_TECHNOLOGY_NAME 30
#define MAX_FACULTY_NAME 30
#define MAX_PASSWORD 20
#define MAX_VENUE_DETAIL 30
#define MAX_MONTH 30

// Data structures
typedef struct {
    char userName[30];
    char password[20];
} Admin;

typedef struct {
    char technologyName[30];
    char facultyName[30];
    char password[30];
} Faculty;

typedef struct {
    int batchId;
    char technology[MAX_TECHNOLOGY_NAME];
    char startDate[30];
    int noOfDays;
    char endDate[30];
    char venueDetail[MAX_VENUE_DETAIL];
    int noOfParticipants;
    char month[MAX_MONTH];
} Training;

typedef struct {
    int batchId;
    char technology[MAX_TECHNOLOGY_NAME];
    char startDate[30];
    int noOfDays;
    char endDate[30];
    char venueDetail[MAX_VENUE_DETAIL];
    int noOfParticipants;
    char month[MAX_MONTH];
    char facultyName[MAX_FACULTY_NAME];
    char status[30];
} FacultyAssignment;

// Function prototypes
void adminLogin();
void facultyLogin();
void createTrainingSchedule();
void updateTrainingSchedule();
void allocateSchedule();
void generateMonthlyReport();
void displayFacultySchedule();
void cancelFacultySchedule();

// Global variables
Admin admin;
Faculty faculties[MAX_USERS];
int numFaculties = 0;
Training schedules[MAX_SCHEDULES];
int numSchedules = 0;
FacultyAssignment facultyAssignments[MAX_SCHEDULES];
int numAssignments ;

// File names
const char* ADMIN_FILE = "admin.txt";
const char* FACULTIES_FILE = "faculties.txt";
const char* SCHEDULES_FILE = "schedules.txt";
const char* ASSIGNMENTS_FILE = "assignments.txt";

// Helper functions
void saveAdmin() {
    FILE* file = fopen(ADMIN_FILE, "w");
    if (file != NULL) {
        fprintf(file, "%s %s", admin.userName, admin.password);
        fclose(file);
    }
}

void loadAdmin() {
    FILE* file = fopen(ADMIN_FILE, "r");
    if (file != NULL) {
        fscanf(file, "%s %s", admin.userName, admin.password);
        fclose(file);
    }
}

void saveFaculties() {
    FILE* file = fopen(FACULTIES_FILE, "w");
    if (file != NULL) {
        for (int i = 0; i < numFaculties; i++) {
            fprintf(file, "%s %s %s\n", faculties[i].technologyName, faculties[i].facultyName, faculties[i].password);
        }
        fclose(file);
    }
}

void loadFaculties() {
    FILE* file = fopen(FACULTIES_FILE, "r");
    if (file != NULL) {
        while (fscanf(file, "%s %s %s\n", faculties[numFaculties].technologyName, faculties[numFaculties].facultyName, faculties[numFaculties].password) != EOF) {
            numFaculties++;
        }
        fclose(file);
    }
}

void saveSchedules() {
    FILE* file = fopen(SCHEDULES_FILE, "w");
    if (file != NULL) {
        for (int i = 0; i < numSchedules; i++) {
            fprintf(file, "%d %s %s %d %s %s %d %s\n",
                    schedules[i].batchId, schedules[i].technology, schedules[i].startDate, schedules[i].noOfDays,
                    schedules[i].endDate, schedules[i].venueDetail, schedules[i].noOfParticipants, schedules[i].month);
        }
        fclose(file);
    }
}

void loadSchedules() {
    FILE* file = fopen(SCHEDULES_FILE, "r");
    if (file != NULL) {
        while (fscanf(file, "%d %s %s %d %s %s %d %s\n",
                      &schedules[numSchedules].batchId, schedules[numSchedules].technology, schedules[numSchedules].startDate,
                      &schedules[numSchedules].noOfDays, schedules[numSchedules].endDate, schedules[numSchedules].venueDetail,
                      &schedules[numSchedules].noOfParticipants, schedules[numSchedules].month) != EOF) {
            numSchedules++;
        }
        fclose(file);
    }
}

void saveAssignments() {
    FILE* file = fopen(ASSIGNMENTS_FILE, "w");
    if (file != NULL) {
        for (int i = 0; i < numAssignments; i++) {
            fprintf(file, "%d %s %s %d %s %s %d %s %s %s\n",
                    facultyAssignments[i].batchId, facultyAssignments[i].technology, facultyAssignments[i].startDate,
                    facultyAssignments[i].noOfDays, facultyAssignments[i].endDate, facultyAssignments[i].venueDetail,
                    facultyAssignments[i].noOfParticipants, facultyAssignments[i].month, facultyAssignments[i].facultyName,
                    facultyAssignments[i].status);
        }
        fclose(file);
    }
}

void loadAssignments() {
    FILE* file = fopen(ASSIGNMENTS_FILE, "r");
    if (file != NULL) {
        while (fscanf(file, "%d %s %s %d %s %s %d %s %s %s\n",
                      &facultyAssignments[numAssignments].batchId, facultyAssignments[numAssignments].technology,
                      facultyAssignments[numAssignments].startDate, &facultyAssignments[numAssignments].noOfDays,
                      facultyAssignments[numAssignments].endDate, facultyAssignments[numAssignments].venueDetail,
                      &facultyAssignments[numAssignments].noOfParticipants, facultyAssignments[numAssignments].month,
                      facultyAssignments[numAssignments].facultyName, facultyAssignments[numAssignments].status) != EOF) {
            numAssignments++;
        }
        fclose(file);
    }
}

void adminSignup() {

    Admin admin;

   strcpy(admin.userName, "admin");
    strcpy(admin.password, "admin");

    

    saveAdmin();

    printf("Admin Signup successful!\n");
}

void adminLogin() {
    char userName[30];
    char password[20];

  Admin admin;

   strcpy(admin.userName, "admin");
    strcpy(admin.password, "admin");

    

    saveAdmin();

    printf("Admin Username: %s\n", admin.userName);
    printf("Admin Password: %s\n", admin.password);

    printf("Admin Login\n");
    printf("Username: ");
    scanf("%s", userName);
    printf("Password: ");
    scanf("%s", password);

     printf(" Username: %s\n", userName);
    printf(" Password: %s\n", password);

    if (strcmp(userName, admin.userName) == 0 && strcmp(password, admin.password) == 0) {
        printf("Login successful!\n");
        // Perform admin operations
          
          adminOperations();

    } else {
        printf("Invalid username or password.\n");
    }
}



void facultySignup() {
    if (numFaculties == MAX_FACULTIES) {
        printf("Maximum number of faculties reached. Cannot signup.\n");
        return;
    }

    printf("Faculty Signup\n");
    printf("Enter Faculty Name: ");
    scanf("%s", faculties[numFaculties].facultyName);
    // printf("Enter Technology Name: ");
    // scanf("%s", faculties[numFaculties].technologyName);
    printf("Enter Password: ");
    scanf("%s", faculties[numFaculties].password);

    numFaculties++;

    saveFaculties();

    printf("Faculty Signup successful!\n");
}
 


void facultyLogin() {
    char userName[30];
    char password[20];
    int facultyIndex = -1;

    printf("Faculty Login\n");
    printf("Username: ");
    scanf("%s", userName);
    printf("Password: ");
    scanf("%s", password);

    // Find the faculty index based on username and password
    for (int i = 0; i < numFaculties; i++) {
        if (strcmp(userName, faculties[i].facultyName) == 0 && strcmp(password, faculties[i].password) == 0) {
            facultyIndex = i;
            break;
        }
    }

    if (facultyIndex != -1) {
        printf("Login successful!\n");
        // Perform faculty operations
        facultyOperations(userName);
    } else {
        printf("Invalid username or password.\n");
    }
}

void createTrainingSchedule() {
    Training schedule;
    printf("Create New Training Schedule\n");
    // Input all the details of the training schedule
    printf("Technology: ");
    scanf("%s", schedule.technology);
    printf("Batch ID: ");
    scanf("%d", &schedule.batchId);
    printf("Start Date: ");
    scanf("%s", schedule.startDate);
    printf("Number of Days: ");
    scanf("%d", &schedule.noOfDays);
    printf("End Date: ");
    scanf("%s", schedule.endDate);
    printf("Venue Detail: ");
    scanf("%s", schedule.venueDetail);
    printf("Number of Participants: ");
    scanf("%d", &schedule.noOfParticipants);
    printf("Month: ");
    scanf("%s", schedule.month);

    // Save the schedule to the array and file
    schedules[numSchedules++] = schedule;
    saveSchedules();


    printf("Training Schedule created successfully!\n");
}

void updateTrainingSchedule() {
    int batchId;
    int scheduleIndex = -1;

    printf("Update Training Schedule\n");
    printf("Enter Batch ID: ");
    scanf("%d", &batchId);

    // Find the index of the schedule based on batch ID
    for (int i = 0; i < numSchedules; i++) {
        if (schedules[i].batchId == batchId) {
            scheduleIndex = i;
            break;
        }
    }

    if (scheduleIndex != -1) {
        // Update the schedule details
        printf("Technology: ");
        scanf("%s", schedules[scheduleIndex].technology);
        printf("Start Date: ");
        scanf("%s", schedules[scheduleIndex].startDate);
        printf("Number of Days: ");
        scanf("%d", &schedules[scheduleIndex].noOfDays);
        printf("End Date: ");
        scanf("%s", schedules[scheduleIndex].endDate);
        printf("Venue Detail: ");
        scanf("%s", schedules[scheduleIndex].venueDetail);
        printf("Number of Participants: ");
        scanf("%d", &schedules[scheduleIndex].noOfParticipants);
        printf("Month: ");
        scanf("%s", schedules[scheduleIndex].month);

        // Save the updated schedule to the file
        saveSchedules();

        printf("Training Schedule updated successfully!\n");
    } else {
        printf("No schedule found with the given Batch ID.\n");
    }
}

void allocateSchedule() {
    int batchId;
    int facultyIndex = -1;

    printf("Allocate Schedule to Faculty\n");
    printf("Enter Batch ID: ");
    scanf("%d", &batchId);

    // Find the index of the schedule based on batch ID
    int scheduleIndex = -1;
    for (int i = 0; i < numSchedules; i++) {
        if (schedules[i].batchId == batchId) {
            scheduleIndex = i;
            break;
        }
    }

    if (scheduleIndex != -1) {
        printf("Enter Faculty Name: ");
        char facultyName[30];
        scanf("%s", facultyName);

        // Find the index of the faculty based on name
        for (int i = 0; i < numFaculties; i++) {
            if (strcmp(facultyName, faculties[i].facultyName) == 0) {
                facultyIndex = i;
                break;
            }
        }

        if (facultyIndex != -1) {
            // Check if the schedule is already assigned to a faculty
            if (strcmp(facultyAssignments[scheduleIndex].status, "Assigned") == 0) {
                printf("Schedule is already assigned to a faculty.\n");
            } else {
                // Assign the schedule to the faculty
                strcpy(facultyAssignments[scheduleIndex].facultyName, facultyName);
                strcpy(facultyAssignments[scheduleIndex].status, "Assigned");
                saveAssignments();
                printf("Schedule assigned to faculty successfully!\n");
            }
        } else {
            printf("Faculty not found with the given name.\n");
        }
    } else {
        printf("No schedule found with the given Batch ID.\n");
    }
}


void displayFacultySchedule(const char* facultyName) {
    printf("Training Schedule for Faculty: %s\n", facultyName);
    printf("-------------------------------------------------\n");

    for (int i = 0; i < numAssignments; i++) {
        if (strcmp(facultyAssignments[i].facultyName, facultyName) == 0) {
            printf("Batch ID: %d\n", facultyAssignments[i].batchId);
            printf("Technology: %s\n", facultyAssignments[i].technology);
            printf("Start Date: %s\n", facultyAssignments[i].startDate);
            printf("End Date: %s\n", facultyAssignments[i].endDate);
            printf("Venue: %s\n", facultyAssignments[i].venueDetail);
            printf("No. of Participants: %d\n", facultyAssignments[i].noOfParticipants);
            printf("Month: %s\n", facultyAssignments[i].month);
            printf("Status: %s\n", facultyAssignments[i].status);
            printf("-----------------------------------------\n");
        }
    }

    
}




void cancelFacultySchedule(int batchId) {
    int found = 0;

    for (int i = 0; i < numAssignments; i++) {
          if (facultyAssignments[i].batchId == batchId) {
            // Cancel the faculty schedule
            strcpy(facultyAssignments[i].status, "Cancelled");
            found = 1;
            break;
        }
    }

    if (found) {
        saveAssignments();
        printf("Faculty schedule with Batch ID %d has been cancelled.\n", batchId);
    } else {
        printf("Faculty schedule with Batch ID %d not found.\n", batchId);
    }
}




void generateMonthlyReport() {
    char month[30];
    printf("Generate Monthly Report\n");
    printf("Enter Month: ");
    scanf("%s", month);

    printf("Trainings happening in %s:\n", month);
    printf("Batch ID\tTechnology\tStart Date\tEnd Date\tFaculty\n");



    for (int i = 0; i < numAssignments; i++) {
        if (strcmp(facultyAssignments[i].month, month) == 0) {
            printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n", facultyAssignments[i].batchId,
                   facultyAssignments[i].technology, facultyAssignments[i].startDate,
                   facultyAssignments[i].endDate, facultyAssignments[i].facultyName);
        }
    }
}

 void facultyViewSchedule(const char* facultyName) {
    printf("Training Schedule for Faculty: %s\n", facultyName);
    printf("Batch ID\tTechnology\tStart Date\tEnd Date\n");

    

    for (int i = 0; i < numAssignments; i++) {
        if (strcmp(facultyAssignments[i].facultyName, facultyName) == 0) {
            printf("%d\t\t%s\t\t%s\t\t%s\n", facultyAssignments[i].batchId,
                   facultyAssignments[i].technology, facultyAssignments[i].startDate,
                   facultyAssignments[i].endDate);
        }
    }

}

//     void facultyViewSchedule(const char* facultyName) {
//     printf("Training Schedule for Faculty: %s\n", facultyName);
//     printf("Batch ID\tTechnology\tStart Date\tEnd Date\n");
//      printf("faculty name", facultyAssignments.facultyName);

   
//         if (strcmp(facultyAssignments->facultyName, facultyName) == 0) {
//              printf("%d\t\t%s\t\t%s\t\t%s\n", facultyAssignments->batchId,
//                    facultyAssignments->technology, facultyAssignments->startDate,
//                    facultyAssignments->endDate,facultyAssignments->month,facultyAssignments->noOfDays, facultyAssignments->noOfParticipants,facultyAssignments->venueDetail);
        
//     }

   
// }


void cancelTrainingSchedule(const char* facultyName) {
    int batchId;
    int assignmentIndex = -1;

    printf("Cancel Training Schedule\n");
    printf("Enter Batch ID: ");
    scanf("%d", &batchId);

    // Find the index of the assignment based on batch ID and faculty name
    for (int i = 0; i < numAssignments; i++) {
               if (facultyAssignments[i].batchId == batchId && strcmp(facultyAssignments[i].facultyName, facultyName) == 0) {
            assignmentIndex = i;
            break;
        }
    }

    if (assignmentIndex != -1) {
        // Check if the assignment status is "Assigned"
        if (strcmp(facultyAssignments[assignmentIndex].status, "Assigned") == 0) {
            // Mark the assignment as cancelled
            strcpy(facultyAssignments[assignmentIndex].status, "Cancelled");
            saveAssignments();
            printf("Training schedule cancelled successfully!\n");
        } else {
            printf("The training schedule is not assigned to you.\n");
        }
    } else {
        printf("No training schedule found with the given Batch ID and faculty name.\n");
    }

    
}



void adminOperations() {
    int choice;

    do {
        printf("\nAdmin Operations\n");
        printf("1. Create a new training schedule\n");
        printf("2. Update existing schedules\n");
        printf("3. Allocate schedule to a trainer\n");
        printf("4. Generate a monthly report\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Handle creating a new training schedule
                createTrainingSchedule();
                printf("Creating a new training schedule...\n");
                break;
            case 2:
                // Handle updating existing schedules
                updateTrainingSchedule();
                printf("Updating existing schedules...\n");
                break;
            case 3:
                // Handle allocating schedule to a trainer
                allocateSchedule();
                printf("Allocating schedule to a trainer...\n");
                break;
            case 4:
                // Handle generating a monthly report
                generateMonthlyReport();
                printf("Generating a monthly report...\n");
                break;
            case 5:
                printf("Logging out...\n");
                return main();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

void facultyOperations(char userName[30]) {
    const char* FacultyName = userName;
    int choice;

    do {
        printf("Welcome %s\n", userName);
        printf("\nFaculty Operations\n");
        printf("\nFaculty Operations\n");
        printf("1. View assigned schedule\n");
        printf("2. Cancel a training session\n");
        printf("3. to display schedule\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Handle viewing assigned schedule
                facultyViewSchedule(FacultyName);
                printf("Viewing assigned schedule...\n");
                break;
            case 2:
                // Handle canceling a training session
                cancelTrainingSchedule(FacultyName);
                printf("Canceling a training session...\n");
                break;

             case 3:
                // Handle canceling a training session
                displayFacultySchedule(FacultyName);
                printf("training session ...\n");
                break;

            case 4:
                printf("Logging out...\n");
                main();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}


int main() {
    adminSignup();
    int choice;

    loadFaculties();
    loadSchedules();
    loadAssignments();

    do {
        printf("\nTraining Schedule Management System\n");
        printf("1. Faculty Signup\n");
        printf("2. Faculty Login\n");
        printf("3. Admin Login\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                facultySignup();
                break;
            case 2:
                facultyLogin();
                break;
            case 3:
                adminLogin();
                break;
            case 4:
                printf("Quitting application...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}


