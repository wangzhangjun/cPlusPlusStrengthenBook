//
// Created by zhjwang on 2021-02-13.
//
#include <iostream>
#include <string>
#include <vector>

void main09()
{
    std::vector<int> v1;
    std::cout << v1.size() << std::endl; //0
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    std::cout << v1.size() << std::endl; //3

    std::cout << "头部元素：" << v1.front() << std::endl; //获取头部元素
    v1.front() = 11;//修改头部元素， 函数返回值当左值，应该返回一个引用

    while(v1.size() > 0) {
        std::cout << v1.back() << std::endl; //获取尾部元素
        v1.pop_back(); //删除尾部元素
    }
}

//vector的初始化
void main10()
{
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(7);

    std::vector<int> v2 = v1; //对象初始化

    std::vector<int> v3(v1.begin(), v1.begin()+2);
}

void main11()
{
    std::vector<int> v1(10);
    for(int i = 0; i < 10; i++)
    {
        //如果要通过等号的方式赋值的话，
        //必须要声明v1的大小，否则会报错： std::vector<int> v1(10)
        v1[i] = i + 1;
    }
    for(int i = 0; i< 10; i++) {
        std::cout << v1[i] << std::endl;
    }
}

int main()
{
    //main09();
    main11();
    return 0;
}
