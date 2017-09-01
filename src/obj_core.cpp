#include "../include/obj_core.hpp"

namespace obj
{
	object::object() { __reg_type<object>(this); }
	/*registers a list of protocol std::type::info that are implemented by this runtime class*/
	void object::__reg_protos(object *obj, const std::vector<type::info> &infos) {
		size_t size = infos.size();
		if (size == 1) __reg_proto(obj, infos[0]);
		for (size_t c = 0; c < size; c++) {
			obj->_type->_protocols.insert({ infos[c]._id, infos[c] });
		}
	}
}