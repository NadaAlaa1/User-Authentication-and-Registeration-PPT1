#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

int registerUser(User users[], int count) {
    if (count >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return count;
    }

    User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    // Check if username already exists
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists. Please choose a different one.\n");
            return count;
        }
    }

    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[count] = newUser;
    printf("Registration successful.\n");

    return count + 1;
}

int loginUser(User users[], int count) {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful. Welcome, %s!\n", username);
            return 1;
        }
    }

    printf("Invalid username or password. Login failed.\n");
    return 0;
}

int main() {
    User users[MAX_USERS];
    int userCount = 0;
    int loggedIn = 0;
    int choice;

    do {
        printf("\n1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                userCount = registerUser(users, userCount);
                break;
            case 2:
                loggedIn = loginUser(users, userCount);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3 && !loggedIn);

    return 0;
}
