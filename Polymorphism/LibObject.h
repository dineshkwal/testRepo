#pragma once

#include <string>
#include <iostream>
#include <algorithm>

namespace detail
{
	struct is_space
	{
		bool operator()(char ch) const
		{
			return ch == ' ';
		}
	};
}

class lib_internal
{
};

class lib_object : public lib_internal
{
public:
	lib_object(std::string str) : lib_data{ std::move(str) } { }

	void print(bool skip_white_space = false) const
	{
		if (!skip_white_space)
		{
			std::cout << "lib_object: " << lib_data << '\n';
		}
		else
		{
			auto temp_copy = lib_data;
			temp_copy.erase(std::remove_if(temp_copy.begin(), temp_copy.end(), detail::is_space{}), temp_copy.end());
			std::cout << "lib_object: " << temp_copy << '\n';
		}
	}

private:
	std::string lib_data;
};