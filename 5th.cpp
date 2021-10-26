#include <iostream>
#include <string>
using namespace std;

class worker {
protected:
	 string name;	
public:
	worker() {
		name = "No Name";
	}
	worker( string _name) {
		name = _name;
	}
	~worker() {

	}

	void print() {
		 cout << "Worker`s name is " << name <<  endl;
	}
};

class junior : virtual protected worker {
protected:
	int motivationLevel;
public:
	junior(): worker(){
		motivationLevel=1;
	}
	junior( string _name, int _motivationLevel):worker(_name){
		motivationLevel = _motivationLevel;
	}
	~junior() {
	}
	void print() {
		 cout << "Junior`s name is " << name <<  endl;
		 cout << "Number of junior`s languages is " << motivationLevel <<  endl;
	}
};

class middle : protected junior {
protected:
	int staminaLevel;
public:
	middle():junior() {
		staminaLevel = 1;
	}
	middle( string _name, int _langNum,  int _staminaLevel) :junior(_name, _langNum) {
		motivationLevel = _langNum;
		staminaLevel = _staminaLevel;
	}
	~middle() {
	}

	void print() {
		 cout << "Middle`s name is " << name <<  endl;
		 cout << "Number of middle`s languages is " << name <<  endl;
		 cout << "Middle`s num oflanguages: " << motivationLevel <<  endl << "Middle main lang" << staminaLevel <<  endl;
		 cout <<  endl;
	}
};
class mentor : virtual protected worker {
protected:
	int numOfStudents;
public:
	mentor():worker() {
		numOfStudents = 0;
	}
	mentor( string _name, int _numOfStudents) :worker(_name) {
		numOfStudents = _numOfStudents;
	}
	~mentor() {

	}
	void print() {
		 cout << "Mentor`s name is " << name <<  endl;
		 cout << "Number of mentor`s student is " << numOfStudents <<  endl;
	}
};
class teamlead : protected mentor {
protected:
	int numOfWorkersInTheTeam;
public:
	teamlead() :mentor() {
		numOfWorkersInTheTeam = 0;
	}
	teamlead( string _name, int _numOfStudents, int _numOfWorkersInTheTeam) :mentor(_name,_numOfStudents) {
		numOfWorkersInTheTeam = _numOfWorkersInTheTeam;
	}
	~teamlead() {
	}
	void print() {
		 cout << "Teamlead`s name is " << name <<  endl;
		 cout << "Number of teamlead`s students is " << name <<  endl;
		 cout << "Number of workers the in team is " << numOfWorkersInTheTeam <<  endl;
	}
};
class officeSystem : protected middle, protected teamlead {
protected:
	int frameNum;
	
public:
	officeSystem() :middle(), teamlead() {
		frameNum = 0;
	}
	officeSystem( string _name, int _motivationLevel, int _numOfStudents, int _numOfWorkersInTheTeam, int _frameNum,  int _staminaLevel) :
		teamlead(_name, _numOfStudents, _numOfWorkersInTheTeam), middle(_name, _motivationLevel, _staminaLevel), worker (_name) {
		frameNum = _frameNum;
	}
	~officeSystem() {
	}
	void print() {
		 cout << "system name is " << name <<  endl;
		 cout << "system`s num of anguages: " << motivationLevel <<  endl;
		 cout << "system`s main lang " << staminaLevel <<  endl;
		 cout << "Number of workers in the team is " << numOfWorkersInTheTeam << endl;
		 cout << "Num of students" << numOfStudents << endl;
		 cout << "systems num of frameworks " << frameNum <<  endl;
		
		 cout <<  endl;
	}
};

int main() {
	 string name;
	int langNum;
	int frameNum;
	int numOfstudents;
	int numOfWorkers;
	 int staminaLevel;
	 cout << "Print name" <<  endl;
	 getline( cin, name);
	 cout << "Print lang num" <<  endl;
	 cin >> langNum;
	rewind(stdin);
	 cout << "Print name lang" <<  endl;
	 cin >> staminaLevel;
	 cout << "Print frameworks num" <<  endl;
	 cin >> frameNum;
	 cout << "Print num of students" <<  endl;
	 cin >> numOfstudents;
	 cout << "Print num of workers" <<  endl;
	 cin >> numOfWorkers;
	
	officeSystem obj = officeSystem(name, langNum, numOfstudents, numOfWorkers, frameNum, staminaLevel);
	obj.print();

}
//
//
