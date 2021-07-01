#pragma once

#include <iostream>

#define outc std::cout <<
#define outw std::wcout <<
#define spacec << " " <<
#define spacew << L" " <<
#define el << std::endl
#define FORCE_INLINE __forceinline

typedef char byte;
typedef long long llong;
typedef unsigned char uchar;
typedef unsigned char ubyte;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned long long ullong;

namespace conv {
	class Class {
	public:
		template <typename T>
		FORCE_INLINE T& as() {
			return *reinterpret_cast<T*>(this);
		}

		template <typename T>
		FORCE_INLINE T* as_p() {
			return reinterpret_cast<T*>(this);
		}
	};

	FORCE_INLINE const char* tos(bool b) {
		return b ? "true" : "false";
	}

	FORCE_INLINE const wchar_t* tows(bool b) {
		return b ? L"true" : L"false";
	}
}

// As reference
template <typename T>
FORCE_INLINE T& as(void* p) {
	return *reinterpret_cast<T*>(p);
}

// As pointer
template <typename T>
FORCE_INLINE T* as_p(void* p) {
	return reinterpret_cast<T*>(p);
}

// As const pointer
template <typename T>
FORCE_INLINE const T* as_cp(const void* p) {
	return reinterpret_cast<const T*>(p);
}