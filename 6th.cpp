#include <iostream>
#include <string>
using namespace std;

class worker { //абстрактный класс - имеет чисто виртуальные методы. у него не может быть объектов
	int productivity;
protected:
	string name;
public:
	worker() {
		name = "No Name";
	}
	worker(string _name) {
		name = _name;
	}
	virtual ~worker() {

	}

	virtual void print() = 0; //!чисто виртуальная функция
	virtual int calc() = 0; //и ето тоже
};

class junior : virtual public worker {
	int productivity;
protected:
	int motivationLevel;
public:
	junior() : worker() {
		motivationLevel = 1;
	}
	junior(string _name, int _motivationLevel) :worker(_name) {
		motivationLevel = _motivationLevel;
	}
	~junior() {
	}
	void print() {
		cout << "Junior`s name is " << name << endl;
		cout << "mot lvl " << motivationLevel << endl;
		cout << "Productivity " << productivity << endl;
		cout << endl;
	}
	int calc() {
		productivity = motivationLevel;
		return productivity;
	}
};
class middle : public junior {
	int productivity;
protected:
	int staminaLevel;
public:
	middle() :junior() {
		staminaLevel = 1;
	}
	middle(string _name, int _motivationLevel, int _staminaLevel) :junior(_name, _motivationLevel), worker(_name) {
		motivationLevel = _motivationLevel;
		staminaLevel = _staminaLevel;
	}
	~middle() {
	}
	int calc() {
		productivity = motivationLevel * staminaLevel;
		return productivity;
	}

	void print() {
		cout << "Middle`s name is " << name << endl;
		cout << "Middle`s mot lvl " << motivationLevel << endl;
		cout << "Middle stamina lvl " << staminaLevel << endl;
		cout << "Productivity " << productivity << endl;
		cout << endl;
	}
};

class mentor : virtual public worker {
	int productivity;
protected:
	int numOfStudents;
public:
	mentor() :worker() {
		numOfStudents = 0;
	}
	mentor(string _name, int _numOfStudents) :worker(_name) {
		numOfStudents = _numOfStudents;
	}
	~mentor() {

	}
	void print() {
		cout << "Mentor`s name is " << name << endl;
		cout << "Number of mentor`s student is " << numOfStudents << endl;
		cout << "Productivity " << productivity << endl;
	}
	int calc() {
		productivity = numOfStudents * 5;
		return productivity;
	}
};

int main() {
	string name;
	int motivationLevel;
	int numOfstudents;
	int staminaLevel;
	int num{};
	cout << "Print num of elements" << endl;
	cin >> num;
	int inType{};
	
	worker** ptrArr = new worker * [num];
	for (int i = 0; i < num; i++) {
		cout << "1-jun" << endl << "2-mid" << endl << "3-sen" << endl;
		cin >> inType;
		switch (inType) {
		case 1: {
			cout << endl;
			cout << "Print name " << endl;
			rewind(stdin);
			getline(cin, name);
			cout << "Print motivationLevel" << endl;
			cin >> motivationLevel;

			junior* Junior = new junior(name, motivationLevel);
			ptrArr[i] = Junior;
			
			break;
		}
		case 2: {
			cout << endl;
			cout << "Print name " << endl;
			rewind(stdin);
			getline(cin, name);
			cout << "Print staminaLevel" << endl;
			cin >> staminaLevel;
			cout << "Print motivationLevel" << endl;
			cin >> motivationLevel;

			middle* Middle = new middle(name, motivationLevel, staminaLevel);
			ptrArr[i] = Middle;
			break;
		}
		case 3: {
			cout << endl;
			cout << "Print name " << endl;
			rewind(stdin);
			getline(cin, name);
			cout << "Print numOfStudents" << endl;
			cin >> numOfstudents;

			mentor* Mentor = new mentor(name, numOfstudents);
			ptrArr[i] = Mentor;
			break;
		}
		}
	}
	
	
	for (int i = 0; i < 3; i++) {
		ptrArr[i]->calc();
		ptrArr[i]->print();
	}
	for (int i = 0; i < num; i++) {
		delete ptrArr[i];
	}
	delete[] ptrArr;
}
