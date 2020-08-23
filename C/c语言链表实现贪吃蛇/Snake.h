#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ROWMAX 25	//�������
#define COLUMNMAX 40	//�������
#define INITSNAKENODENUM 4	//�߳�ʼ������

	enum {rowBorder, columnBorder, map, snakeBody, snakeHead, food};

	typedef int Map[ROWMAX][COLUMNMAX];
	typedef struct Snake
	{
		int x;
		int y;
		char direction;
		struct Snake * next;
	}Snake;
	typedef struct Food
	{
		int x;
		int y;
	}Food;
	typedef struct UserInfo
	{
		unsigned score;
		char name[80];
		struct UserInfo * next;
	}UserInfo;
	typedef const char * FilePath;
	typedef int rank;

	//��ʼ����Ϸ��ͼ
	void initGameMap(Map m);
	
	//���ߵ�λ�������ͼ��
	void addSnakeToMap(Map m, Snake * SnakeHeader);

	//��ӡ��Ϸ
	void printGame(Map m);

	//����ʳ��
	void produceFood(Snake * SnakeHeader, Map m, Food * f);

	//��Ϸ����
	void gameFlow(void);

	//�Ե�ʳ��
	bool eatFood(Snake * SnakeHeader, Map m, Food * f);

	//����ߵ�λ��
	void clearSnake(Snake * SnakeHeader, Map m);
	
	//�����Լ�
	bool SnakeEatItself(Snake * SnakeHeader);

	//������Ƿ�Խ��
	bool SnakeOverStep(Snake * SnakeHeader);

	//�����Ƿ�Խ��
	bool pointOverstep(int x, int y);

	//�������
	void addSnakeBody(Snake * SnakeHeader);
	
	//�ܷ��ƶ���ͷ
	bool moveHead(Snake * SnakeHeader);

	//�ƶ�����
	void moveBody(Snake * SnakeBody);

	//�ƶ�����
	void move(Snake * SnakeHeader);

	//��ʼ����
	Snake * initSnake(void);

	//�ͷ��ڴ�
	void freeSnake(Snake ** SnakeHeader);
	void freeUserInfo(UserInfo ** UserHeader);

	//��꺯��
	void HideCursor();
	void gotoxy(int x, int y);
	
	//�����û���Ϸ��Ϣ
	FilePath saveUserInfo(UserInfo * user);

	//��ȡ�û���Ϸ��Ϣ
	void loadUserInof(FilePath filePath, UserInfo ** userLinkList);

	//����
	UserInfo * Sort(UserInfo * Header);
	
	//��������
	rank findByName(UserInfo * Header, char name[80]);

	//��ӡ���а�
	void printfRank(UserInfo * Header);

#ifdef __cplusplus
}
#endif