#pragma once

#include <iostream>

#define out std::cout <<
#define wout std::wcout <<
#define space << " " <<
#define wspace << L" " <<
#define el << std::endl
#define _forceinline_ __forceinline

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
		_forceinline_ T& as() {
			return *reinterpret_cast<T*>(this);
		}

		template <typename T>
		_forceinline_ T* as_p() {
			return reinterpret_cast<T*>(this);
		}
	};
}

// As reference
template <typename T>
_forceinline_ T& as(void* p) {
	return *reinterpret_cast<T*>(p);
}

// As pointer
template <typename T>
_forceinline_ T* as_p(void* p) {
	return reinterpret_cast<T*>(p);
}

// As const pointer
template <typename T>
_forceinline_ const T* as_cp(const void* p) {
	return reinterpret_cast<const T*>(p);
}