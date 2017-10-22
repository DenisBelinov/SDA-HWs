#include <iostream>
#include <iomanip>

//task 1
void lastMemberSort(int* arr, int size) {
	int lastMember = arr[size - 1];
	int j = size - 2;
	while (j >= 0 && lastMember < arr[j]) {
		arr[j + 1] = arr[j--];
	}
	arr[j + 1] = lastMember;
}
double getMedian(int* arr, int size) {
	if (size % 2 == 0) {
		return (arr[size / 2] + arr[size / 2 - 1]) / 2.;
	}
	return arr[size / 2];
}
void coutMedians(int* arr, int size) {
	//old
		//int newArr[10000] = { 0 };
		//int currentSize = 1;
		//while(currentSize <= size)
		//{
		//	newArr[currentSize - 1] = arr[currentSize - 1];
		//	lastMemberSort(newArr, currentSize);
		//	std::cout << std::fixed << std::setprecision(1) << getMedian(newArr, currentSize++) << ' ';
		//}
	int currentSize = 1;
	while (currentSize <= size)
	{
		lastMemberSort(arr, currentSize);
		std::cout << std::fixed << std::setprecision(1) << getMedian(arr, currentSize++) << ' ';
	}
}
//task 2
bool lexCompare(int a, int b) {
	int power = 1;
	while (1) {
		int tempA = a;
		int tempB = b;
		int tenthPow = pow(10, power);
		while (tempA > tenthPow) {
			tempA /= 10;
		}
		while (tempB > tenthPow) {
			tempB /= 10;
		}
		double compPartA = tempA % 10;
		double compPartB = tempB % 10;
		if (a < tenthPow / 10)
			compPartA = 0.5;
		if (b < tenthPow / 10)
			compPartB = 0.5;

		if (compPartA > compPartB)
			return true;
		if (compPartA < compPartB)
			return false;
		if (compPartA == 0.5 && compPartB == 0.5)
			return false;
		power++;
	}
}
void LexSelectionSort(int* arr, int size) {
	for (size_t i = 0; i < size - 1; i++) {
		int maxJ = i;
		for (int j = i + 1; j < size; j++) {
			if (lexCompare(arr[j], arr[maxJ])) {
				maxJ = j;
			}
		}
		if (maxJ != i) {
			int temp = arr[i];
			arr[i] = arr[maxJ];
			arr[maxJ] = temp;
		}
	}
}
void coutBiggestNumberIsh(int* arr, int size) {
	LexSelectionSort(arr, size);
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
}

void task1() {
	int count;
	int grades[10000];
	std::cin >> count;
	for (size_t i = 0; i < count; i++)
	{
		std::cin >> grades[i];
	}
	coutMedians(grades, count);
	std::cout << std::endl;
}
void task2() {
	//int test[2] = { 11,110 };
	//coutBiggestNumberIsh(test, 2);
	int count;
	std::cin >> count;
	int arr[100];
	for (size_t i = 0; i < count; i++)
	{
		std::cin >> arr[i];
	}
	coutBiggestNumberIsh(arr, count);
	std::cout << std::endl;
}
void executor(int button) {
	switch (button) {
	case 1: task1(); break;
	case 2: task2(); break;
	default: std::cout << "Wrong input\n"; break;
	}
}
int main(){
	
	int button = 1;
	executor(button);
	return 0;
}
