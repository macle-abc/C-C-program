#include <stdio.h>
#include <time.h>
#include "head_game.h"


int main(void)
{
	unsigned int game2048[N][N], copy[N][N];//game2048[N][N]��ʾ��Ϸ����,copy[N][N]��ʾ��Ϸ��һ������
	unsigned int low, column, sum, return_number;//sum��ʾcopy[N][N]��game2048[N][N]��ͬ���ݵĸ���,return_number���ڴ���int check(int[][N])�����ķ���ֵ
    long double game_score = 0.0, sum_score = 0.0;//game_score����ÿ�����ݵ���ʱ����Ϸ����,sum_score������Ϸ�ܷ�
	long double * score = &game_score, *p_sum_score = &sum_score;//ָ��scoreָ��game_score��ָ��p_sum_scoreָ��sum_score
	char chose;//�����û��Ĳ���
	void(*p)(unsigned int[][N], long double *, long double *) = NULL;
	
	srand((unsigned int)time(NULL));//�趨���������
	//��ʼÿ������Ϊ'.'
	for (low = 0; low < N; low++)
		for (column = 0; column < N; column++)
			copy[low][column] = game2048[low][column] = '.';
	printf("      *************************\n        ��ӭ����2048С��Ϸ\n      *************************\n\n\n");
	show(game2048);//չʾ��ʼ�����
	printf("������S��s��ʾ��Ϸ��ʼ\n");
	chose = getch();
	while (chose != 's' && chose != 'S')
	{
		printf("�������,�Ƿ������Ϸ��S��s���������������������Ϸ)\n");
		chose = getch();
		if (chose != 's' && chose != 'S')
			return 0;
	}
	game_rand(game2048);//�����������
	show(game2048);
	//��Ϸ����
	while (1)
	{
		sum = 0;
		return_number = check(game2048);
		if (return_number)//�ж���Ϸ�Ƿ����
		{
			//������һ����Ϸ����
			for (low = 0; low < N; low++)
				for (column = 0; column < N; column++)
					copy[low][column] = game2048[low][column];
			printf("������w s a d q��W S A D Q��w��W��ʾ����,s��S��ʾ���ƣ�a��A��ʾ���ƣ�d��D��ʾ���ƣ�q��Q��ʾ�˳���Ϸ)\n");
			chose = getch();//�û�����
			while (chose != 'w' && chose != 'W' && chose != 's' && chose != 'S' && chose != 'a' && chose != 'A' && chose != 'd' && chose != 'D')
			{
				if ('q' == chose || 'Q' == chose)
					return 0;
				else
				{
					printf("�������������������\n");
					chose = getch();
				}
			}
			if ('w' == chose || 'W' == chose)//������
				p = move_up;
			else if ('s' == chose || 'S' == chose)//������
				p = move_down;
			else if ('a' == chose || 'A' == chose)//������
				p = move_left;
			else if ('d' == chose || 'D' == chose)//������
				p = move_right;
			(*p)(game2048, score, p_sum_score);//��ʼ�ƶ�
											   //�жϸ÷������ܷ�����ƶ�
			for (low = 0; low < N; low++)
				for (column = 0; column < N; column++)
					if (copy[low][column] == game2048[low][column])//��һ����������Ϸ��������ͬ
						sum++;
			if (sum != N * N)//���������ݲ���ͬ����������
				game_rand(game2048);
			show(game2048);
			printf("����Ϊ��%.lf\n\n\n", *p_sum_score);
		}
		else
		{
			printf("��Ϸ����.\n");
			system("pause");
			return 0;
		}

	}
	return 0;
}
