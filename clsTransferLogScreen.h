#pragma once
# include <iostream>
#include "clsScreen.h"
# include "clsBankClient.h"
# include "fstream"
# include<iomanip>


using namespace std;
class clsTransferLogScreen : protected clsScreen
{
private:
	static void _PrintTransferRegisterRecordLine(clsBankClient::stTransferLogRecord TransferRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(20) << left << TransferRecord.DateTime;
		cout << "| " << setw(10) << left << TransferRecord.SourceAccountNumber;
		cout << "| " << setw(10) << left << TransferRecord.DestinationAccountNumber;
		cout << "| " << setw(10) << left << TransferRecord.Amount;
		cout << "| " << setw(10) << left << TransferRecord.SourceAccountBalanceAfter;
		cout << "| " << setw(10) << left << TransferRecord.DestinationAccountBalanceAfter;
		cout << "| " << setw(10) << left << TransferRecord.UserName;

	}
public :

	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLogRecord> vTransLogList = clsBankClient::GetTransferLogList();

		string Title = "\tTransfer Register List Screen";
		string SubTitle = "\t\t( " + to_string(vTransLogList.size()) + " ) Record(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(20) << left << "DateTime";
		cout << "| " << setw(10) << left << "S.Acct";
		cout << "| " << setw(10) << left << "D.Acct";
		cout << "| " << setw(10) << left << "Amount";
		cout << "| " << setw(10) << left << "S.Balance";
		cout << "| " << setw(10) << left << "D.Balance";
		cout << "| " << setw(10) << left << "UserName";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vTransLogList.size() == 0)
		{
			cout << "\t\t\t\tNo Logins Available In the System!";
		}
		else
		{
			for (clsBankClient::stTransferLogRecord Transfer : vTransLogList)
			{
				_PrintTransferRegisterRecordLine(Transfer);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};

