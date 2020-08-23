
#include "genlib.h"
#include <string.h>
typedef struct OptCourse
{
	unsigned int m_sId;//ѧ��
	string m_cId;//�γ̺�
	double m_score;//�ÿƳɼ�
}OptCourse;
/*
typedef struct{
	...
}your_type;
#define __list_t	your_type
*/

#define __list_t OptCourse

#include "__list_h.h"
#include "__list_c.h"

void CopyOpt(OptCourse* des, const OptCourse* src)
{
	des->m_sId = src->m_sId;
	des->m_score = src->m_score;
	des->m_cId = (string)malloc(strlen(src->m_cId) + 1);
	strcpy(des->m_cId, src->m_cId);
}

void DestructOpt(OptCourse* opt)
{
	free(opt->m_cId);
}

