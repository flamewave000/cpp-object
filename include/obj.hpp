#pragma once
#ifndef _OBJ_HPP_
#define _OBJ_HPP_ 1

#ifndef _OBJ_TYPE_HPP
#include "obj_type.hpp"
#endif

namespace obj {
	/*returns the runtime std::type::info for the templated class type*/
	template<class _obj>
	inline std::type_index typeof() { return std::type_index(typeid(_obj)); }


	/*the root base class of all typed classes*/
	class object {
#pragma region instance variables
	private:
		/*the std::type of the host runtime class*/
		type* __tptr;
#pragma endregion

#pragma region constructors
	public:
		object() : __tptr(nullptr) { $register<object>({}); }
		virtual ~object() { delete __tptr; __tptr = nullptr; }
#pragma endregion

#pragma region protected methods
	protected:
		template<class _obj>
		inline void $register(const std::initializer_list<std::type_index> &protocols) {
			__tptr = new type(typeof<_obj>(), __tptr);
			__tptr->_protocols.insert(protocols.begin(), protocols.end());
		}
#pragma endregion

#pragma region public methods
	public:
		/*returns true if this class inherits from the class or proto described provided by the std::type::info*/
		inline bool instanceof(const std::type_index &obj_type) const { return __tptr->has_class(obj_type) || __tptr->has_protocol(obj_type); }
		template<class _type>
		inline _type* cast_as() { return instanceof(typeof<_type>()) ? (_type*)dynamic_cast<_type*>(this) : (_type*)nullptr; }
		const type & get_type() const { return *__tptr; }
		virtual const char * to_string() const { return __tptr->_info.name(); }
#pragma endregion
	};
#define instanceof(class) instanceof(typeof<class>())
#define cast_as(class) cast_as<class>()
#define typeof(class) typeof<class>()
#define $(class, ...) $register<class>({__VA_ARGS__})
}


#define $base public obj::object
#define $protocol(class_name) class class_name{protected:class_name(){}public
#define $end };
#define $iface(ret, name, ...) virtual ret name(##__VA_ARGS__)=0

#endif