/* 
   * Bus Reservation System
   * Project Created by BEI TEAM MASK
   * Members : Samikchhya Karki, Aashiq Kumar Mahato, Kaushal Kumar Bhattarai, Mandeep Mishra 
   * First Sememster Mini Project
   * © Copyright 2021 Bus Reservation System | Made by BEI TEAM MASK
   * Only for educational purposes
   * Refrence from ITSourceCode.com
*/
// Including Headers
/* Standard Input and Output Header File */
#include <stdio.h>
/*
  * The header file stdlib stands for Standard Library. 
  * It has the information of memory allocation/freeing functions.
*/
#include <stdlib.h>
/*
  * String.h is the header in the C standard library 
  * Which contains macro definitions, constants and declarations of functions 
  * And types used not only for string handling
  * But also various memory handling functions; the name is thus something of a misnomer. 
*/
#include <string.h>
// Defining variables
// Imaginary Bus List
char bus_choice[50][100] = {"Aashiq Yatayat", "Kaushal Travels", "Samikchhya Travels", "Mandeep Delux", "Thapa Express"};
char name[32][100] = {'\0'};
char number[32][2] = {'\0'};
int number_one[32] = {0};
int bus_number;
// User Defined Function
void bus_list();                               // Bus List Function
void book_seat(int booking, char numstr[100]); // Book Seat Function
void booking();                                // Booking Function
int read_number(int bus_number);               // Read Number Function
void read_name(int bus_number);                // Read Name Function
void status();                                 // Status Function
void alt_status(int bus_number);               // Other Status that takes bus_number
void cancle_booking();                         // Cancel booking

// Main Function
int main()
{
    login(); // Calling Login Function
    int num, i;
    do
    {
        system("cls");
        printf("\n\n ------------------------------------------------------------- \n");
        printf("\t    BUS RESERVATION\n");
        printf("   -------------------  MAIN MENU  ------------------- \n\n");
        printf("   [1] View Bus List\n\n");
        printf("   [2] Book Tickets\n\n");
        printf("   [3] Cancel Booking\n\n");
        printf("   [4] Bus Status\n\n");
        printf("   [5] Exit\n\n");
        printf("   ENTER YOUR CHOICE: ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            bus_list(); //for list of bus
            break;
        case 2:
            booking(); //for booking the tickets
            break;
        case 3:
            cancle_booking(); // for canceling the booking
            break;
        case 4:
            status(); // for viewing the status
            break;
        }
        getch();
    } while (num != 5);
    system("CLS");
    printf("\n\n ---------------------------------------\n");
    printf("   THANK YOU FOR USING THIS BUS RESERVATION SYSTEM");
    getch();
    return 0;
}

void bus_list()
{
    system("cls");
    printf("\n\n ---------------------------------------------------\n");
    printf("     --------------------  BUS LIST  ------------------- \n\n");
    // Bus Choices
    printf("   [1]  =>  %s\n\n", bus_choice[0]);
    printf("   [2]  =>  %s\n\n", bus_choice[1]);
    printf("   [3]  =>  %s\n\n", bus_choice[2]);
    printf("   [4]  =>  %s\n\n", bus_choice[3]);
    printf("   [5]  =>  %s\n\n", bus_choice[4]);
}

void booking()
{

    int i = 0;
    char numstr[100];
    system("cls");
    printf("\n\n   ----------------------------------------------------------------\n\n");
    bus_list(); //for seeing bus list
    printf("   ENTER THE BUS NUMBER: \n");
    scanf("%d", &bus_number);
    system("cls");
    printf("\n\n  -----------------\n");
    printf("Your Bus Number is %d ********** %s", bus_number, bus_choice[bus_number - 1]);
    alt_status(bus_number);
    FILE *f1, *fopen(); //for reading the seats from the user.
    char str1[80] = "32", str2[4], str3[4];
    int seat1, seat2, booking = 0;
    if (bus_number == 1)
    {
        f1 = fopen("bus1.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (bus_number == 2)
    {
        f1 = fopen("bus2.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (bus_number == 3)
    {
        f1 = fopen("bus3.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (bus_number == 4)
    {
        f1 = fopen("bus4.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    else if (bus_number == 5)
    {
        f1 = fopen("bus5.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    }
    seat1 = atoi(str1); //covert the string into number
    if (seat1 <= 0)
    {
        printf("There is no blank seat in this bus ");
    }
    else
    {
        printf("\n   ----------------------------\n\n");
        printf("\n   AVAILABLE SEATS: %d\n", seat1);
        printf("\n   NUMBER OF TICKETS: ");
        scanf("%d", &booking);
        printf("\n");

        seat1 = seat1 - booking;
        itoa(bus_number, numstr, 10);
        book_seat(booking, numstr);
        printf("   The Total booking amount is %d", 200 * booking);
        itoa(seat1, str1, 10);
        //for reading the seats from the user.
        if (bus_number == 1)
        {
            f1 = fopen("bus1.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
        else if (bus_number == 2)
        {
            f1 = fopen("bus2.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
        else if (bus_number == 3)
        {
            f1 = fopen("bus3.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
        else if (bus_number == 4)
        {
            f1 = fopen("bus4.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
        else if (bus_number == 5)
        {
            f1 = fopen("bus5.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
    }
}

void book_seat(int booking, char numstr[100])
{
    char tempstr[100], tempstr1[12] = "status", tempstr2[12] = "number";
    int number;
    FILE *a, *b;
    int i = 0;
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);
    a = fopen(tempstr1, "a");     //for open the file to write the name in the file
    b = fopen(tempstr2, "a");     //for open the file for writing the number in the file
    for (i = 0; i < booking; i++) //for entering the person name and seat number in the file
    {
        printf("  Enter the details for ticket no %d \n\n", i + 1);
        printf("   ENTER THE SEAT NUMBER: ");
        scanf("%d", &number);
        printf("\n   ENTER THE PERSON NAME: ");
        scanf("%s", name[number - 1]);
        printf("\n\n   -----------------\n");
        printf("\n");
        itoa(number, tempstr, 10);
        fprintf(a, "%s ", name[number - 1]);
        fprintf(b, "%s ", tempstr);
    }
    fclose(a);
    fclose(b);
}

int read_number(int bus_number) //for putting the numeric value in the array
{
    char tempstr[100], tempstr2[12] = "number";
    FILE *a, *b;
    char numstr[100];
    int i = 0, j = 0, k;
    itoa(bus_number, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr2, numstr);
    a = fopen(tempstr2, "a+"); //for open the file to write the name in the file
    while (!feof(a))
    {
        number[i][j] = fgetc(a);

        if (number[i][j] == ' ')
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
    k = i;
    for (i = 0; i < k; i++)
    {
        number_one[i] = atoi(number[i]);
    }
    fclose(a);
    return k;
}

void read_name(int bus_number) //for putting the numeric value in the array
{
    char tempstr1[12] = "status";
    FILE *b;
    char numstr[100];
    int i = 0, j = 0, k = 0;
    itoa(bus_number, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    b = fopen(tempstr1, "a+"); //for open the file to write the name in the file
    while (!feof(b))
    {
        name[i][j] = fgetc(b);

        if (name[i][j] == ' ')
        {
            j = 0;
            i++;
        }
        else
        {
            j++;
        }
    }
    name[i][j] = '\0';
    k = i;
    fclose(b);
}

void status()
{
    system("cls");
    printf("\n\n  ------------------------------------------------------------\n\n");
    printf("\t\t      BUS RESERVATION          \n\n");
    int i, bus_number, index = 0, j;
    printf("\n   ENTER THE BUS NUMBER: ");
    scanf("%d", &bus_number);
    j = read_number(bus_number);
    read_name(bus_number);
    printf("\t\t   Bus No.%d: %s\n", bus_number, bus_choice[bus_number - 1]);
    char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (i = 0; i < j; i++)
    {
        strcpy(tempname[number_one[i]], name[i]);
    }
    for (i = 0; i < 8; i++)
    {
        printf("   ");
        for (j = 0; j < 4; j++)
        {
            printf("%d.%s\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n");
    }
}

void alt_status(int bus_number)
{
    printf("Your Bus Number is %d ********** %s", bus_number, bus_choice[bus_number - 1]);
    system("cls");
    printf("\n\n  ----------------------------------------------------------\n");
    printf("\t\t      BUS RESERVATION\n\n");
    int i, index = 0, j;
    j = read_number(bus_number);
    read_name(bus_number);
    char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty "};
    for (i = 0; i < j; i++)
    {
        strcpy(tempname[number_one[i]], name[i]);
    }
    for (i = 0; i < 8; i++)
    {
        printf("   ");
        for (j = 0; j < 4; j++)
        {
            printf("%d.%s\t", index + 1, tempname[index + 1]);
            index++;
        }
        printf("\n");
    }
}

void cancle_booking()
{
    int seat_no, i, j;
    char numstr[100], tempstr2[15] = "number", tempstr1[15] = "status";
    printf("\n   ENTER THE BUS NUMBER: ");
    scanf("%d", &bus_number);
    itoa(bus_number, numstr, 10);
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);
    read_number(bus_number);
    read_name(bus_number);
    alt_status(bus_number);
    printf("\n   ENTER THE SEAT NUMBER: ");
    scanf("%d", &seat_no);
    FILE *a, *b;
    a = fopen(tempstr1, "w+");
    b = fopen(tempstr2, "w+");
    for (i = 0; i < 32; i++)
    {
        if (number_one[i] == seat_no)
        {
            for (j = 0; j < 32; j++)
            {
                if (number_one[j] != seat_no && number_one[j] != 0)
                {
                    fprintf(b, "%d ", number_one[j]);
                    fprintf(a, "%s", name[j]);
                }
                else if (number_one[j] == seat_no && number_one[j] != 0)
                {
                    strcpy(name[j], "Empty ");
                }
            }
        }
    }
    fclose(a);
    fclose(b);
    printf("\n\n");
    printf("\n\n   ---------------------------------------------------------- \n");
    printf("   Your Rs 200 has been Returned\n");
}

void login()
{
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "beimask";
    char pass[10] = "beimask";
    do
    {
        system("cls");
        printf("\n\n-----------------\n");
        printf("WELCOME TO BUS RESERVATION");
        printf("\nBy BEI MASK TEAM\n");
        printf("\n-----------------\n");
        printf("Enter the following for login");
        printf("\n-----------------\n");
        printf("\n\n   ENTER USERNAME: ");
        scanf("%s", &uname);
        printf(" \n   ENTER PASSWORD: ");
        while (i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i] = '\0';
        //char code=pword;
        i = 0;
        //scanf("%s",&pword);
        if (strcmp(uname, "beimask") == 0 && strcmp(pword, "beimask") == 0)
        {
            printf("\n  -----------------------------");
            printf("  \n\n   WELCOME USER !!!!");
            printf("\n\n\n   Press any key to continue...");
            getch(); //holds the screen
            break;
        }
        else
        {
            printf("\n ---------------------------------------");
            printf("\n\n   LOGIN IS UNSUCESSFUL...PLEASE TRY AGAIN...");
            a++;

            getch(); //holds the screen
        }
    } while (a <= 2);
    if (a > 2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");

        getch();
    }
    system("cls");
}
