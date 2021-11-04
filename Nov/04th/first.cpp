#include <iostream>
#include "random.h"
#include "memorymanager.h"
struct Register
{
	int base,limit;
};
void solution()
{

	int i,pid,limit,c;
	MemoryManager MM;
	MM.addProc(makeProc(0,100));
	MM.addProc(makeProc(1,80));
	MM.addProc(makeProc(2,50));
	MM.printHole();
	for(i=0;i<30;i++)
	{
		std::cout<<"1: Input 2: Output 3: Show 0: exit : ";
		std::cin>>c;
		switch(c)
		{
			case 1:
				std::cout<<"Enter PID and LIMIT :";
				std::cin>>pid>>limit;
				if(MM.addProc(makeProc(pid,limit))) std::cout<<"Input Success!\n";
				else std::cout<<"Input fail\n";
				break;
			case 2:
				std::cout<<"Enter PID :";
				std::cin>>pid;
				if(MM.subProcbypid(pid)) std::cout<<"Output Success!\n";
				else std::cout<<"Output fail\n";
			case 3:
				MM.printHole();
				break;
			case 0:
				i=30;
		}
	}
}
int main()
{
	solution();
	return 0;
}