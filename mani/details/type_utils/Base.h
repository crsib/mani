//  ==================================================================================
//
//  File:        Base.h
//  Description:
//  Comments:
//  Author:      Dmitry Vedenko
//  E-mail:      vedenko@gmail.com
//
//  The source code is licensed under the BSD 2-clause license. 
//  Redistribution and use in source and binary forms, with or without modification, 
//  are permitted provided that the requirements in the LICENSE file provided are met. 
//
//  ==================================================================================

#ifndef mani_details_type_utils_Base_h__
#define mani_details_type_utils_Base_h__

namespace mani
{
	namespace details
	{
		namespace type_utils
		{
			struct NullType {};
			struct EmptyType {};

			template<int v>
			struct Int2Type { enum { value = v}; };

			template<typename Lhs, typename Rhs>
			struct IsSameType { enum { result = false }; };

			template<typename T>
			struct IsSameType<T,T> { enum { result = true }; };

			namespace internal
			{
				template<typename Lhs, typename Rhs>
				struct check_convertible
				{
					typedef char small_t;
					struct big_t { char dummy[2]; };
					static big_t     check(...);
					static small_t   check(Rhs);
					static Lhs       lhs();
				};
			}

			template<typename Lhs, typename Rhs>
			struct Conversion
			{
				typedef internal::check_convertible<Lhs,Rhs> conversion_check_t;

				enum { exists = sizeof( typename conversion_check_t::small_t ) == sizeof( conversion_check_t::check( conversion_check_t::lhs() ) ) };
				enum { two_way = exists && Conversion<Rhs,Lhs>::exists };
				enum { same_type = false };
			};

			template<typename T>
			struct Conversion<T,T>
			{
				enum { exists = true, two_way = true, same_type = true };
			};

			template<typename T>
			struct Conversion<T,void>
			{
				enum { exists = false, two_way = false, same_type = false };
			};

			template<typename T>
			struct Conversion<void,T>
			{
				enum { exists = false, two_way = false, same_type = false };
			};

			template<>
			struct Conversion<void,void>
			{
				enum { exists = true, two_way = true, same_type = true };
			};

			template<class Base, class Derived>
			struct IsSuperClass
			{
				enum 
				{ 
					result = 
					Conversion< const volatile Derived*, const volatile Base* >::exists && 
					!Conversion< const volatile Base*, const volatile void* >::same_type &&
					!Conversion< const volatile Derived*, const volatile Base* >::same_type,

					same_size = sizeof( Base ) == sizeof( Derived )
				};
			};

			template<class T>
			struct IsSuperClass<T, void>
			{
				enum { result = false, same_size = sizeof(T) == 0 };
			};

			template<class T>
			struct IsSuperClass<void, T>
			{
				enum { result = false, same_size = sizeof(T) == 0 };
			};

			template<>
			struct IsSuperClass<void, void>
			{
				enum { result = false, same_size = true };
			};

			template <bool flag, typename T, typename U>
			struct Select
			{
				typedef T Result;
			};

			template <typename T, typename U>
			struct Select<false, T, U>
			{
				typedef U Result;
			};
		}
	}
}
#endif // mani_details_type_utils_Base_h__