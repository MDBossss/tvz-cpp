#include <iostream>
using namespace std;

class TimeSpan {
public:
	int h, m, s;
	TimeSpan(int _h, int _m, int _s) :h(_h), m(_m), s(_s) {

	}
	TimeSpan operator +(TimeSpan&& a) {
		int temp1 = 0, temp2 = 0;
		temp1 = s + m * 60 + h * 3600;
		temp2 = a.s + a.m * 60 + a.h * 3600;
		for (int i = 0; i < temp2; i++)
		{
			if (s < 59) {
				s++;
			}
			else if (s == 59) {
				s = 0;
				if (m < 59) {
					m++;
				}
				else if (m == 59) {
					m = 0;
					h++;
				}
			}
		}
		return *this;
	}
	operator int() const {
		return s + m * 60 + h * 3600;

	}
};
bool operator<(TimeSpan a, TimeSpan b) {
	int temp1 = 0, temp2 = 0;
	temp1 = a.s + a.m * 60 + a.h * 3600;
	temp2 = b.s + b.m * 60 + b.h * 3600;
	if (temp1 < temp2)
	{
		return 1;
	}
	else return 0;
}
bool operator==(TimeSpan a, TimeSpan&& b) {
	int temp1 = 0, temp2 = 0;
	temp1 = a.s + a.m * 60 + a.h * 3600;
	temp2 = b.s + b.m * 60 + b.h * 3600;
	if (temp1 == temp2) return 1;
	else return 0;
}
ostream& operator<<(ostream& izlaz, const TimeSpan& vrijeme) {
	izlaz << vrijeme.h << ":" << vrijeme.m << ":" << vrijeme.s << endl;
	return izlaz;
}
int main() {


	TimeSpan a(1, 0, 0);
	TimeSpan x(24, 0, 0);

	while (a < x)
	{
		if (a == TimeSpan(1, 0, 0))
			a = a + TimeSpan(10, 6, 7);
		else if (a < TimeSpan(12, 0, 0))
			a = a + TimeSpan(0, 37, 14);
		else
			a = a + TimeSpan(9, 11, 57);

		cout << a;

	}

	cout << "Ukupno sekundi: " << (int)a << endl;

	return 0;

}