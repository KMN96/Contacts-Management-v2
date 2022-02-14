

#define _CRT_SECURE_NO_WARNINGS
#define MAXCONTACTS 5
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"
#include "contacts.h"
//--------------------------------
// Function Definitions
//--------------------------------

// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:

void pause(void)
{
	printf("(Press Enter to Continue)");
	printf("\n");
	clearKeyboard();
}

// getInt function definition goes here:

int getInt(void) {
	int num;
	char nL = 0;

	do
	{
		scanf("%d%c", &num, &nL);
		if (nL != '\n')
		{
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			clearKeyboard();
		}
	} while (nL != '\n');
	return num;
}


// getIntInRange function definition goes here:

int getIntInRange(int min, int max)
{
	int num;
	int flag = 1;

	while (flag == 1)
	{
		num = getInt();
		if (num >= min && num <= max) {
			break;
		}
		else
		{
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	}
	return num;
}


// yes function definition goes here:

int yes(void)
{
	char value, check;

	while (1)
	{
		scanf(" %c", &value);
		scanf("%c", &check);
		if ((value == 'N' || value == 'n') && check == '\n')
		{
			return 0;
		}
		else if ((value == 'Y' || value == 'y') && check == '\n')
		{
			return 1;
		}
		else
		{
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
			continue;
			yes();
		}
	}

}

// menu function definition goes here:

int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	return getIntInRange(0, 6);
}


// contactManagerSystem function definition goes here:

void contactManagerSystem(void)
{
	int function, rep = 0;
	struct Contact contactsInfo[MAXCONTACTS] =
	{

	{
		{"Rick",{'\0'},"Grimes" },
		{11,"Trailer Park",0,"A7A 2J2","King City" },
		{"4161112222", "4162223333", "4163334444"}
	},

	{
		{"Maggie","R.","Greene" },
		{55,"Hightop House",0,"A9A 3K3","Bolton"},
		{"9051112222","9052223333","9053334444"}
	},

	{
		{"Morgan","A.","Jones" },
		{77,"Cottage Lane",0,"C7C 9Q9","Peterborough"},
		{"7051112222","7052223333","7053334444"}
	},

	{
		{"Sasha",{'\0'},"Williams"},
		{55,"Hightop House",0,"A9A 3K3","Bolton"},
		{"9052223333","9052223333","9054445555"}
	},
	};
	
	

	do
	{
		function = menu();
		switch (function)
		{
		case 1:
			displayContacts(contactsInfo, MAXCONTACTS);
			pause();
			break;

		case 2:

			addContact(contactsInfo, MAXCONTACTS);
			pause();
			break;

		case 3:
			updateContact(contactsInfo, MAXCONTACTS);
			pause();
			break;

		case 4:
			deleteContact(contactsInfo, MAXCONTACTS);
			pause();
			break;

		case 5:
			searchContacts(contactsInfo, MAXCONTACTS);
			pause();
			break;

		case 6:
			sortContacts(contactsInfo, MAXCONTACTS);
			pause();
			break;

		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			rep = yes();
			if (rep == 1)
			{
				printf("\nContact Management System: terminated\n");
				return;
			}

			else
			{
				printf("\n");
			}
			break;
		}

	} while ((function >= 0) || (function <= 6));

	return;
	
}



// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;
	int i, j = 0;

	while (needInput == 1)
	{
		scanf("%11s", phoneNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10)
		{
			for (i = 0; i < 10; i++)
			{
				if (phoneNum[i] < '0' || phoneNum[i] > '9')
				{
					j++;
				}
			}
			if (j == 0)
			{
				needInput = 0;
			}
			else
			{
				printf("Enter a 10-digit phone number: "); // For when a numerical digits is not inputed
				j = 0;
			}
			
		}
		else
		{
			printf("Enter a 10-digit phone number: ");
		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) 
{
	int i;

	for ( i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			return i;
		}
	}
	return -1;
}



// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
	printf("\n");
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
}

// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact *contact)
{
	printf(" %s ", contact->name.firstName);
	if (strlen(contact->name.middleInitial) != 0)
	{
		printf("%s ", contact->name.middleInitial);
	}
	printf("%s\n", contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0)
	{
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
	int i, counter = 0;

	displayContactHeader();
	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) != 0)
		{
			displayContact(&contacts[i]);
			counter++;
		}
	}
	displayContactFooter(counter);
}

// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
	char cellNum[11];
	int contactIndex;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	contactIndex = findContactIndex(contacts, size, cellNum);
	if (contactIndex == -1)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else
	{
		printf("\n");
		displayContact(&contacts[contactIndex]);
		printf("\n");
	}
}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
	int i;

	for ( i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 0)
		{
			break;
		}
	}
	if (i == size)
	{
		printf("\n*** ERROR: The contact list is full! ***\n\n");
	}
	else
	{
		printf("\n");
		getContact(&contacts[i]);
		printf("--- New contact added! ---\n\n");
	}
}


// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
	char contactNum[11];
	int contactIndex, flag;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(contactNum);
	contactIndex = findContactIndex(contacts, size, contactNum);
	if (contactIndex == -1 )
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contacts[contactIndex]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		flag = yes();
		if (flag == 1)
		{
			getName(&contacts[contactIndex].name);
		}
		printf("Do you want to update the address? (y or n): ");
		flag = yes();
		if (flag == 1)
		{
			getAddress(&contacts[contactIndex].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		flag = yes();
		if (flag == 1)
		{
			getNumbers(&contacts[contactIndex].numbers);
		}

		printf("--- Contact Updated! ---\n\n");
	}
	
}


// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{
	int contactIndex, flag;
	char contactNum[11];

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(contactNum);
	contactIndex = findContactIndex(contacts, size, contactNum);
	if (contactIndex == -1)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contacts[contactIndex]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		flag = yes();
		if (flag == 1)
		{
			contacts[contactIndex].numbers.cell[0] = '\0';
			contacts[contactIndex].numbers.home[0] = '\0';
			contacts[contactIndex].numbers.business[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
		printf("\n");
	}
}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{
	struct Contact placeholder;
	int i, x;

	for ( i = 0; i < size; i++)
	{
		for ( x = i + 1; x < size; x++)
		{
			if (strlen(contacts[i].numbers.cell) != 0 && strlen(contacts[x].numbers.cell) != 0)
			{
				if (strcmp(contacts[i].numbers.cell, contacts[x].numbers.cell) > 0)
				{
					placeholder = contacts[i];
					contacts[i] = contacts[x];
					contacts[x] = placeholder;
				}
			}
		}
	}
	printf("\n--- Contacts sorted! ---\n\n");

}
