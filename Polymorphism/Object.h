#pragma once

#include <iostream>
#include <string>

class ObjectInterface
{
public:
	virtual ~ObjectInterface() = default;

	virtual void print() = 0;
};

class IntegerObject : public ObjectInterface
{
public:
	IntegerObject(int i) : mData{ i } { }

	void print() override
	{
		std::cout << mData << '\n';
	}

private:
	int mData;
};

class StringObject : public ObjectInterface
{
public:
	StringObject(std::string str) : mData{std::move(str)} { }
	
	void print() override
	{
		std::cout << mData << '\n';
	}

private:
	std::string mData;
};