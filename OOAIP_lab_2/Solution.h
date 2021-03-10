#pragma once

class Solution
{
public:
	virtual void SetVariables();
	virtual void CalvulateAnswer();
	virtual void ShowAnswer();
	virtual ~Solution();
protected:
	float* variables = nullptr;
	float* answers = nullptr;
};

class Linear: public Solution
{
public:
	Linear();
	Linear(float, float);
	void SetVariables();
	void CalvulateAnswer();
	void ShowAnswer();
	~Linear();
private:

};

class Square: public Solution
{
public:
	Square();
	Square(float, float, float);
	void SetVariables();
	void CalvulateAnswer();
	void ShowAnswer();
	~Square();
private:
	float d;
};

class Series
{
public:
	Series();
	void SetVariables();
	void ShowAnswers();
	~Series();
private:
	int LinearNum;
	int SquareNum;
	Solution** equation;
};


