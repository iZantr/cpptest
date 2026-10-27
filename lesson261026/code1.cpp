#include <iostream>
using namespace std;
class Rectangle {
private:
	double width;
	double height;
public:
	double getArea() {
		return width * height;
	}
	double getPerimeter() {
		return 2.0 * (width + height);
	}
};
