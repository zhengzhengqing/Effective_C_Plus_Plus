#include <iostream>
using namespace std;

class Rational
{
    public:
        explicit Rational(int value):value_(value)
        {}
        
        ~Rational()
        {}
        
        Rational& operator=(const Rational & ra)
        {
            value_ = ra.value_;
            return *this;
        }
  
  	const Rational operator*(const Rational & lhs)  // const Rational& rhs
  	{
  	  cout <<"value_ = " <<value_ <<endl;
  	  cout <<"lhs.value_ = " <<lhs.value_ <<endl;
  	  Rational tem(value_ * lhs.value_);
  	  return tem;
  	}
  	
    private:
        int value_;
};

int main()
{

	// 如果关键字const出现在*号的左边，表示被指向的物是常量
	// 如果出现*号的右边，表示指针自身是常量，
	// 如果出现在*号两边，表示被指物和指针两者都是常量
	char greeting[] = "Hello"; 
	char *p_1 = greeting;             // non-const pointer, non-const data
	const char *p_2 = greeting;       // non-const pointer, const data
	char* const p_3 = greeting;       // const pointer, non-const data
	const char* const p_4 = greeting; // const pointer, const data
	
	
	Rational a(2);
	Rational b(4);
	Rational c(6);
	
	//(a * b) = c; // 该行会报错，因为运算符*返回的const类型的变量，不允许修改
	
	
	
	
	
	
	return 0;
}
