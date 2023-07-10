#include <iostream>

using namespace std;

class Test{
public:
	~Test();
};

Test::~Test(){
	cout << "Called Destructor!" << endl;
}

int main(){
	Test test;

	return 0;
}
