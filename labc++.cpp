#include <iostream>
using namespace std;

struct InformOfPlate
{
	char artist[60];
	char genre[20];
	char albumName[30];
	int edition;
	bool isCorrect(int edition);
};

bool InformOfPlate::isCorrect(int edition)
{
	bool result = false;
	if (edition > 10000)
		result = true;

	return result;
}

void task1()
{
	const int N = 2;
	InformOfPlate group[N];

	for (int i = 0; i < N; i++)
	{
		cout << "\nInput artist's name: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].artist, 60);

		cout << "\nIinput genre: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].genre, 20);

		cout << "\nInput album's name: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].albumName, 30);

		for (int i = 0; i < N; i++)
		{
			cout << "\nArtist: " << group[i].artist;
			cout << "\nGenre: " << group[i].genre;
			cout << "\nAlbum: " << group[i].albumName;
		}
	}

}

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
	short difference(Date date) {
		int days1 = 365 * year + month * 30 + day;
		int days2 = 365 * date.year + date.month * 30 + date.day;

		return days2 - days1;
	}
};

struct Worker
{
	string surName;
	string position;
	Date contractSigningDate;
	Date contractDuration;
	float salary;

	void printWorker()
	{
		cout << surName << " ";
		cout << position << " ";
		cout << salary << " ";
		cout << contractSigningDate.day <<"."<< contractSigningDate.month<<"." <<contractSigningDate.year << " ";
		cout << contractDuration.day << "." << contractDuration.month << "." << contractDuration.year << " ";
	}
};


bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if ((day <= 31) && (day > 0))
				result = true;
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if ((day <= 30) && (day > 0))
				result = true;
			break;
		}
		case 2:
		{
			if (year % 4 != 0)
			{
				if ((day <= 28) && (day > 0))
					result = true;
			}
			else
				if (year % 400 == 0)
				{
					if ((day <= 29) && (day > 0))
						result = true;
				}
				else
					if ((year % 100 == 0) && (year % 400 != 0))
					{
						if ((day == 28) && (day > 0))
							result = true;
					}
					else
						if ((year % 4 == 0) && (year % 100 != 0))
							if ((day <= 29) && (day > 0))
								result = true;
			break;
		}
		default:
			result = false;
	}
	return result;
}

void task2()
{
	const int N = 2;
	Worker person[2];
	for (size_t i = 0; i < N; i++)
	{
		cout << "\nInput worker's surname: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> person[i].surName;

		cout << "\nInput worker's position: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> person[i].position;

		cout << "\nInput worker's salary: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> person[i].salary;

		do
		{
			cout << "\nInput worker's contract signing date: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> person[i].contractSigningDate.day >> person[i].contractSigningDate.month >> person[i].contractSigningDate.year;
		} while (!person[i].contractSigningDate.isCorrect());


		do
		{
			cout << "\nInput worker's contract duration: "; 
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> person[i].contractDuration.day >> person[i].contractDuration.month >> person[i].contractDuration.year;
		} while (!person[i].contractDuration.isCorrect());

	}


	int j = 1;
	for (int i = 0; i < N; i++)
	{
		cout << "Worker " << j++ << ": "<<endl;
		person[i].printWorker();
	}
	Date curDate;
	curDate.day = 6;
	curDate.month = 3;
	curDate.year = 20;


	for (int i = 0; i < N; i++)
	{
		int diff = person[i].contractSigningDate.difference(curDate);
		if (diff < 5 && diff > 0)
		{
			cout << "Contoract expires in five days" << endl;
		}
		else
		{
			cout << "Contract do not expire" << endl;
		}
	}
	

}

struct DatePhone
{
	short day;
	short month;
	short year;
	bool isCorrect();		
};

bool DatePhone::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}
	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}
	default:
		result = false;
	}
	return result;
}


struct ABON
{
	string FIO;
	string phoneNumber;
	DatePhone connectionDate;
	int subscriptionFee;//абонентская плата
	int phoneBill;


};

void abonentsInfoInput(const int N, ABON person[])
{

	for (int i = 0; i < N; i++)
	{
		cout << "Input abonent's " << i+1 << " FIO using 'space': " << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> person[i].FIO;

		cout << "Input abonent's " << i+1 << " phone number: " << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> person[i].phoneNumber;

		cout << "Input abonent's " << i+1 << " phone connection date: " << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> person[i].connectionDate.day >> person[i].connectionDate.month >> person[i].connectionDate.year;

		cout << "Input abonent's " << i+1 << " payment amount: " << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> person[i].subscriptionFee;

		cout << "Input abonent's " << i+1 << " phone bill: " << endl;
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> person[i].phoneBill;

	}
}
void infoOutput(const int N, ABON person[])
{
	for (size_t i = 0; i < N; i++)
	{
		cout <<"FIO: " <<person[i].FIO << endl;;
		cout <<"Phone number: " <<person[i].phoneNumber << endl;
		cout << "Connection Date: "<<person[i].connectionDate.day << "." << person[i].connectionDate.month << "." << person[i].connectionDate.year;
		cout << "Subsription Fee: "<<person[i].subscriptionFee << endl;
		cout <<"Phone Bill: "<< person[i].phoneBill << endl;
	
	}
}

void task3()
{
	const int N = 2;
	ABON person[N];

	abonentsInfoInput(N, person);
	infoOutput(N, person);
}

int main()
{
	task1();
	task2();
	task3();
}
