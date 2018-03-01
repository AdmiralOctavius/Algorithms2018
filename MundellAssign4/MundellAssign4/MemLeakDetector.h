/*
A Memory Leak is what we call memory which has not been properly deallocated by a program, which can never be used
again until the operating system steps in and reclaims it. Your program could end up running out of memory to use, slow down, or crash.

Instructions: 
You only need to #include the file for it to work; you do not need to instantiate any MemLeakDetector objects (you'd just get duplicate reporting anyway).
#include this file, then run in Debug mode (Just F5, NOT Ctrl + F5, or click the play button (Local Windows Debugger above), or go to Debug->Start Debugging)
Let the program run to conclusion and close.
Then, look at your Output window, NOT the 'Error List'. Go to View->Output or press Alt + 2 to find it.
Scroll up or make it bigger and IF you have memory leaks they will appear like:

Detected memory leaks!
Dumping objects ->
{222} normal block at 0x000001C8596F2DD0, 16 bytes long.
Data: < AoY            > 80 41 6F 59 C8 01 00 00 00 00 00 00 00 00 00 00
{221} normal block at 0x000001C8596F2E20, 16 bytes long.
Data: <HAoY            > 48 41 6F 59 C8 01 00 00 00 00 00 00 00 00 00 00
{220} normal block at 0x000001C8596F3AA0, 16 bytes long.
Data: < AoY            > 10 41 6F 59 C8 01 00 00 00 00 00 00 00 00 00 00
{219} normal block at 0x000001C8596F3A00, 16 bytes long.
Data: < @oY            > D8 40 6F 59 C8 01 00 00 00 00 00 00 00 00 00 00
c:\users\matt\downloads\datastructures\datastructures\main.cpp(82) : {218} normal block at 0x000001C8596F40D0, 232 bytes long.
Data: <         :oY    > 04 00 00 00 00 00 00 00 00 3A 6F 59 C8 01 00 00
Object dump complete.

Notice the last one shows which line the 'new' was called that wasn't properly deleted.

The goal is to get rid of all those, so it just won't show anything.

You will also see things like:

'DataStructures.exe' (Win32): Loaded 'C:\Windows\System32\rpcrt4.dll'. Cannot find or open the PDB file.
The thread 0x3a14 has exited with code 0 (0x0).

These are all normal and can be ignored.

Please note this won't work on Mac, which has its own version of finding memory leaks. Sorry!
See https://developer.apple.com/library/content/documentation/DeveloperTools/Conceptual/InstrumentsUserGuide/FindingLeakedMemory.html

Feel free to use this in any C++ program you make (you probably should!)
*/

#ifndef MEMLEAKDETECTOR_H//Old way of doing an #include guard, instead of #pragma once
#define MEMLEAKDETECTOR_H

#define _CRTDBG_MAP_ALLOC//Lets us use the memory leak detection system functions
#include <stdlib.h>
#include <crtdbg.h>//CRT = C Runtime library

#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK, __FILE__, __LINE__)//shows us what line the leak started from
#define new DBG_NEW
#endif

//Detects memory leaks. 
class MemLeakDetector
{
public:
	~MemLeakDetector()
	{
		_CrtDumpMemoryLeaks();//where the magic happens
	}
};

 //When the program exits, this object will be destroyed, which will invoke its destructor, which calls the system function that detects memory leaks.
MemLeakDetector _memLeakDetector;//A lot of 'system' code uses underscores so that if you wanted to use the original name in your own code, it won't cause conflicts

#endif