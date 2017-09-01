#ifndef _OBJ_TYPE_HPP
#define _OBJ_TYPE_HPP 1

#ifndef _GLIBCXX_UNORDERED_SET
#ifndef _UNORDERED_SET_
#include <unordered_set>
#endif
#endif
#ifndef _GLIBCXX_TYPEINDEX
#ifndef _TYPEINDEX_
#include <typeindex>
#endif
#endif


namespace obj {
	class object;

	/* wraps the info and relations for a single runtime type */
	class type final {
#pragma region instance variables
	private:
		/* the std::type::info for the runtime host class this std::type represents */
		const std::type_index _info;
		/* the base std::type the host class inherits from; null if we are std::object */
		const type *_base;
		/* the list of protocols the host class implements */
		std::unordered_set<std::type_index> _protocols;
#pragma endregion

#pragma region properties
	public:
		/* returns the std::type::info for the host class */
		inline const std::type_index &get_info() const { return _info; }
		/* returns the std::type of the base class the host class inherits from */
		inline const type &get_base_type() const { return *_base; }
#pragma endregion

#pragma region constructors
	private:
		type(const std::type_index &type_info, const type *base);
	public:
		~type() { delete _base; }
#pragma endregion

#pragma region public methods
	public:
		/*returns true if the provided std::type::info is a protocol type and is
		registered as being implemented by the host class; otherwise false*/
		bool has_protocol(const std::type_index &proto_info) const;
		/*returns true if the provided std::type::info is not a protocol and has the
		same std::type::info::uid as the host class or any of its base classes;
		otherwise false*/
		bool has_class(const std::type_index &type_info) const;
#pragma endregion

#pragma region operator overloads
	public:
		inline bool operator==(const type &other) { return _info == other._info; }
		inline bool operator!=(const type &other) { return _info != other._info; }
		inline bool operator==(const type &other) const { return _info == other._info; }
		inline bool operator!=(const type &other) const { return _info != other._info; }
#pragma endregion

#pragma region friends
		friend object;
#pragma endregion
	};
}

#endif