#include "../include/obj_type.hpp"

namespace obj
{
	//type::info::info(const uid id, const char * name, const bool &is_protocol) : _id(id), _name(name), _is_protocol(is_protocol) {}
	type::type(const std::type_index &type_info, const type *base) : _info(type_info), _base(base) {}

	/*returns true if the provided std::type::info is a protocol type and is
	registered as being implemented by the host class; otherwise false*/
	bool type::has_protocol(const std::type_index &proto_info) const {
		return _protocols.find(proto_info) != _protocols.end() || (_base != nullptr && _base->has_protocol(proto_info));
	}
	/*returns true if the provided std::type::info is not a protocol and has the
	same std::type::info::uid as the host class or any of its base classes;
	otherwise false*/
	bool type::has_class(const std::type_index &type_info) const {
		return _info == type_info || (_base != nullptr && _base->has_class(type_info));
	}
}