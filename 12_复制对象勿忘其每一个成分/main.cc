#include <iostream>
using namespace std;

class Base
{
    public:
	explicit Base(const string& name):
			name_(name)
	{}
	
	~Base()
	{}
	
	Base(const Base& base):
		name_(base.name_)
	{
		cout <<"Base 拷贝构造函数" <<endl;
		//name_ = base.name_;
	}
	
	Base& operator=(const Base& base)
	{
		cout <<"Base 赋值运算符"<<endl;
		if(this == &base)
			return *this;
		name_ = base.name_;
		return *this;
	}
	
	void print_1()
	{
		cout <<"name_ = " <<name_ <<endl;
	}
	
    private:
    	string name_;
};

class Sun : public Base
{
    public:
    	explicit Sun(int num, const string& name = "Base"):
    			Base(name),
    			num_(num)
    	{}
    	
    	~Sun()
    	{}
    	
    	Sun(const Sun& sun):
    		Base(sun), //不添加这一行，编译会报错
    		num_(sun.num_)
    	{
    
    	}
    	
    	Sun& operator=(const Sun& sun)
    	{
    		if(this == &sun)
    			return *this;
    		Base::operator=(sun); // 不添加这一行，编译不会报错,但会导致赋值不完全
    		num_ = sun.num_;
    		return *this;
    	}
    	
    	
    	void print_2()
    	{
    		cout <<"num_  = " << num_ <<endl;

    	}
    	
    private:
    	int num_;
};

int main()
{
	/*
	Sun sun_1(1, "base_1");
	Sun sun_2(2, "base_2");
	sun_1 = sun_2;
	sun_1.print_1();
	sun_1.print_2();
	
	Sun sun(sun_1);
	sun.print_1();
	sun.print_2();
	*/
	
	Sun sun_1(1);
	Sun sun_2(2, "base_2");
	sun_1 = sun_2;
	sun_1.print_1();
	sun_1.print_2();
	return 0;
	
}
