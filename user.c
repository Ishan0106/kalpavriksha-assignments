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
    int result = 0;
    FILE *fp = fopen("users_data.txt", "r");
    if (!fp)
    {
        result = -1; // File error
    }
    else
    {
        Person tempUser;
        while (fscanf(fp, "%d,%49[^,],%d", &tempUser.userID, tempUser.userName, &tempUser.userAge) == 3)
        {
            if (tempUser.userID == id)
            {
                result = 1; // User ID exists
                break;
            }
        }
        fclose(fp);
    }
    return result;
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
    int idToUpdate, found = 0, result = 0;
    Person tempUser;
    FILE *fp = NULL;
    Person userList[100];
    int totalUsers = 0;
    fp = fopen("users_data.txt", "r");
    if (!fp){
        printf("Error opening file\n");
        result = -1;
    }
    else{
        while (fscanf(fp, "%d,%49[^,],%d", &tempUser.userID, tempUser.userName, &tempUser.userAge) == 3){
            userList[totalUsers++] = tempUser;
        }
        fclose(fp);
        fp = NULL;
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
        if (!found){
            printf("Error: User ID %d not found\n");
            result = -1;
        }
        else{
            fp = fopen("users_data.txt", "w");
            if (!fp)
            {
                printf("Error opening file\n");
                result = -1;
            }
            else
            {
                for (int i = 0; i < totalUsers; i++)
                {
                    fprintf(fp, "%d,%s,%d\n", userList[i].userID, userList[i].userName, userList[i].userAge);
                }
            }
        }
    }
    if (fp)
    {
        fclose(fp);
    }
    if (result == -1)
    {
        printf("Operation failed.\n");
    }
}

void removeUser()
{
    int idToDelete, found = 0, result = 0;
    Person tempUser;
    FILE *fp = NULL;
    Person userList[100];
    int totalUsers = 0;
    fp = fopen("users_data.txt", "r");
    if (!fp){
        printf("Error opening file\n");
        result = -1;
    }
    else{
        while (fscanf(fp, "%d,%49[^,],%d", &tempUser.userID, tempUser.userName, &tempUser.userAge) == 3)
        {
            userList[totalUsers++] = tempUser;
        }
        fclose(fp);
        fp = NULL;
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
        if (!found){
            printf("Error: User ID %d not found\n", idToDelete);
            result = -1;
        }
        else{
            fp = fopen("users_data.txt", "w");
            if (!fp)
            {
                printf("Error opening file\n");
                result = -1;
            }
            else
            {
                for (int i = 0; i < totalUsers; i++)
                {
                    fprintf(fp, "%d,%s,%d\n", userList[i].userID, userList[i].userName, userList[i].userAge);
                }
                printf("User with User ID %d deleted successfully\n", idToDelete);
            }
        }
    }
    if (fp)
    {
        fclose(fp);
    }
    if (result == -1)
    {
        printf("Operation failed.\n");
    }
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

        switch (choice)
        {
        case 1:
            addUser();
            break;
        case 2:
            listUsers();
            break;
        case 3:
            modifyUser();
            break;
        case 4:
            removeUser();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 5);

    return 0;
}
