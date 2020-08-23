#include "head_game.h"
void show(unsigned int game[][N])
{
	int low, column;

	for (low = 0; low < N; low++)
	{
		for (column = 0; column < N; column++)
			if (game[low][column] != '.')//�����Ѹ������ӡ������
				printf("%9u", game[low][column]);
			else//����δ�������ӡ'.'
				printf("%9c", game[low][column]);
		printf("\n\n");
	}
}
void game_rand(unsigned int game[][N])
{
	int low_rand, column_rand, result_rand;//low_rand���������column_rand���������result_rand�������

	while (1)
	{
		result_rand = (rand() % 4)> 2 ? 4 : 2;//���ó���2�ļ���Ϊ4������
		low_rand = rand() % 4;//�������
		column_rand = rand() % 4;//�������
		if ('.' == game[low_rand][column_rand])//����δ��������Ϊ��ʼֵ.
		{
			game[low_rand][column_rand] = result_rand;//�����ֵ�2��4�����ֵ��4*4������Ԫ��
			break;
		}
	}
}
int check(unsigned int game[][N])
{
	int low, column;
	for (low = 0; low < N; low++)
		for (column = 0; column < N; column++)
			if (game[low][column] == '.')//������Ϊ��ʼֵ.�������Ϸ
				return 1;
			else
			{
				if (low == 0 && column == 0)//���Ͻ�����
					if (game[low][column] == game[low][column + 1] || game[low][column] == game[low + 1][column])//����֮�����ݴ�����ͬ�������Ϸ
						return 1;
				if (low == 0 && column == N - 1)//���Ͻ�����
					if (game[low][column] == game[low][column - 1] || game[low][column] == game[low + 1][column])//����֮�����ݴ�����ͬ�������Ϸ
						return 1;
				if (low == N - 1 && column == 0)//���½�����
					if (game[low][column] == game[low - 1][column] || game[low][column] == game[low][column + 1])//����֮�����ݴ�����ͬ�������Ϸ
						return 1;
				if (low == N - 1 && column == N - 1)//���½�����
					if (game[low][column] == game[low - 1][column] || game[low][column] == game[low][column - 1])//����֮�����ݴ�����ͬ�������Ϸ
						return 1;
				if (low == 0 && (column != 0 && column != N - 1))//��һ������
					if (game[low][column] == game[low][column - 1] || game[low][column] == game[low][column + 1] || game[low][column] == game[low + 1][column])//����֮�����ݴ�����ͬ�������Ϸ
						return 1;
				if (low == N - 1 && (column != 0 && column != N - 1))//���һ������
					if (game[low][column] == game[low][column - 1] || game[low][column] == game[low][column + 1] || game[low][column] == game[low - 1][column])//����֮�����ݴ�����ͬ�������Ϸ
						return 1;
				if ((low != 0 && low != N - 1) && column == 0)//��һ������
					if (game[low][column] == game[low + 1][column] || game[low][column] == game[low - 1][column] || game[low][column] == game[low][column + 1])//����֮�����ݴ�����ͬ�������Ϸ
						return 1;
				if ((low != 0 && low != N - 1) && column == N - 1)//���һ������
					if (game[low][column] == game[low + 1][column] || game[low][column] == game[low - 1][column] || game[low][column] == game[low][column - 1])//����֮�����ݴ�����ͬ�������Ϸ
						return 1;
				if (low != 0 && low != N - 1 && column != 0 && column != N - 1)//�м�����
					if (game[low][column] == game[low + 1][column] || game[low][column] == game[low - 1][column] || game[low][column] == game[low][column - 1] || game[low][column] == game[low][column + 1])//����֮�����ݴ�����ͬ�������Ϸ
						return 1;
			}
	return 0;//��������Ԫ����Ϊ����1��˵����Ϸ����
}
void move_up(unsigned int game[][N], long double * p, long double * s)
{
	int low, column, low_new;//low��columnΪԭʼ���ݵ����У�low_newΪ��������

	for (column = 0; column < N; column++)
		for (low = 0; low < N - 1; low++)
			if ('.' == game[low][column])//ԭʼ����δ�仯
			{
				for (low_new = low + 1; low_new < N; low_new++)
				{
					if (game[low_new][column] != '.')//�������Ѿ��仯
					{
						//�������ݴ���ԭʼ����
						game[low][column] = game[low_new][column];
						game[low_new][column] = '.';
						break;//����ѭ��
					}
				}
			}
			else	//ԭʼ�����Ѿ��仯��Ϊ'.'
			{
				for (low_new = low + 1; low_new < N; low_new++)
					if (game[low_new][column] != '.')//�������Ѿ��仯
					{
						if (game[low][column] == game[low_new][column])//���ݿ��ۼ����
						{
							game[low][column] += game[low][column];
							game[low_new][column] = '.';
							*p = (double)game[low][column];
							*s = *s + *p;
						}
						else//���ݲ����ۼ����
						{
							if (low_new - low != 1)//��������ԭ���ݼ����Ϊ1ʱ�����ƶ�
							{
								game[low + 1][column] = game[low_new][column];
								game[low_new][column] = '.';
							}
						}
						break;//����ѭ��
					}
			}
}
void move_down(unsigned int game[][N], long double * p, long double * s)
{
	int low, column, low_new;//low��columnΪԭʼ���ݵ����У�low_newΪ��������

	for (column = 0; column < N; column++)
		for (low = N - 1; low > 0; low--)
			if ('.' == game[low][column])//ԭʼ����δ�仯
			{
				for (low_new = low - 1; low_new >= 0; low_new--)
				{
					if (game[low_new][column] != '.')//�������Ѿ��仯
					{
						//�������ݴ���ԭʼ����
						game[low][column] = game[low_new][column];
						game[low_new][column] = '.';
						break;//����ѭ��
					}
				}
			}
			else	//ԭʼ�����Ѿ��仯��Ϊ'.'
			{
				for (low_new = low - 1; low_new >= 0; low_new--)
					if (game[low_new][column] != '.')//�������Ѿ��仯
					{
						if (game[low][column] == game[low_new][column])//���ݿ��ۼ����
						{
							game[low][column] += game[low][column];
							game[low_new][column] = '.';
							*p = (double)game[low][column];
							*s = *s + *p;
						}
						else//���ݲ����ۼ����
						{
							if (low - low_new != 1)//��������ԭ���ݼ����Ϊ1ʱ�����ƶ�
							{
								game[low - 1][column] = game[low_new][column];
								game[low_new][column] = '.';
							}
						}
						break;//����ѭ��
					}
			}
}
void move_left(unsigned int game[][N], long double * p, long double * s)
{
	int column, low, column_new;//low��columnΪԭʼ���ݵ����У�column_newΪ��������

	for (low = 0; low < N; low++)
		for (column = 0; column < N - 1; column++)
			if ('.' == game[low][column])//ԭʼ����δ�仯
			{
				for (column_new = column + 1; column_new < N; column_new++)
				{
					if (game[low][column_new] != '.')//�������Ѿ��仯
					{
						//�������ݴ���ԭʼ����
						game[low][column] = game[low][column_new];
						game[low][column_new] = '.';
						break;//����ѭ��
					}
				}
			}
			else	//ԭʼ�����Ѿ��仯��Ϊ'.'
			{
				for (column_new = column + 1; column_new < N; column_new++)
					if (game[low][column_new] != '.')//�������Ѿ��仯
					{
						if (game[low][column] == game[low][column_new])//���ݿ��ۼ����
						{
							game[low][column] += game[low][column];
							game[low][column_new] = '.';
							*p = (double)game[low][column];
							*s = *s + *p;
						}
						else//���ݲ����ۼ����
						{
							if (column_new - column != 1)//��������ԭ���ݼ����Ϊ1ʱ�����ƶ�
							{
								game[low][column + 1] = game[low][column_new];
								game[low][column_new] = '.';
							}
						}
						break;//����ѭ��
					}
			}
}
void move_right(unsigned int game[][N], long double * p, long double * s)
{
	int column, low, column_new;//low��columnΪԭʼ���ݵ����У�column_newΪ��������

	for (low = 0; low < N; low++)
		for (column = N - 1; column > 0; column--)
			if ('.' == game[low][column])//ԭʼ����δ�仯
			{
				for (column_new = column - 1; column_new >= 0; column_new--)
				{
					if (game[low][column_new] != '.')//�������Ѿ��仯
					{
						//�������ݴ���ԭʼ����
						game[low][column] = game[low][column_new];
						game[low][column_new] = '.';
						break;//����ѭ��
					}
				}
			}
			else	//ԭʼ�����Ѿ��仯��Ϊ'.'
			{
				for (column_new = column - 1; column_new >= 0; column_new--)
					if (game[low][column_new] != '.')//�������Ѿ��仯
					{
						if (game[low][column] == game[low][column_new])//���ݿ��ۼ����
						{
							game[low][column] += game[low][column];
							game[low][column_new] = '.';
							*p = (double)game[low][column];
							*s = *s + *p;
						}
						else//���ݲ����ۼ����
						{
							if (column - column_new != 1)//��������ԭ���ݼ����Ϊ1ʱ�����ƶ�
							{
								game[low][column - 1] = game[low][column_new];
								game[low][column_new] = '.';
							}
						}
						break;//����ѭ��
					}
			}
}
