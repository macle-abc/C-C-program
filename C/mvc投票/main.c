#include "control.h"
#include "view.h"

int main(int argc, const char* argv[])
{
	// �������в����л�ȡ��ѡ������
	CandidateKey* array = CheckValidityCandidates(argc, argv);
	if (!array)
		return -1;
	// ��ӡ������Ϣ
	PrintDesigner("xxx", "xxx");
	// ��ȡͶƱ����
	int voters = GetVotersCount();
	size_t* candidateVotes = (size_t*)malloc(sizeof(size_t) * (argc - 1));
	if (!candidateVotes)
	{
		PrintError("Malloc Error!", true);
	}
	memset(candidateVotes, 0, sizeof(size_t) * (argc - 1));
	// ͶƱ�׶�
	for (int i = 0; i != voters; ++i)
	{
		printf("Vote:");
		char name[80] = { 0 };
		fgets(name, 80, stdin);
		name[strlen(name) - 1] = 0;
		Vote(array, candidateVotes, name, argc - 1);
	}
	// ��ȡ��ʤ����Ϣ����ӡ���
	WinnerInfo winnerinfo = GetWinnerInfo(array, candidateVotes, argc - 1);
	PrintWinner(winnerinfo);
	free(array);
	free(candidateVotes);
	candidateVotes = NULL;
	array = NULL;
	return 0;
}