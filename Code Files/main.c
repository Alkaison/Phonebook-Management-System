#include<stdio.h>
#include<stdlib.h>

// Function Prototypes or Function Declaration 
// informative functions 
void loginPage();
void endScreen();

// login password functions 
void userLogin();
void adminLogin();

// permission functions 
void userPanel();
void adminPanel();

// validation functions 
void checkPassword();
void isValidGender();
void isValidNumber();

// operational functions 
void addNewContact();
void updateContact();
void deleteContact();
void deleteAllContact();
void displayContact();
void searchByName();
void searchByNumber();

int main(){

    loginPage();
    return 0;
}

void loginPage()
{
    int choice;
    printf("-------------------------------- \n");
    printf(">>> Login into system as <<< \n");
    printf("-------------------------------- \n");
    printf("[1] Admin \n");
    printf("[2] User \n");
    printf("-------------------------------- \n");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            adminLogin();
            break;
        case 2:
            userLogin();
            break;
        default:
            printf("ERROR: Invalid input please try again. \n");
            Sleep(1500);
            loginPage();
    }
}

void endScreen()
{
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

void userLogin()
{
    
}

void adminLogin()
{
    
}

void userPanel()
{
    int choice;
    printf("-------------------------------- \n");
    printf(">>> User Panel <<< \n");
    printf("-------------------------------- \n");

    printf("[1] Display All Contact. \n");
    printf("[2] Search By Name. \n");
    printf("[3] Search By Number. \n");
    printf("-------------------------------- \n");
    printf("Enter the numbers choice & Hit ENTER: ");
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

        default:
            printf("ERROR: Invalid input please try again. \n");
            Sleep(1500);
    }
    
}

void adminPanel()
{
    int choice;
    printf("-------------------------------- \n");
    printf(">>> Admin Panel <<< \n");
    printf("-------------------------------- \n");
    printf("[1] Add New Contact. \n");
    printf("[2] Update Contact. \n");
    printf("[3] Display All Contact. \n");
    printf("[4] Search By Name. \n");
    printf("[5] Search By Number. \n");
    printf("[6] Delete Contact. \n");
    printf("[7] Delete All Contact. \n");
    printf("-------------------------------- \n\n");
    printf("Enter the numbers choice & Hit ENTER: ");
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
        default:
            printf("ERROR: Invalid input please try again. \n");
            Sleep(1500);
    }
}

void loginPassword()
{
    
}

void checkPassword()
{

}

void isValidGender()
{

}

void isValidNumber()
{

}

void addNewContact()
{
    int number;
    char name,city;
    printf("Enter Phone Number\n");
    scanf("%d",&number);
    printf("Enter Full Name\n");
    scanf("%s",&name);
    printf("Enter city name\n");
    scanf("%s",&city);
    

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