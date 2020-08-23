#pragma once
#include "PCB.h"
#include <list>
#include <vector>
#include <map>
#include <utility>
#include <cmath>

using std::list;
using std::map;
using std::vector;
using std::pair;
using std::make_pair;

class Schedule
{
private:
	//˽��key����
	class Key
	{
	public:
		uint16_t m_pid;
		clock_t m_remainingTime;
		Key(uint16_t pid = 0, clock_t remainingTime = 0) :
			m_pid(pid), m_remainingTime(remainingTime) { }

		//����operator <
		friend bool operator<(const Key& left, const Key& right)
		{
			return left.m_remainingTime < right.m_remainingTime;
		}
	};
private:
	uint8_t m_cpuNums = 0;//�߼���������Ŀ
	uint8_t m_resourceNums = 0; //��Դ��Ŀ
	uint8_t m_AvailableResourceNum = 0; //��ʹ����Դ��
	uint8_t m_AvailableCPUNum = 0; //��ʹ��CPU��Դ��
	//��������
	map<Key, pair<PCB, bool>> m_readyQueue;
	list<pair<PCB, bool>> m_runningProcess;
	//�ȴ�����
	list<pair<PCB, bool>> m_waitQueue;
public:

	void clear(); //������ж���

	Schedule(uint8_t cpuNums = 1, uint8_t resourceNums = 1);
	Schedule(const Schedule& other) = delete;
	Schedule(Schedule&& other) = delete;
	Schedule& operator=(Schedule&& pcb) = delete;
	Schedule& operator=(const Schedule& pcb) = delete;

	void Running(uint8_t possibilityOfSeizingResources);
	//��ӽ��̵���������
	void AddProcessToReadyQueue(PCB&& process);

	//�����̴Ӿ��������ƶ�������̬
	void ReadyToRunning();
	//�����̴�����̬�ƶ����ȴ�����
	void RunningToWait(pair<PCB, bool>&& pcbInfo);
	//�����̴�����̬�ƶ�����������
	void RunningToEnd();
	//�����̴ӵȴ������ƶ�����������
	void WaitToReady();
	//��ֹ��ǰ���н���
	bool KillRunning(uint16_t pid);

	//�����������еĽ�����Ϣ
	inline const list<pair<PCB, bool>>& GetRunningProcess() const { return m_runningProcess; }
	//���ؾ���������Ϣ
	inline const map<Key, pair<PCB, bool>>& GetReadyQueue() const { return m_readyQueue; }
	//���صȴ�������Ϣ
	inline const list<pair<PCB, bool>>& GetWaitQueue() const { return m_waitQueue; }
	inline int GetCPUNums() const { return m_cpuNums; }
	inline int GetAvailableCPUNums() const { return m_AvailableCPUNum; }
	inline int GetResourceNums() const { return m_resourceNums; }
	inline int GetAvailableResourceNums() const { return m_AvailableResourceNum; }
	//uint8_t m_cpuNums = 0;//�߼���������Ŀ
	//uint8_t m_resourceNums = 0; //��Դ��Ŀ
	//uint8_t m_AvailableResourceNum = 0; //��ʹ����Դ��
	//uint8_t m_AvailableCPUNum = 0; //��ʹ��CPU��Դ��
};
