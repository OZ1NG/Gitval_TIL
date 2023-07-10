#include <iostream>

using namespace std;

class Test { // Test Class 정의
public:		 // class 내 멤버 변수 및 함수 선언
        int a;	
        int b;
    	int c;
        int Test_calc1(); // 멤버 함수 선언
    	int Test_calc2(){ // 멤버 함수 선언 및 정의
    		return a-b;
        }
    	void set_c(int c);
};	// ";"세미콜론으로 끝남. (구조체와 같음)

int Test::Test_calc1(){	// class 내 객체 함수 정의
        return a+b;
}

void Test::set_c(int c){
	this->c = c;		// this 사용
}

int main(){
        Test test_class;	// Test class 정의
        test_class.a = 1;	// "."으로 멤버 변수에 접근
        test_class.b = 2;

    	// 새로 입력받음
        cin >> test_class.a; 
        cin >> test_class.b; 

        cout << test_class.Test_calc1() << endl;	  // "."으로 멤버 함수에 접근
		cout << test_class.Test_calc2() << endl;      // "."으로 멤버 함수에 접근

        return 0;
}
