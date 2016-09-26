/* compiler_name.hpp 1.0 - Etienne Boespflug - 2016
* https://github.com/EBoespflug/cpp-compiler-name
*
* This file has no license and is free to use.
*
* It is provided without any warranties of any
* kind, either express or implied.
*/

#ifndef CCN_COMPILER_NAME_HPP_
#define CCN_COMPILER_NAME_HPP_

#define CCN_UTIL_TO_STRING_FINAL_(x) #x
#define CCN_UTIL_TO_STRING(x) CCN_UTIL_TO_STRING_FINAL_(x)

namespace ccn {

#if defined(__clang__)

#define CCN_CLANG

#define CCN_COMPILER_COMPLETE_NAME	"Clang/LLVM"
#define CCN_COMPILER_NAME			"Clang"
#define CCN_COMPILER_ID				0u


#define CCN_COMPILER_VERSION_MAJOR	__clang_major__
#define CCN_COMPILER_VERSION_MINOR	__clang_minor__
#define CCN_COMPILER_VERSION_PATCH	__clang_patchlevel__

#define CCN_COMPILER_VERSION_NAME			CCN_UTIL_TO_STRING(__clang_major__) "." CCN_UTIL_TO_STRING(__clang_minor__) "." CCN_UTIL_TO_STRING(__clang_patchlevel__)
#define CCN_COMPILER_VERSION_COMPLETE_NAME	__clang_version__

#elif defined(__GNUG__) && !(defined(__clang__) || defined(__INTEL_COMPILER))

#define CCN_GPP

#define CCN_COMPILER_COMPLETE_NAME	"GNU G++"
#define CCN_COMPILER_NAME			"G++"
#define CCN_COMPILER_ID				1u


#define CCN_COMPILER_VERSION_MAJOR	__GNUG__
#define CCN_COMPILER_VERSION_MINOR	__GNUC_MINOR__

#ifdef __GNUC_PATCHLEVEL__
#define CCN_COMPILER_VERSION_PATCH	__GNUC_PATCHLEVEL__
#else
#define CCN_COMPILER_VERSION_PATCH	0 // No information.
#endif

#define CCN_COMPILER_VERSION_NAME			CCN_UTIL_TO_STRING(__GNUG__) "." CCN_UTIL_TO_STRING(__GNUC_MINOR__) "." CCN_UTIL_TO_STRING(CCN_COMPILER_VERSION_PATCH)
#define CCN_COMPILER_VERSION_COMPLETE_NAME	__VERSION__

#elif defined(__HP_aCC)

#define CCN_ACC

#define CCN_COMPILER_COMPLETE_NAME	"HP aC++"
#define CCN_COMPILER_NAME			"aC++"
#define CCN_COMPILER_ID				2u


#define CCN_COMPILER_VERSION_MAJOR	0 // No information (Contained in the version name).
#define CCN_COMPILER_VERSION_MINOR	0 // No information (Contained in the version name).
#define CCN_COMPILER_VERSION_PATCH	0 // No information (Contained in the version name).

#define CCN_COMPILER_VERSION_NAME			__HP_aCC
#define CCN_COMPILER_VERSION_COMPLETE_NAME	__HP_aCC

#elif defined(__IBMCPP__)

#define CCN_IBMCPP

#define CCN_COMPILER_COMPLETE_NAME	"IBM XL C++"
#define CCN_COMPILER_NAME			"XL C++"
#define CCN_COMPILER_ID				3u


#define CCN_COMPILER_VERSION_MAJOR	0 // No information (Contained in the version name).
#define CCN_COMPILER_VERSION_MINOR	0 // No information (Contained in the version name).
#define CCN_COMPILER_VERSION_PATCH	0 // No information (Contained in the version name).

#define CCN_COMPILER_VERSION_NAME			__IBMCPP__
#define CCN_COMPILER_VERSION_COMPLETE_NAME	__xlC_ver__

#elif defined(__ICC) || defined(__INTEL_COMPILER)

#define CCN_ICC

#define CCN_COMPILER_COMPLETE_NAME	"Intel ICPC"
#define CCN_COMPILER_NAME			"ICPC"
#define CCN_COMPILER_ID				4u


#define CCN_COMPILER_VERSION_MAJOR	__GNUG__
#define CCN_COMPILER_VERSION_MINOR	__GNUC_MINOR__

#ifdef __GNUC_PATCHLEVEL__
#define CCN_COMPILER_VERSION_PATCH	__GNUC_PATCHLEVEL__
#else
#define CCN_COMPILER_VERSION_PATCH	0 // No information.
#endif

#ifdef __INTEL_COMPILER
#define CCN_COMPILER_VERSION_NAME			__INTEL_COMPILER
#define CCN_COMPILER_VERSION_COMPLETE_NAME	CCN_UTIL_TO_STRING(__INTEL_COMPILER) ":" CCN_UTIL_TO_STRING(__INTEL_COMPILER_BUILD_DATE)
#else
#define CCN_COMPILER_VERSION_NAME			__ICC
#define CCN_COMPILER_VERSION_COMPLETE_NAME	CCN_UTIL_TO_STRING(__ICC) ":" CCN_UTIL_TO_STRING(__INTEL_COMPILER_BUILD_DATE)
#endif

#elif defined(_MSC_VER)

#define CCN_MSVC

#define CCN_COMPILER_COMPLETE_NAME	"Microsoft Visual C++"
#define CCN_COMPILER_NAME			"MSVC"
#define CCN_COMPILER_ID				5u


#define CCN_COMPILER_VERSION_MAJOR	0 // No information (Contained in the version name).
#define CCN_COMPILER_VERSION_MINOR	0 // No information (Contained in the version name).
#define CCN_COMPILER_VERSION_PATCH	0 // No information (Contained in the version name).

#define CCN_COMPILER_VERSION_NAME			_MSC_BUILD
#define CCN_COMPILER_VERSION_COMPLETE_NAME	_MSC_BUILD

#elif defined(__SUNPRO_CC)

#define CCN_SUNCC

#define CCN_COMPILER_COMPLETE_NAME	"Oracle Solaris C++"
#define CCN_COMPILER_NAME			"Sun C++"
#define CCN_COMPILER_ID				6u


#define CCN_COMPILER_VERSION_MAJOR	0 // No information (Contained in the version name).
#define CCN_COMPILER_VERSION_MINOR	0 // No information (Contained in the version name).
#define CCN_COMPILER_VERSION_PATCH	0 // No information (Contained in the version name).

#define CCN_COMPILER_VERSION_NAME			__SUNPRO_CC
#define CCN_COMPILER_VERSION_COMPLETE_NAME	__SUNPRO_CC

#elif defined(__PGI)

#define CCN_PGI

#define CCN_COMPILER_COMPLETE_NAME	"Portland PGCPP"
#define CCN_COMPILER_NAME			"PGCPP"
#define CCN_COMPILER_ID				7u


#define CCN_COMPILER_VERSION_MAJOR	__PGIC__
#define CCN_COMPILER_VERSION_MINOR	__PGIC_MINOR
#define CCN_COMPILER_VERSION_PATCH	__PGIC_PATCHLEVEL__

#define CCN_COMPILER_VERSION_NAME			CCN_UTIL_TO_STRING(__PGIC__) "." CCN_UTIL_TO_STRING(__PGIC_MINOR) "." CCN_UTIL_TO_STRING(__PGIC_PATCHLEVEL__)
#define CCN_COMPILER_VERSION_COMPLETE_NAME	CCN_UTIL_TO_STRING(__PGIC__) "." CCN_UTIL_TO_STRING(__PGIC_MINOR) "." CCN_UTIL_TO_STRING(__PGIC_PATCHLEVEL__)

#endif

	using compiler_complete_name_t = char[];
	using compiler_name_t = char[];
	using compiler_id_t = unsigned;
	using version_name_t = char[];
	using version_number_t = unsigned long long;

	constexpr const compiler_name_t		compiler_complete_name = CCN_COMPILER_COMPLETE_NAME;
	constexpr const compiler_name_t		compiler_name = CCN_COMPILER_NAME;
	constexpr const compiler_id_t		compiler_id = CCN_COMPILER_ID;

#if (defined(CCN_SUNCC) || defined(CCN_MSVC) || defined(CCN_IBMCPP) || defined(CCN_ACC)) && defined(CCN_DEPRECATE)
	[[deprecated("This value is nil")]] constexpr const version_number_t	compiler_version_major = CCN_COMPILER_VERSION_MAJOR;
	[[deprecated("This value is nil")]] constexpr const version_number_t	compiler_version_minor = CCN_COMPILER_VERSION_MINOR;
#else
	constexpr const version_number_t	compiler_version_major = CCN_COMPILER_VERSION_MAJOR;
	constexpr const version_number_t	compiler_version_minor = CCN_COMPILER_VERSION_MINOR;
#endif
#if (defined(CCN_SUNCC) || defined(CCN_MSVC) || defined(CCN_IBMCPP) || defined(CCN_ACC) || ((defined(CCN_GPP) || defined(CCN_ICC)) && !defined(__GNUC_PATCHLEVEL__))) && defined(CCN_DEPRECATE)
	[[deprecated("This value is nil")]] constexpr const version_number_t	compiler_version_patch = CCN_COMPILER_VERSION_PATCH;
#else
	constexpr const version_number_t	compiler_version_patch = CCN_COMPILER_VERSION_PATCH;
#endif

	constexpr const version_name_t		compiler_version_complete_name = CCN_COMPILER_VERSION_COMPLETE_NAME;
	constexpr const version_name_t		compiler_version_name = CCN_COMPILER_VERSION_NAME;

} // namespace ccn

#endif // CCN_COMPILER_NAME_HPP_
