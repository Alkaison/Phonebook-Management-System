/*
    Project Title: Phonebook Management System 
    Language: C 
    Concepts: File Handling, Struct, Define, etc. 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<ctype.h>

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
    char findNum[MAX_LENGTH];
    char cityName[MAX_LENGTH];
} DETAILS;

// global variables 
char adminPassword[MAX_LENGTH] = "Admin";
char inputPassword[MAX_LENGTH];
char userName[MAX_LENGTH];
char findNumber[MAX_LENGTH];
int choice = 0, len = 0;
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
int isValidNumeric(char num[]);
int isValidName(char *name);
char *removeSpaces(char *str);
void invalidInput(int);
void clearBuffer();

// operational functions 
void addNewContact();
void updateContact();
void deleteContact();
void deleteAllContact();
void displayContact(int);
void searchByName(int);
void searchByNumber(int);
void searchByCity(int);

int main(){

    infoScreen();
    return 0;
}

void infoScreen()
{
    clearBuffer();
    system("title Phonebook Management System");
    system("color 60");
    printf("\n\t\t\t\t------------------------------------------- \n");
    printf("\t\t\t\t   >>> Phonebook Management System  <<< \n");
    printf("\t\t\t\t------------------------------------------- \n\n");
    printf("\t\tIt is a software application that allows users to store, organize\n\t and manage large numbers of contact records efficiently. The system is designed\n\t    to have functions such as adding, updating, viewing and deleting contacts. \n\n");
    printf("\t\t\t\t------------------------------------ \n");
    printf("\t\t\t\t   >>> Meet our project team <<< \n");
    printf("\t\t\t\t------------------------------------ \n\n");
    printf("\t\t\t\t\t > Ganesh Mourya \n");
    printf("\t\t\t\t\t > Amit Nare \n");
    printf("\t\t\t\t\t > Abrar Shaikh \n");
    printf("\t\t\t\t\t > Aditya Tiwari \n");
    printf("\t\t\t\t\t > Vivek Gupta \n");
    printf("\t\t\t\t\t > Manish Nirala \n\n");
    printf("\t\t\t\t------------------------------------ \n\n");
    system("pause");
    loginPage();
}

void loginPage()
{
    clearBuffer();
    system("title Login Page");
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
            printf("--------------------------------------- \n");
            printf("ERROR: Invalid input please try again.  \n");
            printf("--------------------------------------- \n");
            system("pause");
            loginPage();
    }
}

void endScreen()
{
    clearBuffer();
    system("title Credits Page");
    printf("------------------------------------------ \n");
    printf("   >>> Phonebook Management System <<<     \n");
    printf("------------------------------------------ \n");
    Sleep(1500);  // pause the screen for 3 seconds 
    exit(0);
}

void adminLogin()
{
    clearBuffer();
    system("title Admin Login");
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
        printf("------------------------------------------ \n");
        printf("ERROR: Invalid password please try again.  \n");
        printf("------------------------------------------ \n");
        system("pause");
        loginPage();
    }
}

void userPanel()
{
    clearBuffer();
    system("title User Panel");
    printf("----------------------------------- \n");
    printf("\t>>> User Panel <<< \n");
    printf("----------------------------------- \n");
    printf("[1] Display All Contact. \n");
    printf("[2] Search By Name. \n");
    printf("[3] Search By Number. \n");
    printf("[4] Search By City. \n");
    printf("[5] Back to Login. \n");
    printf("[6] EXIT. \n");
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
            searchByCity(USER_CODE);
            break;
        case 5:
            loginPage();
            break;
        case 6:
            endScreen();
            break;
        default:
            printf("---------------------------------------\n");
            printf("ERROR: Invalid input please try again. \n");
            printf("---------------------------------------\n");
            system("pause");
            userPanel();
    }
}

void adminPanel()
{
    clearBuffer();
    system("title Admin Panel");
    printf("------------------------------------ \n");
    printf("\t>>> Admin Panel <<< \n");
    printf("------------------------------------ \n");
    printf(" [1] Add New Contact. \n");
    printf(" [2] Update Contact. \n");
    printf(" [3] Display All Contact. \n");
    printf(" [4] Search By Name. \n");
    printf(" [5] Search By Number. \n");
    printf(" [6] Search By City. \n");
    printf(" [7] Delete Contact. \n");
    printf(" [8] Delete All Contact. \n");
    printf(" [9] Back to Login. \n");
    printf("[10] EXIT. \n");
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
            searchByCity(ADMIN_CODE);
            break;
        case 7:
            deleteContact();
            break;
        case 8:
            deleteAllContact();
            break;
        case 9:
            loginPage();
            break;
        case 10:
            endScreen();
            break;
        default:
            printf("---------------------------------------\n");
            printf("ERROR: Invalid input please try again. \n");
            printf("---------------------------------------\n");
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
            printf("--------------------------------------- \n");
            printf("ERROR: Invalid gender try again later.  \n");
            printf("--------------------------------------- \n");
            return 0;
    }
    return 0;
}

int isValidName(char *name)
{
    for(int cnt=0; cnt < 255; cnt++)
    {
        if(name[cnt] == '\0')
            break;
        if(isalpha(name[cnt]) == 0)
            return 4;
    }
    return 0;
}

int isValidNumeric(char num[])
{   len = 0;
    for(int cnt = 0; cnt < 255; cnt++)
    {
        if(num[cnt] == '\0')
            break;
        len++;
        if(isdigit(num[cnt]) == 0)
        {
            len = 0;
            return 4;
        } 
    }

    if(len != 10)
    {
        printf("------------------------------------------ \n");
        printf("ERROR: phone number must be of 10 digits. \n");
        printf("------------------------------------------ \n");
        return 0;
    }
    else
        return 1;

    return 0;
}

void invalidInput(int entryCode)
{
    printf("--------------------------------------------- \n");
    printf("ERROR: Invalid input please try again later.  \n");
    printf("--------------------------------------------- \n");
    system("pause");
    (entryCode == 101) ? userPanel() : adminPanel();
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
    system("cls");  // clears the output screen 
    fflush(stdin);  // clears the input buffers like '\n' 
}

void addNewContact()
{
    clearBuffer();
    system("title Add New Contact");
    int flag = 0;
    printf("------------------------------ \n");
    printf("   >>> Add New Contact <<<     \n");
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
        gets(contact.findNum);
        printf("\n");

        removeSpaces(contact.findNum);
        // validates gender & phoneNumber inputs to prevent storing invalid data into files 
        if(isValidGender(&contact.gender))
        {
            if(isValidNumeric(contact.findNum) == 1)
            {
                removeSpaces(contact.firstName);
                removeSpaces(contact.lastName);
                removeSpaces(contact.cityName);
                fprintf(pF, "%s %s %c %s %s\n", contact.firstName, contact.lastName, contact.gender, contact.findNum, contact.cityName);
                printf("Success: Contact details added in the record. \n");
            }
            else
                flag = 1;
        }
    }
    else
        printf("ERROR: Unable to locate or open the file. \n");

    fclose(pF);
    if(flag == 1 && len == 0)
    {
        printf("------------------------------------------------------- \n");
        printf("ERROR: Invalid input for phone number try again later.  \n");
        printf("------------------------------------------------------- \n");
    }
    system("pause");
    adminPanel();
}

void updateContact()
{
    clearBuffer();
    system("title Update Contact");
    char confirmDelete[MAX_LENGTH];
    int flag = 0;

    printf("----------------------------- \n");
    printf("   >>> Update Contact <<< \n");
    printf("----------------------------- \n\n");
    printf("Enter the phone number to update [+91]: ");
    gets(findNumber);
    printf("\n");

    if(isValidNumeric(findNumber) == 4)
        invalidInput(ADMIN_CODE);

    pF = fopen("ContactList.txt", "r");
    FILE *pT = fopen("temporary.txt", "w");

    while(fscanf(pF, "%s %s %c %s %s\n",contact.firstName, contact.lastName, &contact.gender, contact.findNum, contact.cityName) != EOF)
    {
        if(strcmp(findNumber, contact.findNum) == 0)
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
            gets(copy.findNum);
            printf("\n");

            fflush(stdin);
            printf("Type `CONFIRM` to update this details: ");
            gets(confirmDelete);

            printf("\n");
            if(strcmp(confirmDelete, "CONFIRM") == 0)
            {
                removeSpaces(copy.findNum);
                if(isValidGender(&copy.gender))
                {
                    if(isValidNumeric(copy.findNum) == 1)
                    {
                        removeSpaces(copy.firstName);
                        removeSpaces(copy.lastName);
                        removeSpaces(copy.cityName);
                        fprintf(pT, "%s %s %c %s %s\n",copy.firstName, copy.lastName, copy.gender, copy.findNum, copy.cityName);
                        flag = 2;
                    }
                    else
                        fprintf(pT, "%s %s %c %s %s\n", contact.firstName, contact.lastName, contact.gender, contact.findNum, contact.cityName);
                }
                else
                {
                    fprintf(pT, "%s %s %c %s %s\n", contact.firstName, contact.lastName, contact.gender, contact.findNum, contact.cityName);
                    flag = 3;
                }
            }
            else
            {
                flag = 1;
                fprintf(pT, "%s %s %c %s %s\n", contact.firstName, contact.lastName, contact.gender, contact.findNum, contact.cityName);
            }
        }
        else
            fprintf(pT, "%s %s %c %s %s\n", contact.firstName, contact.lastName, contact.gender, contact.findNum, contact.cityName);
    }
    fclose(pF);
    fclose(pT);

    // only perform update process only if the user is ready for it 
    if(flag == 1 || flag == 2)
    {
        pF = fopen("ContactList.txt", "w");
        pT = fopen("temporary.txt", "r");
        
        while(fscanf(pT, "%s %s %c %s %s\n",contact.firstName, contact.lastName, &contact.gender, contact.findNum, contact.cityName) != EOF)
            fprintf(pF, "%s %s %c %s %s\n", contact.firstName, contact.lastName, contact.gender, contact.findNum, contact.cityName);

        fclose(pF);
        fclose(pT);
    }
    
    pT = fopen("temporary.txt", "w");
    fclose(pT);

    if(flag == 0 && len == 10)
    {
        printf("----------------------------------------- \n");
        printf("> No contacts found matching your input.  \n");
        printf("----------------------------------------- \n");
    }
    else if(flag == 1)
    {
        printf("----------------------------------------- \n");
        printf("> ERROR: Invalid message try again later. \n");
        printf("----------------------------------------- \n");
    }
    else if(flag == 2)
    {
        printf("----------------------------- \n");
        printf("> Success: contact updated.   \n");
        printf("----------------------------- \n");
    }
    
    system("pause");
    adminPanel();
}

void deleteContact()
{
    clearBuffer();
    system("title Delete Contact");
    char confirmDelete[MAX_LENGTH];
    int flag = 0;

    printf("----------------------------- \n");
    printf("   >>> Delete Contact <<< \n");
    printf("----------------------------- \n\n");
    printf("Enter the phone number to delete [+91]: ");
    gets(findNumber);
    printf("\n");

    if(isValidNumeric(findNumber) == 4)
        invalidInput(ADMIN_CODE);
    
    pF = fopen("ContactList.txt", "r");
    FILE *pT = fopen("temporary.txt", "w");

    while(fscanf(pF, "%s %s %c %s %s\n",contact.firstName, contact.lastName, &contact.gender, contact.findNum, contact.cityName) != EOF)
    {
        if(strcmp(findNumber, contact.findNum) == 0)
        {
            printf("> Name: %s %s \n", contact.firstName, contact.lastName);
            printf("> Gender: %c \n", contact.gender);
            printf("> City: %s \n", contact.cityName);
            printf("> Phone Number: %s \n", contact.findNum);
            printf("----------------------------- \n\n");

            fflush(stdin);
            flag = 1;
            printf("Type `CONFIRM` to delete this contact: ");
            gets(confirmDelete);

            printf("\n");
            if(strcmp(confirmDelete, "CONFIRM") == 0)
                flag = 2;
            else
                fprintf(pT, "%s %s %c %s %s\n", contact.firstName, contact.lastName, contact.gender, contact.findNum, contact.cityName);
        }
        else
            fprintf(pT, "%s %s %c %s %s\n", contact.firstName, contact.lastName, contact.gender, contact.findNum, contact.cityName);
    }
    fclose(pF);
    fclose(pT);

    if(flag == 1 || flag == 2)
    {
        pF = fopen("ContactList.txt", "w");
        pT = fopen("temporary.txt", "r");
        
        while(fscanf(pT, "%s %s %c %s %s\n",contact.firstName, contact.lastName, &contact.gender, contact.findNum, contact.cityName) != EOF)
            fprintf(pF, "%s %s %c %s %s\n", contact.firstName, contact.lastName, contact.gender, contact.findNum, contact.cityName);

        fclose(pF);
        fclose(pT);
    }
    
    pT = fopen("temporary.txt", "w");
    fclose(pT);

    // show the messaage according to the operations perform 
    if(flag == 0 && len == 10)
    {
        printf("----------------------------------------- \n");
        printf("> No contacts found matching your input.  \n");
        printf("----------------------------------------- \n");
    }
    else if(flag == 1)
    {
        printf("----------------------------------------- \n");
        printf("> ERROR: Invalid message try again later. \n");
        printf("----------------------------------------- \n");
    }
    else if(flag == 2)
    {
        printf("----------------------------- \n");
        printf("> Success: contact deleted.   \n");
        printf("----------------------------- \n");
    }

    system("pause");
    adminPanel();
}

void deleteAllContact()
{
    clearBuffer();
    system("title Delete All Contact");
    char confirmDelete[MAX_LENGTH];
    printf("--------------------------------- \n");
    printf("   >>> Delete All Contact <<< \n");
    printf("--------------------------------- \n\n");
    printf("Type `CONFIRM` to delete all the contact. \n");
    printf("Message: ");
    gets(confirmDelete);
    printf("\n");

    // checks for the confirmation message 
    choice = strcmp(confirmDelete, "CONFIRM");
    if(choice == 0)
    {
        pF = fopen("ContactList.txt", "w");  // erases everything from file and then save it 
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
    int counter = 1;
    system("title Display All Contact");
    printf("\n\n\t\t\t\t---------------------------- \n");
    printf("\t\t\t\t   >>> Contacts List <<< \n");
    printf("\t\t\t\t---------------------------- \n\n");
    pF = fopen("ContactList.txt", "r");

    printf("\t\t|===============================================================| \n");
    printf("\t\t|ID| \tName\t\t| Gender | Phone Number\t| City Name\t| \n");
    printf("\t\t|===============================================================| \n");

    while(fscanf(pF, "%s %s %c %s %s\n",contact.firstName, contact.lastName, &contact.gender, contact.findNum, contact.cityName) != EOF)
        printf("\t\t| %d| %s %s \t| %c |\t %s \t| %s \t| \n", counter++, contact.firstName, contact.lastName, contact.gender, contact.findNum, contact.cityName);

    printf("\t\t|===============================================================| \n\n");

    fclose(pF);
    system("pause");
    (entryCode == 101) ? userPanel() : adminPanel();
}

void searchByName(int entryCode)
{
    clearBuffer();
    system("title Search By Name");
    char findName[MAX_LENGTH];
    int compare = 1, flag = 0;

    printf("----------------------------- \n");
    printf("   >>> Search By Name <<<     \n");
    printf("----------------------------- \n\n");

    printf("Enter the first or last name: ");
    gets(findName);

    // if the input has space at end remove it 
    if(findName[strlen(findName) - 1] == ' ')
        findName[strlen(findName) - 1] = '\0';

    printf("\n");
    strlwr(findName);

    if(isValidName(findName) == 4)
        invalidInput(entryCode);

    pF = fopen("ContactList.txt", "r");
    while(fscanf(pF, "%s %s %c %s %s\n",contact.firstName, contact.lastName, &contact.gender, contact.findNum, contact.cityName) != EOF)
    {
        compare = strcmp(findName, contact.firstName);

        if(compare != 0)
            compare = strcmp(findName, contact.lastName);
        
        if(compare == 0)
        {
            printf("> Name: %s %s \n", contact.firstName, contact.lastName);
            printf("> Gender: %c \n", contact.gender);
            printf("> City: %s \n", contact.cityName);
            printf("> Phone Number: %s \n", contact.findNum);
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
    system("title Search By Number");
    int flag = 0;

    printf("------------------------------- \n");
    printf("   >>> Search By Number <<< \n");
    printf("------------------------------- \n\n");

    printf("Enter the phone number [+91]: ");
    gets(findNumber);

    printf("\n");
    if(isValidNumeric(findNumber) == 4)
        invalidInput(entryCode);
    if(len != 10)
        flag++;
    
    pF = fopen("ContactList.txt", "r");
    while(fscanf(pF, "%s %s %c %s %s\n",contact.firstName, contact.lastName, &contact.gender, contact.findNum, contact.cityName) != EOF)
    {
        if(strcmp(findNumber, contact.findNum) == 0)
        {
            printf("> Name: %s %s \n", contact.firstName, contact.lastName);
            printf("> Gender: %c \n", contact.gender);
            printf("> City: %s \n", contact.cityName);
            printf("> Phone Number: %s \n", contact.findNum);
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
    (entryCode == 101) ? userPanel() : adminPanel();  // get them back to there panel according to entrycode 
}

void searchByCity(int entryCode)
{
    clearBuffer();
    system("title Search By City Name");
    char findCity[MAX_LENGTH];
    int compare = 1, flag = 0;

    printf("----------------------------- \n");
    printf("   >>> Search By City <<<     \n");
    printf("----------------------------- \n\n");

    printf("Enter the city name: ");
    gets(findCity);

    // if the input has space at end remove it 
    if(findCity[strlen(findCity) - 1] == ' ')
        findCity[strlen(findCity) - 1] = '\0';

    printf("\n");
    strlwr(findCity);

    if(isValidName(findCity) == 4)
        invalidInput(entryCode);

    pF = fopen("ContactList.txt", "r");
    while(fscanf(pF, "%s %s %c %s %s\n",contact.firstName, contact.lastName, &contact.gender, contact.findNum, contact.cityName) != EOF)
    {
        compare = strcmp(findCity, contact.firstName);
        
        if(compare == 0)
        {
            printf("> Name: %s %s \n", contact.firstName, contact.lastName);
            printf("> Gender: %c \n", contact.gender);
            printf("> City: %s \n", contact.cityName);
            printf("> Phone Number: %s \n", contact.findNum);
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