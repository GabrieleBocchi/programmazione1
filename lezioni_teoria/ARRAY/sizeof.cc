#include <iostream>

using namespace std;

void test_sizeof(int arr[10], int n) {
		cout << "Inside test_sizeof" << endl;
		cout << "A = sizeof(arr) = " << sizeof(arr) << endl;
		cout << "    sizeof(int*) = " << sizeof(int *) << endl;
		cout << "B = sizeof(int) = " << sizeof(int) << endl;
		cout << "A/B = " << sizeof(arr)/sizeof(int) << endl;
}

int main() {
		int test[10];
		cout << "Inside main" << endl;
		cout << "A = sizeof(test) = " << sizeof(test) << endl;
		cout << "    sizeof(int*) = " << sizeof(int *) << endl;
		cout << "B = sizeof(test) = " << sizeof(int) << endl;
		cout << "A/B = " << sizeof(test)/sizeof(int) << endl;
		cout << "==========================" << endl;
		test_sizeof(test, 10);
}
