//
// Created by zhjwang on 2021-02-12.
//

#include <iostream>
#include <string>

//string构造
/*
 * 1. sring() //构造一个口弄个的字符串
 * 2. string(const string &str) //构造一个与str一样的string。如string s1(s2)。
 * 3. string(const char *s);    //用字符串s初始化
 * 4. string(int n,char c);    //用n个字符c初始化
 * */
void main01()
{
    std::string s1 = "123";
    std::string s2("456");
    std::string s3(s1);
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;
}
//遍历
void main02()
{
    std::string s1 = "abcdef";
    //数组方式
    std::cout << "数组方式：" << std::endl;
    for(int i = 0; i < s1.length(); i++) {
        std::cout << s1[i] ;
    }
    std::cout << std::endl;

    //迭代器
    std::cout << "迭代器方式：" << std::endl;
    for(std::string::iterator it = s1.begin(); it != s1.end(); ++it) {
        std::cout << *it ;
    }
    std::cout << std::endl;

    //at方式
    /*
     * at方式和[]方式的最大区别在于，at在访问出错的时候，可以跑出异常。[]会直接导致系统崩溃
     * 如果您希望通过try,catch捕获异常，建议使用at
     * */
    std::cout << "at方式：" << std::endl;
    for(int i = 0; i < s1.length(); i++) {
        std::cout << s1.at(i) ;
    }
    std::cout << std::endl;
}

//字符指针和string的转换
void main03() {
    std::string s1 = "aaabbb";
    //c_str返回一个以'\0'结尾的字符串的首地址
    printf("s1:%s\n", s1.c_str());  //s1 => char *

    //s1的内容copy到buf中
    //把当前串中以pos开始的n个字符拷贝到以s为起始位置的字符数组中，
    //返回实际拷贝的数目。注意要保证s所指向的空间足够大以容纳当前字符串，不然会越界。
    char buf1[128] = {0};
    s1.copy(buf1,3,0);  //只拷贝3个字符，不会加\0
    std::cout << buf1 <<std::endl;
}

//拼接
void main04()
{
    std::string s1 = "aa";
    std::string s2 = "bbb";
    std::string s3 = s1 + s2;
    std::string s4 = s1.append(s3);
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
}

//查找替换
/*
 * 1. int find(char c,int pos=0) const;  //从pos开始查找字符c在当前字符串的位置
 * 2. int find(const char *s, int pos=0) const;  //从pos开始查找字符串s在当前字符串的位置
 * 3. int find(const string &s, int pos=0) const;  //从pos开始查找字符串s在当前字符串中的位置
 * 如果找不到就返回-1
 * 1. int rfind(char c, int pos=npos) const;   //从pos开始从后向前查找字符c在当前字符串中的位置
 * 2. int rfind(const char *s, int pos=npos) const;
 * 3. int rfind(const string &s, int pos=npos) const;
 * r表示return，反向查找。找不到就返回-1
 * */
void main05()
{
    std::string s1 = "wzj hell0 wzj 111 wzj 222 wzj 333";
    size_t  index = s1.find("wzj",0);
    std::cout << index << std::endl;  //0

    //求wzj出现的次数
    size_t  offindex = s1.find("wzj", 0);
    while(offindex != std::string::npos)
    {
        std::cout << "在下标index:" << offindex << "找到wzj\n";
        offindex = offindex + 1;
        offindex = s1.find("wzj", offindex);
    }
    //替换
    s1.replace(0,3,"zxn"); //zxn hell0 wzj 111 wzj 222 wzj 333
    std::cout << "replace:" << s1 << std::endl;

    //替换大小写
    offindex = s1.find("wzj", 0);
    while(offindex != std::string::npos)
    {
        std::cout << "在下标index:" << offindex << "找到wzj\n";
        s1.replace(offindex,3,"WZJ");
        offindex = offindex + 1;
        offindex = s1.find("wzj", offindex);
    }
    std::cout << "replace大写:" << s1 << std::endl;
}

int main(){
//    main01();
//    main02();
//    main03();
//    main04();
    main05();
    std::cout << "hello world" << std::endl;
    return 0;
}