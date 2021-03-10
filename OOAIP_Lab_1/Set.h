#pragma once

class Set
{
private:
	int cardinality; //���������� �������� ���������
	int cardinalityNow; //�������� �������� ���������
	int* elements = nullptr; //������ ��������� ���������

public:
	Set(); //������ �����������
	Set(int); //����������� � ����������

	void AddElement(); //���������� �������� ���������
	void ShowSet(); //����� ��������� �� �������
	bool IsIntersection(Set&); // ����������� ����������� ���� ��������
	void ShowIntersection(Set&); //����� ��������� ����������� ���� ��������
	
	~Set(); //����������
};