// ThreadPool.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ThreadPool.h"
#include <stdio.h>

class Task : TaskBase
{
public:
	Task() { printf("Task Construct\n"); }
	~Task() { printf("Task Destruct\n"); }

	int Run() 
	{
		int i = 10;
		while (i >= 0)
		{
			printf("%d\n", i);
			Sleep(100);
			i--;
		}
		return i;
	}
};

class TaskCb : TaskCallbackBase
{
public:
	TaskCb() { printf("TaskCb Construct\n"); }
	~TaskCb() { printf("TaskCb Destruct\n"); }

	void Run(int result) 
	{
		printf("%d\n", result);
	}
};

int main()
{
	ThreadPool threadPool(3);
	shared_ptr<TaskBase> task((TaskBase*)new Task());
	shared_ptr<TaskCallbackBase> taskCb((TaskCallbackBase*)new TaskCb());
	for (size_t i = 0; i < 3; i++)
	{
		threadPool.QueueTaskItem(task, taskCb);
	}
	
	getchar();

    return 0;
}

