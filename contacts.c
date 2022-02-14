
#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

#include <stdio.h>
#include <string.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
#include "contacts.h"
#include "contactHelpers.h"


// getName:
void getName(struct Name* name)
{
    int yN;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    yN = yes();
    if (yN == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]%*c", name->middleInitial);
    }
    else if (yN == 0)
    {
        strcpy(name->middleInitial, "\0");
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{
    int yN;
    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt();
    while (address->streetNumber < 0)
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        scanf("%d%*c", &address->streetNumber);
    }


    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);
    

    printf("Do you want to enter an apartment number? (y or n): ");

    yN = yes();

    if (yN == 1)
    {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();
    }

    while (address->apartmentNumber < 0)
    {
        printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
        scanf("%d", &address->apartmentNumber);
        clearKeyboard();
        
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7c", address->postalCode);
    clearKeyboard();
    
    
    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
    
    

}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    int yN;

    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);
    

    printf("Do you want to enter a home phone number? (y or n): ");
    //if (yesNo == 'y' && yesNo == 'Y') // <-- No! can't be both 'y' AND 'Y' (should be OR ||)
    yN = yes();
    if (yN == 1)
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);

    }
    else if (yN == 0)
    {
        strcpy(numbers->home, "\0");
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    yN = yes();
    if (yN == 1)
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }
    else if (yN == 0)
    {
        strcpy(numbers->business, "\0");
    }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}