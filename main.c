/*
Author Names:
Ryan Cole - 2106111
Wolde Kristos - 2304844
Sheriann Sewell - 2210110
Davin Simpson - 2301564
Matthew Webster 2305616

Tutor Name: Michelle March

Occurrence: UN2

*/
#include <conio.h>
#include <ctype.h>
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

// Command line options for clearing screen: Windows/Mac
#define clear system("cls || clear")
#define pause system("pause || sleep 5");

typedef struct {
  FuelType fuelType;
  float cost; // Cost per gallon
} Tank;

typedef struct {
  FuelType fuelType;
  float fuelAmt;
  char lubeReq;
  enum { Cash = 1, Card = 2 } payType;
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
void welcomeScreen();
void serveCustomer();
void generateReceipt();
void codServe();
void chargeServe();
void printReceipt();
void addCharge();
Charge blankCharge();
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
char *getLicensePlateInfo();

int main() {
  welcomeScreen();
  clear;
  mainMenu();
  return 0;
}

void welcomeScreen() {
  printf("Welcome to Stateline Gas Station Program\n"
         "This program was created by:\n"
         "\tRyan Cole (2106111)\n"
         "\tWolde Kristos (2304844)\n"
         "\tSheriann Sewell (2210110)\n"
         "\tDavin Simpson (2301564) \n"
         "\tMatthew Webster - 2305616\n"
         "\nOcc : UN2\n"
         "Tutor: Michelle March\n"
         "\nAdmin Password is:123456\n");
  pause;
  clear;
}

bool enterPassword() {
  char password[100] = {0};

  clear;

  printf("Authorization Required\n");
  printf("Enter Password:");

  int i = 0;
  char c;

  // User enters the password
  do {
    c = getch(); // Record each charcter
    if (c == 13 || c == 3)
      break;

    if (c == 8) { // Allow backspace
      if (strlen(password) == 0) {
        continue;
      }
      printf("\b \b");
      password[strlen(password) - 1] = '\0';
      continue;
    }

    sprintf(password, "%s%c", password, c);
    printf("*"); // Print a mask instead of the character
  } while (c != EOF);
  printf("\n");

  clear;

  if (strcmp(password, Correct_Password) == 0) {
    printf("Access Granted\n");
    return true;
  } else {
    printf("Invalid Password Entered\n");
    return false;
  }
  clear;
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
void serveCustomer() {
  Charge *charge;
  CoD *cod;

  // Example
  CoD cust;
  cod = &cust;

  Charge cst;
  charge = &cst;

  bool valid;

  int fuelType;

  enum { CoDCustomer = 1, ChargeCustomer = 2 } choice;

  valid = true;
  do {
    if (!valid) {
      printf("Incorrect option entered. Please choose 1 or 2\n");
    }
    printf("Select type of Customer\n\t 1- Cash on Delivery (CoD) \n\t 2 - "
           "Charge Customer\n");
    printf("Enter choice:");
    scanf("%d", &choice);
    valid = false;
    clear;
  } while (choice != 1 && choice != 2);

  if (choice == CoDCustomer) {

    valid = true;
    do {
      if (valid == false) {
        printf(
            "Incorrect Fuel Type entered. Please select an optuion from 1-3\n");
      }
      printf("Select Fuel Type\n\t1. E10-87\n\t 2. E10-90\n\t 3.Diesel\n");
      printf("Enter option:");

      scanf("%d", &fuelType);

      valid = false;
      clear;
    } while (fuelType < 1 || fuelType > 3);

    cod->fuelType = fuelType;

    printf("Enter Fuel Amount:");

    scanf("%f", &cod->fuelAmt);

    clear;

    cod->lubeReq = randomInteger(0, 1) ? 'Y' : 'N';

    do {
      printf("Select Payment Type\n\t 1. Cash \n\t 2. Card\n");
      printf("Enter Choice:");

      scanf("%d", &cod->payType);
      clear;
    } while (cod->payType != 1 && cod->payType != 2);

  } else if (choice == ChargeCustomer) {
    char idname[50];
    int id = 0;

    printf("Enter ID or Business Name:");
    scanf("%s", idname);

    if (isdigit(idname[0])) { // Digit characters are id number
      sscanf(idname, "%d", &id);
      charge->idNo = id;
    } else {
      strcpy(charge->name, idname);
    }
    clear;

    int numReps;
    valid = true;
    do {
      printf("Enter number of representatives:");
      scanf("%d", &numReps);
      valid = false;
    } while (numReps > 5 || numReps < 1);

    charge->repNum = numReps;

    strcpy(charge->licenseNo, getLicensePlateInfo());

    bool prefDeposit = randomInteger(0, 1) ? true : false;

    int minDepo = 0;
    int litr;

    if (prefDeposit) {
      minDepo = 10000;
      litr = 50;

      printf("Minimum Deposit is $%d for %d liters", minDepo, litr);
    }
  }
}

void printReceipt() {
  printf("\nProcessing Successful.\n");
  printf("RECEIPT\n");
  printf("Transaction Date: %s\n", __DATE__);
  printf("Type of Customer: Cash on Delivery (COD)\n");
  printf("Items Purchased: \n");
  printf("GCT Amount: \n");
  printf("Total Amount: \n");
  printf("Cash Given/Charge Amount: \n");
  printf("Change: \n");
}

void codServe() {}
void chargeServe() {}
void addCharge(Charge *ch) {
  int licenseNo, i, index;
  char licenseletters[2], licenseNums[5], fullLicense[6];

  srand(time(0));
  ch->idNo = randomInteger(999, 100);
  // printf("ID: %d\n\n", ch->idNo);
  printf("Business Name: ");
  gets(ch->name);
  printf("Number of Representatives (no more than 5): ");
  scanf("%d", &ch->repNum);

  licenseNo = randomInteger(9999, 1000);
  // printf("%d\n\n", licenseNo);

  for (i = 0; i < 2; i++) {
    index = rand() % 26;
    licenseletters[i] = randomCharacter(index);
    // printf("%c\n", licenseletters[i]);
  }

  sprintf(licenseNums, "%d", licenseNo);
  strcpy(fullLicense, licenseNums);
  strcat(fullLicense, licenseletters);
  strcpy(ch->licenseNo, fullLicense);
  // puts(fullLicense);
  // puts(ch->licenseNo);

  printf("Preference (Deposit or Maximum Litres): ");
}

Charge blankCharge() {
  Charge ch;

  ch.idNo = 0;
  strcpy(ch.name, " ");
  // ch.fuelType = ' ';
  ch.fuel = 0;
  ch.fuelAmt = 0;
  ch.lubeRequest = ' ';
  ch.depositAmt = 0;

  return ch;
}

void existingCharge() {}
void deleteCharge() { enterPassword(); }

char *getLicensePlateInfo() {
  static char licNo[7];
  bool valid = false;
  do {
    printf("Enter Lisense Plate Number:");
    scanf("%s", licNo);

    // Valid
    if (strlen(licNo) != 6) {
      clear;
      printf("Invalid. License Plate should have 6 characters\n");
      continue;
    }

    valid = isdigit(licNo[0]) && licNo[1] && licNo[2] && licNo[3];

    valid &= isalpha(licNo[4]) && isalpha(licNo[5]);

    if (!valid) {
      clear;
      printf(
          "Invalid. License Plate should use the following format 5786KW \n");
    }
  } while (!valid);
  return licNo;
}

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
void updateCharge() { enterPassword(); }
void refuelTank() { enterPassword(); }
void chargeSearch() {}
void chargePayment() {}
void generateReport() {}
void exitProgram() {}
