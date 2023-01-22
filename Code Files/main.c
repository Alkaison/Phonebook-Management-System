#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

// define constants 
#define MAX_LENGTH 255
#define ENTER 13
#define TAB 9
#define BKSP 8
#define USER_CODE 101
#define ADMIN_CODE 102

// struct for contacts record 
typedef struct RECORD
{
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    char gender;
    double phoneNumber;
    char cityName[MAX_LENGTH];
} DETAILS;

// global variables 
char adminPassword[MAX_LENGTH] = "Admin";
char inputPassword[MAX_LENGTH];
char userName[MAX_LENGTH];
int choice = 0;
DETAILS contact;
DETAILS copy;
FILE *pF = NULL;

// Function Prototypes or Function Declaration 
// informative functions 
void infoScreen();
void loginPage();
void endScreen();

// login password & permission functions 
void adminLogin();
void userPanel();
void adminPanel();

// validation functions 
int isValidGender(char *gender);
int isValidNumber(double *number);
char *removeSpaces(char *str);
void clearBuffer();

// operational functions 
void addNewContact();
void updateContact();
void deleteContact();
void deleteAllContact();
void displayContact(int);
void searchByName(int);
void searchByNumber(int);

int main(){

    infoScreen();
    return 0;
}

void infoScreen()
{
    clearBuffer();
    system("color 60");
    printf("\t\t------------------------------------------- \n");
    printf("\t\t   >>> Phonebook Management System  <<< \n");
    printf("\t\t------------------------------------------- \n\n");
    printf("\tIt is a software application that allows users to store, organize\n and manage large numbers of contact records efficiently. The system is designed\n to have functions such as adding, updating, viewing, listing and deleting contacts. \n\n");
    system("pause");
    loginPage();
}

void loginPage()
{
    clearBuffer();
    printf("----------------------------------- \n");
    printf("   >>> Login into system as <<< \n");
    printf("----------------------------------- \n");
    printf("[1] Administrator. \n");
    printf("[2] User profile. \n");
    printf("[3] EXIT. \n");
    printf("----------------------------------- \n\n");
    printf("Enter the number & Hit ENTER: ");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            adminLogin();
            break;
        case 2:
            userPanel();
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
    printf("--------------------------- \n");
    printf("ERROR: currently under work \n");
    printf("--------------------------- \n");
    exit(0);
}

void adminLogin()
{
    clearBuffer();
    char ch;
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
    printf("[4] Back to Login. \n");
    printf("[5] EXIT. \n");
    printf("----------------------------------- \n\n");
    printf("Enter the number & Hit ENTER: ");
    scanf("%d",&choice);
    
    switch (choice)
    {
        case 1:
            displayContact(USER_CODE);
            break;
        case 2:
            searchByName(USER_CODE);
            break;
        case 3:
            searchByNumber(USER_CODE);
            break;
        case 4:
            loginPage();
            break;
        case 5:
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
    printf("[8] Back to Login. \n");
    printf("[9] EXIT. \n");
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
            displayContact(ADMIN_CODE);
            break;
        case 4:
            searchByName(ADMIN_CODE);
            break;
        case 5:
            searchByNumber(ADMIN_CODE);
            break;
        case 6:
            deleteContact();
            break;
        case 7:
            deleteAllContact();
            break;
        case 8:
            loginPage();
            break;
        case 9:
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

int isValidNumber(double *number)
{
    if(*number <= 1000000000 || *number >= 9999999999)
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
            if(isValidNumber(&contact.phoneNumber))
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
    clearBuffer();
    char confirmDelete[MAX_LENGTH];
    double findNumber;
    int flag = 0;

    printf("----------------------------- \n");
    printf("   >>> Update Contact <<< \n");
    printf("----------------------------- \n\n");
    printf("Enter the phone number to update [+91]: ");
    scanf("%lf",&findNumber);
    printf("\n");

    pF = fopen("ContactList.txt", "r");
    FILE *pT = fopen("temporary.txt", "w");

    while(fscanf(pF, "%s %s %c %lf %s\n",contact.firstName, contact.lastName, &contact.gender, &contact.phoneNumber, contact.cityName) != EOF)
    {
        if(findNumber == contact.phoneNumber)
        {
            printf("--------------------------------------------------- \n");
            printf("> Contact Found in records. Enter the new details.\n");
            printf("--------------------------------------------------- \n");
            fflush(stdin);
            printf("Enter the first name: ");
            gets(copy.firstName);

            printf("Enter the last name: ");
            gets(copy.lastName);

            printf("Enter the city name: ");
            gets(copy.cityName);

            printf("Enter the gender [M/F]: ");
            scanf(" %c",&copy.gender);
            fflush(stdin);
            
            printf("Enter the phone number [+91]: ");
            scanf("%lf",&copy.phoneNumber);
            printf("\n");

            fflush(stdin);
            printf("Type `CONFIRM` to update this details: ");
            gets(confirmDelete);

            printf("\n");
            if(strcmp(confirmDelete, "CONFIRM") == 0)
            {
                if(isValidGender(&copy.gender))
                {
                    if(isValidNumber(&copy.phoneNumber))
                    {
                        removeSpaces(copy.firstName);
                        removeSpaces(copy.lastName);
                        removeSpaces(copy.cityName);
                        fprintf(pT, "%s %s %c %.0lf %s\n",copy.firstName, copy.lastName, copy.gender, copy.phoneNumber, copy.cityName);
                        flag = 2;
                    }
                    else
                    {
                        fprintf(pT, "%s %s %c %.0lf %s\n", contact.firstName, contact.lastName, contact.gender, contact.phoneNumber, contact.cityName);
                        flag = 3;
                    }
                }
                else
                {
                    fprintf(pT, "%s %s %c %.0lf %s\n", contact.firstName, contact.lastName, contact.gender, contact.phoneNumber, contact.cityName);
                    flag = 3;
                }
            }
            else
            {
                flag = 1;
                fprintf(pT, "%s %s %c %.0lf %s\n", contact.firstName, contact.lastName, contact.gender, contact.phoneNumber, contact.cityName);
            }
        }
        else
            fprintf(pT, "%s %s %c %.0lf %s\n", contact.firstName, contact.lastName, contact.gender, contact.phoneNumber, contact.cityName);
    }
    fclose(pF);
    fclose(pT);

    if(flag == 1 || flag == 2)
    {
        pF = fopen("ContactList.txt", "w");
        pT = fopen("temporary.txt", "r");
        
        while(fscanf(pT, "%s %s %c %lf %s\n",contact.firstName, contact.lastName, &contact.gender, &contact.phoneNumber, contact.cityName) != EOF)
            fprintf(pF, "%s %s %c %.0lf %s\n", contact.firstName, contact.lastName, contact.gender, contact.phoneNumber, contact.cityName);

        fclose(pF);
        fclose(pT);
    }
    
    pT = fopen("temporary.txt", "w");
    fclose(pT);

    printf("----------------------------------------- \n");

    if(flag == 0)
        printf("> No contacts found matching your input. \n");
    else if(flag == 1)
        printf("> ERROR: Invalid message try again later. \n");
    else if(flag == 2)
        printf("> Success: contact updated. \n");

    printf("----------------------------------------- \n");
    system("pause");
    adminPanel();
}

void deleteContact()
{
    clearBuffer();
    char confirmDelete[MAX_LENGTH];
    double findNumber;
    int flag = 0;

    printf("----------------------------- \n");
    printf("   >>> Delete Contact <<< \n");
    printf("----------------------------- \n\n");
    printf("Enter the phone number to delete [+91]: ");
    scanf("%lf",&findNumber);
    printf("\n");

    pF = fopen("ContactList.txt", "r");
    FILE *pT = fopen("temporary.txt", "w");

    while(fscanf(pF, "%s %s %c %lf %s\n",contact.firstName, contact.lastName, &contact.gender, &contact.phoneNumber, contact.cityName) != EOF)
    {
        if(findNumber == contact.phoneNumber)
        {
            printf("> Name: %s %s \n", contact.firstName, contact.lastName);
            printf("> Gender: %c \n", contact.gender);
            printf("> City: %s \n", contact.cityName);
            printf("> Phone Number: %.0lf \n", contact.phoneNumber);
            printf("----------------------------- \n\n");

            fflush(stdin);
            flag = 1;
            printf("Type `CONFIRM` to delete this contact: ");
            gets(confirmDelete);

            printf("\n");
            if(strcmp(confirmDelete, "CONFIRM") == 0)
                flag = 2;
            else
                fprintf(pT, "%s %s %c %.0lf %s\n", contact.firstName, contact.lastName, contact.gender, contact.phoneNumber, contact.cityName);
        }
        else
            fprintf(pT, "%s %s %c %.0lf %s\n", contact.firstName, contact.lastName, contact.gender, contact.phoneNumber, contact.cityName);
    }
    fclose(pF);
    fclose(pT);

    if(flag == 1 || flag == 2)
    {
        pF = fopen("ContactList.txt", "w");
        pT = fopen("temporary.txt", "r");
        
        while(fscanf(pT, "%s %s %c %lf %s\n",contact.firstName, contact.lastName, &contact.gender, &contact.phoneNumber, contact.cityName) != EOF)
            fprintf(pF, "%s %s %c %.0lf %s\n", contact.firstName, contact.lastName, contact.gender, contact.phoneNumber, contact.cityName);

        fclose(pF);
        fclose(pT);
    }
    
    pT = fopen("temporary.txt", "w");
    fclose(pT);

    printf("----------------------------------------- \n");

    if(flag == 0)
        printf("> No contacts found matching your input. \n");
    else if(flag == 1)
        printf("> ERROR: Invalid message try again later. \n");
    else
        printf("> Success: contact deleted. \n");

    printf("----------------------------------------- \n");
    system("pause");
    adminPanel();
}

void deleteAllContact()
{
    clearBuffer();
    char confirmDelete[MAX_LENGTH];
    printf("--------------------------------- \n");
    printf("   >>> Delete All Contact <<< \n");
    printf("--------------------------------- \n\n");
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

void displayContact(int entryCode)
{
    clearBuffer();
    printf("---------------------------- \n");
    printf("   >>> Contacts List <<< \n");
    printf("---------------------------- \n");
    pF = fopen("ContactList.txt", "r");

    while(fscanf(pF, "%s %s %c %lf %s\n",contact.firstName, contact.lastName, &contact.gender, &contact.phoneNumber, contact.cityName) != EOF)
    {
        printf("> Name: %s %s \n", contact.firstName, contact.lastName);
        printf("> Gender: %c \n", contact.gender);
        printf("> City: %s \n", contact.cityName);
        printf("> Phone Number: %.0lf \n", contact.phoneNumber);
        printf("--------------------------- \n");
    }

    fclose(pF);
    system("pause");
    (entryCode == 101) ? userPanel() : adminPanel();
}

void searchByName(int entryCode)
{
    clearBuffer();
    char findName[MAX_LENGTH];
    int compare = 1, flag = 0;

    printf("----------------------------- \n");
    printf("   >>> Search By Name <<< \n");
    printf("----------------------------- \n\n");

    printf("Enter the first or last name: ");
    gets(findName);
    strlwr(findName);

    if(findName[strlen(findName) - 1] == ' ')
        findName[strlen(findName) - 1] = '\0';
    
    printf("\n");
    pF = fopen("ContactList.txt", "r");
    while(fscanf(pF, "%s %s %c %lf %s\n",contact.firstName, contact.lastName, &contact.gender, &contact.phoneNumber, contact.cityName) != EOF)
    {
        compare = strcmp(findName, contact.firstName);

        if(compare != 0)
            compare = strcmp(findName, contact.lastName);
        
        if(compare == 0)
        {
            printf("> Name: %s %s \n", contact.firstName, contact.lastName);
            printf("> Gender: %c \n", contact.gender);
            printf("> City: %s \n", contact.cityName);
            printf("> Phone Number: %.0lf \n", contact.phoneNumber);
            printf("----------------------------- \n");
            flag++;
        }
    }
    fclose(pF);
    if(flag == 0)
    {
        printf("----------------------------------------- \n");
        printf("> No contacts found matching your input. \n");
        printf("----------------------------------------- \n");
    }
    system("pause");
    (entryCode == 101) ? userPanel() : adminPanel();
}

void searchByNumber(int entryCode)
{
    clearBuffer();
    double findNumber;
    int flag = 0;

    printf("------------------------------- \n");
    printf("   >>> Search By Number <<< \n");
    printf("------------------------------- \n\n");

    printf("Enter the phone number [+91]: ");
    scanf("%lf",&findNumber);

    printf("\n");
    pF = fopen("ContactList.txt", "r");
    while(fscanf(pF, "%s %s %c %lf %s\n",contact.firstName, contact.lastName, &contact.gender, &contact.phoneNumber, contact.cityName) != EOF)
    {
        if(findNumber == contact.phoneNumber)
        {
            printf("> Name: %s %s \n", contact.firstName, contact.lastName);
            printf("> Gender: %c \n", contact.gender);
            printf("> City: %s \n", contact.cityName);
            printf("> Phone Number: %.0lf \n", contact.phoneNumber);
            printf("----------------------------- \n");
            flag++;
        }
    }
    fclose(pF);
    if(flag == 0)
    {
        printf("----------------------------------------- \n");
        printf("> No contacts found matching your input. \n");
        printf("----------------------------------------- \n");
    }
    system("pause");
    (entryCode == 101) ? userPanel() : adminPanel();
}