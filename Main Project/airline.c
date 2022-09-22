#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PASSENGERS 30

typedef struct
{
    int id; // 4 digits
    char name[30];
    int age;
    char gender[10];
    int passport; // 5 digits
    char address[30];
    char contact[12];
    int luggage;

    char flight[6];
    char departure[15];
    char destination[15];
    char seatClass[30];
    char seatType[30];
    int bill;
} airline;
airline pas[PASSENGERS];
int indexx = 0;

void welcomeScreen();
void mainMenu();
void menu();
void instruction();
void exitScreen();

void reservation();            // 1
void cancel();                 // 2
void flightSchedule(int flag); // 3
void checkDetails();           // 4
void changeSeat();             // 5
void printTicket();            // 6

int checkid(int id); // extra - 1
int main(void)
{
    system("color F0");
    welcomeScreen();
    mainMenu();

    return 0;
}

void welcomeScreen()
{
    system("cls");

    FILE *p;
    p = fopen("welcome.txt", "r");
    char c;
    while (fscanf(p, "%c", &c) != EOF)
        printf("%c", c);
    fclose(p);

    fflush(stdin);
    getchar();
}
void mainMenu()
{
mainMenu:
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Welcome to the Airline Reservation System ***\n\n");
    printf("\t\t\t\t\t\t\t\t--------------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t\t1. Menu\n\n");
    printf("\t\t\t\t\t\t\t\t2. Flight Schedule\n\n");
    printf("\t\t\t\t\t\t\t\t3. Instruction\n\n");
    printf("\t\t\t\t\t\t\t\t4. EXIT\n\n");
    printf("\t\t\t\t\t\t\t\t--------------------------------------------\n\n");

    printf("\t\t\t\t\t\t\t\tEnter Your Choice:     ");
    int mo;
    scanf("%d", &mo);
    if (mo == 1)
        menu();
    else if (mo == 2)
        flightSchedule(1);
    else if (mo == 3)
        instruction();
    else if (mo == 4)
        exitScreen();
    else
        goto mainMenu;
}
void menu()
{
menu:
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Welcome to the Menu***\n\n");
    printf("\t\t\t\t\t\t\t\t--------------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t\t1. Reservation\n\n");
    printf("\t\t\t\t\t\t\t\t2. Cancel\n\n");
    printf("\t\t\t\t\t\t\t\t3. Flight Schedule\n\n");
    printf("\t\t\t\t\t\t\t\t4. Check my details\n\n");
    printf("\t\t\t\t\t\t\t\t5. Change my Seat\n\n");
    printf("\t\t\t\t\t\t\t\t6. Print my ticket\n\n");
    printf("\t\t\t\t\t\t\t\t7. Back to MainMenu\n\n");
    printf("\t\t\t\t\t\t\t\t--------------------------------------------\n\n");

    printf("\t\t\t\t\t\t\t\tEnter Your Choice:     ");
    int mo2;
    scanf("%d", &mo2);
    if (mo2 == 1)
        reservation();
    else if (mo2 == 2)
        cancel();
    else if (mo2 == 3)
        flightSchedule(2);
    else if (mo2 == 4)
        checkDetails();
    else if (mo2 == 5)
        changeSeat();
    else if (mo2 == 6)
        printTicket();
    else if (mo2 == 7)
        mainMenu();
    else
        goto menu;
}
void instruction()
{
    system("cls");

    FILE *p;
    p = fopen("instruction.txt", "r");
    char c;
    while (fscanf(p, "%c", &c) != EOF)
        printf("%c", c);
    fclose(p);

    fflush(stdin);
    getchar();
    mainMenu();
}
void exitScreen()
{
    system("cls");

    FILE *p;
    p = fopen("exit.txt", "r");
    char c;
    while (fscanf(p, "%c", &c) != EOF)
        printf("%c", c);
    fclose(p);
}

// 1 -- menu
void reservation()
{
reservation_input:
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Welcome to the Reservation System ***\n\n");
    printf("\t\t\t\t\t\t\t\tPassenger ID                      :");
    scanf("%d", &pas[indexx].id);
    if (pas[indexx].id == 0)
    {
        printf("\t\t\t\t\t\t\t\tINVALID Paseenger ID.\n");
        printf("\t\t\t\t\t\t\t\tEnter Valid PassengerID.\n\n");

        printf("\t\t\t\t\t\t\t\tEnter any key to continue...");
        fflush(stdin);
        getchar();
        goto reservation_input;
    }

    printf("\t\t\t\t\t\t\t\tName                              :");
    fflush(stdin);
    gets(pas[indexx].name);

    printf("\t\t\t\t\t\t\t\tAge                               :");
    scanf("%d", &pas[indexx].age);

    printf("\t\t\t\t\t\t\t\tGender                            :");
    fflush(stdin);
    gets(pas[indexx].gender);

    printf("\t\t\t\t\t\t\t\tPassport No.                      :");
    scanf("%d", &pas[indexx].passport);

    printf("\t\t\t\t\t\t\t\tAddress                           :");
    fflush(stdin);
    gets(pas[indexx].address);

    printf("\t\t\t\t\t\t\t\tContact                           :");
    fflush(stdin);
    gets(pas[indexx].contact);

    printf("\t\t\t\t\t\t\t\tNumber of Luggage                 :");
    scanf("%d", &pas[indexx].luggage);

    printf("\t\t\t\t\t\t\t\tHave you filled all data?[Y/N]    :");
    char ch;
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'Y' || ch == 'y')
    {
        printf("\n\n\t\t\t\t\t\t\t\tYou have filled out all informations correctly...\n");
        printf("\t\t\t\t\t\t\t\tEnter any key to continue...");
        fflush(stdin);
        getchar();
    }

    else if (ch == 'N' || ch == 'n')
    {
        printf("\t\t\t\t\t\t\t\tFill out you information correctly this time.");
        goto reservation_input;
    }

selectFlight:
    // Flight Schedule
    system("cls");

    FILE *p;
    p = fopen("schedule.txt", "r");
    char c;
    while (fscanf(p, "%c", &c) != EOF)
        printf("%c", c);
    fclose(p);

    printf("\t\t\t\t\t\t\t\tEnter Your Choice:     ");
    int choice1;
    scanf("%d", &choice1);
    if (choice1 == 1)
    {
        strcpy(pas[indexx].flight, "ICPC1");
        strcpy(pas[indexx].departure, "Canada");
        strcpy(pas[indexx].destination, "South Korea");
    }
    else if (choice1 == 2)
    {
        strcpy(pas[indexx].flight, "ICPC2");
        strcpy(pas[indexx].departure, "China");
        strcpy(pas[indexx].destination, "India");
    }
    else if (choice1 == 3)
    {
        strcpy(pas[indexx].flight, "ICPC3");
        strcpy(pas[indexx].departure, "USA");
        strcpy(pas[indexx].destination, "Russia");
    }
    else if (choice1 == 4)
    {
        strcpy(pas[indexx].flight, "ICPC4");
        strcpy(pas[indexx].departure, "Bangladesh");
        strcpy(pas[indexx].destination, "Itali");
    }
    else if (choice1 == 5)
    {
        strcpy(pas[indexx].flight, "ICPC5");
        strcpy(pas[indexx].departure, "Nepal");
        strcpy(pas[indexx].destination, "Bangladesh");
    }
    else
    {
        printf("\t\t\t\t\t\t\t\tInvalid choice.\nEnter choice correctly.\n");
        goto selectFlight;
    }

seatClass:
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Select Your Seat Class***\n\n");
    printf("\t\t\t\t\t\t\t\t----------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t\tNumber    Seat Type                Price\n\n");
    printf("\t\t\t\t\t\t\t\t1.        First Class              $1300\n\n");
    printf("\t\t\t\t\t\t\t\t2.        Business Class           $800 \n\n");
    printf("\t\t\t\t\t\t\t\t3.        Prime Economy Class      $500 \n\n");
    printf("\t\t\t\t\t\t\t\t4.        Economy Class            $250 \n\n");
    printf("\t\t\t\t\t\t\t\t----------------------------------------\n\n");

    printf("\t\t\t\t\t\t\t\tEnter Your Choice:     ");
    int choice2;
    scanf("%d", &choice2);
    if (choice2 == 1)
    {
        strcpy(pas[indexx].seatClass, "First Class");
        pas[indexx].bill = 1300;
    }
    else if (choice2 == 2)
    {
        strcpy(pas[indexx].seatClass, "Business Class");
        pas[indexx].bill = 800;
    }
    else if (choice2 == 3)
    {
        strcpy(pas[indexx].seatClass, "Prime Economy Class");
        pas[indexx].bill = 500;
    }
    else if (choice2 == 4)
    {
        strcpy(pas[indexx].seatClass, "Economy Class");
        pas[indexx].bill = 250;
    }
    else
    {
        printf("\t\t\t\t\t\t\t\tInvalid choice.\nEnter choice correctly.\n");
        goto seatClass;
    }

seatType:
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Select Your Seat Type***\n\n");
    printf("\t\t\t\t\t\t\t\t--------------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t\tNumber    Seat Type\n\n");
    printf("\t\t\t\t\t\t\t\t1.        Window Seat\n\n");
    printf("\t\t\t\t\t\t\t\t2.        Normal Seat\n\n");
    printf("\t\t\t\t\t\t\t\t--------------------------------------------\n\n");

    printf("\t\t\t\t\t\t\t\tEnter Your Choice:     ");
    int choice3;
    scanf("%d", &choice3);
    if (choice3 == 1)
        strcpy(pas[indexx].seatType, "Window Seat");
    else if (choice3 == 2)
        strcpy(pas[indexx].seatType, "Normal Seat");
    else
    {
        printf("\t\t\t\t\t\t\t\tInvalid choice.\nEnter choice correctly.\n");
        goto seatType;
    }

    indexx++;
    menu();
}
// 2 -- cancel
void cancel()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t  *** Cancel Reservation ***\n\n\n");
    printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n\n\n\n");
    printf("\t\t\t\t\t\t\t\tEnter Your Passport ID:     ");
    int id;
    scanf("%d", &id);
    int ind = checkid(id);
    if (ind == -1)
        notFound();
    pas[ind].id = 0;

    printf("\t\t\t\t\t\t\t\tYour reservation has been CANCELLED.\n\n");
    printf("\t\t\t\t\t\t\t\tEnter any key to continue...\n");

    fflush(stdin);
    getchar();
    menu();
}
// 3 -- menu
void flightSchedule(int flag)
{
    system("cls");

    FILE *p;
    p = fopen("schedule.txt", "r");
    char c;
    while (fscanf(p, "%c", &c) != EOF)
        printf("%c", c);
    fclose(p);

    fflush(stdin);
    getchar();
    if (flag == 1)
        mainMenu();
    else
        menu();
}
// 4 -- menu
void checkDetails()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tEnter Your Passport ID:     ");
    int id;
    scanf("%d", &id);
    int ind = checkid(id);
    if (ind == -1)
        notFound();

// found -- details
details:
    system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t\t            *** Details of passenger ***\n\n");
    printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t\tPassenger ID                      :%d\n\n", pas[ind].id);
    printf("\t\t\t\t\t\t\t\tName                              :%s\n\n", pas[ind].name);
    printf("\t\t\t\t\t\t\t\tAge                               :%d\n\n", pas[ind].age);
    printf("\t\t\t\t\t\t\t\tGender                            :%s\n\n", pas[ind].gender);
    printf("\t\t\t\t\t\t\t\tPassport No.                      :%d\n\n", pas[ind].passport);
    printf("\t\t\t\t\t\t\t\tAddress                           :%s\n\n", pas[ind].address);
    printf("\t\t\t\t\t\t\t\tContact                           :%s\n\n", pas[ind].contact);
    printf("\t\t\t\t\t\t\t\tNumber of Luggage                 :%d\n\n", pas[ind].luggage);
    printf("\t\t\t\t\t\t\t\tFlight No.                        :%s\n\n", pas[ind].flight);
    printf("\t\t\t\t\t\t\t\tDeparture                         :%s\n\n", pas[ind].departure);
    printf("\t\t\t\t\t\t\t\tDestination                       :%s\n\n", pas[ind].destination);
    printf("\t\t\t\t\t\t\t\tSeat Class                        :%s\n\n", pas[ind].seatClass);
    printf("\t\t\t\t\t\t\t\tSeat Type                         :%s\n\n\n", pas[ind].seatType);
    printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n");
    printf("\t\t\t\t\t\t\t\tTotal Bill                        :$%d\n", pas[ind].bill);
    printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n\n");

    printf("\t\t\t\t\t\t\t\tEnter any key to continue...\n");
    fflush(stdin);
    getchar();
    menu();
}
// 5 -- menu
void changeSeat()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tEnter Your Passport ID:     ");
    int id;
    scanf("%d", &id);
    int ind = checkid(id);
    if (ind == -1)
        notFound();

seatClass:
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Select Your Seat Class***\n\n");
    printf("\t\t\t\t\t\t\t\t----------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t\tNumber    Seat Type                Price\n\n");
    printf("\t\t\t\t\t\t\t\t1.        First Class              $1300\n\n");
    printf("\t\t\t\t\t\t\t\t2.        Business Class           $800 \n\n");
    printf("\t\t\t\t\t\t\t\t3.        Prime Economy Class      $500 \n\n");
    printf("\t\t\t\t\t\t\t\t4.        Economy Class            $250 \n\n");
    printf("\t\t\t\t\t\t\t\t----------------------------------------\n\n");

    printf("\t\t\t\t\t\t\t\tEnter Your Choice:     ");
    int choice2;
    scanf("%d", &choice2);
    if (choice2 == 1)
    {
        strcpy(pas[ind].seatClass, "First Class");
        pas[ind].bill = 1300;
    }
    else if (choice2 == 2)
    {
        strcpy(pas[ind].seatClass, "Business Class");
        pas[ind].bill = 800;
    }
    else if (choice2 == 3)
    {
        strcpy(pas[ind].seatClass, "Prime Economy Class");
        pas[ind].bill = 500;
    }
    else if (choice2 == 4)
    {
        strcpy(pas[ind].seatClass, "Economy Class");
        pas[ind].bill = 250;
    }
    else
    {
        printf("\t\t\t\t\t\t\t\tInvalid choice.\nEnter choice correctly.\n");
        goto seatClass;
    }

seatType:
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t*** Select Your Seat Type***\n\n");
    printf("\t\t\t\t\t\t\t\t--------------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t\tNumber    Seat Type\n\n");
    printf("\t\t\t\t\t\t\t\t1.        Window Seat\n\n");
    printf("\t\t\t\t\t\t\t\t2.        Normal Seat\n\n");
    printf("\t\t\t\t\t\t\t\t--------------------------------------------\n\n");

    printf("\t\t\t\t\t\t\t\tEnter Your Choice:     ");
    int choice3;
    scanf("%d", &choice3);
    if (choice3 == 1)
        strcpy(pas[ind].seatType, "Window Seat");
    else if (choice3 == 2)
        strcpy(pas[ind].seatType, "Normal Seat");
    else
    {
        printf("\t\t\t\t\t\t\t\tInvalid choice.\nEnter choice correctly.\n");
        goto seatType;
    }
    menu();
}
// 6 -- menu
void printTicket()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tEnter Your Passport ID:     ");
    int id;
    scanf("%d", &id);
    int ind = checkid(id);
    if (ind == -1)
        notFound();

    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n\n");
    printf("\t\t\t\t\t\t\t\t                     *** Ticket ***\n\n");
    printf("\t\t\t\t\t\t\t\t---------------------------------------------------------\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t--------------\n");
    printf("\t\t\t\t\t\t\t\t|              |     Name           :%s\n", pas[ind].name);
    printf("\t\t\t\t\t\t\t\t|  =O=    =O=  |     Passport ID    :%d\n", pas[ind].id);
    printf("\t\t\t\t\t\t\t\t|              |     Age            :%d\n", pas[ind].age);
    printf("\t\t\t\t\t\t\t\t|   \\____/     |     Gender         :%s\n", pas[ind].gender);
    printf("\t\t\t\t\t\t\t\t|              |     Age            :%d\n", pas[ind].age);
    printf("\t\t\t\t\t\t\t\t---------------      Contact        :%s\n\n", pas[ind].contact);
    printf("\t\t\t\t\t\t\t\tFlight No.                :%s\n\n", pas[ind].flight);
    printf("\t\t\t\t\t\t\t\tDeparture                 :%s\n\n", pas[ind].departure);
    printf("\t\t\t\t\t\t\t\tDestination               :%s\n\n", pas[ind].destination);

    printf("\t\t\t\t\t\t\t\tEnter any key to continue...\n");
    fflush(stdin);
    getchar();
    menu();
}

// extra -- 1
int checkid(int id)
{
    for (int i = 0; i < indexx; i++)
        if (pas[i].id == id)
            return i;
    return -1;
}
// extra -- 2
int notFound()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\tNO RECORDS...!!!\n");
    printf("\t\t\t\t\t\t\t\t\tTry inserting valid input first....\n\n\n");
    printf("\t\t\t\t\t\t\t\t\tEnter any key to continue.....");

    fflush(stdin);
    getchar();

    menu();
}


