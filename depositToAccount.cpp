#include "Bank.h"

void depositToAccount(LinkedList& list)
{
	double amount;
	bool invalid;
	string searchItem;
	Node *current;

	invalid = true;
	cout << "\033[H\033[2J" << endl;

	cout << "\t ************************************************************************ \n"
		 << "\t *                       SEARCH FOR AN ACCOUNT                          * \n"
		 << "\t ************************************************************************ \n"
		 << "\t *\n"
		 << "\t *\n"
		 << "\t    Enter the account number: ";

	getline(cin, searchItem);
	current = list.head;
	while (current)
	{
		if (current->accountNumber == searchItem)
		{
			cout << "\n\t Account Number: " << current->accountNumber
				 << " | Name: " << current->name
				 << " | Account Type: " << current->accountType
				 << " | Balance: $" << current->balance << endl << endl;

			do
			{
				cout << "\n\t How much would you like to deposit?: $";
				if (!(cin >> amount))
				{
					cin.clear();
					cout << "\n\t Invalid input - Please enter a number\n";
				}
				else if (amount <= 0)
				{
					cout << "\n\t Invalid Input - Please enter a number greater to 0\n";
				}
				else
				{
					invalid = false;
				}
				cin.ignore(1000, '\n');
			}while(invalid);

			(current->balance) = (current->balance) + amount;

			cout << "\n\t Deposit made\n"
				 << "\n\t Press enter to continue";
			cin.ignore(1000, '\n');

			return;
		}
		current = current->next;
	}
	cout << "Account not found." << endl;
}
