#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Espresso
#define espresso_coffeebeans 8
#define espresso_water 30
#define espresso_milk 0
#define espresso_chocosyrup 0
float espresso_price = 3.5;

//Cappuccino
#define cappuccino_coffeebeans 8
#define cappuccino_water 30
#define cappuccino_milk 70
#define cappuccino_chocosyrup 0
float cappuccino_price = 4.5;

//Mocha
#define mocha_coffeebeans 8
#define mocha_water 39
#define mocha_milk 160
#define mocha_chocosyrup 30
float mocha_price = 5.5;

//Other Constants
#define admin_password "pass"
float total_amount = 0;


//Threshhold Values
int threshhold_coffee = 200; 
int threshhold_water = 200;
int threshhold_milk = 200;
int threshhold_chocosyrup = 200;

//Functions
int coffeeOrder();
int userPayment(float to_be_paid);
int adminMode();
int replenishMode();
int changePrice();


//Main Function
int main(){

    int user_preference;
    while (1){
        printf("\n\n*MENU*\n");
        printf("1. Coffee Order\n");
        printf("2. Admin Mode\n");
        printf("3. Exit\n");
        printf("Please choose your preference: ");
        scanf("%d", &user_preference);

        switch (user_preference) {
            case 1:
            coffeeOrder();
            break;
            case 2:
            adminMode();
            break;
            case 3:
            return 0;
            default:
            printf("Invalid choice\n");
            break;
        }
        }
    return 0;
}



//Coffee Order Main Function
int coffeeOrder(){
    int user_coffee;
    printf("\n\n*COFFEE MENU*\n");
    printf("1. Espresso\t\t%.2f\n",espresso_price);
    printf("2. Cappuccino\t\t%.2f\n",cappuccino_price);
    printf("3. Mocha\t\t%.2f\n",mocha_price);
    printf("0. Exit\n");
    printf("Select Your Order: ");
    scanf("%d", &user_coffee);

    switch (user_coffee) {
        case 1:
            printf("You have ordered Espresso\n");
            printf("The price is %.1f dhs\n",espresso_price);
            printf("Checking for Availability...\n");
            if (espresso_coffeebeans<=threshhold_coffee && espresso_water<=threshhold_water && espresso_milk<=threshhold_milk && espresso_chocosyrup<=threshhold_chocosyrup){
                printf("Making coffee\n");
                printf("Completed.\n");
                userPayment(espresso_price);

                //Changing Available Values
                threshhold_coffee -= espresso_coffeebeans;
                threshhold_milk -= espresso_milk;
                threshhold_chocosyrup -= espresso_chocosyrup;
                threshhold_water -= espresso_water;
            } else {
                printf("Unavailable due to temporarily insufficient ingredients");
            }
            break;
        case 2:
            printf("You have ordered Cappuccino\n");
            printf("The price is %.1f dhs\n",cappuccino_price);
            printf("Checking for Availability...\n");
            if (cappuccino_coffeebeans<=threshhold_coffee && cappuccino_water<=threshhold_water && cappuccino_milk<=threshhold_milk && cappuccino_chocosyrup<=threshhold_chocosyrup){
                printf("Making coffee\n");
                printf("Completed.\n");
                userPayment(cappuccino_price);

                //Changing Available Values
                threshhold_coffee -= cappuccino_coffeebeans;
                threshhold_milk -= cappuccino_milk;
                threshhold_chocosyrup -= cappuccino_chocosyrup;
                threshhold_water -= cappuccino_water;
            } else {
                printf("Unavailable due to temporarily insufficient ingredients");
            }
            break;
        case 3:
            printf("You have ordered Mocha\n");
            printf("The price is %.1f dhs\n",mocha_price);
            printf("Checking for Availability...\n");
            if (mocha_coffeebeans<=threshhold_coffee && mocha_water<=threshhold_water && mocha_milk<=threshhold_milk && mocha_chocosyrup<=threshhold_chocosyrup){
                printf("Making coffee\n");
                printf("Completed.\n");
                userPayment(mocha_price);

                //Changing Available Values
                threshhold_coffee -= mocha_coffeebeans;
                threshhold_milk -= mocha_milk;
                threshhold_chocosyrup -= mocha_chocosyrup;
                threshhold_water -= mocha_water;
            } else {
                printf("Unavailable due to temporarily insufficient ingredients");
            }
            break;
        default:
            printf("Invalid Choice\n");
            break;
    }
}

//Payment Function
int userPayment(float to_be_paid){
    float pay = 0;
    float amt;
    while (pay<to_be_paid){
        printf("Enter 1 to insert 1 dhs and 0.5 to insert 0.5 dhs: ");
        scanf("%f",&amt);
        if (amt==1){
            pay=pay+1;
        }
        else if (amt==0.5){
            pay=pay+0.5;
        }
        else{
            printf("Invalid coin\n");
        }
    }
    if (pay>to_be_paid){
        float change = pay - to_be_paid;
        printf("Your change is %.1f\n",change);
    }
    total_amount+=to_be_paid;
    printf("Thank you! Have a nice day!\n\n");
    return 0;
}

//Admin Mode Function
int adminMode(){
    char user_pass[50];
    int mode;
    printf("Enter admin password: ");
    scanf("%s",user_pass);

    if (strcmp(user_pass, admin_password) == 0){
        printf("Successful Login\n");

        while (1){
            printf("\n\n*ADMIN MODE CHOICES*\n");
            printf("1. Dislay Quantity and Total Sale\n");
            printf("2. Replenish Ingredients\n");
            printf("3. Change Coffee Price\n");
            printf("4. Exit\n");
            printf("Enter choice: ");
            scanf("%d",&mode);

            switch (mode) {
                case 1:
                    printf("Displaying Quantity and Total Sale\n\n");
                    printf("Current Quantity of Coffee is %d g\n",threshhold_coffee);
                    printf("Current Quantity of Water is %d ml\n",threshhold_water);
                    printf("Current Quantity of Milk is %d ml\n",threshhold_milk);
                    printf("Current Quantity of Chocolate Syrup is %d ml\n",threshhold_chocosyrup);
                    printf("The total sales are %.2f dhs",total_amount);
                    break;
                case 2:
                    replenishMode();
                    break;
                case 3:
                    changePrice();
                    break;
                case 4:
                    printf("Exiting...\n");
                    return 0;
                default:
                    printf("Invalid input\n");
            
            }
        }
    } else {
        printf("Invalid Password");
    }

    return 0;
}

//Replenish Mode Function
int replenishMode(){
    int replenish_choice;
    int new_quantity;
    printf("Replenish Ingredients\n\n");
    printf("1. Coffee Beans\n");
    printf("2. Water\n");
    printf("3. Milk\n");
    printf("4. Chocolate Syrup\n");
    printf("0. Exit\n");
    printf("Select the item to replenish: ");
    scanf("%d",&replenish_choice);

    srand(time(NULL));

    new_quantity = 100 + rand() % 400;

    switch (replenish_choice) {
        case 1:
            printf("Replenishing Coffee Beans...\n");
            printf("Adding %d grams of Coffee Beans\n",new_quantity);
            threshhold_coffee+=new_quantity;
            printf("The new quantity of Coffee Beans is %d grams",threshhold_coffee);
            break;

        case 2:
            printf("Replenishing Water...\n");
            printf("Adding %d grams of Water\n",new_quantity);
            threshhold_water+=new_quantity;
            printf("The new quantity of Water is %d litres",threshhold_water);
            break;

        case 3:
            printf("Replenishing Milk...\n");
            printf("Adding %d grams of Milk\n",new_quantity);
            threshhold_milk+=new_quantity;
            printf("The new quantity of Milk is %d litres",threshhold_milk);
            break;

        case 4:
            printf("Replenishing Chocolate Syrup...\n");
            printf("Adding %d grams of Chocolate Syrup\n",new_quantity);
            threshhold_chocosyrup+=new_quantity;
            printf("The new quantity of Chocolate Syrup is %d litres",threshhold_chocosyrup);
            break;
        default:
            printf("Exiting...");
            break;
    }

    return 0;
}

//Change Price Function
int changePrice(){
    int change_price_item;
    float change_price_value;
    printf("Change Coffee Price\n");
    printf("Enter 1 to change Espresso price\n");
    printf("Enter 2 to change Cappuccino price\n");
    printf("Enter 3 to change Mocha price\n");
    printf("Enter 0 to exit\n");
    printf("Enter your choice: ");
    scanf("%d",&change_price_item);

    switch (change_price_item) {
        case 1:
            printf("Changing Espresso Amount\n");
            printf("Current value of item: %.2f\n",espresso_price);
            printf("Changed value of item: ");
            scanf("%f",&change_price_value);
            espresso_price=change_price_value;
            break;
        case 2:
            printf("Changing Cappuccino Amount\n");
            printf("Current value of item: %.2f\n",cappuccino_price);
            printf("Changed value of item: ");
            scanf("%f",&change_price_value);
            cappuccino_price=change_price_value;
            break;
        case 3:
            printf("Changing Mocha Amount\n");
            printf("Current value of item: %.2f\n",mocha_price);
            printf("Changed value of item: ");
            scanf("%f",&change_price_value);
            mocha_price=change_price_value;
            break;
        case 0:
            printf("Exiting...");
            break;
        default:
            printf("Invalid Input");
            break;
    }
    return 0;
}

