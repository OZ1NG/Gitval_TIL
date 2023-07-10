#include <iostream>

using namespace std;

class Test{
public:
	int real_a;
	Test();
	Test(int a);
};

Test::Test(){
	real_a = 1;
	cout << "Test():real_a : " << real_a << endl; 
}

Test::Test(int a){
    real_a = a;
    cout << "Test(int a):real_a : " << real_a << endl;
}

int main(){

	Test test1;
	Test test2(2);

	return 0;

}



















