#ifndef CONTROL
#define CONTROL
#include "model.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/// <summary>
/// ��ӡ������Ϣ�������Ƿ��˳�����
/// </summary>
/// <param name="error">������Ϣ</param>
/// <param name="isExit">�Ƿ��˳�����</param>
void PrintError(const char* error, bool isExit);

/// <summary>
/// ����ѡ����Ч��
/// </summary>
/// <param name="argc">main��argc</param>
/// <param name="argv">main��argv</param>
/// <returns>�����Ч�򷵻غ�ѡ����Ŀ�������������򷵻�NULL</returns>
CandidateKey* CheckValidityCandidates(int argc, const char* argv[]);

/// <summary>
/// ���ͶƱ������Ч��
/// </summary>
/// <param name="number">�����ͶƱ����</param>
/// <returns>�Ƿ���Ч</returns>
bool CheckValidityVoters(int number);

/// <summary>
/// ��ȡͶƱ����
/// </summary>
/// <returns>�Ϸ���ͶƱ����</returns>
int GetVotersCount();

/// <summary>
/// ��array��Ѱ��name���±꣬Ȼ����ݸ��±���������Ӧ��candidateVotes�У��Ӷ�����ͶƱ
/// </summary>
/// <param name="array">��ѡ����Ϣ</param>
/// <param name="candidateVotes">��ѡ�˵�Ʊ���</param>
/// <param name="name">ͶƱ����ѡ�˵�����</param>
/// <param name="count">��ѡ������</param>
void Vote(CandidateKey* array, size_t* candidateVotes, const char* name, size_t count);



/// <summary>
/// ���ȴ�candidateVotes�л�ȡ���Ʊ�����±꣬Ȼ����ݸ��±��ȡarray�е�name��Ϣ���Ӷ���ȡ����ʤ����Ϣ
/// </summary>
/// <param name="array">��ѡ����Ϣ</param>
/// <param name="candidateVotes">��ѡ�˵�Ʊ���</param>
/// <param name="count">��ѡ������</param>
/// <returns>��ʤ����Ϣ</returns>
WinnerInfo GetWinnerInfo(CandidateKey* array, size_t* candidateVotes, size_t count);

#endif