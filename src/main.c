#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"
#include "task_manager.h"

int main()
{
  time_t now = time(NULL);
  string *attendees = calloc(4, sizeof(string));
  attendees[0] = strdup("Jon");
  attendees[1] = strdup("Andrew");
  attendees[2] = strdup("Sally");
  Task *task1 = add_task("This is task 1", "New task, who dis 1", false);
  Appointment *appointment = add_appointment("This is an appointment", "New appointment, who dis", now, now, attendees);
  print_task(task1);
  print_appointment(appointment);
  free_task(task1);
  free_appointment(appointment);
  return 0;
}