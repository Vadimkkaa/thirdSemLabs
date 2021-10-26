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
	cout << "Print name" << endl;
	getline(cin, name);
	cout << "Print mot lvl" << endl;
	cin >> motivationLevel;
	cout << "Print stamina lvl" << endl;
	cin >> staminaLevel;
	cout << "Print num of students" << endl;
	cin >> numOfstudents;
	cout << endl;

	worker** ptrArr = new worker * [3];
	junior *Junior = new junior(name, motivationLevel);
	middle* Middle = new middle(name, motivationLevel, staminaLevel);
	mentor* Mentor = new mentor(name, numOfstudents);

	ptrArr[0] = Junior;
	ptrArr[1] = Middle;
	ptrArr[2] = Mentor;

	for (int i = 0; i < 3; i++) {
		ptrArr[i]->calc();
		ptrArr[i]->print();
	}
	delete Junior;
	delete Middle;
	delete Mentor;
	delete[] ptrArr;
}
//
//