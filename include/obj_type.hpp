#ifndef _OBJ_TYPE_HPP
#define _OBJ_TYPE_HPP 1

#ifndef _GLIBCXX_UNORDERED_MAP
#ifndef _UNORDERED_MAP_
#include <unordered_map>
#endif
#endif
//#ifndef _GLIBCXX_MEMORY
//#ifndef _MEMORY_
//#include <memory>
//#endif
//#endif

namespace obj {
	class object;

	/* wraps the info and relations for a single runtime type */
	class type final {
#pragma region internal classes
	public:
		/* contains the class info of a single runtime type */
		class info final {
#pragma region internal classes
		public:
			/* unique identifier */
			typedef size_t uid;
#pragma endregion

#pragma region instance variables
		private:
			/* the unique id of the class in the form of a RTTI hash code */
			const uid _id;
			/* the runtime class name */
			const char * _name;
			/* true if the class is a protocol; otherwise false */
			const bool _is_protocol;
#pragma endregion

#pragma region constructors
		public:
			info(const uid id, const char * name, const bool &is_protocol);
#pragma endregion

#pragma region properties
		public:
			/* returns the unique id in the form of a RTTI hash code */
			inline const uid get_id() const { return _id; }
			/* returns the runtime class name */
			inline const char * get_name() const { return _name; }
			/* returns true if the class is a protocol; otherwise false */
			inline bool is_protocol() const { return _is_protocol; }
#pragma endregion

#pragma region operator overloads
		public:
			inline bool operator==(const type::info &other) { return this->_id == other._id; }
			inline bool operator!=(const type::info &other) { return this->_id != other._id; }
			inline bool operator==(const type::info &other) const { return this->_id == other._id; }
			inline bool operator!=(const type::info &other) const { return this->_id != other._id; }
			inline bool operator==(const uid &other) { return this->_id == other; }
			inline bool operator!=(const uid &other) { return this->_id != other; }
			inline bool operator==(const uid &other) const { return this->_id == other; }
			inline bool operator!=(const uid &other) const { return this->_id != other; }
#pragma endregion

#pragma region friends
			friend type;
			friend object;
#pragma endregion
		};
#pragma endregion

#pragma region instance variables
	private:
		/* the std::type::info for the runtime host class this std::type represents */
		info _info;
		/* the base std::type the host class inherits from; null if we are std::object */
		//const std::shared_ptr<type> _base;
		const type* _base;
		/* the list of protocols the host class implements */
		std::unordered_map<info::uid, info> _protocols;
#pragma endregion

#pragma region properties
	public:
		/* returns the std::type::info for the host class */
		inline const info &get_info() const { return _info; }
		/* returns the std::stype of the base class the host class inherits from */
		inline const type &get_base_type() const { return *_base; }
#pragma endregion

#pragma region constructors
	private:
		type(const info &type_info, const type* base);//const std::shared_ptr<type> &base);
#pragma endregion

#pragma region public methods
	public:
		/*returns true if the provided std::type::info is a protocol type and is
		registered as being implemented by the host class; otherwise false*/
		bool has_protocol(const info &proto_info) const;
		/*returns true if the provided std::type::info is not a protocol and has the
		same std::type::info::uid as the host class or any of its base classes;
		otherwise false*/
		bool has_class(const info &type_info) const;
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