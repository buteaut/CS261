/*
 * CS 261 Assignment 5
 * Name: Thomas Buteau
 * Date: 5-28-17
 */

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
    // FIXME: implement
	struct Task* newTask = malloc(sizeof(struct Task));
	strcpy(newTask->name, name);
	newTask->priority = priority;
    return newTask;
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return 
 */
int taskCompare(void* left, void* right)
{
    // FIXME: implement
	struct Task *tempLeft = (Task*)left;
	struct Task *tempRight = (Task*)right;

	if (tempLeft->priority < tempRight->priority)
	{
		return -1;
	}
	if (tempLeft->priority == tempRight->priority)
	{
		return 0;
	}
	//if (tempLeft->priority > tempRight->priority)
		return 1;
}

/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    Task* task = (Task*)value;
    printf("(%d, %s)", task->priority, task->name);
}
