#include <iostream>
using namespace std;

//方法2
class noncopyable
{
    public:
        noncopyable() = default;
        ~noncopyable() = default;
        noncopyable(const noncopyable&) = delete;
        noncopyable& operator=(const noncopyable&) = delete;
};

class HomeForSale : public noncopyable   // 继承于noncopyable
{
    public:
        HomeForSale() = default;
        ~HomeForSale() = default;
     
    // 该注释打开将导致无法创建对象，编译报错，构造函数必须是public属性
    // private:
    //     HomeForSale() = default;
    //     ~HomeForSale() = default;
    
    
    // 禁止拷贝和赋值操作,因为是private属性（方法1,该方法有风险，因为可以在成员函数里实现拷贝和复制）
    // 比如 copy_or_assignment_in_member_function 调用拷贝和赋值
    //private:
    //    HomeForSale(const HomeForSale&);   // 只声明
    //    HomeForSale& operator=(const HomeForSale&); //只声明

    // public:
    //     void copy_or_assignment_in_member_function()
    //     {
    //         HomeForSale hs_test_1;
    //         HomeForSale hs_test_2(hs_test_1);
    //     }
};

int main()
{
    // 方法1的测试
    //HomeForSale hs_1;
    //hs_1.copy_or_assignment_in_member_function();
    //HomeForSale hs_2(hs_1);  // 打开注释，编译报错，因为拷贝和赋值操作是私有的

    // 方法2的测试
    //HomeForSale hs_2;
    //HomeForSale hs_3(hs_2); // 取消注释，编译会报错
    return 0;
}
