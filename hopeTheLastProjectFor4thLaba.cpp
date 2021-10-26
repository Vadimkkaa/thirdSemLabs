#include <iostream>

class myDouble {
	int arraySize;
	double *arr;
public:
	myDouble();
	myDouble(int);
	myDouble(const myDouble& obj);
	~myDouble() {
		delete[] arr;
		std::cout << "destructor was here" << std::endl;
	}
	double get(int number) {
		number--;
		if (!arr[number]) {
			return 1;
		}
		return arr[number];
	}
	bool set(int number) {
		number--;
		if (!arr[number]) {
			return 1;
		}
		double n = 0;
		std::cout << "Print new value" << std::endl;
		std::cin >> n;
		arr[number] = n;
		return 0;
	};
	void init() {
		int num{};
		std::cout << "Enter num of el" << std::endl;
		std::cin >> num;
		arraySize = num;
		arr = new double[arraySize];
		std::cout << "Array created. Enter values." << std::endl;
		for (int i = 0; i < arraySize; i++) {
			std::cout << "Enter value with number" << i + 1 << std::endl;
			std::cin >> arr[i];
		}
	}
	void print() {
		std::cout << "Array:" << std::endl;
		for (int i = 0; i < arraySize; i++) {
			std::cout << arr[i] << " " << std::endl;
		}
		std::cout << std::endl;
	}
	void print(int number) {
		std::cout << arr[number-1] << std::endl;
	}
	void sort() {
		for (int i = 0; i < arraySize; i++) {
			for (int j = 0; j < arraySize; j++) {
				if (arr[i] > arr[i + 1]) {
					std::swap(arr[i], arr[i + 1]);
				}
			}
		}
	}
	int getSize() {
		return arraySize;
	}
	void* operator new(size_t size) {
		return new char[size];
	}
	/*void* operator new[](size_t size, int number) {
		return new char[size * number];
	}*/
	void operator delete(void* ptr) {
		delete ptr;
	}
	
	

	const myDouble &operator=(const myDouble& x) {
		if (this == &x) {
			return *this;
		}
		delete[]arr;
		arr = new double[x.arraySize];
		arraySize = x.arraySize;
		for (int i = 0; i < arraySize; i++) {
			arr[i] = x.arr[i];
		}
		//memcpy(arr, x.arr, sizeof(double) * arraySize);
		return *this;
	}

};
myDouble::myDouble() {
	arraySize = 1;
	arr = new double[1];
}
myDouble::myDouble(int a) {
	arraySize = a;
	arr = new double[arraySize];
	std::cout << "Array created. Enter values." << std::endl;
	for (int i = 0; i < arraySize; i++) {
		std::cout << "Enter value with number" << i + 1 << std::endl;
		std::cin >> arr[i];
	}
}
myDouble::myDouble(const myDouble& obj) {
	this->arraySize = obj.arraySize;
	delete[] this->arr;
	this->arr = new double[arraySize];
	for (int i = 0; i < arraySize; i++) {
		this->arr[i] = obj.arr[i];
	}
	//memcpy(arr, obj.arr, sizeof(double) * arraySize);
}

int main() {
	int num{};
	/*{
		std::cout << "Enter number of elements in first common array" << std::endl;
		std::cin >> num;
		myDouble* objectOne = new myDouble(num);
		myDouble* objectOneCopy = new myDouble();
		*objectOneCopy = *objectOne;
		std::cout << "Enter the number of element to rewrite." << std::endl;
		std::cin >> num;
		objectOne->set(num);
		objectOne->print();
		objectOneCopy->print();
		delete objectOne;
		delete objectOneCopy;
	}*/
	{
		std::cout << "Enter number of elements in dynamic array" << std::endl;

		int objArrSize = 0;
		std::cin >> objArrSize;
		myDouble* myArray = new myDouble[objArrSize];

		for (int i = 0; i < objArrSize; i++) {
			std::cout << "Enter num of el in the " << i + 1 << "th array" << std::endl;
			std::cin >> num;
			myArray[i] = myDouble(num);
		}
		std::cout << "array print -_-_-__-_-_-__-_-_--__" << std::endl;
		for (int i = 0; i < objArrSize; i++) {
			myArray[i].print();
		}

		//int numForRewrite = 0;
		//int numForRewriteIn = 0;
		//std::cout << "enter num of el of array to rewrite" << std::endl;
		//std::cin >> numForRewrite;

		///*while (1) {
		//	std::cout << "enter num of el of array to rewrite" << std::endl;
		//	std::cin >> numForRewrite;
		//	if (numForRewrite <= objArrSize) {
		//		break;
		//	}
		//	std::cout << "uncorrect input" << std::endl;
		//}*/
		//std::cout << "enter num of element in " << numForRewrite << " array to rewrite" << std::endl;
		//
		///*while (1) {
		//	std::cout << "enter num of el of array to rewrite" << std::endl;
		//	
		//	if (numForRewriteIn <= myArray[numForRewrite].getSize()) {
		//		break;
		//	}
		//	std::cout << "uncorrect input" << std::endl;
		//}*/
		//std::cout << "enter num of el of array to rewrite" << std::endl;
		//std::cin >> numForRewriteIn;
		//myArray[--numForRewrite].set(numForRewriteIn);

		//for (int i = 0; i < objArrSize; i++) {
		//	myArray[i].print();
		//}

		int seqSize;
		std::cout << "Enter sequence size" << std::endl;
		std::cin >> seqSize;

		double* seq;
		seq = new double[seqSize];
		std::cout << "Enter sequence" << std::endl;

		for (int i = 0; i < seqSize; i++) {
			std::cin >> seq[i];
		}

		int trig = 0;
		for (int i = 0; i < objArrSize; i++) {// for every object in array
			if (seqSize > myArray[i].getSize()) {
				break;
			}

			for (int j = 0; j < seqSize; j++) { //for every number in seq
				if (seq[j] == myArray[i].get(j+1)) {
					trig++;
				}
				else {
					trig = 0;
				}
			}
			if (trig == seqSize) {
				std::cout << std::endl << "sequence that u finding is " << std::endl;
				myArray[i].print();
				trig = 0;
			}
		}
	}
	return 0;
}
// поиск последовательностей
// введен размер и например
// введено 1 2 3 4
// вывести все массивы с последовательностью 1 2 3 4 в динамическом массиве в мейне