#include <stdio.h>

// Data structures

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
void enterPassword();
void updateCharge();
void deleteCharge();
void chargeSearch();
void chargePayment();
void refuelTank();
void generateReport();

int main() { return 0; }
