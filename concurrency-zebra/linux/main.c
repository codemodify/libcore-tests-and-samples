#include <stdio.h>
#include <unistd.h>

#include <libcore-types/types.h>
#include <libcore-concurrency-thread/thread.h>

void threadedCodeStarted(ThreadInputData data) {
	printf("threadedCode: STARTED\n");
}

ThreadOutputData threadedCode(ThreadInputData data) {
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("threadedCode: abracadabra %d\n", i);
	}
	printf("\n");
}

void threadedCodeFinished(ThreadInputData data) {
	printf("threadedCode: FINISHED\n");
}

int main(int argc, char** argv) {
	ThreadRef thread = ThreadNew();
	thread->ThreadOnSart = threadedCodeStarted;
	thread->CodeToRun = threadedCode;
	thread->ThreadOnFinish = threadedCodeFinished;

	printf("thread-handle-before-run: %x\n", thread);

	ThreadRun(thread, nil);
	ThreadDelete(&thread);

	printf("thread-handle-after-run: %x\n", thread);

	sleep(3);
}
