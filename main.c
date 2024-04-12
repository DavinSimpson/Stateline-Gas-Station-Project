#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define E87CAP 75708.23
#define E90CAP 113562.35
#define DIESELCAP 94635.29

#define E87PRICE 184.90
#define E90PRICE 193.60
#define DIESELPRICE 182.30

#define L5W30PRICE 2900
#define L5W40PRICE 3500
#define L15W40PRICE 3600
#define LSAR40PRICE 2100

typedef enum { E10_87 = 1, E10_90, DIESEL } FuelType;

typedef enum { L5W30 = 1, L5W40, L15W40, LSAE40 } LubeType;
// Data structures

#define Correct_Password "123456"

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

/*typedef struct {
  union {
    int id;
    char businessName[50];
  };
  int licenseNo;
  char fuelAmt;
  char lubeReq;
  char payType;
} Charge;*/

typedef struct {
  int idNo;
  char name[40];
  int repNum;
  char licenseNo[6];
  FuelType fuel;
  float fuelAmt;
  char lubeRequest;
  float depositAmt;
} Charge;

Charge customers[50];

// Function prototypes
void mainMenu();
void serveCustomer();
void generateReceipt();
void codServe();
void chargeServe();
void addCharge();
void blankCharge();
void existingCharge();
void deleteCharge();
int randomInteger(int, int);
char randomCharacter(int);
void paytoCharge();
void updateCharge();
void refuelTank();
void chargeSearch();
void chargePayment();
void generateReport();
void exitProgram();
bool enterPassword(); // Returns true if password is valid

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
      return;
      break;

    default:
      printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 9);

  return;
}
void serveCustomer() {}
void generateReceipt() {}
void codServe() {}
void chargeServe() {}
void addCharge() {}
void blankCharge() {}
void existingCharge() {}
void deleteCharge() {}

int randomInteger(int upper, int lower) {
  int randomNum;

  srand(time(0));
  randomNum = rand() % ((upper - lower + 1) + lower);

  return randomNum;
}

char randomCharacter(int index) {
  char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  return charset[index];
}
void paytoCharge() {}
void updateCharge() {}
void refuelTank() {}
void chargeSearch() {}
void chargePayment() {}
void generateReport() {}
void exitProgram() {}
