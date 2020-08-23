#ifndef MODEL
#define MODEL
#include <string.h>

/// <summary>
/// ��ѡ������
/// </summary>
typedef struct
{
	char name[80]; 
}CandidateKey;

/// <summary>
/// ��ʤ����Ϣ
/// </summary>
typedef struct
{
	size_t count; // ��ʤ������
	int index[9]; // ��ʤ���±�
	const char* name[9]; // ��ʤ������
}WinnerInfo;

/// <summary>
/// ��ȡname��array�ж�Ӧ���±�
/// </summary>
/// <param name="array">��ѡ������</param>
/// <param name="name">��Ҫ��ȡ�±��name</param>
/// <param name="count">��ѡ������</param>
/// <returns>��name�����򷵻ض�Ӧ���±꣬���򷵻�-1</returns>
int GetKeyIndex(CandidateKey* array, const char* name, int count);

#endif
