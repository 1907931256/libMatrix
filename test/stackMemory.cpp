#include<crtdbg.h>
#include<windows.h>
#include<malloc.h>
#include<LMT_MATRIX.h>
int func(void);
int func(void)
{
	void* p = _malloca(sizeof(MATRIX));	// raising stack overflow

	if(!p)
		return 0;
	func();

	return 1;
}

int main()
{
	_SYSTEM_INFO	s;

	GetSystemInfo(&s);

	func();

 
	_CrtDumpMemoryLeaks();

	return 1;
}