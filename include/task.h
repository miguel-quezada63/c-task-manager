#pragma once

#include "utilities.h"

typedef struct Task
{
  size_t id;
  string title;
  string description;
  bool completed;
} Task;

Task *create_task(size_t id, string title, string description, bool completed);
void free_task(Task *task);