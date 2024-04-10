#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Data structures

#define Correct_Password "123456"

typedef enum { E10_87, E10_90, Diesel } FuelType;

typedef struct {
  FuelType FuelType;
  float cost; // Cost per gallon
} Tank;

typedef struct {
  FuelType FuelType;
  float fuelAmt;
  char lubeReq;
  char payType;
} CoD;

typedef struct {
  union {
    int id;
    char businessName[50];
  };
  int licenseNo;
  char fuelAmt;
  char lubeReq;
  char payType;
} Charge;

// Function prototypes

void mainMenu();
void serveCustomer();
void generateReceipt();
void blankCharge();
void addCharge();
void existingCharge();
bool enterPassword(); // Returns true if password is valid
void updateCharge();
void deleteCharge();
void chargeSearch();
void chargePayment();
void refuelTank();
void generateReport();

int main() {
  enterPassword();
  return 0;
}

bool enterPassword() {
  char password[100] = {0};

  printf("Authorization Required\n");
  printf("Enter Password:");

  int i = 0;
  char c;

  // User enters the password
  do {
    c = getch(); // Record each charcter
    if (c == 13)
      break;
    sprintf(password, "%s%c", password, c);
    printf("*"); // Print a mask instead of the character
  } while (c != EOF);
  printf("\n");

  if (strcmp(password, Correct_Password) == 0) {
    printf("Access Granted\n");
    return true;
  } else {
    printf("Invalid Password Entered\n");
    return false;
  }
}

void mainMenu() {
    // Declare variables for menu use
    int choice;
   

    // Main menu loop
    do {
        // Display menu options
        printf("\nMain Menu\n");
        printf("1. Serve Customer\n");
        printf("2. Add Charge Customer\n");
        printf("3. Update Charge Customer\n");
        printf("4. Delete Charge Customer\n");
        printf("5. Make Payment to Charge Account\n");
        printf("6. Refuel Tank\n");
        printf("7. Generate Report\n");
        printf("8. Search for existing Charge Customer \n");

        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Execute corresponding function based on user choice
        switch (choice) {
            case 1:
                serveCustomer();
                break;
            case 2:
                addCharge();
                break;
            case 3:
                updateCharge();
                break;
            case 4:
                deleteCharge();
                break;
            case 5:
                chargePayment();
                break;
            case 6:
                refuelTank();
                break;
            case 7:
                generateReport();
                break;
            case 8:
                chargeSearch();
                break;
            case 9:
                exit();
            
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}