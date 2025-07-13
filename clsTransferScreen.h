#pragma once
# include <iostream>
# include "clsBankClient.h"
# include "clsScreen.h"
# include "clsInputValidate.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClientInfo(clsBankClient Client)
	{
		cout << "\nClient Card :\n";
		cout << "________________________\n";
		cout << "\nFull Name : " << Client.FullName() << endl;
		cout << "Acc.Number : " << Client.AccountNumber() << endl;
		cout << "Balance : " << Client.AccountBalance << endl;
		cout << "________________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		AccountNumber= clsInputValidate::ReadString();
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Invalid Account Number , Please Enter Account Number To Transfer From: ";
			AccountNumber= clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount: ";
		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the availabe Balance , Enter another amount ? ";
			Amount = clsInputValidate::ReadFloatNumber();

		}

		return Amount;
	}

public :

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");

		cout << "\nPlease Enter Account Number To Transfer From: ";
		
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientInfo(SourceClient);

		cout << "\nPlease Enter Account Number To Transfer To: ";

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());


		while (DestinationClient.AccountNumber() == SourceClient.AccountNumber())
		{
			cout << "\n Invalid Account Number (as source and destination acn't be the same) , Please Enter Account Number To Transfer To: ";
			DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		}

		_PrintClientInfo(DestinationClient);
		

		float Amount = _ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre you sure you want to perform this operation [ y / n ] : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient , CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully \n";
			}
			else
			{
				cout << "\nTransaction faild\n";
			}
		}
		else
		{
			cout << "\nOperation canceled" << endl ;
		}
	
		_PrintClientInfo(SourceClient);
		_PrintClientInfo(DestinationClient);

	}

};

