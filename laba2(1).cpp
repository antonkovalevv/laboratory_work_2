#include <iostream>
#include <vector>
#include <typeinfo>

class Class1 {
public:
	virtual ~Class1() {}
	virtual Class1* clone() const { return new Class1(*this); }
};

class Class2 : public Class1 {
public:
	virtual Class1* clone() const override { return new Class2(*this); }
};

void my_copy(const Class1& obj, std::vector<Class1*>& db) {
	db.push_back(obj.clone());
}

int main() {
	std::vector<Class1*> db;

	Class1 obj1;
	Class2 obj2;

	my_copy(obj1, db);
	my_copy(obj2, db);

	for (auto& obj : db) {
		std::cout << typeid(*obj).name() << std::endl;
		delete obj;
	}

	return 0;
}