#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

// define constants 
#define MAX_LENGTH 255
#define ENTER 13
#define TAB 9
#define BKSP 8

// global variables 
char adminPassword[MAX_LENGTH] = "Admin";
char userPassword[MAX_LENGTH] = "root";
char userName[MAX_LENGTH];
int choice = 0;

// Function Prototypes or Function Declaration 
// informative functions 
void loginPage();
void endScreen();

// login password functions 
void getUsername();
void userLogin();
void adminLogin();

// permission functions 
void userPanel();
void adminPanel();

// validation functions 
void isValidGender();
void isValidNumber();
void clearBuffer();

// operational functions 
void addNewContact();
void updateContact();
void deleteContact();
void deleteAllContact();
void displayContact();
void searchByName();
void searchByNumber();

int main(){

    getUsername();
    return 0;
}

void loginPage()
{
    clearBuffer();
    printf("----------------------------------- \n");
    printf("   >>> Login into system as <<< \n");
    printf("----------------------------------- \n");
    printf("[1] Administrator \n");
    printf("[2] User profile \n");
    printf("[3] Exit system \n");
    printf("----------------------------------- \n\n");
    printf("Enter the number & Hit ENTER: ");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            adminLogin();
            break;
        case 2:
            userLogin();
            break;
        case 3:
            endScreen();
            break;
        default:
            printf("ERROR: Invalid input please try again. \n");
            system("pause");
            loginPage();
    }
}

void endScreen()
{
    clearBuffer();
    printf("-------------------------------- \n");
    printf(">>> Team Members <<< \n");
    printf("-------------------------------- \n");
    printf("[1] Ganesh \n");
    printf("[2] Amit \n");
    printf("[3] Abrar \n");
    printf("[4] Vivek \n");
    printf("[5] Manish \n");
    printf("[6] Aditya \n");
    printf("-------------------------------- \n");
    exit(0);
}

void getUsername()
{
    clearBuffer();
    printf("------------------------------------------- \n");
    printf("   >>> Phonebook Management System  <<< \n");
    printf("------------------------------------------- \n\n");
    printf("Enter Username: ");
    scanf(" %s",&userName);
    fflush(stdin);
    loginPage();
}

void userLogin()
{
    clearBuffer();
    char inputPassword[255], ch;
    int i = 0;

    printf("---------------------------------- \n");
    printf("   >>> User Profile Login  <<< \n");
    printf("---------------------------------- \n\n");
    printf("Enter your password & Hit ENTER: ");

    while(1)
    {
        ch = getch(); // get single character at one time & validate it 
        if(ch == ENTER || ch == TAB){
            inputPassword[i] = '\0';
            break;
        }
        else if(ch == BKSP){
            if(i > 0){
                i--;
                printf("\b \b"); // for backspace
            }
        }
        else{
            inputPassword[i++] = ch;
            printf("* \b");	// to replace password character with * 
        }
    }

    fflush(stdin);
    printf("\n");
    // verifies the password 
    if(strcmp(userPassword, inputPassword) == 0)
        userPanel();
    else
    {
        printf("ERROR: Invalid password please try again. \n");
        system("pause");
        loginPage();
    }
}

void adminLogin()
{
    clearBuffer();
    char inputPassword[255], ch;
    int i = 0;

    printf("----------------------------------- \n");
    printf("   >>> Administrator Login  <<< \n");
    printf("----------------------------------- \n\n");
    printf("Enter your password & Hit ENTER: ");

    while(1)
    {
        ch = getch(); // get single character at one time & validate it 
        if(ch == ENTER || ch == TAB){
            inputPassword[i] = '\0';
            break;
        }
        else if(ch == BKSP){
            if(i > 0){
                i--;
                printf("\b \b"); // for backspace
            }
        }
        else{
            inputPassword[i++] = ch;
            printf("* \b");	// to replace password character with * 
        }
    }

    fflush(stdin);
    printf("\n");
    // verifies the password 
    if(strcmp(adminPassword, inputPassword) == 0)
        adminPanel();
    else
    {
        printf("ERROR: Invalid password please try again. \n");
        system("pause");
        loginPage();
    }
}

void userPanel()
{
    clearBuffer();
    printf("----------------------------------- \n");
    printf("\t>>> User Panel <<< \n");
    printf("----------------------------------- \n");
    printf("[1] Display All Contact. \n");
    printf("[2] Search By Name. \n");
    printf("[3] Search By Number. \n");
    printf("[4] Logout. \n");
    printf("----------------------------------- \n\n");
    printf("Enter the number & Hit ENTER: ");
    scanf("%d",&choice);
    
    switch (choice)
    {
        case 1:
            displayContact();
            break;
        case 2:
            searchByName();
            break;
        case 3:
            searchByNumber();
            break;
        case 4:
            endScreen();
            break;
        default:
            printf("ERROR: Invalid input please try again. \n");
            system("pause");
            userPanel();
    }
}

void adminPanel()
{
    clearBuffer();
    printf("------------------------------------ \n");
    printf("\t>>> Admin Panel <<< \n");
    printf("------------------------------------ \n");
    printf("[1] Add New Contact. \n");
    printf("[2] Update Contact. \n");
    printf("[3] Display All Contact. \n");
    printf("[4] Search By Name. \n");
    printf("[5] Search By Number. \n");
    printf("[6] Delete Contact. \n");
    printf("[7] Delete All Contact. \n");
    printf("[8] Logout. \n");
    printf("------------------------------------ \n\n");
    printf("Enter the number & Hit ENTER: ");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            addNewContact();
            break;
        case 2:
            updateContact();
            break;
        case 3:
            displayContact();
            break;
        case 4:
            searchByName();
            break;
        case 5:
            searchByNumber();
            break;
        case 6:
            deleteContact();
            break;
        case 7:
            deleteAllContact();
            break;
        case 8:
            endScreen();
            break;
        default:
            printf("ERROR: Invalid input please try again. \n");
            system("pause");
            adminPanel();
    }
}

void isValidGender()
{

}

void isValidNumber()
{

}

void clearBuffer()
{
    system("cls");
    fflush(stdin);
}

void addNewContact()
{
  
}

void updateContact()
{

}

void deleteContact()
{

}

void deleteAllContact()
{

}

void displayContact()
{

}

void searchByName()
{

}

void searchByNumber()
{

}
