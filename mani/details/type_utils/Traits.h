//  ==================================================================================
//
//  File:        Traits.h
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

// The code is mostly a copy of Loki Traits from Andrei Alexandrescu's Loki library

#ifndef mani_details_type_utils_Traits_h__
#define mani_details_type_utils_Traits_h__

#include "mani/details/type_utils/TypeList.h"

namespace mani
{
	namespace details
	{
		namespace type_utils
		{
			template <typename T>
			struct IsCustomUnsignedInt
			{
				enum { result = 0 };
			}; 

			template <typename T>
			struct IsCustomSignedInt
			{
				enum { result = 0 };
			};   

			template <typename T>
			struct IsCustomFloat
			{
				enum { result = 0 };
			};

			namespace internal
			{
				typedef Vector<unsigned char, unsigned short int,unsigned int, unsigned long int>::result_t
					StdUnsignedInts;
				typedef Vector<signed char, short int,int, long int>::result_t
					StdSignedInts;
				typedef Vector<bool, char, wchar_t>::result_t
					StdOtherInts;
				typedef Vector<float, double, long double>::result_t
					StdFloats;
            
				template <typename U> struct AddPointer
				{
					typedef U* Result;
				};

				template <typename U> struct AddPointer<U&>
				{
					typedef U* Result;
				};

				template <class U> struct AddReference
				{
					typedef U & Result;
				};

				template <class U> struct AddReference<U &>
				{
					typedef U & Result;
				};

				template <> struct AddReference<void>
				{
					typedef NullType Result;
				};

				template <class U> struct AddParameterType
				{
					typedef const U & Result;
				};

				template <class U> struct AddParameterType<U &>
				{
					typedef U & Result;
				};

				template <> struct AddParameterType<void>
				{
					typedef NullType Result;
				};

				template <typename T>
				struct IsFunctionPointerRaw
				{enum{result = 0};};

				template <typename T>
				struct IsFunctionPointerRaw<T(*)()> 
				{enum {result = 1};};

				template <typename T, 
					typename P01>
				struct IsFunctionPointerRaw<T(*)(P01)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05, 
					P06)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, P15)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19, typename P20>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, P20)> 
				{enum {result = 1};};

				template <typename T>
				struct IsFunctionPointerRaw<T(*)(
					...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01>
				struct IsFunctionPointerRaw<T(*)(
					P01, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05, 
					P06, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, P15,
					...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, ...)> 
				{enum {result = 1};};

				template <typename T, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19, typename P20>
				struct IsFunctionPointerRaw<T(*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, P20,
					...)> 
				{enum {result = 1};};


				template <typename T>
				struct IsMemberFunctionPointerRaw
				{enum{result = 0};};

				template <typename T, typename S>
				struct IsMemberFunctionPointerRaw<T (S::*)()> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01>
				struct IsMemberFunctionPointerRaw<T (S::*)(P01)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, P15)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19, typename P20>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, P20)> 
				{enum {result = 1};};

				template <typename T, typename S>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, P15,
					...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, ...)> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19, typename P20>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, P20,
					...)> 
				{enum {result = 1};};

				// Const versions

				template <typename T, typename S>
				struct IsMemberFunctionPointerRaw<T (S::*)() const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01>
				struct IsMemberFunctionPointerRaw<T (S::*)(P01) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, P15) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19, typename P20>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, P20) const> 
				{enum {result = 1};};

				template <typename T, typename S>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, P15,
					...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, ...) const> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19, typename P20>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, P20,
					...) const> 
				{enum {result = 1};};

				// Volatile versions

				template <typename T, typename S>
				struct IsMemberFunctionPointerRaw<T (S::*)() volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01>
				struct IsMemberFunctionPointerRaw<T (S::*)(P01) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, P15) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19, typename P20>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, P20) volatile> 
				{enum {result = 1};};

				template <typename T, typename S>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, P15,
					...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, ...) volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19, typename P20>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, P20,
					...) volatile> 
				{enum {result = 1};};

				// Const volatile versions

				template <typename T, typename S>
				struct IsMemberFunctionPointerRaw<T (S::*)() const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01>
				struct IsMemberFunctionPointerRaw<T (S::*)(P01) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, P15) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19, typename P20>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, P20) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05,
					P06, P07, P08, P09, P10,
					P11, P12, P13, P14, P15,
					...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, ...) const volatile> 
				{enum {result = 1};};

				template <typename T, typename S, 
					typename P01, typename P02, typename P03, typename P04, typename P05,
					typename P06, typename P07, typename P08, typename P09, typename P10,
					typename P11, typename P12, typename P13, typename P14, typename P15,
					typename P16, typename P17, typename P18, typename P19, typename P20>
				struct IsMemberFunctionPointerRaw<T (S::*)(
					P01, P02, P03, P04, P05, 
					P06, P07, P08, P09, P10, 
					P11, P12, P13, P14, P15,
					P16, P17, P18, P19, P20,
					...) const volatile> 
				{enum {result = 1};};
			}

			template <typename T>
			class Traits
			{
			private:

				template <class U> struct ReferenceTraits
				{
					enum { result = false };
					typedef U ReferredType;
				};

				template <class U> struct ReferenceTraits<U&>
				{
					enum { result = true };
					typedef U ReferredType;
				};

				template <class U> struct PointerTraits
				{
					enum { result = false };
					typedef NullType PointeeType;
				};

				template <class U> struct PointerTraits<U*>
				{
					enum { result = true };
					typedef U PointeeType;
				};

				template <class U> struct PointerTraits<U*&>
				{
					enum { result = true };
					typedef U PointeeType;
				};

				template <class U> struct PToMTraits
				{
					enum { result = false };
				};

				template <class U, class V> struct PToMTraits<U V::*>
				{
					enum { result = true };
				};

				template <class U, class V> struct PToMTraits<U V::*&>
				{
					enum { result = true };
				};

				template <class U> struct FunctionPointerTraits
				{
					enum{ result = internal::IsFunctionPointerRaw<U>::result };
				};

				template <typename U> struct PToMFunctionTraits
				{
					enum{ result = internal::IsMemberFunctionPointerRaw<U>::result };
				};

				template <class U> struct UnConst
				{
					typedef U Result;
					enum { isConst = 0 };
				};

				template <class U> struct UnConst<const U>
				{
					typedef U Result;
					enum { isConst = 1 };
				};

				template <class U> struct UnConst<const U&>
				{
					typedef U& Result;
					enum { isConst = 1 };
				};

				template <class U> struct UnVolatile
				{
					typedef U Result;
					enum { isVolatile = 0 };
				};

				template <class U> struct UnVolatile<volatile U>
				{
					typedef U Result;
					enum { isVolatile = 1 };
				};

				template <class U> struct UnVolatile<volatile U&>
				{
					typedef U& Result;
					enum { isVolatile = 1 };
				};

			public:
				typedef typename UnConst<T>::Result 
					non_const_type_t;
				typedef typename UnVolatile<T>::Result 
					non_volatile_type_t;
				typedef typename UnVolatile<typename UnConst<T>::Result>::Result 
					unqualified_type_t;
				typedef typename PointerTraits<unqualified_type_t>::PointeeType 
					pointee_type_t;
				typedef typename ReferenceTraits<T>::ReferredType 
					referred_type_t;

				enum { is_const          = UnConst<T>::isConst };
				enum { is_volatile       = UnVolatile<T>::isVolatile };
				enum { is_reference      = ReferenceTraits<unqualified_type_t>::result };
				enum { is_function       = FunctionPointerTraits<typename internal::AddPointer<T>::Result >::result };
				enum { is_function_pointer= FunctionPointerTraits<
					typename ReferenceTraits<unqualified_type_t>::ReferredType >::result };
				enum { is_member_function_pointer= PToMFunctionTraits<
					typename ReferenceTraits<unqualified_type_t>::ReferredType >::result };
				enum { is_member_pointer  = PToMTraits<
					typename ReferenceTraits<unqualified_type_t>::ReferredType >::result ||
					is_member_function_pointer };
				enum { is_pointer        = PointerTraits<
					typename ReferenceTraits<unqualified_type_t>::ReferredType >::result ||
					is_function_pointer };

				enum { is_std_unsigned_int = IndexOf<internal::StdUnsignedInts, unqualified_type_t>::result >= 0 ||
					IndexOf<internal::StdUnsignedInts, 
					typename ReferenceTraits<unqualified_type_t>::ReferredType>::result >= 0};
				enum { is_std_signed_int   = IndexOf<internal::StdSignedInts, unqualified_type_t>::result >= 0 ||
					IndexOf<internal::StdSignedInts, 
					typename ReferenceTraits<unqualified_type_t>::ReferredType>::result >= 0};
				enum { is_std_integral    = is_std_unsigned_int || is_std_signed_int ||
					IndexOf<internal::StdOtherInts, unqualified_type_t>::result >= 0 ||
					IndexOf<internal::StdOtherInts, 
					typename ReferenceTraits<unqualified_type_t>::ReferredType>::result >= 0};
				enum { is_std_float       = IndexOf<internal::StdFloats, unqualified_type_t>::result >= 0 ||
					IndexOf<internal::StdFloats, 
					typename ReferenceTraits<unqualified_type_t>::ReferredType>::result >= 0};
				enum { is_std_arith       = is_std_integral || is_std_float };
				enum { is_std_fundamental = is_std_arith || is_std_float || Conversion<T, void>::same_type };

				enum { is_unsigned_int    = is_std_unsigned_int || IsCustomUnsignedInt<unqualified_type_t>::result };
				enum { is_signed_int      = is_std_signed_int || IsCustomSignedInt<unqualified_type_t>::result };
				enum { is_integral        = is_std_integral || is_unsigned_int || is_signed_int };
				enum { is_float           = is_std_float || IsCustomFloat<unqualified_type_t>::result };
				enum { is_arith           = is_integral || is_float };
				enum { is_fundamental     = is_std_fundamental || is_arith };

				typedef typename Select<is_std_arith || is_pointer || is_member_pointer, T, 
					typename internal::AddParameterType<T>::Result>::Result 
					parameter_type_t;
			};
		}
	}
}

#endif // mani_details_type_utils_Traits_h__