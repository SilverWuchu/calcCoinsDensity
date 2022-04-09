

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

double _unit;
double _theRadius;
const double _PI = 3.1415926;
double _theHeight;
double _theWeight;
double _innerSide = 0;

double _res = 0;

struct Coin {
	string _name;
	double _weight;
	double _radius;
	double _height;
	
	double _density;
};

vector<Coin> _myList;

//unit 0.001
//diameter 38.8
//height 2.1
//pi 3.1416
//weight 26.84
//inner 0
//OLD data
//NEW data
//name 31.35 40.4 2.3
//name 2.66 18.4 1.0
void ParseIn () {
	Coin coinSolo;
	double diameter = 0;
	
	ifstream inFile ("densityCalc.in");
	
	while (inFile >> coinSolo._name) {
		inFile >> coinSolo._weight;
		inFile >> diameter;
		coinSolo._radius = diameter / 2;
		
		inFile >> coinSolo._height;
		
		_myList.push_back(coinSolo);
	}
	
	inFile.close();
	
	cout << "coinList.size=>" << _myList.size() << endl;
	
}

//what: take coin and calculate the volume
double CalcCylinderVolume (Coin solo) {
	double surface = 0;
	double theVolume = 0;
	double hole = 0;
	
	surface = _PI * solo._radius * solo._radius;
	theVolume = surface * solo._height;
	
//	hole = _innerSide * _innerSide * _theHeight;
//	cout << "hole->" << hole << endl;
//	theVolume -= hole;
	
//	if (_unit == 0.001) {
//		theVolume /= 1000;
//	}

	theVolume /= 1000;
	
//	cout << "volume->" << theVolume  << "(cm^3)" << endl;
	return theVolume;
}



void Core () {
	double volume = 0;
	double density = 0;
	Coin coinSolo;
	
	for (int i = 0; i < _myList.size(); i++) {
		coinSolo = _myList[i];
		volume = CalcCylinderVolume(coinSolo);
		
		density = coinSolo._weight / volume;
		
		//cout << density << endl;
		_res =(int) (density * 100);
		_res /= (double) 100;
		
		_myList[i]._density = _res;
	}

}

void CWriteOut () {
	Coin coinSolo;
	
	for (int i = 0; i < _myList.size(); i++) {
		coinSolo = _myList[i];
		
		cout << coinSolo._name << "=>" << "RHO->" << coinSolo._density << endl;
	}
}


int main () {
	ParseIn();
	Core();
	CWriteOut();

	return 0;	
}
