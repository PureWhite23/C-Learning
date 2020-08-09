#include<iostream>

using namespace std;

class CPU
{
public:
	virtual void calc() = 0;

};

class GPU
{
public:
	virtual void draw() = 0;

};

class MemoryCard
{
public:
	virtual void storage() = 0;

};

class Computer
{
public:
	Computer(CPU *cpu, GPU *gpu, MemoryCard *memoryCard)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_memoryCard = memoryCard;
	}
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}
		if (m_memoryCard != NULL)
		{
			delete m_memoryCard;
			m_memoryCard = NULL;
		}
	}
	void doWork();

private:
	CPU *m_cpu;
	GPU *m_gpu;
	MemoryCard * m_memoryCard;

};

void Computer::doWork()
{
	m_cpu->calc();
	m_gpu->draw();
	m_memoryCard->storage();

}

class IntelCPU : public CPU
{
public:
	virtual void calc()
	{
		cout << "��װIntelCPU" << endl;
	}
};

class AMDCPU : public CPU
{
public:
	virtual void calc()
	{
		cout << "��װAMDCPU" << endl;
	}
};

class NvidiaGPU : public GPU
{
public:
	virtual void draw()
	{
		cout << "��װNvidia�Կ�" << endl;
	}
};

class AMDGPU : public GPU
{
public:
	virtual void storage()
	{
		cout << "��װAMD�Կ�" << endl;
	}
};

class SamsungMemoryCard : public MemoryCard
{
public:
	virtual void storage()
	{
		cout << "��װSamSung�ڴ���" << endl;
	}
};

class KingstonMemoryCard : public MemoryCard
{
public:
	virtual void draw()
	{
		cout << "��װKingston�ڴ���" << endl;
	}
};
int main() 
{
	CPU *intelCpu = new IntelCPU;
	GPU *nvidiaGpu = new NvidiaGPU;
	MemoryCard *memoryCard = new SamsungMemoryCard;

	Computer *computer1 = new Computer(intelCpu,nvidiaGpu,memoryCard);

	computer1->doWork();
	delete computer1;

	system("pause");
	return 0;
}