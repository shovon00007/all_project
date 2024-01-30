#include<stdio.h>
#include<stdlib.h>

int again;
int total = 0;
int dinner_rate[23][2] = {
    {0, 270}, {1, 420}, {2, 360}, {3, 480}, {4, 520},
    {5, 260}, {6, 310}, {7, 180}, {8, 170}, {9, 230},
    {10, 220}, {11, 100}, {12, 140}, {13, 180}, {14, 200},
    {15, 50}, {16, 20}, {17, 80}, {18, 60}, {19, 60},
    {20, 60}, {21, 25}, {22, 25}
};

int purchased[][3] = {
    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0},
    {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}
};

char str[50];

void dinner(char dinnermenu[][100]);
void main_menu();
void display();
void dinner_menu();
void display_dinner_bill(char dinnermenu[][100]);
void repeatdinner(char dinnermenu[][100]);

int main()
{
    char dinnermenu[][100] = {"Basmati Kacchi", "Kacchi Kadhok",
                              "Basmati Kacchi + Borhani + Firni",
                              "Basmati Kacchi + Chicken Roast + Borhani + Jali Kebab",
                              "Basmati Kacchi + Beef Rezala + Borhani + Jali Kebab",
                              "Plain Polao + Chicken Roast + Borhani",
                              "Plain Polao + Beef Roast + Borhani",
                              "Mutton Chuijaal", "Beef Chuijaal",
                              "Mutton Chuijaal + Plain Polao",
                              "Beef Chuijaal + Plain Polao", "Plain Polao",
                              "Chicken Roast", "Beef Rezala", "Mutton Rezala",
                              "Jali Kebab", "Chatni", "Badam Shorbot", "Borhani", "Firni",
                              "Jorda", "Water(500mL)", "CocaCola(250mL)"};

    display();
    gets(str);
    dinner(dinnermenu);

    return 0;
}

void display()
{
    printf(" =============================================== \n");
    printf(" Welcome to Kacchi Dine, Chittagong. \n ");
    printf(" =============================================== \n\n\n");
    printf("Please Enter Your Name: ");
}

void display_dinner_bill(char dinnermenu[][100])
{
    int i;
    printf("\n+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf(" Kacchi Dine, Chittagong \n");
    printf("\t BILLING INFORMATION \n");
    printf("\n\t\t Name :");
    puts(str);
    printf("\n\n");
    printf("\t\t ITEMS\t\t\t\t\t\t\tPrice(in Tk.)\n\n");
    for (i = 0; i < 24; i++)
    {
        if (purchased[i][1] != 0)
        {
            printf("\t\t %s \t\t\t\t\t\t", dinnermenu[i]);
            printf("%d\n", purchased[i][1]);
        }
    }
    printf("\n\n\t\tTotal=Tk.%d\n\n", total);
    printf("\n\n+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\t\tThanks For Choosing Kacchi Dine\n");
    printf("\t\tStay With Us\n\n\n");
}

void dinner(char dinnermenu[][100])
{
    int choice = 0;
    int quantity = 0;
    int code, i;
    dinner_menu();
    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    if (code >= 0 && code <= 23)
    {
        printf("\nEnter the quantity::");
        scanf("%d", &quantity);
        purchased[code][1] = quantity * dinner_rate[code][1];
        total += purchased[code][1];
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        dinner(dinnermenu);
    }
    repeatdinner(dinnermenu);
}

void dinner_menu()
{
    printf("\n\n\t Welcome to Kacchi Dine, Chittagong. \n ");
    printf("\t =============================================== \n\n\n");
    printf("\t\t $ Kacchi Menu $ \n\n");
    printf("\t\t && Please select the food that you would like to purchase. &&\n\n");
    printf("\t [0] Basmati Kacchi - Tk 270.00\n");
    printf("\t [1] Kacchi Kadhok - Tk 420.00\n");
    printf("\t [2] Basmati Kacchi + Borhani + Firni - Tk 360.00\n");
    printf("\t [3] Basmati Kacchi + Chicken Roast + Borhani + Jali Kebab - Tk 480.00\n");
    printf("\t [4] Basmati Kacchi + Beef Rezala + Borhani + Jali Kebab - TK 520.00\n");
    printf("\n\t\t $ Polao Menu $ \n\n");
    printf("\t [5] Plain Polao + Chicken Roast + Borhani - Tk 260.00\n");
    printf("\t [6] Plain Polao + Beef Roast + Borhani - Tk 310.00\n");
    printf("\n\t\t $ Chuijaal $ \n\n");
    printf("\t [7] Mutton Chuijaal - Tk 180.00\n");
    printf("\t [8] Beef Chuijaal - Tk 170.00\n");
    printf("\t [9] Mutton Chuijaal + Plain Polao - Tk 230.00\n");
    printf("\t [10] Beef Chuijaal + Plain Polao - Tk 220.00\n");
    printf("\n\t\t $ Others Item $ \n\n");
    printf("\t [11] Plain Polao - Tk 100.00\n");
    printf("\t [12] Chicken Roast - Tk 140.00\n");
    printf("\t [13] Beef Rezala - Tk 180.00\n");
    printf("\t [14] Mutton Rezala - Tk 200.00\n");
    printf("\t [15] Jali Kebab - Tk 50.00\n");
    printf("\t [16] Chatni - Tk 20.00\n");
    printf("\n\t\t $ Sweets and Drinks $ \n\n");
    printf("\t [17] Badam Shorbot - Tk 80.00\n");
    printf("\t [18] Borhani - Tk 60.00\n");
    printf("\t [19] Firni - Tk 60.00\n");
    printf("\t [20] Jorda - Tk 60.00\n");
    printf("\t [21] Water(500mL) - Tk 25.00\n");
    printf("\t [22] CocaCola(250mL) - Tk 25.00\n");
}

void repeatdinner(char dinnermenu[][100])
{
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
    scanf("%d", &again);
    if (again == 1)
    {
        dinner(dinnermenu);
    }
    else if (again == 2)
    {
        display_dinner_bill(dinnermenu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatdinner(dinnermenu);
    }
}
