
#include <stdlib.h>
#include <string.h>
#include <iostream>

/// Note:
/// this is a very C-style example, to make the concept of move semantics and r-value references easier to understand
/// you shouldn't actually write your own string class, and you really shouldn't do it like this

struct string
{
	char* data;

	string(const char* p) {
		size_t size = strlen(p) + 1;
		data = new char[size];
		memcpy(data, p, size);
	}

	~string() {
		delete[] data;
	}

	string(const string& from) {
		std::cout << "Copying string" << std::endl;
		size_t size = strlen(from.data) + 1;
		data = new char[size];
		memcpy(data, from.data, size);
	}
};

string funReturningString() {
	string s("Foo");
	return s;
}

int main() {

	string x("Bla");

	string a(x);
	// we need a copy, program could look at x later
	string c(funReturningString());
	// we *don't* need a copy, but still have to make one

}
