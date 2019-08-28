
#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;



class weatheR
{

private:
	struct resultaT
	{
		float avgfukt;
		float avgtemp;
		long int datE2;
		double mogel;

	};
	vector <resultaT> avgvectorin;
	vector <resultaT> avgvectorout;

	struct MyStruct
	{
		long int datE;
		string inOrout;
		long int timE;
		float temP;
		int fukT;
	};
	vector < MyStruct> vectorIn;
	vector < MyStruct> vectorOut;


public:
	weatheR()
	{
		string line;
		string iu;
		MyStruct topush;
		ifstream wprog("1.txt");

		if (wprog.is_open())
		{

			while (!wprog.eof())
			{
				getline(wprog, line, ' ');
				line.erase(4, 1);
				line.erase(6, 1);
				topush.datE = stol(line);

				getline(wprog, line, ',');
				line.erase(2, 1);
				line.erase(4, 1);
				topush.timE = stol(line);

				getline(wprog, line, ',');
				topush.inOrout = line;

				getline(wprog, line, ',');
				topush.temP = stof(line);

				getline(wprog, line);
				topush.fukT = stoi(line);

				if (topush.inOrout == "Inne")
					vectorIn.push_back(topush);
				else
					vectorOut.push_back(topush);
			}
			wprog.close();
		}

		else
		{
			std::cout << "unable to open\n";

		}
		/*for (size_t i = 0; i < vectorIn.size(); i++)
		{
			cout << vectorIn[i].datE << endl;
			cout << vectorIn[i].fukT << endl;
			cout << vectorIn[i].inOrout << endl;
			cout << vectorIn[i].temP << endl;
			cout << vectorIn[i].timE << endl;
			cout << endl;


		}*/
		calcavg();

	};
	//void sort()
	//{
	//	vector<


	void calcavg()
	{
		float sumtemp{ 0 };
		float fukt{ 0 };
		int counter{ 0 };
		resultaT adan;

		for (size_t i = 0; i < vectorIn.size() - 1; i++)
		{
			if (vectorIn[i].datE == vectorIn[i + 1].datE)
			{
				sumtemp = sumtemp + vectorIn[i].temP;
				fukt = fukt + vectorIn[i].fukT;

				counter++;
			}
			else
			{
				sumtemp = sumtemp + vectorIn[i].temP;
				fukt = fukt + vectorIn[i].fukT;
				counter++;
				sumtemp = sumtemp / counter;
				fukt = fukt / counter;

				adan.datE2 = vectorIn[i].datE;
				adan.avgtemp = sumtemp;
				adan.avgfukt = fukt;
				float y = -0.0015*pow(sumtemp, 3) + 0.1193*pow(sumtemp, 2) - 2.9878*sumtemp + 102.96;
				adan.mogel = fukt - y;

				avgvectorin.push_back(adan);
				counter = sumtemp = fukt = 0;
			}
			/*
			if(vectorIn[i].fukT)
			{

			}
			*/

		}
		for (size_t i = 0; i < vectorOut.size() - 1; i++)
		{
			if (vectorOut[i].datE == vectorOut[i + 1].datE)
			{
				sumtemp = sumtemp + vectorOut[i].temP;
				fukt = fukt + vectorOut[i].fukT;

				counter++;
			}
			else
			{
				sumtemp = sumtemp + vectorOut[i + 1].temP;
				fukt = fukt + vectorOut[i + 1].fukT;
				counter++;
				sumtemp = sumtemp / counter;
				fukt = fukt / counter;

				adan.datE2 = vectorOut[i].datE;
				adan.avgtemp = sumtemp;
				adan.avgfukt = fukt;
				avgvectorout.push_back(adan);
				counter = sumtemp = fukt = 0;

			}
		}

	};

	void sortTempIn() {

		vector<resultaT> temporarlyV(avgvectorin);
		sort(temporarlyV.begin(), temporarlyV.end(), [](const resultaT g, const resultaT m) {return g.avgtemp > m.avgtemp; });//1

		for (size_t i = 0; i < temporarlyV.size(); i++)
			cout << "Datum " << temporarlyV[i].datE2 << ", Temperatur " << temporarlyV[i].avgtemp << endl;

	};

	void sortFuktin() {
		vector<resultaT> temporarlyV(avgvectorin);
		sort(temporarlyV.begin(), temporarlyV.end(), [](const resultaT g, const resultaT m) {return g.avgfukt > m.avgfukt; });//1

		for (size_t i = 0; i < temporarlyV.size(); i++)
			cout << "Datum " << temporarlyV[i].datE2 << ", Fuktighet " << temporarlyV[i].avgfukt << endl;

	};
	void sortMogelin() {
		vector<resultaT> temporarlyV(avgvectorin);
		sort(temporarlyV.begin(), temporarlyV.end(), [](const resultaT g, const resultaT m) {return g.mogel > m.mogel; });//1

		for (size_t i = 0; i < temporarlyV.size(); i++)
			cout << "Datum " << temporarlyV[i].datE2 << ", MögelindeX " << temporarlyV[i].mogel << endl;

	};


	void sortTempOut()

	{
		vector<resultaT> temporarlyV(avgvectorout);
		sort(temporarlyV.begin(), temporarlyV.end(), [](const resultaT g, const resultaT m) {return g.avgtemp > m.avgtemp; });//1

		for (size_t i = 0; i < temporarlyV.size(); i++)
			cout << "Datum " << temporarlyV[i].datE2 << ", Temperatur " << temporarlyV[i].avgtemp << endl;

	};
	void sortFuktout() {
		vector<resultaT> temporarlyV(avgvectorout);
		sort(temporarlyV.begin(), temporarlyV.end(), [](const resultaT g, const resultaT m) {return g.avgfukt > m.avgfukt; });//1

		for (size_t i = 0; i < temporarlyV.size(); i++)
			cout << "Datum " << temporarlyV[i].datE2 << ", Fuktighet " << temporarlyV[i].avgfukt << endl;

	};
	void sortMogelout() {
		vector<resultaT> temporarlyV(avgvectorout);
		sort(temporarlyV.begin(), temporarlyV.end(), [](const resultaT g, const resultaT m) {return g.mogel > m.mogel; });//666


		for (size_t i = 0; i < temporarlyV.size(); i++)
			cout << "Datum " << temporarlyV[i].datE2 << ", MogelindeX " << temporarlyV[i].mogel << endl;

	};


	void inDoor()
	{
		long int userinp;
		bool found = false;

		cout << "Enter the date you want to show for indoor values\n" << endl;
		cin >> userinp;
		for (int i = 0; i < avgvectorin.size(); i++)
		{

			if (userinp == avgvectorin[i].datE2)

			{
				cout << "Date found: " << endl;

				cout << "Date " << avgvectorin[i].datE2 << "\ntemp in " << avgvectorin[i].avgtemp << "\nfukt in " << avgvectorin[i].avgfukt << "\nmogel in " << avgvectorin[i].mogel << endl;

				found = true;
				break;

			}
		}
		if (found == false)
			cout << "Date not found\n";
	}

	void outDoor()
	{
		long int userinp;
		bool found = false;
		bool kör = true;
		cout << "Enter the date you want to show values for outdoor " << endl;
		cin >> userinp;
		for (int i = 0; i < avgvectorout.size(); i++)
		{
			if (userinp == avgvectorout[i].datE2)
			{
				cout << "Date " << avgvectorout[i].datE2 << "\ntemp in " << avgvectorout[i].avgtemp << "\nfukt in " << avgvectorout[i].avgfukt << "\nmogel in " << avgvectorout[i].mogel << endl;

				found = true;
				break;
			}
		}
		if (found == false)
		{
			cout << "Date not found\n";
		}
	}




	void Autumn()
	{


		int counter{ 0 };
		bool flagga = false;
		for (size_t i = 0; i < avgvectorout.size(); i++)
		{
			if (avgvectorout[i].avgtemp <= 10 && avgvectorout[i].avgtemp >= 0)
				counter++;
			else
				counter = 0;
			if (counter == 5)
			{
				cout << "HÖST HITTAD " << avgvectorout[i - 4].datE2 << endl;
				flagga = true;
				break;
			}
		}
		if (flagga == false)
			cout << " Host ej hittad" << endl;

	}

	void winter()

	{

		bool flagga = false;
		int counter{ 0 };

		for (size_t i = 0; i < avgvectorout.size(); i++)
		{
			if (avgvectorout[i].avgtemp <= 0)
				counter++;
			else
				counter = 0;
			if (counter == 5)
			{
				cout << "Vinter HITTAD " << avgvectorout[i - 4].datE2 << endl;
				flagga = true;
				break;
			}

		}
		if (flagga == false)
		{
			cout << "Vinter inte hittad" << endl;

		}


	}

};


int main()
{
	weatheR adonay;
	bool flagga = true;

	do
	{


		cout << "1. Visa alla värden efter datum (inne)" << endl
			<< "2. Visa alla värden efter datum (ute)" << endl
			<< "3. Sortera Temperatur inne" << endl
			<< "4. Sortera Temperatur ute" << endl
			<< "5. Sortera Fukt inne" << endl
			<< "6. Sortera Fukt ute" << endl
			<< "7. Sortera mogel inne" << endl
			<< "8. Sortera mogel ute" << endl
			<< "9. Hitta host" << endl
			<< "10. Hitta Vinter" << endl
			<< "11.Exit" << endl;




		int userinput;

		cin >> userinput;
		switch (userinput)
		{
		case 1:
			adonay.inDoor();
			break;
		case 2:
			adonay.outDoor();
			break;
		case 3:
			adonay.sortTempIn();
			break;
		case 4:
			adonay.sortTempOut();
			break;
		case 5:
			adonay.sortFuktin();
			break;
		case 6:
			adonay.sortFuktout();
			break;
		case 7:
			adonay.sortMogelin();
			break;
		case 8:
			adonay.sortMogelout();
			break;
		case 9:
			adonay.Autumn();
			break;
		case 10:
			adonay.winter();
			break;
		case 11:
			flagga = false;
			break;

		default:

			cout << "Out of range" << endl;
			break;
		}


		cout << endl << endl;

	} while (flagga == true);

}