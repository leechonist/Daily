#include <iostream>
#include "firstfit.h"
#include "worstfit.h"
#include "random.h"
#define RANDOM
#define WORSTFIT


struct Register
{
	int base,limit;
};
void solution()
{
	int c,percent = -2,n,i,pid=5,m;
	int* arr;
	#ifdef FIRSTFIT
	//FIRSTFIT이 define 되었다면
	MemoryManager* FF = new FirstFitClass;
	#endif
	#ifdef WORSTFIT
	//WORSTFIT이 define 되었다면
	MemoryManager* FF = new WorstFitClass;
	#endif

	Random R; //랜덤 클래스. 이하 생략
	
	//메모리 관리 클래스 초기화
	FF->addProc(makeProc(0,100));
	FF->addProc(makeProc(1,80));
	FF->addProc(makeProc(2,50));
	FF->addProc(makeProc(3,60));
	FF->addProc(makeProc(4,95));
	FF->printHole();

	//30회 반복
	for(i=0;i<30;i++)
	{
		std::cout<<"1: Input 2: Output 0: exit : ";
	#ifdef RANDOM //RANDOM이 define 되었다면 스스로 입력을 받고,
		n = R(0,9);
		if(n>=percent){ //Process를 생성하면 다음에는 Process를 삭제할 확률 증가
			percent++;
			c = 1;
		}
		else{ 
			percent--; //Process를 삭제하면 다음에는 Process를 생성할 확률 증가
			c = 2;
		}
		std::cout<<c<<std::endl;
	#endif
	#ifndef RANDOM //RANDOM이 define 되지 않았다면 사용자에게 입력을 받는다.
		std::cin>>c;
	#endif
	std::cout<<"-----------------------\n";
		switch(c)
		{
			case 1:
				std::cout<<"Enter Process LIMIT : ";
				#ifdef RANDOM
				n = R(10,100);
				std::cout<<n<<std::endl;
				#endif
				
				#ifndef RANDOM
				std::cin>>n;
				#endif

				if(FF->addProc(makeProc(pid,n))){ //프로세스 생성
					pid++;
					std::cout<<"\n+Input Success!\n";
				}
				else std::cout<<"\n-Input fail\n";
				
				FF->printHole();
				break;
			case 2:
				
				std::cout<<"-----------------------\n"<<"PID List";
				m = FF->printProcess(&arr);
				std::cout<<"Enter Pid :";
				#ifdef RANDOM
				n = R(0,m-1);
				m = arr[n];
				n=m;
				std::cout<<n<<std::endl;
				
				#endif
				
				#ifndef RANDOM
				std::cin>>n;
				#endif

				if(FF->subProcbyPID(n)) std::cout<<"\n+Output Success!\n"; //프로세스 삭제
				else std::cout<<"\n-Output fail\n";

				FF->printHole();
				break;
			case 0:
				i=30;
		}
	}
	std::cout<<"\n\nProcess Done!\n\n";
	FF->printProcess(&arr);
	FF->printHole();
	delete FF;
}
int main()
{
	solution();
	getchar();
	return 0;
}