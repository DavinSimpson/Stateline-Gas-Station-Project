void addCharge(Charge *ch)
{
    int licenseNo, i, index;
    char licenseletters[2], licenseNums[5], fullLicense[6];

    srand(time(0));
    ch->idNo = randomInteger(999, 100);
    //printf("ID: %d\n\n", ch->idNo);
    printf("Business Name: ");
    gets(ch->name);
    printf("Number of Representatives (no more than 5): ");
    scanf("%d", &ch->repNum);
    
    licenseNo = randomInteger(9999, 1000);
    //printf("%d\n\n", licenseNo);

    for (i=0; i<2; i++)
    {
        index = rand() % 26;
        licenseletters[i] = randomCharacter(index);
        //printf("%c\n", licenseletters[i]);
    }

    sprintf(licenseNums, "%d", licenseNo);
    strcpy(fullLicense, licenseNums);
    strcat(fullLicense, licenseletters);
    strcpy(ch->licenseNo, fullLicense);
    //puts(fullLicense);
    //puts(ch->licenseNo);
    
    printf("Preference (Deposit or Maximum Litres): ");
    
    
    


}
