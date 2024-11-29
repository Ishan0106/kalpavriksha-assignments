#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int userID;
    char userName[50];
    int userAge;
} Person;

int checkUserID(int id)
{
    FILE *fp = fopen("users_data.txt", "r");
    if (!fp)
    {
        // printf("Unable to open the file.\n");
        return -1;
    }
    Person tempUser;
    while (fscanf(fp, "%d,%49[^,],%d", &tempUser.userID, tempUser.userName, &tempUser.userAge) == 3)
    {
        if (tempUser.userID == id)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void addUser()
{
    Person newUser;
    printf("Enter User ID: ");
    scanf("%d", &newUser.userID);
    if (checkUserID(newUser.userID) == 1)
    {
        printf("Error: User ID %d already exists\n", newUser.userID);
        return;
    }
    printf("Enter Username: ");
    scanf(" %49s", newUser.userName);
    printf("Enter User Age: ");
    scanf("%d", &newUser.userAge);

    FILE *fp = fopen("users_data.txt", "a");
    if (!fp)
    {
        printf("Error opening file\n");
        return;
    }
    fprintf(fp, "%d,%s,%d\n", newUser.userID, newUser.userName, newUser.userAge);
    fclose(fp);
    printf("User added successfully\n");
}

void listUsers()
{
    Person tempUser;
    FILE *fp = fopen("users_data.txt", "r");
    if (!fp)
    {
        printf("Unable to open file\n");
        return;
    }
    printf("UserID  Username  Age\n\n");
    while (fscanf(fp, "%d,%49[^,],%d", &tempUser.userID, tempUser.userName, &tempUser.userAge) == 3)
    {
        printf("   %d    %s    %d\n", tempUser.userID, tempUser.userName, tempUser.userAge);
    }
    fclose(fp);
}

void modifyUser()
{
    int idToUpdate, found = 0;
    Person tempUser;
    FILE *fp = fopen("users_data.txt", "r");
    if (!fp)
    {
        printf("Error opening file\n");
        return;
    }

    Person userList[100];
    int totalUsers = 0;

    while (fscanf(fp, "%d,%49[^,],%d", &tempUser.userID, tempUser.userName, &tempUser.userAge) == 3)
    {
        userList[totalUsers++] = tempUser;
    }
    fclose(fp);

    printf("Enter User ID to update: ");
    scanf("%d", &idToUpdate);
    for (int i = 0; i < totalUsers; i++)
    {
        if (userList[i].userID == idToUpdate)
        {
            found = 1;
            printf("Enter new Username: ");
            scanf(" %49s", userList[i].userName);
            printf("Enter new User Age: ");
            scanf("%d", &userList[i].userAge);
            printf("\nUpdated successfully:\n");
            printf("UserID: %d, Username: %s, Age: %d\n", userList[i].userID, userList[i].userName, userList[i].userAge);
            break;
        }
    }
    if (!found)
    {
        printf("Error: User ID %d not found\n", idToUpdate);
        return;
    }
    fp = fopen("users_data.txt", "w");
    if (!fp)
    {
        printf("Error opening file\n");
        return;
    }
    for (int i = 0; i < totalUsers; i++)
    {
        fprintf(fp, "%d,%s,%d\n", userList[i].userID, userList[i].userName, userList[i].userAge);
    }
    fclose(fp);
}

void removeUser()
{
    int idToDelete, found = 0;
    Person tempUser;
    FILE *fp = fopen("users_data.txt", "r");
    if (!fp)
    {
        printf("Error opening file\n");
        return;
    }
    Person userList[100];
    int totalUsers = 0;

    while (fscanf(fp, "%d,%49[^,],%d", &tempUser.userID, tempUser.userName, &tempUser.userAge) == 3)
    {
        userList[totalUsers++] = tempUser;
    }
    fclose(fp);

    printf("Enter User ID to delete: ");
    scanf("%d", &idToDelete);

    for (int i = 0; i < totalUsers; i++)
    {
        if (userList[i].userID == idToDelete)
        {
            found = 1;
            for (int j = i; j < totalUsers - 1; j++)
            {
                userList[j] = userList[j + 1];
            }
            totalUsers--;
            break;
        }
    }

    if (!found)
    {
        printf("Error: User ID %d not found\n", idToDelete);
        return;
    }

    fp = fopen("users_data.txt", "w");
    if (!fp)
    {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < totalUsers; i++)
    {
        fprintf(fp, "%d,%s,%d\n", userList[i].userID, userList[i].userName, userList[i].userAge);
    }
    fclose(fp);
    printf("User with User ID %d deleted successfully\n", idToDelete);
}

int main()
{
    int choice;
    do
    {
        printf("\n--- User Management System ---\n");
        printf("1. Add User\n");
        printf("2. List Users\n");
        printf("3. Update User\n");
        printf("4. Remove User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addUser();
        }
        else if (choice == 2)
        {
            listUsers();
        }
        else if (choice == 3)
        {
            modifyUser();
        }
        else if (choice == 4)
        {
            removeUser();
        }
        else if (choice == 5)
        {
            printf("Exiting...\n");
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
