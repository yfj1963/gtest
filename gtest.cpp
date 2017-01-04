#include<iostream>
#include<vector>
#include<string>
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
													   int main()
													   {

													       cin.get();
													           return 0;
														   }

