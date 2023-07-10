#include <iostream>

using namespace std;

class Test{
private:
    int a;
    void Test_private(){
        a = 1;
    }
public:
    Test(){		// 생성자
        this->a = 0;
    }
    void Test_public(){ // 내부에서 자기 자신을 선언
        Test inter_test;
        cout << "Inter_Test Class a : " << inter_test.a << endl;
        inter_test.a = 100; 	// private 변수 a에 직접 접근
        cout << "Inter_Test Class a : " << inter_test.a << endl;
        inter_test.Test_private(); 	// private 함수 Test_f에 직접 접근
        cout << "Inter_Test Class a : " << inter_test.a << endl;
    }
};

int main(){
    Test test;
    test.Test_public();
    
    return 0;
}
