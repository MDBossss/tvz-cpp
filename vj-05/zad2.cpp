#include <iostream>
#include <vector>


using namespace std;

template <class T>
class Komparator {
public:
	T parametar;
	Komparator(){}
	bool vece_ili_jednako(T par1, T par2) {
		return !(par1 >= par2);
	}


};

template <class P>
bool usporedi(vector<P> v, Komparator<P> p) {
	for (int i = 0; i < v.size()-1; i++) {
		if (p.vece_ili_jednako(v[i], v[i + 1])) {
			cout << "false\n";
			return false;
			break;
		}
	}
	cout << "true\n";
	return true;
}

int main() {

	vector<int> br = { 5,4,3,1,2 };
	Komparator<int> p;
	usporedi<int>(br, p);
	return 0;
}