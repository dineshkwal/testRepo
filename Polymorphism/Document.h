#pragma once

#include "Object.h"

#include <vector>
#include <memory>
#include <utility>

class Document
{
public:
	void push_back(std::unique_ptr<ObjectInterface> obj)
	{
		mObjects.push_back(std::move(obj));
	}

	void print() const
	{
		std::cout << "<document>" << '\n';
		for (const auto& obj : mObjects)
		{
			obj->print();
		}
		std::cout << "</document>" << '\n';
	}

private:
	std::vector<std::unique_ptr<ObjectInterface>> mObjects;
};
