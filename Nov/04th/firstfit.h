#include "memorymanager.h"

class FirstFitClass : public MemoryManager
{
private: 
    void printLabel()
    {
        std::cout<<"First Fit Memory's Hole : \n";
    }
protected:
    Process* getSaveHole(int aLimit) //입력받은 크기보다 크거나 같은 구멍을 발견하면 바로 return
    {
        Process* tmp=mPrc;
        int hole;
        hole = get_hole();
		if(hole >= aLimit)
		{
			return nullptr;
		}
		while(tmp!=nullptr)
		{
			hole = get_hole(tmp);
			if(hole >= aLimit) {
				return tmp;
			}
			tmp = tmp->link;
		}
        return nullptr;
    }
public:
    FirstFitClass(){}
};