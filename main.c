#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
double stockPrice = 100.0;
double balance = 1000.0;
int stocksOwned = 0;
int authenticated = 0;

// User authentication function
int authenticateUser() {
    char username[20];
    char password[20];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if the username and password match
    if (strcmp(username, "user") == 0 && strcmp(password, "password") == 0) {
        printf("Authentication successful!\n");
        return 1; // Authenticated
    } else {
        printf("Authentication failed. Please try again.\n");
        return 0; // Not authenticated
    }
}

// Simulate a price change
void simulatePriceChange() {
    double change = (rand() % 21 - 10) / 10.0; // Random change between -1.0 and 1.0
    stockPrice += change;
    if (stockPrice < 0.0) {
        stockPrice = 0.0;
    }
}

// Display portfolio and options
void displayMenu() {
    printf("Stock Price: %.2lf\n", stockPrice);
    printf("Balance: $%.2lf\n", balance);
    printf("Stocks Owned: %d\n", stocksOwned);
    printf("1. Buy Stocks\n");
    printf("2. Sell Stocks\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
}

// Main game loop
int main() {
    srand(time(NULL));

    // User authentication loop
    while (!authenticated) {
        authenticated = authenticateUser();
    }
 while (1) {
        simulatePriceChange();
        displayMenu();

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the quantity of stocks to buy: ");
                int quantity;
                scanf("%d", &quantity);
                if (stockPrice * quantity > balance) {
                    printf("Not enough balance.\n");
                } else {
                    stocksOwned += quantity;
                    balance -= stockPrice * quantity;
                }
                break;

            case 2:
                printf("Enter the quantity of stocks to sell: ");
                scanf("%d", &quantity);
                if (quantity > stocksOwned) {
                    printf("Not enough stocks.\n");
                } else {
                    stocksOwned -= quantity;
                    balance += stockPrice * quantity;
                }
                break;

            case 3:
                printf("Thank you for playing!\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}
