//Temperature Array Program
//Author: Jackie Marcano
#include <iostream>
#include <fstream>

using namespace std;

void averageHigh(int temperatures[12][2], int high)
{
	//sum all high values, then divide them by 12
	int total = 0;
	for (int i = 0; i < 12; i++)
	{
		total += temperatures[i][1];
	}
	int averageHigh = total / 12;
	cout << "Average High temperature is: " << averageHigh << endl;
}

void averageLow(int temperatures[12][2], int low)
{
	//sum all low values, then divide them by 12
	int total = 0;
	for (int i = 0; i < 12; i++)
	{
		total += temperatures[i][0];
	}
	int averageLow = total / 12;
	cout << "Average Low Temperature is: " << averageLow << endl;
}

void indexHighTemp(int temperatures[12][2], int high)
{
	int x, y;
	int highestTemp = temperatures[0][high];
	//scroll through array with a for(), if array is higher than current value of temporary value, then print out said value.
	for (int i = 0; i < 12; i++)
	{
		if (highestTemp < temperatures[i][high])
		{
			//Replace with new highest temperature.
			highestTemp = temperatures[i][high];
			x = i;
			y = high;
		}
	}
	cout << "Highest Temperature in the year was " << highestTemp << " In index [" << x << "] [" << y << "]" << endl;
}

void indexLowTemp(int temperatures[12][2], int low)
{
	int x, y;
	int lowestTemp = temperatures[0][low];
	//scroll through array with a for(), if array is lower than current value of temporary value, then print out said value.
	for (int i = 0; i < 12; i++)
	{
		if (lowestTemp > temperatures[i][low])
		{
			lowestTemp = temperatures[i][0];
			//Array variables
			x = i;
			y = low;
			//Replace with new lowest temperature.
		}
	}
	cout << "Lowest Temperature in the year was " << lowestTemp << " In index [" << x << "] [" << y << "]" << endl;
}



void getData()
{
	int lowTemp = 0;
	int highTemp = 1;
	int maxTemps = 12;
	ifstream yearlyTemp;
	yearlyTemp.open("month_Rand_Numbers.txt");
	int tempVariation[12][2];
	for (int i = 0; i < maxTemps; i++)
	{
		for (int n = 0; n < 2; n++)
		{
			yearlyTemp >> tempVariation[i][n];
		}
	}
		cout << "Information from file stored." << endl;
	averageHigh(tempVariation, highTemp);
	averageLow(tempVariation, lowTemp);
	indexHighTemp(tempVariation, highTemp);
	indexLowTemp(tempVariation, lowTemp);
	}



int main()
{
	getData();
	return 0;
}

