#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int main() {

    int pin = 1234;
    int pin2, pin3, newpin;

    int i = 0;
    int choice;
    int mablagh;

    int balance = 0;
    int hesabSakhte = 0;

    char name[20];
    char family[20];

    int a[10] = {0};
    int j = 0;

    while (i < 3) {
        printf("Enter PIN: ");
        scanf("%d", &pin2);

        if (pin == pin2) {
            break;
        } else {
            i++;
            printf("Error\n");
        }
    }

    if (i == 3) {
        return 0;
    }

    while (1) {

        printf("\n1.Balance/Create\n2.Deposit\n3.Withdraw\n4.Change PIN\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {

            case 1: // check mojoodi ya sakhte hesab
                if (hesabSakhte == 0) {
                    printf("Name: ");
                    scanf("%s", name);

                    printf("Family: ");
                    scanf("%s", family);

                    printf("Initial balance: ");
                    scanf("%d", &balance);

                    hesabSakhte = 1;
                }

                printf("Balance: %d\n", balance);
                a[j] = balance;
                j = (j + 1) % 10;
                break;

            case 2: // variz vajh
                if (hesabSakhte == 0) break;

                printf("Deposit amount: ");
                scanf("%d", &mablagh);

                if (mablagh > 0) {
                    balance += mablagh;
                    printf("balance:%d\n",balance);
                    a[j] = mablagh;
                    j = (j + 1) % 10;
                }
                break;

            case 3: // bardasht vajh
                if (hesabSakhte == 0) break;

                printf("Withdraw amount: ");
                scanf("%d", &mablagh);

                if (mablagh > 0 && mablagh <= balance) {
                    balance -= mablagh;
                    printf("balance:%d\n",balance);
                    a[j] = -mablagh;
                    j = (j + 1) % 10;
                }
                break;

            case 4: // taghir pin
                printf("Current PIN: ");
                scanf("%d", &pin3);

                if (pin == pin3) {
                    printf("New PIN: ");
                    scanf("%d", &newpin);
                    pin = newpin;
                }
                break;

            case 5: // khorooj
                printf("finish");
                return 0;
        }
    }
	return 0;
}