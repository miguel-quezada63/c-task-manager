#include "utilities.h"
#include "task_manager.h"
#include "task.h"
#include "appointment.h"

static TaskManager taskManager;

void init_task_manager(void)
{
  taskManager.current_id = 0;
}

Task *add_task(string title, string description, bool completed)
{
  ++taskManager.num_tasks;
  taskManager.tasks = realloc(taskManager.tasks, taskManager.num_tasks * sizeof(Task));
  Task *newTask = create_task(++taskManager.current_id, title, description, completed);
  return newTask;
}

void print_task(Task *task)
{
  string isCompleted = task->completed ? "Yes" : "No";
  printf("\n----- %zu -----\nTitle: %s\nDescription: %s\nIs completed: %s\n\n",
         task->id,
         task->title,
         task->description,
         isCompleted);
}

Appointment *add_appointment(string title, string description, time_t start_time, time_t stop_time, string *attendees)
{
  ++taskManager.num_appointments;
  taskManager.appointments = realloc(taskManager.appointments, taskManager.num_appointments * sizeof(Appointment));
  Appointment *newAppointment = create_appointment(++taskManager.current_id, title, description, start_time, stop_time, attendees);
  return newAppointment;
}

void print_appointment(Appointment *appointment)
{
  printf("----- %zu -----\nTitle: %s\nDescription: %s\nStart Time: %sStop Time: %sAttendees: ",
         appointment->id,
         appointment->title,
         appointment->description,
         asctime(gmtime(&appointment->start_time)),
         asctime(gmtime(&appointment->stop_time)));
  for (size_t i = 0; i < appointment->num_attendees; ++i)
    printf(i == appointment->num_attendees - 1 ? "%s\n\n" : "%s, ", appointment->attendees[i]);
}