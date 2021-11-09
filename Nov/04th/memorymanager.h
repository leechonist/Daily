#ifndef MEMORY_MANAGER_H_
#define MEMORY_MANAGER_H_
#include <iostream>
#define MEMORYSIZE 1000
struct Process
{
	int base,limit,pid;
	Process* link;
};
Process* makeProc(int aPid, int aLimit)
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
protected:
	Process* mPrc;	//프로세스 연결리스트
	int mCount;		//프로세스 개수
	int get_hole(Process* aPrc = nullptr) //프로세스 뒤에 있는 빈공간의 크기 반환
	{
		int hole=0;
		if(aPrc == nullptr) hole = mPrc->base; //맨 앞의 구멍 크기 = 맨 앞의 위치 - 0
		else if(aPrc->link == nullptr) hole = MEMORYSIZE - (aPrc->base + aPrc->limit); //맨 뒤의 구멍 크기 = 메모리 최대 크기 - (맨 뒤의 위치 + 맨 뒤의 크기)
		else hole = aPrc->link->base - (aPrc->base + aPrc->limit); //중간의 구멍 크기 = 뒤 프로세스의 위치 - (앞 프로세스의 크기 + 앞 프로세스의 위치)
		
		return hole;
	}
	virtual Process* getSaveHole(int) = 0;

private:
	void addList(Process* aFront,Process* aTarget) //연결리스트에 프로세스 저장
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
	void subList(Process* aFront,Process* aTarget) //연결리스트에 프로세스 삭제
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
	virtual void printLabel() = 0;
public:
	MemoryManager()
	{
		mPrc = nullptr;
		mCount = 0;
	}
	~MemoryManager()
	{
		Process* tmp = mPrc,*del;
		while(tmp)
		{
			del = tmp;
			tmp = tmp->link;
			delete del;
		}
	}
	bool addProc(Process* aPrc) //프로세스 저장
	{
		int hole;
		Process* tmp;
		if(!mCount) //비어있을 경우
		{
			if(aPrc->limit < MEMORYSIZE){
				mPrc = aPrc;
				mCount++;
				return true;
			}
			return false;
		} 
		
		tmp = getSaveHole(aPrc->limit);
		hole = get_hole(tmp);
		if(hole >= aPrc->limit) //빈 구멍이 프로세스보다 큰 경우
		{
			addList(tmp,aPrc);
			mCount++;
			return true;
		}

		return false;
	}
	bool subProcbyPID(int aPid) //프로세스 아이디로 프로세스 삭제
	{
		Process* front=nullptr, *target=mPrc;
		while(target && (target->pid != aPid))
		{
			front = target;
			target = target->link;
		}
		if(!target) return false; //프로세스 아이디가 존재하지 않다면
		subList(front,target);
		return true;
	}
	void printHole() //빈공간 출력
	{
		int i=i,hole=0,top;
		std::cout<<"-----------------------\n";
		printLabel();
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
	int printProcess(int** aArr) //프로세스 아이디, 크기 출력 & 프로세스 아이디 목록과 프로세스 개수를 가져옴
	{
		int i=0;
		Process* tmp = mPrc;
		if(aArr) delete aArr; //배열이 비어있지 않으면 삭제
		(*aArr) = new int[mCount];
		
		while(tmp)
		{
			(*aArr)[i++]=tmp->pid;
			std::cout<<"Process : "<<tmp->pid<<" ,Limit : "<<tmp->limit<<std::endl;
			tmp= tmp->link;
		}
		return i;
	}
};
#endif

