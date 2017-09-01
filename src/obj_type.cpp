#include "../include/obj_type.hpp"

namespace obj
{
	type::info::info(const uid id, const char * name, const bool &is_protocol) : _id(id), _name(name), _is_protocol(is_protocol) {}
	type::type(const info &type_info, const type*base/*const std::shared_ptr<type> &base*/) : _info(type_info), _base(base) {}

	/*returns true if the provided std::type::info is a protocol type and is
	registered as being implemented by the host class; otherwise false*/
	bool type::has_protocol(const info &proto_info) const {

		auto find = _protocols.find(proto_info._id);
		auto end = _protocols.end();

		return proto_info._is_protocol && (find != end || (_base != nullptr && _base->has_protocol(proto_info)));
		//if (proto_info._is_protocol) {
		//	for (size_t c = 0, size = _protocols.size(); c < size; c++) {
		//		if (_protocols[c] == proto_info) {
		//			return true;
		//		}
		//	}
		//	if (_base != nullptr) {
		//		return const_cast<type*>(_base.get())->has_protocol(proto_info);
		//	}
		//}
		//return false;
	}
	/*returns true if the provided std::type::info is not a protocol and has the
	same std::type::info::uid as the host class or any of its base classes;
	otherwise false*/
	bool type::has_class(const info &type_info) const {
		return !type_info._is_protocol && (_info == type_info || (_base != nullptr && /*const_cast<type*>(_base.get())*/_base->has_class(type_info)));
	}
}