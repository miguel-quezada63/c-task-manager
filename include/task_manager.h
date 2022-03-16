#pragma once

#include <time.h>
#include "task.h"
#include "appointment.h"
#include "utilities.h"

typedef struct TaskManager
{
  size_t current_id;
  Task *tasks;
  size_t num_tasks;
  Appointment *appointments;
  size_t num_appointments;
} TaskManager;

typedef union FindByIdUnion
{
  Task *task;
  Appointment *appointment;
} FindByIdUnion;

void init_task_manager(void);

Task *add_task(string title, string description, bool completed);
bool edit_task(Task *task, string title, string description, bool completed);
void print_task(Task *task);

Appointment *add_appointment(string title, string description, time_t start_time, time_t stop_time, string *attendees);
bool edit_appointment(Appointment *appointment, string title, string description, time_t start_time, time_t stop_time, string *attendees);
void print_appointment(Appointment *appointment);

FindByIdUnion find_by_id(size_t id);