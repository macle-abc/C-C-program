#ifndef type
#error: no define "type", need [#define type ...] before [#include "array.h"]
#else

#include <stdio.h> // FILE, fwrite, fread
#include <stdlib.h> // malloc, free, qsort
#include <string.h> // memset
#include <stdarg.h> // va_list

typedef struct s{
	type* data;
	int length;
	int capacity;
}array;

array new_array(int n, ...); // ��ʼ������, ������n��Ԫ��
int array_add(array* arr,type const t); // ����һ��Ԫ�ص�����ĩβ
// a.length ���鳤��
// a.data[i] ���ʻ�����Ԫ��
int array_insert(array* arr, int index, type const t); // ��index������һ��Ԫ��t
int array_insert_many(array* arr, int index, int n, type* ta); // ������Ԫ��
int array_remove(array*, int index); // ɾ��index��Ԫ��
int array_remove_many(array*, int index, int n); // ɾ��index����ʼ��n��Ԫ��
int array_set_length(array*, int new_length); // �������鳤��
void array_clear(array*); // ɾ������������Ԫ��
void delete_array(array*); // �ͷ������ڴ�
void array_sort(array*, int (*cmp)(const type*, const type*)); // ����cmp����������



#undef type

#endif