#ifndef MEMORY_MANAGER_H_
#define MEMORY_MANAGER_H_
#include <iostream>
#define MEMORYSIZE 1000
struct Process
{
	int pid,base,limit;
	Process* link;
};
Process* makeProc(int aPid,int aLimit)
{
	Process* p = new Process;
	p->pid = aPid;
	p->limit = aLimit;
	p->base = 0;
	p->link = NULL;
	return p;
}
class MemoryManager
{
private:
	Process* mPrc;
	int mCount;
private:
	int get_hole(Process* aPrc = nullptr)
	{
		int hole=0;
		if(aPrc == nullptr) hole = mPrc->base;
		else if(aPrc->link == nullptr) hole = MEMORYSIZE - (aPrc->base + aPrc->limit);
		else hole = aPrc->link->base - (aPrc->base + aPrc->limit);
		
		return hole;
	}
	void addList(Process* aFront,Process* aTarget)
	{
		Process* tmp;
		if(!aFront)
		{
			tmp = mPrc;
			mPrc = aTarget;
			mPrc->link = tmp;
		}
		else
		{
			tmp = aFront->link;
			aFront->link = aTarget;
			aTarget->link = tmp;
			aTarget->base = aFront->base+aFront->limit;
		}
		mCount++;
	}
	void subList(Process* aFront,Process* aTarget)
	{
		if(mCount<1) return;
		Process* tmp;
		
		if(!aFront)
		{
			mPrc = nullptr;
			mPrc = aTarget->link;
		}
		else
		{
			tmp = aTarget;
			aFront->link = aTarget->link;
		}
		delete aTarget;
		mCount--;
	}
public:
	MemoryManager()
	{
		mPrc = nullptr;
		mCount = 0;
	}
	bool addProc(Process* aPrc) //최초 합
	{
		int hole;
		Process* tmp = mPrc;
		if(!mCount)
		{
			if(aPrc->limit < MEMORYSIZE){
				mPrc = aPrc;
				mCount++;
				return true;
			}
			return false;
		}
		hole = get_hole();
		if(hole >= aPrc->limit)
		{
			//aPrc->mPrc 삽입
			addList(nullptr,aPrc);
			mCount++;
			return true;
		}
		while(tmp!=nullptr)
		{
			hole = get_hole(tmp);
			if(hole > aPrc->limit) {
				//tmp->aPrc 삽입
				addList(tmp,aPrc);
				mCount++;
				return true;
			}
			tmp = tmp->link;
		}
		return false;
	}
	bool subProcbypid(int aPid)
	{
		Process* tmp = mPrc,*prev = nullptr;
		while(tmp!=nullptr)
		{
			if(tmp->pid == aPid) break;
			prev= tmp;
			tmp = tmp->link;
		}
		if(tmp && tmp->pid == aPid)
		{
			//tmp 제거
			subList(prev,tmp);
			mCount--;
			return true;
		}
		return false;
	}
	void printHole()
	{
		int i=i,hole=0,top;
		Process* tmp=mPrc;
		if(mCount==0)
		{
			printf("%3d ~ %3d hole : %d block\nis empty\n",0,MEMORYSIZE-1,MEMORYSIZE);
			return;
		}
		if((hole=get_hole())>0) printf("%3d ~ %3d hole : %d block\n",0,mPrc->base-1,hole);
		while(tmp)
		{
			top = tmp->link==nullptr ? MEMORYSIZE:tmp->link->base;
			if((hole=get_hole(tmp))>0) printf("%3d ~ %3d hole : %d block\n",tmp->base+tmp->limit,top-1,hole);			
			tmp = tmp->link;
		}
	}
};
#endif

