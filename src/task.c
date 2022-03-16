#include "utilities.h"
#include "task.h"

Task *create_task(size_t id, string title, string description, bool completed)
{
  Task *newTask = malloc(sizeof(Task));
  newTask->id = id;
  newTask->title = strdup(title);
  newTask->description = strdup(description);
  newTask->completed = false;
  return newTask;
}

void free_task(Task *task)
{
  free(task->title);
  free(task->description);
  free(task);
}