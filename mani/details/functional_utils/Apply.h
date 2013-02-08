//  ==================================================================================
//
//  File:        Apply.h
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

#ifndef mani_details_functional_Apply_h__
#define mani_details_functional_Apply_h__

#include "mani/details/functional_utils/DeduceSignature.h"

namespace mani
{
	namespace details
	{
		namespace functional_utils
		{
			namespace __private
			{
				template< int count, typename Sig >
				struct function_apply_helper
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params );
				};
				
				template< typename Sig >
				struct function_apply_helper<0, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params )
					{
						return fn( );
					}
				};

				template< typename Sig >
				struct function_apply_helper<1, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params )
					{
						using namespace mani::details::type_utils;
						return fn( Field<0>( params ) );
					}
				};

				template< typename Sig >
				struct function_apply_helper<2, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params )
					{
						using namespace mani::details::type_utils;
						return fn( Field<0>( params ), Field<1>( params ) );
					}
				};

				template< typename Sig >
				struct function_apply_helper<3, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params )
					{
						using namespace mani::details::type_utils;
						return fn( Field<0>( params ), Field<1>( params ), Field<2>( params ) );
					}
				};

				template< typename Sig >
				struct function_apply_helper<4, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params )
					{
						using namespace mani::details::type_utils;
						return fn( Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ) );
					}
				};

				template< typename Sig >
				struct function_apply_helper<5, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params )
					{
						using namespace mani::details::type_utils;
						return fn( Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ) );
					}
				};

				template< typename Sig >
				struct function_apply_helper<6, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params )
					{
						using namespace mani::details::type_utils;
						return fn( Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ), Field<5>( params ) );
					}
				};

				template< typename Sig >
				struct function_apply_helper<7, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params )
					{
						using namespace mani::details::type_utils;
						return fn( 
							Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ), Field<5>( params ),
							Field<6>( params ) 
							);
					}
				};

				template< typename Sig >
				struct function_apply_helper<8, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params )
					{
						using namespace mani::details::type_utils;
						return fn( 
							Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ), Field<5>( params ), 
							Field<6>( params ), Field<7>( params ) 
							);
					}
				};

				template< typename Sig >
				struct function_apply_helper<9, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params )
					{
						using namespace mani::details::type_utils;
						return fn( 
							Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ), Field<5>( params ), 
							Field<6>( params ), Field<7>( params ), Field<8>( params )  
							);
					}
				};

				template< typename Sig >
				struct function_apply_helper<10, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params )
					{
						using namespace mani::details::type_utils;
						return fn( 
							Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ), Field<5>( params ), 
							Field<6>( params ), Field<7>( params ), Field<8>( params ), Field<9>( params )  
							);
					}
				};

				template< typename Sig >
				struct function_apply_helper<11, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params )
					{
						using namespace mani::details::type_utils;
						return fn( 
							Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ), Field<5>( params ), 
							Field<6>( params ), Field<7>( params ), Field<8>( params ), Field<9>( params ), Field<10>( params )  
							);
					}
				};

				template< typename Sig >
				struct function_apply_helper<12, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params )
					{
						using namespace mani::details::type_utils;
						return fn( 
							Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ),  Field<5>( params ), 
							Field<6>( params ), Field<7>( params ), Field<8>( params ), Field<9>( params ), Field<10>( params ), Field<11>( params )  
							);
					}
				};

				// methods
				template< int count, typename Sig >
				struct method_apply_helper
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this );
				};

				template< typename Sig >
				struct method_apply_helper<0, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this )
					{
						return (__this->*fn)( );
					}
				};

				template< typename Sig >
				struct method_apply_helper<1, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this )
					{
						using namespace mani::details::type_utils;
						return (__this->*fn)( Field<0>( params ) );
					}
				};

				template< typename Sig >
				struct method_apply_helper<2, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this )
					{
						using namespace mani::details::type_utils;
						return (__this->*fn)( Field<0>( params ), Field<1>( params ) );
					}
				};

				template< typename Sig >
				struct method_apply_helper<3, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this )
					{
						using namespace mani::details::type_utils;
						return (__this->*fn)( Field<0>( params ), Field<1>( params ), Field<2>( params ) );
					}
				};

				template< typename Sig >
				struct method_apply_helper<4, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this )
					{
						using namespace mani::details::type_utils;
						return (__this->*fn)( Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ) );
					}
				};

				template< typename Sig >
				struct method_apply_helper<5, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this )
					{
						using namespace mani::details::type_utils;
						return (__this->*fn)( Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ) );
					}
				};

				template< typename Sig >
				struct method_apply_helper<6, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this )
					{
						using namespace mani::details::type_utils;
						return (__this->*fn)( Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ), Field<5>( params ) );
					}
				};

				template< typename Sig >
				struct method_apply_helper<7, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this )
					{
						using namespace mani::details::type_utils;
						return (__this->*fn)( 
							Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ), Field<5>( params ),
							Field<6>( params ) 
							);
					}
				};

				template< typename Sig >
				struct method_apply_helper<8, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this )
					{
						using namespace mani::details::type_utils;
						return (__this->*fn)( 
							Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ), Field<5>( params ), 
							Field<6>( params ), Field<7>( params ) 
							);
					}
				};

				template< typename Sig >
				struct method_apply_helper<9, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this )
					{
						using namespace mani::details::type_utils;
						return (__this->*fn)( 
							Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ), Field<5>( params ), 
							Field<6>( params ), Field<7>( params ), Field<8>( params )  
							);
					}
				};

				template< typename Sig >
				struct method_apply_helper<10, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this )
					{
						using namespace mani::details::type_utils;
						return (__this->*fn)( 
							Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ), Field<5>( params ), 
							Field<6>( params ), Field<7>( params ), Field<8>( params ), Field<9>( params )  
							);
					}
				};

				template< typename Sig >
				struct method_apply_helper<11, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this )
					{
						using namespace mani::details::type_utils;
						return (__this->*fn)( 
							Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ), Field<5>( params ), 
							Field<6>( params ), Field<7>( params ), Field<8>( params ), Field<9>( params ), Field<10>( params )  
							);
					}
				};

				template< typename Sig >
				struct method_apply_helper<12, Sig>
				{
					static typename Sig::return_value_t
						apply( typename Sig::pointer_t fn, const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params, typename Sig::class_t* __this )
					{
						using namespace mani::details::type_utils;
						return (__this->*fn)( 
							Field<0>( params ), Field<1>( params ), Field<2>( params ), Field<3>( params ), Field<4>( params ),  Field<5>( params ), 
							Field<6>( params ), Field<7>( params ), Field<8>( params ), Field<9>( params ), Field<10>( params ), Field<11>( params )  
							);
					}
				};

				template< typename Sig >
				typename Sig::return_value_t
					apply( 
					Sig, typename Sig::class_t* __this, typename Sig::pointer_t fn, 
					const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params,
					mani::details::type_utils::true_type
					)
				{ 
					return __private::method_apply_helper<Sig::arg_count, Sig>::apply( fn, params, __this );
				}

				template< typename Sig >
				typename Sig::return_value_t
					apply( 
					Sig, typename Sig::class_t* __this, typename Sig::pointer_t fn, 
					const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params,
					mani::details::type_utils::false_type
					)
				{ 
					return __private::function_apply_helper<Sig::arg_count, Sig>::apply( fn, params );
				}
			}

			template< typename Sig >
			typename Sig::return_value_t
				apply( 
				Sig __, typename Sig::class_t* __this, typename Sig::pointer_t fn, 
				const mani::details::type_utils::Tuple<typename Sig::parameters_t>& params = mani::details::type_utils::Tuple<typename Sig::parameters_t>() 
				)
			{ 
				return __private::apply( 
					__, __this, fn, params, 
					typename mani::details::type_utils::Select< Sig::is_method, mani::details::type_utils::true_type, mani::details::type_utils::false_type >::result_t() );
			}

		}
	}
}

#endif // mani_details_functional_Apply_h__
