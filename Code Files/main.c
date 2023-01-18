#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

// define constants 
#define MAX_LENGTH 255
#define ENTER 13
#define TAB 9
#define BKSP 8

// struct for contacts record 
typedef struct
{
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    char gender;
    double phoneNumber;
    char cityName[MAX_LENGTH];
} DETAILS;

// global variables 
char adminPassword[MAX_LENGTH] = "Admin";
char userPassword[MAX_LENGTH] = "root";
char inputPassword[MAX_LENGTH];
char userName[MAX_LENGTH];
int choice = 0;
DETAILS contact;
DETAILS copy;
FILE *pF = NULL;

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
int isValidGender(char *gender);
int isValidNumber(double);
char *removeSpaces(char *str);
char *enterPassword(char *pass);
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
    printf("--------------------------- \n");
    printf("   >>> Team Members <<< \n");
    printf("--------------------------- \n\n");
    printf("ERROR: currently under work \n");
    printf("--------------------------- \n");
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
    printf("---------------------------------- \n");
    printf("   >>> User Profile Login  <<< \n");
    printf("---------------------------------- \n\n");

    enterPassword(inputPassword);
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
    printf("----------------------------------- \n");
    printf("   >>> Administrator Login  <<< \n");
    printf("----------------------------------- \n\n");

    enterPassword(inputPassword);
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

char *enterPassword(char *pass)
{
    char ch;
    int i = 0;
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
    return inputPassword;
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

int isValidGender(char *gender)
{
    switch (*gender)
    {
        case 'M':
        case 'm':
                *gender = 'm';
                return 1;
        case 'F':
        case 'f':
            *gender = 'f';
            return 1;
        default:
            printf("ERROR: Invalid gender try again later. \n");
            return 0;
    }

    return 0;
}

int isValidNumber(double number)
{
    if(number <= 1000000000 || number >= 9999999999)
    {
        printf("ERROR: Invalid phone number try again later. \n");
        return 0;
    }
    else
        return 1;

    return 0;
}

char *removeSpaces(char *str) 
{
	int i = 0, j = 0; 
	while (str[i]) 
	{
		if (str[i] != ' ') 
		str[j++] = str[i]; 
		i++; 
	}
	str[j] = '\0';
    strlwr(str);
	return str;
}

void clearBuffer()
{
    system("cls");
    fflush(stdin);
}

void addNewContact()
{
    clearBuffer();
    int flag = 0;
    printf("------------------------------ \n");
    printf("   >>> Add New Contact <<< \n");
    printf("------------------------------ \n\n");
    pF = fopen("ContactList.txt", "ab+");
    
    if(pF != NULL)
    {
        printf("Enter the first name: ");
        gets(contact.firstName);

        printf("Enter the last name: ");
        gets(contact.lastName);

        printf("Enter the city name: ");
        gets(contact.cityName);

        printf("Enter the gender [M/F]: ");
        scanf(" %c",&contact.gender);
        fflush(stdin);

        printf("Enter the phone number [+91]: ");
        scanf("%lf",&contact.phoneNumber);
        printf("\n");

        if(isValidGender(&contact.gender))
        {
            if(isValidNumber(contact.phoneNumber))
            {
                removeSpaces(contact.firstName);
                removeSpaces(contact.lastName);
                removeSpaces(contact.cityName);
                fprintf(pF, "%s %s %c %.0lf %s\n", contact.firstName, contact.lastName, contact.gender, contact.phoneNumber, contact.cityName);
                printf("Success: Contact details added in the record. \n");
            }
        }
    }
    else
        printf("ERROR: Unable to locate or open the file. \n");

    fclose(pF);
    system("pause");
    adminPanel();
}

void updateContact()
{

}

void deleteContact()
{

}

void deleteAllContact()
{
    clearBuffer();
    char confirmDelete[MAX_LENGTH];
    printf("------------------------------ \n");
    printf("   >>> Delete All Contact <<< \n");
    printf("------------------------------ \n\n");
    printf("Type `CONFIRM` to delete all the contact. \n");
    printf("Message: ");
    gets(confirmDelete);
    printf("\n");
    choice = strcmp(confirmDelete, "CONFIRM");
    if(choice == 0)
    {
        pF = fopen("ContactList.txt", "w");
        fclose(pF);
        printf("Success: All contact details are deleted. \n");
    }
    else
        printf("ERROR: Invalid message try again later. \n");
    
    system("pause");
    adminPanel();
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
