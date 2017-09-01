#pragma once

/*registers the provided derived type as being the host class*/
#define DERIVED(derived) this->__reg_type<derived>()
/*registers the list of protocol std::type::info as being implemented by the host class*/
#define IMPLEMENTS(...) this->__reg_protos({__VA_ARGS__});
/*short hand helper for retrieving the std::type::info of a protocol*/
#define PROTO(protocol) std::proto_info<protocol>()
/*short hand helper for extending std::object as the base*/
#define ROOT_BASE public std::object

#define IFACE(return_type, method_name, ...) virtual return_type method_name(__VAR_ARGS__) = 0

#define PROTOCOL(p_name) class p_name{public:virtual~p_name(){}protected:p_name(){}public
#define PROTOCOL_IMP(p_name, ...) class p_name:__VA_ARGS__{public:virtual~p_name(){}protected:p_name(){}public
#define PROTOEND };
