#include<iostream>
#include<thread>
#include<Windows.h>
#include<mutex>
#include<condition_variable>
//#include "Timer.h"
using namespace std;

void DoStuff() {
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << "-" << j + i << ", ";
		}

		cout << endl;
	}
}


int main() {
	//Sleep(100);
	//DoStuff();

	thread workerThread(DoStuff);
	//thread workerThread2(DoOtherStuff);

	//Wait until thread done
	workerThread.join();
	//workerThread2.join();

	//Race condition - 2 or more threades tryting to access the the same resource
	//Thread safety, writing a program that threads don't clamor over one another

	return;
}