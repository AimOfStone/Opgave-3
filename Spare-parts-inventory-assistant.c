#include <stdio.h>
#include <string.h>


int main (void){
char *inventory[] = {"hydraulic_pump", "plc_module", "servo_motor"};
char request[50];
int length = sizeof(inventory) / sizeof(inventory[0]);
char input[100];
printf("Hej. Welcome to the spare parts inventory!");

//loop begin
 while (1) {
        printf("Which part do you need? ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; //remove newline

        if (strcmp(input, "Do you actually have any parts?") == 0 ||
            strcmp(input, "Is there anything in stock at all?") == 0) {

            printf("We have %d part(s)!\n", length);//Do you actually have any parts
            for (int i = 0; i < length; i++) { //is there anything in stock at all?
                printf("%s\n", inventory[i]); 
            }
            continue;
        }

        int found = 0;
        for (int i = 0; i < length; i++) {  //For loop
            if (strcmp(input, inventory[i]) == 0) {
                printf("I've got %s here for you 😊\n", inventory[i]);
                return 0; 
            }
        }
        printf("I am afraid we don't have any %s in the inventory 😔\n", input);
    }
}

/*

Hej. Welcome to the spare parts inventory!
Which part do you need? pLC module
I am afraid we don't have any pLC module in the inventory 😔
Which part do you need? screws
I am afraid we don't have any screws in the inventory 😔
Which part do you need? Do you actualy have any parts?
We have 3 part(s)!
hydraulic pump
PLC module
servo motor
Which part do you need? quit
I am afraid we don't have any quit in the inventory 😔
Which part do you need? servo motor
I've got servo motor here for you 😊

*/