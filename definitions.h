#pragma once

#include <iostream>

#define el << std::endl
#define _forceinline_ __forceinline

typedef char byte;
typedef long long llong;
typedef unsigned char ubyte;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned long long ullong;

namespace conv {
	class _Conv_ {
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

template <typename T>
_forceinline_ T& as(void* p) {
	return *reinterpret_cast<T*>(p);
}

template <typename T>
_forceinline_ T* as_p(void* p) {
	return reinterpret_cast<T*>(p);
}