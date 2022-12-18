//********projet gestionnaire de bibliothèque de Fourat Jebali 1ére prepa Group 03********//
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
//----------Menu------------
int selection = -1;
int *p = &selection;
void menu1();
void menu2();
void menu3();
void menu4();
void print_users();
void print_docs();
void menu()
{
    system("cls");
    printf("welcome to the main menu , press enter to continue ");
    int test = 1;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to exit program) \n"
               "To add - delete - update - search a user enter 1 \n"
               "To add - delete - update - search a document enter 2 \n"
               "To return a book enter 3 \n"
               "To request a new loan enter 4 \n"
               "To print all users enter 5 \n"
               "To print all documents enter 6 \n"
               "\nEnter choice: ");

        scanf("%d", p);
        if (*p == 0)
        {
            break;
        }
        else
        {
            if ((*p == 1) or (*p == 2) or (*p == 3) or (*p == 4) or (*p == 5) or (*p == 6))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", *p);
                test = 1;
            }
        }
    } while (test == 1);
    switch (*p)
    {
    case 1:
        menu1();
        break;
    case 2:
        menu2();
        break;
    case 3:
        menu3();
        break;
    case 4:
        menu4();
        break;
    case 5:
        print_users();
        break;
    case 6:
        print_docs();
        break;
    }
}
int choice()
{
    int n;
    do
    {
        printf("\nif u want to continue doing this task type 1"
               "\nto return to the main menu type 0"
               "\nEnter choice :");
        scanf("%d", &n);
    } while ((n != 0) && (n != 1));
    return n;
}
//---------------manage documents------------------
typedef struct
{
    char title[20];
    char location[20];
    int code;
    int nb;
} docs;
typedef struct
{
    int day;
    int month;
    int year;
} date;

typedef struct
{
    char auteur[20];
    date date1;
    docs docs1;
} article;
// intitialisation des données dans le tableau d'enreg
article art[20] = {{"David abraham", {10, 10, 1990}, {"Anxiety", "row 1", 1, 7}},
                   {"Eduard camavinga", {22, 7, 2022}, {"Ukraine invasion", "row 5", 2, 1}},
                   {"Christina kuvski", {3, 1, 2019}, {"pollution in serbia", "row 17", 3, 6}}};
int taille_art = 3;

typedef struct
{
    char auteur[20];
    char editeur[20];
    date date2;
    docs docs2;
} livre;
// intitialisation des données dans le tableau d'enreg
livre liv[20] = {{"Safi saied", "Safi saied", {17, 3, 2008}, {"Politique", "row 6", 1, 13}},
                 {"David abraham", "David abraham", {30, 7, 2022}, {"ooooooo", "row 3", 2, 0}},
                 {"Ahmed Ahmed", "Ahmed Ahmed", {23, 3, 2001}, {"zzzzz", "row 19", 3, 1}}};
int taille_liv = 3;

typedef struct
{
    int freq;
    docs docs3;
} magazine;
magazine mag[20] = {{7, {"mag1", "row 400", 1, 4}},
                    {3, {"mag2", "row 36", 2, 47}},
                    {9, {"mag3", "row 17", 3, 20}}};
int taille_mag = 3;
// test on date
int verif_day(int d)
{
    if ((d < 1) and (d > 31))
    {
        return 0;
    }
    return 1;
}
int verif_month(int m)
{
    if ((m < 1) and (m > 12))
    {
        return 0;
    }
    return 1;
}
int verif_year(int y)
{
    if ((y < 1950) and (y > 2023))
    {
        return 0;
    }
    return 1;
}
// test on existence
// articles
int exist_in_art(int id1)
{
    int i;
    for (i = 0; i < taille_art; i++)
    {
        if (art[i].docs1.code == id1)
        {
            return 1;
        }
    }
    return 0;
}
// books
int exist_in_liv(int id1)
{
    int i;
    for (i = 0; i < taille_liv; i++)
    {
        if (liv[i].docs2.code == id1)
        {
            return 1;
        }
    }
    return 0;
}
// magazine
int exist_in_mag(int id1)
{
    int i;
    for (i = 0; i < taille_mag; i++)
    {
        if (mag[i].docs3.code == id1)
        {
            return 1;
        }
    }
    return 0;
}
// articles :

void add_article()
{
    do
    {
        system("cls");
        getchar();
        printf("Enter the author name :");
        gets(art[taille_art].auteur);

        printf("Enter the sort date :");
        printf("\nday :");
        scanf("%d", &art[taille_art].date1.day);
        printf("month :");
        scanf("%d", &art[taille_art].date1.month);
        printf("year :");
        scanf("%d", &art[taille_art].date1.year);

        printf("Enter the article title :");
        gets(art[taille_art].docs1.title);

        printf("Enter the article location :");
        gets(art[taille_art].docs1.location);

        art[taille_art].docs1.code = taille_art + 1;

        printf("Enter the quantity of article you want to add :");
        scanf("%d", &art[taille_art].docs1.nb);
        taille_art = taille_art + 1;
    } while (choice() == 1);
    menu();
}

// books :

void add_livre()
{
    do
    {
        system("cls");
        getchar();
        printf("Enter the author name :");
        gets(liv[taille_liv].auteur);

        printf("Enter the editor :");
        gets(liv[taille_liv].editeur);

        printf("Enter the sort date :");
        printf("\nday :");
        scanf("%d", &liv[taille_liv].date2.day);
        printf("month :");
        scanf("%d", &liv[taille_liv].date2.month);
        printf("year :");
        scanf("%d", &liv[taille_liv].date2.year);

        printf("Enter the book title :");
        gets(liv[taille_liv].docs2.title);

        printf("Enter the book location :");
        gets(liv[taille_liv].docs2.location);

        liv[taille_liv].docs2.code = taille_liv + 1;

        printf("Enter the number of books you want to add :");
        scanf("%d", &liv[taille_liv].docs2.nb);
        taille_liv = taille_liv + 1;
    } while (choice() == 1);
    menu();
}

// magazines :

void add_magazine()
{
    do
    {
        system("cls");
        getchar();
        printf("Enter the frequency :");
        scanf("%d", &mag[taille_mag].freq);

        printf("Enter the magazine title :");
        gets(mag[taille_mag].docs3.title);

        printf("Enter the magazine location :");
        gets(mag[taille_mag].docs3.location);

        mag[taille_mag].docs3.code = taille_mag + 1;

        printf("Enter the number of magazines you want to add :");
        scanf("%d", &mag[taille_mag].docs3.nb);
        taille_mag = taille_mag + 1;
    } while (choice() == 1);
    menu();
}

void sous_menu_add()
{
    system("cls");
    printf("ADD DOCUMENT MENU");
    int test = 1;
    int select;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to the main menu) \n"
               "To add an article enter 1 \n"
               "To add a book enter 2 \n"
               "To add a magazine enter 3 \n"
               "\nEnter choice: ");

        scanf("%d", &select);
        if (select == 0)
        {
            menu();
        }
        else
        {
            if ((select == 1) or (select == 2) or (select == 3))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select)
    {
    case 1:
        add_article();
        break;
    case 2:
        add_livre();
        break;
    case 3:
        add_magazine();
        break;
    }
}

void add_doc()
{
    system("cls");
    sous_menu_add();
}
// delete article
int position_in_art(int x)
{
    int pos = -1;
    for (int i = 0; i < taille_art; i++)
    {
        if (art[i].docs1.code = x)
        {
            pos = i;
        }
    }
    return pos;
}
void delete_article()
{
    do
    {
        system("cls");
        int id1;
        printf("Enter article id :");
        scanf("%d", &id1);
        for (int i = 0; i < taille_art; i++)
        {
            int pos = position_in_art(id1);
            if (pos == -1)
            {
                printf("This article does not exist in our database !");
                break;
            }
            else
            {
                for (int j = pos; j < taille_art; j++)
                {
                    art[j] = art[j + 1];
                }
            }
        }
        taille_art = taille_art - 1;
    } while (choice() == 1);
    menu();
}

// delete book

int position_in_liv(int x)
{
    int pos = -1;
    for (int i = 0; i < taille_liv; i++)
    {
        if (liv[i].docs2.code = x)
        {
            pos = i;
        }
    }
    return pos;
}
void delete_book()
{
    do
    {
        system("cls");
        int id1;
        printf("Enter the book id :");
        scanf("%d", &id1);
        for (int i = 0; i < taille_liv; i++)
        {
            int pos = position_in_liv(id1);
            if (pos == -1)
            {
                printf("This book does not exist in our database !");
            }
            else
            {
                for (int j = pos; j < taille_liv; j++)
                {
                    liv[j] = liv[j + 1];
                }
            }
        }
        taille_liv = taille_liv - 1;
    } while (choice() == 1);
    menu();
}

// delete magazine

int position_in_mag(int x)
{
    int pos = -1;
    for (int i = 0; i < taille_mag; i++)
    {
        if (mag[i].docs3.code = x)
        {
            pos = i;
        }
    }
    return pos;
}
void delete_magazine()
{
    do
    {
        system("cls");
        int id1;
        printf("Enter the magazine id :");
        scanf("%d", &id1);
        for (int i = 0; i < taille_mag; i++)
        {
            int pos = position_in_mag(id1);
            if (pos == -1)
            {
                printf("This magazine does not exist in our database !");
            }
            else
            {
                for (int j = pos; j < taille_mag; j++)
                {
                    mag[j] = mag[j + 1];
                }
            }
        }
        taille_mag = taille_mag - 1;
    } while (choice() == 1);
    menu();
}

// delete doc

void sous_menu_delete()
{
    system("cls");
    printf("DELETE DOCUMENT MENU");
    int test = 1;
    int select;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to the main menu) \n"
               "To delete an article enter 1 \n"
               "To delete a book enter 2 \n"
               "To delete a magazine enter 3 \n"
               "\nEnter choice: ");

        scanf("%d", &select);
        if (select == 0)
        {
            menu();
        }
        else
        {
            if ((select == 1) or (select == 2) or (select == 3))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select)
    {
    case 1:
        delete_article();
        break;
    case 2:
        delete_book();
        break;
    case 3:
        delete_magazine();
        break;
    }
}
void delete_doc()
{
    sous_menu_delete();
}

// update doc

// update article
void sous_menu_update_article();
void update_auteur_article(int id1)
{
    system("cls");
    char auteur1[20];
    printf("enter the new author name :");
    gets(auteur1);
    for (int i = 0; i < taille_art; i++)
    {
        if (art[i].docs1.code == id1)
        {
            strcpy(art[i].auteur, auteur1);
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_article();
    }
    else
    {
        menu();
    }
}
void update_day_art(int id1)
{
    system("cls");
    int newday;
    printf("enter the new day :");
    scanf("%d", &newday);
    for (int i = 0; i < taille_art; i++)
    {
        if (art[i].docs1.code == id1)
        {
            art[i].date1.day = newday;
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_article();
    }
    else
    {
        menu();
    }
}
void update_month_art(int id1)
{
    system("cls");
    int newmonth;
    printf("enter the new month :");
    scanf("%d", &newmonth);
    for (int i = 0; i < taille_art; i++)
    {
        if (art[i].docs1.code == id1)
        {
            art[i].date1.month = newmonth;
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_article();
    }
    else
    {
        menu();
    }
}
void update_year_art(int id1)
{
    system("cls");
    int newyear;
    printf("enter the new year :");
    scanf("%d", &newyear);
    for (int i = 0; i < taille_art; i++)
    {
        if (art[i].docs1.code == id1)
        {
            art[i].date1.year = newyear;
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_article();
    }
    else
    {
        menu();
    }
}
void sous_menu_update_date_article(int id1)
{
    system("cls");
    printf("UPDATE ARTICLE DATE MENU");
    int test = 1;
    int select;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to the main menu) \n"
               "To update day enter 1 \n"
               "To update month enter 2 \n"
               "To update year enter 3 \n"
               "\nEnter choice: ");

        scanf("%d", &select);
        if (select == 0)
        {
            menu();
        }
        else
        {
            if ((select == 1) or (select == 2) or (select == 3))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select)
    {
    case 1:
        update_day_art(id1);
        break;
    case 2:
        update_month_art(id1);
        break;
    case 3:
        update_year_art(id1);
        break;
    }
}
void update_date_article(int id1)
{
    sous_menu_update_date_article(id1);
}
void update_title_article(int id1)
{
    system("cls");
    char title1[20];
    printf("enter the new title :");
    gets(title1);
    for (int i = 0; i < taille_art; i++)
    {
        if (art[i].docs1.code == id1)
        {
            strcpy(art[i].docs1.title, title1);
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_article();
    }
    else
    {
        menu();
    }
}
void update_location_article(int id1)
{
    system("cls");
    char loc1[20];
    printf("enter the new location :");
    gets(loc1);
    for (int i = 0; i < taille_art; i++)
    {
        if (art[i].docs1.code == id1)
        {
            strcpy(art[i].docs1.location, loc1);
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_article();
    }
    else
    {
        menu();
    }
}
void update_quantity_article(int id1)
{
    system("cls");
    int qte;
    printf("enter the new quantity :");
    scanf("%d", &qte);
    for (int i = 0; i < taille_art; i++)
    {
        if (art[i].docs1.code == id1)
        {
            art[i].docs1.nb = qte;
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_article();
    }
    else
    {
        menu();
    }
}
void sous_menu_update_article()
{
    system("cls");
    printf("UPDATE ARTICLES MENU");
    int test = 1;
    int select, id1;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to the main menu) \n"
               "To the author name of an article enter 1 \n"
               "To the date of an article enter 2 \n"
               "To the title of an article enter 3 \n"
               "To the location of an article enter 4 \n"
               "To the quantity of an article enter 5 \n"
               "\nEnter choice: ");

        scanf("%d", &select);
        if (select == 0)
        {
            menu();
        }
        else
        {
            if ((select == 1) or (select == 2) or (select == 3) or (select == 4) or (select == 5) or (select == 6))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select);
                test = 1;
            }
        }
    } while (test == 1);
    printf("enter article code you want to update :");
    scanf("%d", &id1);
    while (exist_in_art(id1) == 0)
    {
        printf("Sorry this code does not exist in our data base"
               "\nplease enter a valid id :");
        scanf("%d", &id1);
    }
    switch (select)
    {
    case 1:
        update_auteur_article(id1);
        break;
    case 2:
        update_date_article(id1);
        break;
    case 3:
        update_title_article(id1);
        break;
    case 4:
        update_location_article(id1);
        break;
    case 5:
        update_quantity_article(id1);
        break;
    }
}

void update_article()
{
    sous_menu_update_article();
}

// update books
void sous_menu_update_book();
void update_auteur_book(int id1)
{
    system("cls");
    char auteur1[20];
    printf("enter the new author name :");
    gets(auteur1);
    for (int i = 0; i < taille_liv; i++)
    {
        if (liv[i].docs2.code == id1)
        {
            strcpy(liv[i].auteur, auteur1);
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_book();
    }
    else
    {
        menu();
    }
}
void update_editeur_book(int id1)
{
    system("cls");
    char editeur1[20];
    printf("enter the new editor name :");
    gets(editeur1);
    for (int i = 0; i < taille_liv; i++)
    {
        if (liv[i].docs2.code == id1)
        {
            strcpy(liv[i].editeur, editeur1);
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_book();
    }
    else
    {
        menu();
    }
}
void update_day_liv(int id1)
{
    system("cls");
    int newday;
    printf("enter the new day :");
    scanf("%d", &newday);
    for (int i = 0; i < taille_liv; i++)
    {
        if (liv[i].docs2.code == id1)
        {
            liv[i].date2.day = newday;
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_book();
    }
    else
    {
        menu();
    }
}
void update_month_liv(int id1)
{
    system("cls");
    int newmonth;
    printf("enter the new month :");
    scanf("%d", &newmonth);
    for (int i = 0; i < taille_liv; i++)
    {
        if (liv[i].docs2.code == id1)
        {
            liv[i].date2.month = newmonth;
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_book();
    }
    else
    {
        menu();
    }
}
void update_year_liv(int id1)
{
    system("cls");
    int newyear;
    printf("enter the new year :");
    scanf("%d", &newyear);
    for (int i = 0; i < taille_liv; i++)
    {
        if (liv[i].docs2.code == id1)
        {
            liv[i].date2.year = newyear;
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_book();
    }
    else
    {
        menu();
    }
}
void sous_menu_update_date_book(int id1)
{
    system("cls");
    printf("UPDATE BOOKS DATE MENU");
    int test = 1;
    int select;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to the main menu) \n"
               "To update day enter 1 \n"
               "To update month enter 2 \n"
               "To update year enter 3 \n"
               "\nEnter choice: ");

        scanf("%d", &select);
        if (select == 0)
        {
            menu();
        }
        else
        {
            if ((select == 1) or (select == 2) or (select == 3))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select)
    {
    case 1:
        update_day_liv(id1);
        break;
    case 2:
        update_month_liv(id1);
        break;
    case 3:
        update_year_liv(id1);
        break;
    }
}
void update_date_book(int id1)
{
    sous_menu_update_date_book(id1);
}
void update_title_book(int id1)
{
    system("cls");
    char title1[20];
    printf("enter the new title :");
    gets(title1);
    for (int i = 0; i < taille_liv; i++)
    {
        if (liv[i].docs2.code == id1)
        {
            strcpy(liv[i].docs2.title, title1);
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_book();
    }
    else
    {
        menu();
    }
}
void update_location_book(int id1)
{
    system("cls");
    char loc1[20];
    printf("enter the new location :");
    gets(loc1);
    for (int i = 0; i < taille_liv; i++)
    {
        if (liv[i].docs2.code == id1)
        {
            strcpy(liv[i].docs2.location, loc1);
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_book();
    }
    else
    {
        menu();
    }
}
void update_quantity_book(int id1)
{
    system("cls");
    int qte;
    printf("enter the new quantity :");
    scanf("%d", &qte);
    for (int i = 0; i < taille_liv; i++)
    {
        if (liv[i].docs2.code == id1)
        {
            liv[i].docs2.nb = qte;
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_book();
    }
    else
    {
        menu();
    }
}
void sous_menu_update_book()
{
    system("cls");
    printf("UPDATE BOOKS MENU");
    int test = 1;
    int select, id1;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to the main menu) \n"
               "To update the author name of a book enter 1 \n"
               "To update the editor name of a book enter 2 \n"
               "To update the date of a book enter 3 \n"
               "To update the title of a book enter 4 \n"
               "To update the location of a book enter 5 \n"
               "To update the quantity of a book enter 6 \n"
               "\nEnter choice: ");

        scanf("%d", &select);
        if (select == 0)
        {
            menu();
        }
        else
        {
            if ((select == 1) or (select == 2) or (select == 3) or (select == 4) or (select == 5) or (select == 6) or (select == 7))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select);
                test = 1;
            }
        }
    } while (test == 1);
    printf("\nenter book code you want to update :");
    scanf("%d", &id1);
    while (exist_in_liv(id1) == 0)
    {
        printf("Sorry this code does not exist in our data base"
               "\nplease enter a valid id :");
        scanf("%d", &id1);
    }
    switch (select)
    {
    case 1:
        update_auteur_book(id1);
        break;
    case 2:
        update_editeur_book(id1);
        break;
    case 3:
        update_date_book(id1);
        break;
    case 4:
        update_title_book(id1);
        break;
    case 5:
        update_location_book(id1);
        break;
    case 6:
        update_quantity_book(id1);
        break;
    }
}

void update_book()
{
    sous_menu_update_book();
}

// update magazine
void sous_menu_update_magazine();
void update_freq_mag(int id1)
{
    system("cls");
    int newfreq;
    printf("Enter a new frequency :");
    scanf("%d", &newfreq);
    for (int i = 0; i < taille_mag; i++)
    {
        if (mag[i].docs3.code == id1)
        {
            mag[i].freq = newfreq;
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_magazine();
    }
    else
    {
        menu();
    }
}
void update_title_mag(int id1)
{
    system("cls");
    char title1[20];
    printf("enter the new title :");
    gets(title1);
    for (int i = 0; i < taille_mag; i++)
    {
        if (mag[i].docs3.code == id1)
        {
            strcpy(mag[i].docs3.title, title1);
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_magazine();
    }
    else
    {
        menu();
    }
}
void update_location_mag(int id1)
{
    system("cls");
    char loc1[20];
    printf("enter the new location :");
    gets(loc1);
    for (int i = 0; i < taille_mag; i++)
    {
        if (mag[i].docs3.code == id1)
        {
            strcpy(mag[i].docs3.location, loc1);
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_magazine();
    }
    else
    {
        menu();
    }
}
void update_quantity_mag(int id1)
{
    system("cls");
    int qte;
    printf("enter the new quantity :");
    scanf("%d", &qte);
    for (int i = 0; i < taille_mag; i++)
    {
        if (mag[i].docs3.code == id1)
        {
            mag[i].docs3.nb = qte;
        }
    }
    int n = choice();
    if (n == 1)
    {
        sous_menu_update_magazine();
    }
    else
    {
        menu();
    }
}
void sous_menu_update_magazine()
{
    system("cls");
    printf("UPDATE MAGAZINES MENU");
    int test = 1;
    int select, id1;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to the main menu) \n"
               "To update the frequency of a magazine enter 1 \n"
               "To update the title of a magazine enter 2 \n"
               "To update the location of a magazine enter 3 \n"
               "To update the number of magazines available enter 4 \n"
               "\nEnter choice: ");

        scanf("%d", &select);
        if (select == 0)
        {
            menu();
        }
        else
        {
            if ((select == 1) or (select == 2) or (select == 3) or (select == 4) or (select == 5))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select);
                test = 1;
            }
        }
    } while (test == 1);
    printf("\nenter magazine code you want to update :");
    scanf("%d", &id1);
    while (exist_in_mag(id1) == 0)
    {
        printf("Sorry this code does not exist in our data base"
               "\nplease enter a valid id :");
        scanf("%d", &id1);
    }
    switch (select)
    {
    case 1:
        update_freq_mag(id1);
        break;
    case 2:
        update_title_mag(id1);
        break;
    case 3:
        update_location_book(id1);
        break;
    case 4:
        update_quantity_mag(id1);
        break;
    }
}

void update_magazine()
{
    sous_menu_update_magazine();
}

void sous_menu_update()
{
    system("cls");
    printf("UPDATE DOCUMENT MENU");
    int test = 1;
    int select;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to the main menu) \n"
               "To update an article enter 1 \n"
               "To update a book enter 2 \n"
               "To update a magazine enter 3 \n"
               "\nEnter choice: ");

        scanf("%d", &select);
        if (select == 0)
        {
            menu();
        }
        else
        {
            if ((select == 1) or (select == 2) or (select == 3))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select)
    {
    case 1:
        update_article();
        break;
    case 2:
        update_book();
        break;
    case 3:
        update_magazine();
        break;
    }
}

void update_doc()
{
    system("cls");
    sous_menu_update();
}

// search for a doc
// search article
void search_article();
void search_article_by_author()
{
    system("cls");
    char auteur1[20];
    int test, pos;
    test = 0;
    printf("Enter the author name :");
    gets(auteur1);
    for (int i = 0; i < taille_art; i++)
    {
        if (strcmp(art[i].auteur, auteur1) == 0)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The article : \nauthor name : %s \npublish date : %d/%d/%d"
               "\ntitle : %s \ncode : %d \nlocation : %s \nquantity : %d",
               art[pos].auteur, art[pos].date1.day, art[pos].date1.month, art[pos].date1.year,
               art[pos].docs1.title, art[pos].docs1.code, art[pos].docs1.location, art[pos].docs1.nb);
    }
    else
    {
        printf("Sorry we could not find an article !");
    }
    int n = choice();
    if (n == 1)
    {
        search_article();
    }
    else
    {
        menu();
    }
}
void search_article_by_title()
{
    system("cls");
    char title1[20];
    int test, pos;
    test = 0;
    printf("Enter the title :");
    gets(title1);
    for (int i = 0; i < taille_art; i++)
    {
        if (strcmp(art[i].docs1.title, title1) == 0)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    printf("\nSorry we could not find an article !");
    if (test == 1)
    {
        printf("The article : \nauthor name : %s \npublish date : %d/%d/%d"
               "\ntitle : %s \ncode : %d \nlocation : %s \nquantity : %d",
               art[pos].auteur, art[pos].date1.day, art[pos].date1.month, art[pos].date1.year,
               art[pos].docs1.title, art[pos].docs1.code, art[pos].docs1.location, art[pos].docs1.nb);
    }
    else
    {
        printf("Sorry we could not find an article !");
    }
    int n = choice();
    if (n == 1)
    {
        search_article();
    }
    else
    {
        menu();
    }
}
void search_article_by_date()
{
    system("cls");
    int day1, month1, year1, test, pos;
    test = 0;
    printf("Enter the day :");
    scanf("%d", &day1);
    printf("Enter the month :");
    scanf("%d", &month1);
    printf("Enter the year :");
    scanf("%d", &year1);
    for (int i = 0; i < taille_art; i++)
    {
        if ((art[i].date1.day == day1) and (art[i].date1.month == month1) and (art[i].date1.year == year1))
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The article : \nauthor name : %s \npublish date : %d/%d/%d"
               "\ntitle : %s \ncode : %d \nlocation : %s \nquantity : %d",
               art[pos].auteur, art[pos].date1.day, art[pos].date1.month, art[pos].date1.year,
               art[pos].docs1.title, art[pos].docs1.code, art[pos].docs1.location, art[pos].docs1.nb);
    }
    else
    {
        printf("Sorry we could not find an article !");
    }
    int n = choice();
    if (n == 1)
    {
        search_article();
    }
    else
    {
        menu();
    }
}
void search_article_by_location()
{
    system("cls");
    char loc1[20];
    int test, pos;
    test = 0;
    printf("Enter the location :");
    gets(loc1);
    for (int i = 0; i < taille_art; i++)
    {
        if (strcmp(art[i].docs1.location, loc1) == 0)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The article : \nauthor name : %s \npublish date : %d/%d/%d"
               "\ntitle : %s \ncode : %d \nlocation : %s \nquantity : %d",
               art[pos].auteur, art[pos].date1.day, art[pos].date1.month, art[pos].date1.year,
               art[pos].docs1.title, art[pos].docs1.code, art[pos].docs1.location, art[pos].docs1.nb);
    }
    else
    {
        printf("Sorry we could not find an article !");
    }
    int n = choice();
    if (n == 1)
    {
        search_article();
    }
    else
    {
        menu();
    }
}
void search_article_by_code()
{
    system("cls");
    system("cls");
    int code1, test, pos;
    test = 0;
    printf("Enter the code :");
    scanf("%d", &code1);
    for (int i = 0; i < taille_art; i++)
    {
        if (art[i].docs1.code == code1)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The article : \nauthor name : %s \npublish date : %d/%d/%d"
               "\ntitle : %s \ncode : %d \nlocation : %s \nquantity : %d",
               art[pos].auteur, art[pos].date1.day, art[pos].date1.month, art[pos].date1.year,
               art[pos].docs1.title, art[pos].docs1.code, art[pos].docs1.location, art[pos].docs1.nb);
    }
    else
    {
        printf("Sorry we could not find an article !");
    }
    int n = choice();
    if (n == 1)
    {
        search_article();
    }
    else
    {
        menu();
    }
}
void search_article()
{
    system("cls");
    printf("SEARCH ARTICLES MENU");
    int test = 1;
    int select1;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to users menu) \n"
               "To search by author name enter 1 \n"
               "To search by publish date enter 2 \n"
               "To search by title enter 3 \n"
               "To search by location enter 4 \n"
               "To search by code enter 5 \n"
               "\nEnter choice: ");

        scanf("%d", &select1);
        if (select1 == 0)
        {
            menu();
        }
        else
        {
            if ((select1 == 1) or (select1 == 2) or (select1 == 3) or (select1 == 4) or (select1 == 5))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select1);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select1)
    {
    case 1:
        search_article_by_author();
        break;
    case 2:
        search_article_by_date();
        break;
    case 3:
        search_article_by_title();
        break;
    case 4:
        search_article_by_location();
        break;
    case 5:
        search_article_by_code();
        break;
    }
}

// search book
void search_book();
void search_book_by_author()
{
    system("cls");
    char auteur1[20];
    int test, pos;
    test = 0;
    printf("Enter the author name :");
    gets(auteur1);
    for (int i = 0; i < taille_liv; i++)
    {
        if (strcmp(liv[i].auteur, auteur1) == 0)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The book : \nauthor name : %s "
               "\neditor : %s \npublish date : %d/%d/%d \ntitle : %s \ncode : %d "
               "\nlocation : %s \nquantity : %d",
               liv[pos].auteur, liv[pos].editeur, liv[pos].date2.day,
               liv[pos].date2.month, liv[pos].date2.year, liv[pos].docs2.title, liv[pos].docs2.code, liv[pos].docs2.location,
               liv[pos].docs2.nb);
    }
    else
    {
        printf("Sorry we could not find an article !");
    }
    int n = choice();
    if (n == 1)
    {
        search_book();
    }
    else
    {
        menu();
    }
}
void search_book_by_editor()
{
    system("cls");
    char editeur1[20];
    int test, pos;
    test = 0;
    printf("Enter the editor name :");
    gets(editeur1);
    for (int i = 0; i < taille_liv; i++)
    {
        if (strcmp(liv[i].editeur, editeur1) == 0)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The book : \nauthor name : %s "
               "\neditor : %s \npublish date : %d/%d/%d \ntitle : %s \ncode : %d "
               "\nlocation : %s \nquantity : %d",
               liv[pos].auteur, liv[pos].editeur, liv[pos].date2.day,
               liv[pos].date2.month, liv[pos].date2.year, liv[pos].docs2.title, liv[pos].docs2.code, liv[pos].docs2.location,
               liv[pos].docs2.nb);
    }
    else
    {
        printf("Sorry we could not find an article !");
    }
    int n = choice();
    if (n == 1)
    {
        search_book();
    }
    else
    {
        menu();
    }
}
void search_book_by_title()
{
    system("cls");
    char title1[20];
    int test, pos;
    test = 0;
    printf("Enter the editor name :");
    gets(title1);
    for (int i = 0; i < taille_liv; i++)
    {
        if (strcmp(liv[i].docs2.title, title1) == 0)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The book : \nauthor name : %s "
               "\neditor : %s \npublish date : %d/%d/%d \ntitle : %s \ncode : %d "
               "\nlocation : %s \nquantity : %d",
               liv[pos].auteur, liv[pos].editeur, liv[pos].date2.day,
               liv[pos].date2.month, liv[pos].date2.year, liv[pos].docs2.title, liv[pos].docs2.code, liv[pos].docs2.location,
               liv[pos].docs2.nb);
    }
    else
    {
        printf("Sorry we could not find an article !");
    }
    int n = choice();
    if (n == 1)
    {
        search_book();
    }
    else
    {
        menu();
    }
}
void search_book_by_date()
{
    system("cls");
    int day1, month1, year1;
    int test, pos;
    test = 0;
    printf("Enter the day :");
    scanf("%d", &day1);
    printf("Enter the month :");
    scanf("%d", &month1);
    printf("Enter the year :");
    scanf("%d", &year1);
    for (int i = 0; i < taille_art; i++)
    {
        if ((liv[i].date2.day == day1) and (liv[i].date2.month == month1) and (liv[i].date2.year == year1))
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The book : \nauthor name : %s "
               "\neditor : %s \npublish date : %d/%d/%d \ntitle : %s \ncode : %d "
               "\nlocation : %s \nquantity : %d",
               liv[pos].auteur, liv[pos].editeur, liv[pos].date2.day,
               liv[pos].date2.month, liv[pos].date2.year, liv[pos].docs2.title, liv[pos].docs2.code, liv[pos].docs2.location,
               liv[pos].docs2.nb);
    }
    else
    {
        printf("Sorry we could not find an article !");
    }
    int n = choice();
    if (n == 1)
    {
        search_book();
    }
    else
    {
        menu();
    }
}
void search_book_by_location()
{
    system("cls");
    char loc1[20];
    int test, pos;
    test = 0;
    printf("Enter the location :");
    gets(loc1);
    for (int i = 0; i < taille_liv; i++)
    {
        if (strcmp(liv[i].docs2.location, loc1) == 0)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The book : \nauthor name : %s "
               "\neditor : %s \npublish date : %d/%d/%d \ntitle : %s \ncode : %d "
               "\nlocation : %s \nquantity : %d",
               liv[pos].auteur, liv[pos].editeur, liv[pos].date2.day,
               liv[pos].date2.month, liv[pos].date2.year, liv[pos].docs2.title, liv[pos].docs2.code, liv[pos].docs2.location,
               liv[pos].docs2.nb);
    }
    else
    {
        printf("Sorry we could not find an article !");
    }
    int n = choice();
    if (n == 1)
    {
        search_book();
    }
    else
    {
        menu();
    }
}
void search_book_by_code()
{
    system("cls");
    int code1, test, pos;
    test = 0;
    printf("Enter the code :");
    scanf("%d", &code1);
    for (int i = 0; i < taille_liv; i++)
    {
        if (liv[i].docs2.code == code1)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The book : \nauthor name : %s "
               "\neditor : %s \npublish date : %d/%d/%d \ntitle : %s \ncode : %d "
               "\nlocation : %s \nquantity : %d",
               liv[pos].auteur, liv[pos].editeur, liv[pos].date2.day,
               liv[pos].date2.month, liv[pos].date2.year, liv[pos].docs2.title, liv[pos].docs2.code, liv[pos].docs2.location,
               liv[pos].docs2.nb);
    }
    else
    {
        printf("Sorry we could not find an article !");
    }
    int n = choice();
    if (n == 1)
    {
        search_book();
    }
    else
    {
        menu();
    }
}
void search_book()
{
    system("cls");
    printf("SEARCH BOOKS MENU");
    int test = 1;
    int select1;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to users menu) \n"
               "To search by author name enter 1 \n"
               "To search by editor name enter 2 \n"
               "To search by publish date enter 3 \n"
               "To search by title enter 4 \n"
               "To search by location enter 5 \n"
               "To search by code enter 6 \n"
               "\nEnter choice: ");

        scanf("%d", &select1);
        if (select1 == 0)
        {
            menu();
        }
        else
        {
            if ((select1 == 1) or (select1 == 2) or (select1 == 3) or (select1 == 4) or (select1 == 5) or (select1 == 6))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select1);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select1)
    {
    case 1:
        search_book_by_author();
        break;
    case 2:
        search_book_by_editor();
    case 3:
        search_book_by_date();
        break;
    case 4:
        search_book_by_title();
        break;
    case 5:
        search_book_by_location();
        break;
    case 6:
        search_book_by_code();
        break;
    }
}

// search magazine
void search_magazine();
void search_magazine_by_freq()
{
    system("cls");
    int freq1, test, pos;
    test = 0;
    printf("Enter a frequency ;");
    scanf("%d", &freq1);
    for (int i = 0; i < taille_mag; i++)
    {
        if (mag[i].freq == freq1)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The magazine : \nfrequency : %d \ntitle : %s  \ncode : %d \nlocation : %s \nquantiy : %d", mag[pos].freq, mag[pos].docs3.title, mag[pos].docs3.code, mag[pos].docs3.location, mag[pos].docs3.nb);
    }
    else
    {
        printf("Sorry we could not find a magazine !");
    }
    int n = choice();
    if (n == 1)
    {
        search_magazine();
    }
    else
    {
        menu();
    }
}
void search_magazine_by_title()
{
    system("cls");
    char title1[20];
    int test, pos;
    test = 0;
    printf("Enter a title :");
    gets(title1);
    for (int i = 0; i < taille_mag; i++)
    {
        if (strcmp(mag[i].docs3.title, title1) == 0)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The magazine : \nfrequency : %d \ntitle : %s  \ncode : %d \nlocation : %s \nquantiy : %d", mag[pos].freq, mag[pos].docs3.title, mag[pos].docs3.code, mag[pos].docs3.location, mag[pos].docs3.nb);
    }
    else
    {
        printf("Sorry we could not find a magazine !");
    }
    int n = choice();
    if (n == 1)
    {
        search_magazine();
    }
    else
    {
        menu();
    }
}
void search_magazine_by_location()
{
    system("cls");
    char loc1[20];
    int test, pos;
    test = 0;
    printf("Enter a location ;");
    gets(loc1);
    for (int i = 0; i < taille_mag; i++)
    {
        if (strcmp(mag[i].docs3.location, loc1) == 0)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The magazine : \nfrequency : %d \ntitle : %s  \ncode : %d \nlocation : %s \nquantiy : %d", mag[pos].freq, mag[pos].docs3.title, mag[pos].docs3.code, mag[pos].docs3.location, mag[pos].docs3.nb);
    }
    else
    {
        printf("Sorry we could not find a magazine !");
    }
    int n = choice();
    if (n == 1)
    {
        search_magazine();
    }
    else
    {
        menu();
    }
}
void search_magazine_by_code()
{
    system("cls");
    int code1, test, pos;
    test = 0;
    printf("Enter a code ;");
    scanf("%d", &code1);
    for (int i = 0; i < taille_mag; i++)
    {
        if (mag[i].docs3.code == code1)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("The magazine : \nfrequency : %d \ntitle : %s  \ncode : %d \nlocation : %s \nquantiy : %d", mag[pos].freq, mag[pos].docs3.title, mag[pos].docs3.code, mag[pos].docs3.location, mag[pos].docs3.nb);
    }
    else
    {
        printf("Sorry we could not find a magazine !");
    }
    int n = choice();
    if (n == 1)
    {
        search_magazine();
    }
    else
    {
        menu();
    }
}
void search_magazine()
{
    system("cls");
    printf("SEARCH MAGAZINES MENU");
    int test = 1;
    int select1;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to users menu) \n"
               "To search by author name enter 1 \n"
               "To search by editor name enter 2 \n"
               "To search by publish date enter 3 \n"
               "To search by title enter 4 \n"
               "To search by location enter 5 \n"
               "To search by code enter 6 \n"
               "\nEnter choice: ");

        scanf("%d", &select1);
        if (select1 == 0)
        {
            menu();
        }
        else
        {
            if ((select1 == 1) or (select1 == 2) or (select1 == 3) or (select1 == 4) or (select1 == 5) or (select1 == 6))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select1);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select1)
    {
    case 1:
        search_magazine_by_freq();
        break;
    case 4:
        search_magazine_by_title();
        break;
    case 5:
        search_magazine_by_location();
        break;
    case 6:
        search_magazine_by_code();
        break;
    }
}

void sous_menu_search()
{
    system("cls");
    printf("SEARCH DOCUMENT MENU");
    int test = 1;
    int select;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to the main menu) \n"
               "To search an article enter 1 \n"
               "To search a book enter 2 \n"
               "To search a magazine enter 3 \n"
               "\nEnter choice: ");

        scanf("%d", &select);
        if (select == 0)
        {
            break;
        }
        else
        {
            if ((select == 1) or (select == 2) or (select == 3))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select)
    {
    case 1:
        search_article();
        break;
    case 2:
        search_book();
        break;
    case 3:
        search_magazine();
        break;
    }
}

void search_doc()
{
    system("cls");
    sous_menu_search();
}
/////////////
void menu2()
{
    system("cls");
    printf("This menu is to manage document");
    int test = 1;
    int select1;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to the main menu) \n"
               "To add a document enter 1 \n"
               "To delete a document enter 2 \n"
               "To update document information enter 3 \n"
               "To search for a document enter 4 \n"
               "\nEnter choice: ");

        scanf("%d", &select1);
        if (select1 == 0)
        {
            menu();
        }
        else
        {
            if ((select1 == 1) or (select1 == 2) or (select1 == 3) or (select1 == 4))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select1);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select1)
    {
    case 1:
        add_doc();
        break;
    case 2:
        delete_doc();
        break;
    case 3:
        update_doc();
        break;
    case 4:
        search_doc();
        break;
    }
}
//---------------manage user---------------

typedef struct
{
    char nom[20];
    char prenom[20];
    int id;
    char adresse[50];
    char type[20];
    int limit;
} user;

user T[10] = {{"jbeli", "fourat", 1, "Djerba", "etudiant", 2}, {"nacef", "Mohamed", 2, "bizerte", "enseignant", 4}, {"chr", "nouri", 3, "gabes", "visiteur", 1}};
int taille_user = 3;
int verif_type(char ch[])
{
    if ((strcmp(ch, "etudiant") == 0) or (strcmp(ch, "enseignant") == 0) or (strcmp(ch, "visiteur") == 0))
    {
        return 1;
    }
    return 0;
}

void remplir()
{

    getchar();
    printf("Nom       :");
    gets(T[taille_user].nom);

    printf("prenom       :");
    gets(T[taille_user].prenom);

    T[taille_user].id = taille_user + 1;

    printf("Adresse       :");
    gets(T[taille_user].adresse);

    printf("Type       :");
    gets(T[taille_user].type);
    while (verif_type(T[taille_user].type) != 1)
    {
        printf("Type       :");
        gets(T[taille_user].type);
    }

    if (strcmp(T[taille_user].type, "etudiant") == 0)
    {
        T[taille_user].limit = 2;
    }
    else if (strcmp(T[taille_user].type, "enseignant") == 0)
    {
        T[taille_user].limit = 4;
    }
    else
    {
        T[taille_user].limit = 1;
    }
}
// add user
void add_user()
{
    do
    {
        system("cls");
        remplir();
        taille_user++;
    } while (choice() == 1);
    menu();
}
// update user
void update_user();
void update_nom(int x)
{
    system("cls");
    char nom1[20];
    printf("enter the new name :");
    gets(nom1);
    for (int i = 0; i < taille_user; i++)
    {
        if (T[i].id == x)
        {
            strcpy(T[i].nom, nom1);
        }
    }
    int n = choice();
    if (n == 1)
    {
        update_user();
    }
    else
    {
        menu();
    }
}
void update_prenom(int x)
{
    system("cls");
    char prenom1[20];
    printf("enter the new prename :");
    gets(prenom1);
    for (int i = 0; i < taille_user; i++)
    {
        if (T[i].id == x)
        {
            strcpy(T[i].prenom, prenom1);
        }
    }
    int n = choice();
    if (n == 1)
    {
        update_user();
    }
    else
    {
        menu();
    }
}
void update_id(int x)
{
    system("cls");
    int newid;
    printf("enter the new id :");
    scanf("%d", &newid);
    for (int i = 0; i < taille_user; i++)
    {
        if (T[i].id == x)
        {
            T[i].id = newid;
        }
    }
    int n = choice();
    if (n == 1)
    {
        update_user();
    }
    else
    {
        menu();
    }
}
void update_adresse(int x)
{
    system("cls");
    char adresse1[50];
    printf("enter the new adresse :");
    gets(adresse1);
    for (int i = 0; i < taille_user; i++)
    {
        if (T[i].id == x)
        {
            strcpy(T[i].adresse, adresse1);
        }
    }
    int n = choice();
    if (n == 1)
    {
        update_user();
    }
    else
    {
        menu();
    }
}
void update_type(int x)
{
    system("cls");
    char type1[20];
    printf("enter the new type :");
    gets(type1);
    while (verif_type(type1) != 0)
    {
        printf("\nplease enter a valid type :");
        scanf("%s", &type1);
    }
    for (int i = 0; i < taille_user; i++)
    {
        if (T[i].id == x)
        {
            strcpy(T[i].type, type1);
        }
    }
    int n = choice();
    if (n == 1)
    {
        update_user();
    }
    else
    {
        menu();
    }
}
void update_user()
{
    system("cls");
    printf("UPFATE USER MENU");
    int id1, taille, choice;
    printf("\nWrite the id of the person you want to update his information  :");
    scanf("%d", &id1);
    printf("\nwhat do you want to change :\n"
           "if you want to change the name enter 1\n"
           "first name enter 2\n"
           "id enter 3\n"
           "adresse enter 4\n"
           "type enter 5\n"
           "\nEnter Choice :");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        update_nom(id1);
        break;
    case 2:
        update_prenom(id1);
        break;
    case 3:
        update_id(id1);
        break;
    case 4:
        update_adresse(id1);
        break;
    case 5:
        update_type(id1);
        break;
    }
    system("cls");
}
// search for a user
void search_user();
void search_by_nom()
{
    system("cls");
    char nom1[20];
    int test, pos;
    test = 0;
    printf("\nEnter the name to search :");
    scanf("%s", &nom1);
    for (int i = 0; i < taille_user; i++)
    {
        if (strcmp(nom1, T[i].nom) == 0)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("\nThe user %s %s exist in our database", T[pos].nom, T[pos].prenom);
    }
    else
    {
        printf("\nSorry ! The user you searching for does not exist in our database");
    }
    int n = choice();
    if (n == 1)
    {
        search_user();
    }
    else
    {
        menu();
    }
}
void search_by_prenom()
{
    system("cls");
    char prenom1[20];
    int test, pos;
    test = 0;
    printf("\nEnter the prenom to search :");
    scanf("%s", &prenom1);
    for (int i = 0; i < taille_user; i++)
    {
        if (strcmp(prenom1, T[i].prenom) == 0)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("\nThe user %s %s exist in our database", T[pos].nom, T[pos].prenom);
    }
    else
    {
        printf("\nSorry ! The user you searching for does not exist in our database");
    }
    int n = choice();
    if (n == 1)
    {
        search_user();
    }
    else
    {
        menu();
    }
}
void search_by_id()
{
    system("cls");
    int id1, test, pos;
    printf("\nEnter the id to search :");
    scanf("%d", &id1);
    test = 0;
    pos = 0;
    for (int i = 0; i < taille_user; i++)
    {
        if (id1 == T[i].id)
        {
            test = 1;
            pos = i;
            break;
        }
    }

    if (test == 1)
    {
        printf("\nThe user %s %s exist in our database", T[pos].nom, T[pos].prenom);
    }
    else
    {
        printf("\nSorry ! The user you searching for does not exist in our database");
    }
    int n = choice();
    if (n == 1)
    {
        search_user();
    }
    else
    {
        menu();
    }
}
void search_by_adresse()
{
    system("cls");
    char adresse1[50];
    int test, pos;
    test = 0;
    printf("\nEnter the adresse to search :");
    scanf("%s", &adresse1);
    for (int i = 0; i < taille_user; i++)
    {
        if (strcmp(adresse1, T[i].adresse) == 0)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("\nThe user %s %s exist in our database", T[pos].nom, T[pos].prenom);
    }
    else
    {
        printf("\nSorry ! The user you searching for does not exist in our database");
    }
    int n = choice();
    if (n == 1)
    {
        search_user();
    }
    else
    {
        menu();
    }
}
void search_by_type()
{
    system("cls");
    char type1[20];
    int test, pos;
    test = 0;
    printf("\nEnter the type to search :");
    scanf("%s", &type1);
    while (verif_type(type1) != 1)
    {
        printf("\nPlease Enter a valid type to search :");
        scanf("%s", &type1);
    }
    for (int i = 0; i < taille_user; i++)
    {
        if (strcmp(type1, T[i].type) == 0)
        {
            test = 1;
            pos = i;
            break;
        }
    }
    if (test == 1)
    {
        printf("\nThe user %s %s exist in our database", T[pos].nom, T[pos].prenom);
    }
    else
    {
        printf("\nSorry ! The user you searching for does not exist in our database");
    }
    int n = choice();
    if (n == 1)
    {
        search_user();
    }
    else
    {
        menu();
    }
}
void search_user()
{
    system("cls");
    printf("SEARCH USERS MENU");
    int test = 1;
    int select1;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to users menu) \n"
               "To search by name enter 1 \n"
               "To search by first name enter 2 \n"
               "To search by id enter 3 \n"
               "To search by adresse enter 4 \n"
               "To search by type enter 5 \n"
               "\nEnter choice: ");

        scanf("%d", &select1);
        if (select1 == 0)
        {
            menu();
        }
        else
        {
            if ((select1 == 1) or (select1 == 2) or (select1 == 3) or (select1 == 4) or (select1 == 5))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select1);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select1)
    {
    case 1:
        search_by_nom();
        break;
    case 2:
        search_by_prenom();
        break;
    case 3:
        search_by_id();
        break;
    case 4:
        search_by_adresse();
        break;
    case 5:
        search_by_type();
        break;
    }
}
// delete
void menu1();
int position(int x)
{
    int pos = -1;
    for (int i = 0; i < taille_user; i++)
    {
        if (T[i].id = x)
        {
            pos = i;
        }
    }
    return pos;
}
void delete_user()
{
    system("cls");
    int id1;
    printf("Enter the user id :");
    scanf("%d", &id1);
    for (int i = 0; i < taille_user; i++)
    {
        int pos = position(id1);
        if (pos == -1)
        {
            printf("This user does not exist in our database !");
        }
        else
        {
            for (int j = pos; j < taille_user; j++)
            {
                T[j] = T[j + 1];
            }
        }
    }
    taille_user--;
    int n = choice();
    if (n == 1)
    {
        menu1();
    }
    else
    {
        menu();
    }
}
void menu1()
{
    system("cls");
    printf("MANAGE USERS MENU");
    int test = 1;
    int select1;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to the main menu) \n"
               "To add a user enter 1 \n"
               "To delete a user enter 2 \n"
               "To update user information enter 3 \n"
               "To search for a user enter 4 \n"
               "\nEnter choice: ");

        scanf("%d", &select1);
        if (select1 == 0)
        {
            menu();
        }
        else
        {
            if ((select1 == 1) or (select1 == 2) or (select1 == 3) or (select1 == 4))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select1);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select1)
    {
    case 1:
        add_user();
        break;
    case 2:
        delete_user();
        break;
    case 3:
        update_user();
        break;
    case 4:
        search_user();
        break;
    }
}
// loan manage
time_t now = time(NULL);
struct tm *date_now = gmtime(&now);
struct tm *cur_time = localtime(&now);
char *st = asctime(cur_time);

typedef struct
{
    int id;
    int iddoc;
    char typedoc[10];
    int valid; // ce champ peut prendre deux valeurs : 1 si l'adherent à retourner le document et 0 dans le cas contraire
} back;
back TB[10];
int taille_b = 0;

typedef struct
{
    int id;
    int iddoc;
    char typedoc[10];
    date datedeb;
    date datefin;
} emprunt;
emprunt TE[10];
int taille_emp = 0;

// loan article
int exist_in_user(int x)
{
    int test = 0;
    for (int i = 0; i < taille_user; i++)
    {
        if (T[i].id == x)
        {
            test = 1;
            break;
        }
    }
    return test;
}
int loan_check(int x)
{
    int i,test;
    test = 1;
    while (i < taille_b)
    {
        if (TB[i].id == x)
        {
            if (TB[i].valid == 0)
            {
                test = 0;break;
            }
        }
        i++;
    }
    return test;
}
int visiteur(int id1)
{
    int test = 0;
    for (int i = 0; i < taille_art; i++)
    {
        if (T[i].id == id1)
        {
            if (strcmp(T[i].type, "visiteur") == 0)
            {
                test = 1;
                break;
            }
        }
    }
    if (test == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int etudiant(int id1)
{
    int test = 0;
    for (int i = 0; i < taille_art; i++)
    {
        if (T[i].id == id1)
        {
            if (strcmp(T[i].type, "etudiant") == 0)
            {
                test = 1;
                break;
            }
        }
    }
    if (test == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int limit(int id1)
{
    int test = 0;
    for (int i = 0; i < taille_user; i++)
    {
        if (T[i].limit > 0)
        {
            test = 1;
            break;
        }
    }
    return test;
}
void loan_article()
{
    system("cls");
    int id1, code1;
    printf("Enter your id :");
    scanf("%d", &id1);
    printf("\nEnter article code :");
    scanf("%d", &code1);
    if ((loan_check(id1) == 0))
    {
        printf("Sorry ! you have already a document on loan !");
    }
    while ((limit(id1) == 1) && (exist_in_user(id1) == 1))
    {
        TE[taille_emp].id = id1;
        TE[taille_emp].iddoc = code1;
        // date systeme
        TE[taille_emp].datedeb.day = date_now->tm_mday;
        TE[taille_emp].datedeb.month = date_now->tm_mon;
        TE[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        if (etudiant(id1) == 1)
        {
            TE[taille_emp].datefin.day = (date_now->tm_mday) + 14;
            TE[taille_emp].datefin.month = date_now->tm_mon;
            TE[taille_emp].datefin.year = (date_now->tm_year) + 1900;
        }
        else if (visiteur(id1) == 1)
        {
            TE[taille_emp].datedeb.day = date_now->tm_mday + 7;
            TE[taille_emp].datedeb.month = date_now->tm_mon;
            TE[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        }
        else
        {
            TE[taille_emp].datedeb.day = (date_now->tm_mday) + 21;
            TE[taille_emp].datedeb.month = date_now->tm_mon;
            TE[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        }
        strcpy(TE[taille_emp].typedoc, "article");
    }
    Sleep(1000);
    printf("\ntask done with success !");
    Sleep(1000);
    printf("\n in process ...");
    Sleep(1000);
    menu();
}

// loan book
void loan_book()
{
    system("cls");
    int id1, code1;
    printf("Enter your id :");
    scanf("%d", &id1);
    printf("\nEnter book code :");
    scanf("%d", &code1);
    if ((loan_check(id1) == 0))
    {
        printf("Sorry ! you have already a document on loan !");
    }
    while ((limit(id1) == 1) && (exist_in_user(id1) == 1))
    {
        TE[taille_emp].id = id1;
        TE[taille_emp].iddoc = code1;

        TE[taille_emp].datedeb.day = date_now->tm_mday;
        TE[taille_emp].datedeb.month = date_now->tm_mon;
        TE[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        if (etudiant(id1) == 1)
        {
            TE[taille_emp].datefin.day = (date_now->tm_mday) + 14;
            TE[taille_emp].datefin.month = date_now->tm_mon;
            TE[taille_emp].datefin.year = (date_now->tm_year) + 1900;
        }
        else if (visiteur(id1) == 1)
        {
            TE[taille_emp].datedeb.day = date_now->tm_mday + 7;
            TE[taille_emp].datedeb.month = date_now->tm_mon;
            TE[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        }
        else
        {
            TE[taille_emp].datedeb.day = (date_now->tm_mday) + 21;
            TE[taille_emp].datedeb.month = date_now->tm_mon;
            TE[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        }
        strcpy(TE[taille_emp].typedoc,"book");
    }
    Sleep(1000);
    printf("\ntask done with success !");
    Sleep(1000);
    printf("\n in process ...");
    Sleep(1000);
    menu();
}
// loan magazine
void loan_magazine()
{
    system("cls");
    int id1, code1;
    printf("Enter your id :");
    scanf("%d", &id1);
    printf("\nEnter magazine code :");
    scanf("%d", &code1);
    if ((loan_check(id1) == 0))
    {
        printf("Sorry ! you have already a document on loan !");
    }
    while ((limit(id1) == 1) && (exist_in_user(id1) == 1))
    {
        TE[taille_emp].id = id1;
        TE[taille_emp].iddoc = code1;

        TE[taille_emp].datedeb.day = date_now->tm_mday;
        TE[taille_emp].datedeb.month = date_now->tm_mon;
        TE[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        if (etudiant(id1) == 1)
        {
            TE[taille_emp].datefin.day = (date_now->tm_mday) + 14;
            TE[taille_emp].datefin.month = date_now->tm_mon;
            TE[taille_emp].datefin.year = (date_now->tm_year) + 1900;
        }
        else if (visiteur(id1) == 1)
        {
            TE[taille_emp].datedeb.day = date_now->tm_mday + 7;
            TE[taille_emp].datedeb.month = date_now->tm_mon;
            TE[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        }
        else
        {
            TE[taille_emp].datedeb.day = (date_now->tm_mday) + 21;
            TE[taille_emp].datedeb.month = date_now->tm_mon;
            TE[taille_emp].datedeb.year = (date_now->tm_year) + 1900;
        }
        strcpy(TE[taille_emp].typedoc, "magazine");
    }
    Sleep(1000);
    printf("\ntask done with success !");
    Sleep(1000);
    printf("\n in process ...");
    Sleep(1000);
    menu();
}

void menu4()
{
    system("cls");
    printf("LOAN DOCUMENT MENU");
    int test = 1;
    int select1;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to the main menu) \n"
               "To loan an article enter 1 \n"
               "To loan a book enter 2 \n"
               "To loan a magazine enter 3 \n"
               "\nEnter choice: ");

        scanf("%d", &select1);
        if (select1 == 0)
        {
            menu();
        }
        else
        {
            if ((select1 == 1) or (select1 == 2) or (select1 == 3))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select1);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select1)
    {
    case 1:
        loan_article();
    case 2:
        loan_book();
        break;
    case 3:
        loan_magazine();
        break;
    }
}
// print all documents
void print_articles()
{
    for (int i = 0; i < taille_art; i++)
    {
        printf("\n------------");
        printf("\nArticle n%d", i + 1);
        printf("\nauthor name : %s", art[i].auteur);
        printf("\npublish date : %d/%d/%d", art[i].date1.day, art[i].date1.month, art[i].date1.year);
        printf("\ntitle : %s", art[i].docs1.title);
        printf("\nlocation : %s", art[i].docs1.location);
        printf("\ncode : %d", art[i].docs1.code);
        printf("\nquantity : %d\n", art[i].docs1.nb);
    }
}
void print_books()
{
    for (int j = 0; j < taille_liv; j++)
    {
        printf("\n------------");
        printf("\nBook n%d", j + 1);
        printf("\nauthor name : %s", liv[j].auteur);
        printf("\neditor name : %s", liv[j].editeur);
        printf("\npublish date : %d/%d/%d", liv[j].date2.day, liv[j].date2.month, liv[j].date2.year);
        printf("\ntitle : %s", liv[j].docs2.title);
        printf("\nlocation : %s", liv[j].docs2.location);
        printf("\ncode : %d", liv[j].docs2.code);
        printf("\nquantity : %d\n", liv[j].docs2.nb);
    }
}
void print_magazines()
{
    for (int k = 0; k < taille_mag; k++)
    {
        printf("\n------------");
        printf("\nMagazine n%d", k + 1);
        printf("\nfrequency : %d", mag[k].freq);
        printf("\ntitle : %s", mag[k].docs3.title);
        printf("\nlocation : %s", mag[k].docs3.location);
        printf("\ncode : %d", mag[k].docs3.code);
        printf("\nquantity : %d\n", mag[k].docs3.nb);
    }
}
void print_docs()
{
    system("cls");
    printf("\n****ARTICLES****\n");
    print_articles();
    printf("\n****BOOKS****\n");
    print_books();
    printf("\n****MAGAZINES****\n");
    print_magazines();
    int choice;
    printf("\nTo return to the main menu type 0:");
    scanf("%d", &choice);
    if (choice == 0)
    {
        menu();
    }
}

// print all users
void print_users()
{
    system("cls");
    for (int i = 0; i < taille_user; i++)
    {
        printf("\n------------");
        printf("\nUser n%d", i + 1);
        printf("\nname : %s", T[i].nom);
        printf("\nfirst name : %s", T[i].prenom);
        printf("\nid : %d", T[i].id);
        printf("\nadresse : %s", T[i].adresse);
        printf("\ntype : %s", T[i].type);
    }
    int choice;
    printf("\nTo return to the main menu type 0:");
    scanf("%d", &choice);
    if (choice == 0)
    {
        menu();
    }
}
// return documents

int check_validity(int id1)
{
    int test = 0;
    for (int i = 0; i < taille_emp; i++)
    {
        if (TE[i].id == id1)
        {
            test = 1;
            break;
        }
    }
    return test;
}
// return article
void return_article()
{
    system("cls");
    int id1, code1;
    printf("\nEnter your id :");
    scanf("%d", &id1);
    printf("Enter article code :");
    scanf("%d", &code1);
    if (check_validity(id1) == 0)
    {
        TB[taille_b].id = id1;
        TB[taille_b].iddoc = code1;
        TB[taille_b].valid = 1;
        strcpy(TB[taille_b].typedoc,"article");
        taille_b++;
        Sleep(1000);
        printf("task done with success !");
        Sleep(1000);
        printf("\n in process ...");
        Sleep(1000);
        menu();
    }
    else
    {
        printf("Could not find this id ! Please enter a valid id");
        return_article();
    }
}
// return book
void return_book()
{
    system("cls");
    int id1, code1;
    printf("\nEnter your id :");
    scanf("%d", &id1);
    printf("Enter book code :");
    scanf("%d", &code1);
    if (check_validity(id1) == 1)
    {
        TB[taille_b].id = id1;
        TB[taille_b].iddoc = code1;
        TB[taille_b].valid = 1;
        strcpy(TB[taille_b].typedoc, "book");
        taille_b++;
        Sleep(1000);
        printf("task done with success !");
        Sleep(1000);
        printf("\n in process ...");
        Sleep(1000);
        menu();
    }
    else
    {
        printf("Could not find this id ! Please enter a valid id");
        return_article();
    }
}
// return magazine
void return_magazine()
{
    system("cls");
    int id1, code1;
    printf("\nEnter your id :");
    scanf("%d", &id1);
    printf("Enter magazine code :");
    scanf("%d", &code1);
    if (check_validity(id1) == 1)
    {
        TB[taille_b].id = id1;
        TB[taille_b].iddoc = code1;
        TB[taille_b].valid = 1;
        strcpy(TB[taille_b].typedoc, "magazine");
        taille_b++;
        Sleep(1000);
        printf("task done with success !");
        Sleep(1000);
        printf("\n in process ...");
        Sleep(1000);
        menu();
    }
    else
    {
        printf("Could not find this id ! Please enter a valid id");
        return_article();
    }
}
void menu3()
{
    system("cls");
    printf("RETURN DOCUMENT MENU");
    int test = 1;
    int select1;
    do
    {
        printf("\nPlease select from the following menu (Type 0 to return to the main menu) \n"
               "To return an article enter 1 \n"
               "To return a book enter 2 \n"
               "To return a magazine enter 3 \n"
               "\nEnter choice: ");

        scanf("%d", &select1);
        if (select1 == 0)
        {
            menu();
        }
        else
        {
            if ((select1 == 1) or (select1 == 2) or (select1 == 3))
            {
                test = 0;
            }
            else
            {
                printf("\nValue: %d did not match any menu choice", select1);
                test = 1;
            }
        }
    } while (test == 1);
    switch (select1)
    {
    case 1:
        return_article();
        break;
    case 2:
        return_book();
        break;
    case 3:
        return_magazine();
        break;
    }
}
//----------------------------//
int main()
{
    menu();
}
