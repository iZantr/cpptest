#include <iostream>
using namespace std;
class IntArray {
private:
	int size{ 0 };
	int* data{ nullptr };

public:
	IntArray(int s): size{s}, data{new int [s]{}}{}
	IntArray(const IntArray& other) :size(other.size), data{ new int[other.size] } {
		for (int i = 0; i < size; i++) data[i] = other.data[i];
		cout << "deep copy coppied: " << data << "\n";
	}
	~IntArray() { delete[] data; }

	IntArray& set(int idx, int val) {
		if (idx >= 0 && idx < size) data[idx] = val;
		return *this;
	}
	void print(string label) const {
		cout << label << "\n";
		for (int i = 0; i < size; ++i) {
			cout << data[i];
			cout << "\n";

		}
	}
};

int main() {
	IntArray arr1(3);
	arr1.set(0, 10).set(1, 20).set(2, 30);
	IntArray arr2 = arr1;
	arr2.set(0, 999);
	arr1.print("original: ");
	arr2.print("copy: ");
}