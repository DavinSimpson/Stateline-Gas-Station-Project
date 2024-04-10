#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <conio.h>

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

typedef enum
{
    E10_87 = 1,
    E10_90,
    DIESEL
} FuelType;

typedef enum
{
    L5W30 = 1,
    L5W40,
    L15W40,
    LSAE40
} LubeType;
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
