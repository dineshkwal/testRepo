#include "Document.h"

int main()
{
	Document doc;

	doc.push_back(std::make_unique<IntegerObject>(3));
	doc.push_back(std::make_unique<StringObject>("test string 1"));
	doc.push_back(std::make_unique<StringObject>("test string 2"));

	doc.print();
}