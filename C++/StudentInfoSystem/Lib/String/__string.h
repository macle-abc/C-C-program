#ifndef _24K_STRING
#define _24K_STRING

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

typedef char* mystring_iterator;

typedef struct mystring {
	char* _data;
	size_t _size;
	size_t _capacity;

	char (*at)(const struct mystring*, size_t);
	char (*front)(const struct mystring*);
	char (*back)(const struct mystring*);
	char* (*data)(struct mystring*);
	const char* (*c_str)(const struct mystring*);

	mystring_iterator(*begin)(struct mystring*);
	mystring_iterator(*end)(struct mystring*);
	mystring_iterator(*rbegin)(struct mystring*);
	mystring_iterator(*rend)(struct mystring*);
	mystring_iterator(*prev)(struct mystring*, mystring_iterator);
	mystring_iterator(*next)(struct mystring*, mystring_iterator);

	int (*empty)(const struct mystring*);
	size_t(*size)(const struct mystring*);
	size_t(*length)(const struct mystring*);
	struct mystring* (*reserve)(struct mystring*, size_t);
	size_t(*capacity)(const struct mystring*);
	struct mystring* (*shrink_to_fit)(struct mystring*);
	struct mystring* (*clear)(struct mystring*);
	struct mystring* (*resize)(struct mystring*, size_t);

	struct mystring* (*insert)(struct mystring*, size_t, char);
	struct mystring* (*erase)(struct mystring*, size_t);
	struct mystring* (*push_back)(struct mystring*, char);
	struct mystring* (*pop_back)(struct mystring*);
	struct mystring* (*assign)(struct mystring*, const char*);

	struct mystring* (*write)(struct mystring*, FILE*);
	struct mystring* (*read)(struct mystring*, FILE*);
	struct mystring* (*save)(struct mystring*, const char*);
	struct mystring* (*load)(struct mystring*, const char*);

	void (*destroy)(struct mystring*);

	struct mystring* (*add)(struct mystring*, const struct mystring*);
	struct mystring* (*append)(struct mystring*, const char*);
	int (*compare)(const struct mystring*, const struct mystring*);
	struct mystring* (*replace)(struct mystring*, size_t, size_t, const char*);

	int (*find)(const struct mystring*, size_t, const char*);
	int (*find_first_of)(const struct mystring*, size_t, const char*);
	int (*find_first_not_of)(const struct mystring*, size_t, const char*);
	struct mystring* (*reverse)(struct mystring*);
	int (*find_last_of)(const struct mystring*, size_t, const char*);
	int (*find_last_not_of)(const struct mystring*, size_t, const char*);

	struct mystring* (*fgetline)(struct mystring*, FILE*, int);
	struct mystring* (*getline)(struct mystring*);
	struct mystring* (*fgets)(struct mystring*, FILE*);
	struct mystring* (*gets)(struct mystring*);

	struct mystring* (*swap)(struct mystring*, struct mystring*);
	struct mystring* (*split)(const struct mystring*, size_t, size_t);

}mystring;

/* s->function(s, ...); */

char mystring_at(const mystring* s, size_t pos);
/* ���� s �ĵ�pos���ַ�,  pos>=0  */

char mystring_front(const mystring* s);
/* ���� s �ĵ�һ���ַ� */

char mystring_back(const mystring* s);
/* ���� s �����һ���ַ� */

char* mystring_data(mystring* s);
/* ���� s ���ַ�����ַ */

const char* mystring_c_str(const mystring* s);
/* ���� s ���ַ�����ַ, �����޸�, ���������ʱʹ�� */

int mystring_empty(const mystring* s);
/* �ж� s �Ƿ�Ϊ���ַ��� */

size_t mystring_size(const mystring* s);
size_t mystring_length(const mystring* s);
/* ���� s �ĳ���, 2������һ�� */

mystring* mystring_reserve(mystring* s, size_t new_cap);
/* ȷ�� s ��new_cap���ַ��Ŀռ�, ����mystring����ʱ���realloc */

size_t mystring_capacity(const mystring* s);
/* ���� s ���ڴ��С */

mystring* mystring_shrink_to_fit(mystring* s);
/* ʹ s ���ڴ��С��Ӧ���ĳ���, �ͷŶ�����ڴ� */

mystring* mystring_clear(mystring* s);
/* ����ַ�������, s���ȱ�Ϊ0 */

mystring* mystring_resize(mystring* s, size_t count);
/* ǿ�е���s�ĳ��� */

mystring* mystring_insert(mystring* s, size_t pos, char c);
/* ��posλ�ò����ַ�c */

mystring* mystring_erase(mystring* s, size_t pos);
/* ɾ��posλ�õ��ַ� */

mystring* mystring_push_back(mystring* s, char c);
/* ��s��ĩβ׷���ַ�c */

mystring* mystring_pop_back(mystring* s);
/* ɾ��s�����һ���ַ� */

mystring* mystring_assign(mystring* s, const char* cs);
/* ����ַ���s����, ���ַ���cs��ֵ��s */

mystring* mystring_add(mystring* s, const mystring* s1);
/* ��mystring s1׷�ӵ�sĩβ */

mystring* mystring_append(mystring* s, const char* cs);
/* ���ַ���cs׷�ӵ�sĩβ */

int mystring_compare(const mystring* s, const mystring* s1);
/* �Ƚ�s, s1��С  ���� s - s1 */

mystring* mystring_replace(mystring* s, size_t pos, size_t count, const char* cs);
/* ��s��posλ�ÿ�ʼ��count���ַ��滻Ϊcs�ַ��� */

int mystring_find(const mystring* s, size_t pos, const char* cs);
/* ��s��posλ�ÿ�ʼ����cs�ַ��� */

int mystring_find_first_of(const mystring* s, size_t pos, const char* cs);
/* ��s��posλ�ÿ�ʼ���� ������ cs�ַ��� �е��ַ�, �������±�, û�ҵ�����-1 */

int mystring_find_first_not_of(const mystring* s, size_t pos, const char* cs);
/* ��s��posλ�ÿ�ʼ���� ���� cs�ַ��� �е��ַ�, �������±�, û�ҵ�����-1 */

int mystring_find_last_of(const mystring* s, size_t pos, const char* cs);
/* ��s��posλ�ÿ�ʼ[��ǰ]���� ������ cs�ַ��� �е��ַ�, �������±�, û�ҵ�����-1 */

int mystring_find_last_not_of(const mystring* s, size_t pos, const char* cs);
/* ��s��posλ�ÿ�ʼ[��ǰ]���� ���� cs�ַ��� �е��ַ�, �������±�, û�ҵ�����-1 */

mystring* mystring_reverse(mystring* s);
/* ���ַ������ݵ��� */

mystring* mystring_fgetline(mystring* s, FILE* fp, int delim);
/* ���ļ�fp��ȡ�ַ���s, �Զ���չs�ڴ�, ֱ�������ַ�delim, ��ȡ�������ַ�delim */

mystring* mystring_getline(mystring* s);
/* ��ȡһ��, �൱�� fgetline(s, stdin, '\n'); */

mystring* mystring_fgets(mystring* s, FILE* fp);
/* ���ļ���ȡ�ַ��� �൱�� fscanf fp,%s  ����ǰ��հ��ַ� */

mystring* mystring_gets(mystring* s);
/* �൱�� fgets(s, stdin); */

mystring* mystring_init(mystring* s);
/* ��ʼ��mystring s */

void mystring_destroy(mystring* s);
/* �ͷ�s������ڴ�, s�������� δ��ʼ�� ״̬ */

mystring* mystring_swap(mystring* s1, mystring* s2);
/* �����ַ���s1��s2������ */

mystring* (*split)(const mystring* s, size_t pos1, size_t pos2);
/* �����ַ��� s �� [pos1, pos2) �� ���ַ���, ���ı�ԭ�ַ��� */

#endif