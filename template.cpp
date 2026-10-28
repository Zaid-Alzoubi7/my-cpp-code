#include <iostream>
using namespace std;
template <class eletype>
class T {
	eletype x, y;
public:
	T() {
		x = 0;y = 0;
	}
	T(eletype a, eletype b) {
		x = a;y = b;
	}
	eletype sum() {
		return x + y;
	}
};
int main() {
	T<double> t1(5.5, 3.6);
	T<int> t2(5, 6);
	cout<< t1.sum()<<endl;
	cout << t2.sum();
}
