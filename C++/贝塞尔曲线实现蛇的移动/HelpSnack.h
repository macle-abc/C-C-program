#pragma once

#include <cmath>
#include <list>
#include <deque>
using std::list;
using std::deque;

class HelpSnack
{
public:
	bool SnackMove(float* pts, int n, float x, float y);
	//Ĭ���Ѿ����ú������߷��̵ĸ�������
	HelpSnack() = default;
	//tempA���ðڶ����
	//tempW���ðڶ����ڵĵ���
	//tempOFF���ðڶ�����
	//tempB���ðڶ�ƫ����
	//tempOffSet��ÿ�β����ľ���
	//tempRange���ڿ�����ֹͣ�ƶ����� SnackMOve��(x,y)�ķ�Χ Ĭ��15.0f
	HelpSnack(double tempA, double tempW, double tempOFF, double tempB, float tempOffSet, float tempRange) 
		: OffSet(tempOffSet), range(tempRange)
	{
		m_angleArg.A = tempA;
		m_angleArg.W = tempW;
		m_angleArg.OFF = tempOFF;
		m_angleArg.B = tempB;
	}

private:
	struct point
	{
		float x;
		float y;
	};
	struct line
	{
		point head;
		point tail;
	};
	struct angleArg
	{
		//���
		double A;
		//����:2 * M_PI / W
		double W;
		//����
		double OFF;
		//����ƫ����
		double B;
	};

	//�Ƕ�ֵת���ȵĽ���
	const double One = M_PI / 180.0;
	//ÿ�β����ľ���
	float OffSet = 6.0f;
	//��ϵı���������
	list<point> m_BezierCurve;
	//������������
	deque<point> m_SnackBody;
	//���Ǻ�������
	angleArg m_angleArg = { 3, 5, 6, 10 };
	//������ķ�Χ
	float range = 15.0f;
	//�µ�xy
	point newPos = { 0 };
	//ԭʼxy
	point oldPos = { 0 };

	double saveAngle;
	point saveO;
	point saveN;

private:
	//���������
	double Simplify(int n, int m) const;
	//�������
	inline double CombinationNumber(int n, int m) const;
	//���������ߵ�ÿһ���е���Ҫ��͵���
	inline double EachItem(int i, int n, double pi, double _t, double t) const;
	//���챴��������
	void CalculateBezierCurve(double incream);

	//�涨˳ʱ��תΪ����
	//��ʱ��תΪ����
	//�ýǶ�����x�ᵽx1��ĽǶ�
	//��Χ(-180, 180]
	//�����Ʒ�Χ(-Pi,pi]
	inline double IncludedAngle(const HelpSnack::line temp) const;

	//y=f(x)
	inline double CurveFunction(double x) const;

	//��ȡ������ϵԭ����������ϵ��λ��
	const HelpSnack::point GetOldOInNew(const HelpSnack::line temp) const;

	//temp�Ǿ�����ϵ������
	//O��x�ᵽx1��ĽǶ�
	//basePointΪ������ϵ��ԭ����������ϵ��ֵ
	const HelpSnack::point TransformToNew(const HelpSnack::point temp, double O, const HelpSnack::point basePoint) const;

	// tempΪ������ϵ������
	//OΪx1�ᵽx��ĽǶ�
	//basePointΪ������ϵ��ԭ���ھ�����ϵ��ֵ
	const HelpSnack::point TransformToOld(const HelpSnack::point temp, double O, const HelpSnack::point basePoint) const;

	const HelpSnack::line ConstructLine(const HelpSnack::point head, const HelpSnack::point tail) const;

};
