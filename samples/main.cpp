#include <iostream>
#include "../include/obj.hpp"


using namespace std;
using namespace obj;


class walks {
protected:
	walks() {}
public:
	virtual void walk() = 0;
};
class eats {
protected:
	eats() {}
public:
	virtual void eat() = 0;
};

class animal : public object, public walks, public eats {
public:
	animal() {
		object::__reg_type<animal>(this);
		object::__reg_protos(this, { proto_info<walks>(), proto_info<eats>() });
	}
	void walk() {
		cout << "I have walked" << endl;
	}
	void eat() {
		cout << "I have eaten" << endl;
	}
};


int main() {

	object * obj = new animal();

	//if (obj->instanceof(proto_info<walks>())) {
	//	((walks*)obj)->walk();
	//}
	if (obj->instanceof(proto_info<eats>())) {
		((eats*)obj)->eat();
	}
	if (obj->instanceof(proto_info<eats>())) {
		((eats*)obj)->eat();
	}

	cout << "Press enter to continue..." << flush;
	cin.get();

	return 0;
}