#ifndef HEAD_GAME_H_
#define HEAD_GAME_H_

#define N 4
void show(unsigned int[][N]);//����չʾ��Ϸ����
void move_up(unsigned int[][N], long double *, long double *);//����������Ϸ����
void move_down(unsigned int[][N], long double *, long double *);//����������Ϸ����
void move_left(unsigned int[][N], long double *, long double *);//����������Ϸ����
void move_right(unsigned int[][N], long double *, long double *);//����������Ϸ����
void game_rand(unsigned int[][N]);//�����������2��4,�ҳ���2�ļ���Ϊ4������
int check(unsigned int[][N]);//���ڼ����Ϸ�Ƿ����

#endif
