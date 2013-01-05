#include "mani/mani.h"

#if defined(PLATFORM_WIN_THREADS)
#include <process.h>

void __cdecl threadproc(void* lparam)
{
	assert( reinterpret_cast<mani::Interpreter*>(lparam)->getVirtualMachine() != reinterpret_cast<mani::Interpreter*>(lparam)->getDefaultVirtualMachine() );
	assert( reinterpret_cast<mani::Interpreter*>(lparam)->getVirtualMachine() == reinterpret_cast<mani::Interpreter*>(lparam)->getVirtualMachine() );
}
#elif defined(PLATFORM_POSIX_THREADS)

#endif

int main( int, char** )
{
	mani::Interpreter lua;

	lua.openStandardLibraries();

#if defined(PLATFORM_WIN_THREADS)
	uintptr_t th = _beginthread( threadproc, 0, &lua);
#elif defined(PLATFORM_POSIX_THREADS)

#endif

	assert( lua.getVirtualMachine() == lua.getDefaultVirtualMachine() );

#if defined(PLATFORM_WIN_THREADS)
	WaitForSingleObject(reinterpret_cast<HANDLE>(th), INFINITE);
#elif defined(PLATFORM_POSIX_THREADS)

#endif

	return 0;
}