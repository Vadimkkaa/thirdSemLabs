#include <iostream>
#include <string>
using namespace std;

template <class T>
class myArray {
	int arrSize = 3;
public:
	T arr[3];
	myArray() {
		for (int i = 0; i < arrSize; i++) {
			arr[i] = 0;
		}
	}
	myArray(int n) {
		cout << "Enter array" << endl;
		for (int i = 0; i < arrSize; i++) {
			cin >> arr[i];
		}
	}
	myArray(const myArray& obj) {
		for (int i = 0; i < arrSize; i++) {
			arr[i] = obj.arr[i];
		}
	}
	~myArray() {
	}
	void print() {
		cout << "array output" << endl;
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void singleRewrite(int n) {
		n--;
		if (arr[n]) {
			cin >> arr[n];
		}
	}
	void search(T var) {
		for (int i = 0; i < arrSize; i++) {
			if (arr[i] == var) {
				cout << endl << "FOUNDED on the " << i + 1 << " position" << endl;
				return;
			}
		}
		cout << endl << "no matches" << endl;
	}
};

template <>
class myArray<string> {
	int arrSize = 3;
	string arr[3];
public:
	myArray() {
		for (int i = 0; i < arrSize; i++) {
			arr[i] = "0";
		}
	}
	myArray(int n) {
		cout << "Enter array" << endl;
		for (int i = 0; i < arrSize; i++) {
			rewind(stdin);
			getline(cin,arr[i]);
			rewind(stdin);
		}
	}
	myArray(const myArray& obj) {
		for (int i = 0; i < arrSize; i++) {
			arr[i] = obj.arr[i];
		}
	}
	~myArray() {
	}
	void print() {
		cout << "Array output " << endl;
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << endl;
		}
		cout << endl;
	}
	void singleRewrite(int n) {
		if (arr[n]!="") {
			getline(cin,arr[n]);
		}
	}
	void search(string var) {
		rewind(stdin);
		for (int i = 0; i < arrSize; i++) {
			if (arr[i] == var) {
				cout << endl << "FOUNDED on the " << i << " position" << endl;
				return;
			}
		}
		cout << endl << "no matches" << endl;
	}
};

template<class T>
void arrSwap(myArray<T>& obj) {
	T temp = obj.arr[0];
	obj.arr[0] = obj.arr[2];
	obj.arr[2] = temp;
}

template <class T>
class Arr {
	T* arr;
	int size;
public:
	Arr() {
		//arr = new T[1];
		size = 0;
	}
	Arr(int _size) {
		size = _size;
		arr = new  T[size];
	}
	Arr(const Arr& obj) {
		size = obj.size;
		arr = new T[size];
		for (int i = 0; i < size; i++) {
			arr[i] = obj.arr[i];
		}
	}
	~Arr() {
		delete[]arr;
	}

	void operator= (const Arr& obj) {
		size = obj.size;
		arr = new T * [size];
		for (int i = 0; i < size; i++) {
			arr[i] = obj.arr[i];
		}
	}

	void print() {
		cout << "OBJECT PRINT" << endl;
		for (int i = 0; i < size; i++) {
			cout << arr[i] << endl;
		}
		cout << endl;
	}
	void search() {
		T var{};
		cout << "ENTER VALUE TO START SEARCHING" << endl;
		cin >> var;
		cout << "FOUNDED" << endl;
		for (int i = 0; i < size; i++) {
			if (arr[i] == var) {
				cout << arr[i] << " at " << i << " position";
			}
		}
	}
	void arrAdd(T value) {
		T* copy = new T[size + 1];
		for (int i = 0; i < size; i++) {
			copy[i] = arr[i];
		}
		delete[] arr;
		copy[size] = value;
		arr = new T[size + 1];
		for (int i = 0; i < size + 1; i++) {
			arr[i] = copy[i];
		}
		size++;
		delete[] copy;
	}
};

template <>
class Arr<int> {
	int* arr;
	int size;
public:
	Arr() {
		//arr = new int[1];
		size = 0;
	}
	Arr(int _size) {
		size = _size;
		arr = new  int[size];
	}
	Arr(const Arr& obj) {
		size = obj.size;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = obj.arr[i];
		}
	}
	~Arr() {
		delete[]arr;
	}

	void operator= (const Arr& obj) {
		size = obj.size;
		arr = new int[size];
		for (int i = 0; i < size; i++) {
			arr[i] = obj.arr[i];
		}
	}

	void print() {
		cout << "OBJECT PRINT" << endl;
		for (int i = 0; i < size; i++) {
			cout << arr[i] << endl;
		}
		cout << endl;
	}
	void search() {
		int var{};
		cout << "ENTER VALUE TO START SEARCHING" << endl;
		cin >> var;
		cout << "FOUNDED" << endl;
		for (int i = 0; i < size; i++) {
			if (arr[i] == var) {
				cout << arr[i] << " at " << i << " position";
			}
		}
	}
	void arrAdd(int value) {
		int* copy = new int[size + 1];
		for (int i = 0; i < size; i++) {
			copy[i] = arr[i];
		}
		delete[] arr;
		copy[size] = value;
		arr = new int[size + 1];
		for (int i = 0; i < size + 1; i++) {
			arr[i] = copy[i];
		}
		size++;
		delete[] copy;
	}
	void byStrInit(string str) {
		int nValue = stoi(str);
		arrAdd(nValue);
		return;
	}
};

int main() {
	string mainLine;
	rewind(stdin);
	getline(cin, mainLine);
	Arr arrStr = Arr<string>();
	Arr arrNum = Arr<string>();
	Arr arrInt = Arr<int>();
	Arr arrDbl = Arr<double>();
	cout << "PRINT STRキNG" << endl;
	mainLine += ' ';
	string space = " ";
	mainLine.insert(0, space);
	int lineLenght = mainLine.length();
	bool intTrig = false;
	bool strTrig = false;
	bool dblTrig = false;
	string intLine;
	string strLine;
	string dblLine;
	for (int i = 0; i < lineLenght; i++) {
		if (mainLine[i] == '\0') {
			break;
		}

	if ((mainLine[i] == '.') && ((mainLine[i - 1] < '0') || (mainLine[i - 1] > '9'))) {
		mainLine.erase(i, 1);
		i--;
	}
	if (mainLine[i + 1]) {
		if ((mainLine[i] == '.') && ((mainLine[i + 1] < '0') || (mainLine[i + 1] > '9'))) {
			mainLine.erase(i, 1);
			i--;
		}
	}
}
	for (int i = 0; i < lineLenght; i++) {
		if (mainLine[i] == '\0') {
			break;
		}

		/*if (mainLine[i] == ' ') {
			mainLine.erase(i, 1);
			i--;
			continue;
		}*/

		

		if (((mainLine[i] <= 'Z') && (mainLine[i] >= 'A')) || ((mainLine[i] <= 'z') && (mainLine[i] >= 'a'))) {
			strLine += mainLine[i];
		}
		else {
			strLine += ' ';
		}

		if (((mainLine[i] >= '0') && (mainLine[i] <= '9')) || (mainLine[i] == '.')) {
			intLine += mainLine[i];
		}
		else {
			intLine += ' ';
		}
	}
	cout << mainLine << endl;
	cout << strLine << endl;
	cout << intLine << endl;

	string secStrLine;
	for (int i = 0; i < lineLenght; i++) {
		if (mainLine[i] == '\0') {
			break;
		}
		if (((strLine[i] <= 'Z') && (strLine[i] >= 'A')) || ((strLine[i] <= 'z') && (strLine[i] >= 'a'))) {
			secStrLine += strLine[i];
			strTrig = true;
		}
		else {
			if (strTrig) {
				arrStr.arrAdd(secStrLine);
				strTrig = false;
				secStrLine.clear();
			}
			strTrig = false;
		}
	}
	intLine += 'a';
	string secIntLine;
	lineLenght = intLine.length();
	bool dotTrig = false;
	for (int i = 0; i < lineLenght; i++) {
		if (intLine[i] == '\0') {
			break;
		}
		if (((intLine[i] <= '9') && (intLine[i] >= '0')) || (intLine[i] == '.')) {
			if (intLine[i] == '.') {
				dotTrig = true;
			}
			secIntLine += intLine[i];
			intTrig = true;
		}
		else{
			if (intTrig) {
				if (dotTrig) {
					arrDbl.arrAdd(stod(secIntLine));
				}
				else {
					arrInt.arrAdd(stoi(secIntLine));
				}
				intTrig = false;
				dotTrig = false;
				secIntLine.clear();
			}
			intTrig = false;
		}
	}
	arrStr.print();
	//arrNum.print();
	arrInt.print();
	arrDbl.print();
	return 0;
}
//вводится 1 строка
//somestring with  404  a lot  9.999    of spaces and some4.55 dots 4.   .2
