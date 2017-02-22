#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;
class testcase
{
public:
    testcase(const char* str):casename(str){}
    virtual void Run()=0;
private:
    int testresult;
    const char* casename;
};
class unitcase
{
public:
    static unitcase* getstance();
    void Run();
    testcase* registercase(testcase *);

private:
    vector<testcase*>veclist;
    int sumcount;
};
unitcase* unitcase::getstance()
{
    static unitcase currentcase;
    return &currentcase;
}
testcase* unitcase::registercase(testcase *onecase)
{
    veclist.push_back(onecase);
    return onecase;
}
void unitcase::Run()
{
  int tempcount=1;
  for(vector<testcase*>::iterator iter=veclist.begin();iter!=veclist.end();++iter)
  {
      ++tempcount;
      testcase *current=*iter;
      current->Run();
  }
}

#define TEST_NAME(testcase1)\
        testcase##_test
#define TEST_(testcase1)\
class TEST_NAME(testcase1):public testcase\
{\
public:\
    TEST_NAME(testcase1)(const char *str):testcase(str){}\
    virtual void Run();\
private:\
    static  testcase* const testcase_;\
};\
 testcase*const TEST_NAME(testcase1)::testcase_=unitcase::getstance()->registercase(new TEST_NAME(testcase1)(#testcase1));\
void TEST_NAME(testcase1)::Run()

#define TEST(testcase1)\
        TEST_(testcase1)
TEST(one)
{

}

int CalCrc(int crc, const char *buf, int len)
{
    unsigned int byte;
    unsigned char k;
    unsigned short ACC,TOPBIT;
//    unsigned short remainder = 0x0000;
    unsigned short remainder = crc;
    TOPBIT = 0x8000;
    for (byte = 0; byte < len; ++byte)
    {
        ACC = buf[byte];
        remainder ^= (ACC <<8);
        for (k = 8; k > 0; --k)
        {
            if (remainder & TOPBIT)
            {
                remainder = (remainder << 1) ^0x8005;
            }
            else
            {
                remainder = (remainder << 1);
            }
        }
        //printf("%2x\n",remainder);
    }
    remainder=remainder^0x0000;
    return remainder;
}
int main()
{

    unsigned long long temp =0X145;
    unsigned long long topbit=0X8;
    unsigned long long remainder=0;
    for(int i=12;i>=0;i--)
    {
            unsigned long long temptest=temp>>i;
            temptest=temptest&0X1;
            remainder =remainder|temptest;
            cout<<"temptest=="<<temptest<<"       remainder=-----="<<remainder<<"   adn"<<i<<endl;

            if(remainder&topbit)
            {

                 cout<<"remainder====="<<remainder<<endl;
                 remainder = ((remainder)^0XB)&0XF;
                 remainder = remainder<<1;

            }
            else
            {
                 cout<<"real====="<<remainder<<endl;
                 remainder = remainder<<1;
                 cout<<"real====="<<remainder<<endl;
                // cout<<"remaindermax"<<remainder<<endl;

            }

    }
        cout<<remainder<<endl;
    for(int i=3;i>0;--i)
    {
        if(remainder&topbit)
        {
           cout<<"lastremainder====="<<remainder<<endl;
           remainder = ((remainder)^0XB)&0Xf;
           //remainder = ((remainder)^0X8005)&0XFFFF;
        }
         cout<<"lasst"<<remainder<<endl;
        if(i!=1)
        remainder = (remainder << 1);

    }
    cout<<remainder<<endl;




    char buffer[4] = {0x12, 0x34};
    int crc = CalCrc(0, buffer, 4);//计算得到的16位CRC校验码
    cout<<"crc=="<<crc<<endl;
//接收方在接收到buffer中的数据时，代入CalCrc进行计算，若result的值为0，则说明数据传输过程无误




    // printf("real===%2x\n",remainder);


   // unsigned long long temp = 0X10<<4;
    //temp=temp<<24;
        // printf("%2x\n",result);
    cin.get();
    return 0;
}
