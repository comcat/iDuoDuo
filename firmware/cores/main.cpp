#include <WProgram.h>

extern "C" void __cxa_pure_virtual() { while (1); }

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

