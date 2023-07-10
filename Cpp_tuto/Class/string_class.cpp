#include <iostream>
#include <string>

using namespace std;

class Test {
public:
        string a;
        string b;
        string Test_calc();
};

string Test::Test_calc(){
        return a+b;
}

int main(){

        Test test_class;

        cin >> test_class.a;
        cin >> test_class.b;

        cout << test_class.Test_calc() << endl;

        return 0;
}
