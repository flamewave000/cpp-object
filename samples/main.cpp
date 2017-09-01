#include <iostream>
#include "../include/obj.hpp"


using namespace std;
using namespace obj;


$protocol(walks) :
	$iface(void, walk);
$end

$protocol(eats) :
	$iface(void, eat);
$end

class animal : $base, public walks, public eats {
public:
	animal() { $(animal, typeof(walks), typeof(eats)); }
public:
	void walk() {
		cout << "I have walked" << endl;
	}
	void eat() {
		cout << "I have eaten" << endl;
	}
};

class dog : public animal {
public:
	dog() { $(dog); }
public:
	void bark() { cout << "BARK!!" << endl; }
};

class cat : public animal {
public:
	cat() { $(cat); }
public:
	void meow() { cout << "meeoooow!!" << endl; }
};


int main() {
	object * obj = new animal();
	if (obj->instanceof(eats)) {
		eats* tmp = obj->cast_as(eats);
		tmp->eat();
	}
	if (obj->instanceof(walks)) {
		obj->cast_as(walks)->walk();
	}
	delete obj;


	animal * a = new dog();
	if (a->instanceof(dog)) {
		a->cast_as(dog)->bark();
	}
	cat *c = a->cast_as(cat);
	if (c != nullptr) {
		c->meow();
	}
	delete a;


	a = new cat();
	if (a->instanceof(dog)) {
		a->cast_as(dog)->bark();
	}
	if ((c = a->cast_as(cat)) != nullptr) {
		c->meow();
	}
	delete a;

	cout << "Press enter to continue..." << flush;
	cin.get();

	return 0;
}