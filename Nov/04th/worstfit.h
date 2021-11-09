#include "memorymanager.h"

class WorstFitClass : public MemoryManager
{
private: 
    void printLabel()
    {
        std::cout<<"Worst Fit Memory's Hole : \n";
    }
protected:
    Process* getSaveHole(int aLimit) //가장 큰 구멍 앞에있는 프로세스 return
    {
        Process* maxPrc,*tmp=mPrc;
        int hole,maxHole;

        maxHole = get_hole();
        maxPrc = nullptr;
        while(tmp)
        {
            hole = get_hole(tmp);
            if(hole > maxHole)
            {
                maxHole = hole;
                maxPrc = tmp;
            }
            tmp = tmp->link;
        }

        return maxPrc;        
    }
public:
    WorstFitClass(){}
};