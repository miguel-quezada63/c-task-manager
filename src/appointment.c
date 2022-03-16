#include "appointment.h"
#include "task_manager.h"

extern TaskManager taskManager;

Appointment *create_appointment(size_t id, string title, string description, time_t start_time, time_t stop_time, string *attendees)
{
  Appointment *newAppointment = malloc(sizeof(Appointment));
  newAppointment->id = id;
  newAppointment->num_attendees = get_str_arr_size(attendees);
  newAppointment->title = strdup(title);
  newAppointment->description = strdup(description);
  newAppointment->attendees = calloc(newAppointment->num_attendees + 1, sizeof(string));
  for (size_t i = 0; i < newAppointment->num_attendees; ++i)
    newAppointment->attendees[i] = strdup(attendees[i]);
  newAppointment->start_time = start_time;
  newAppointment->stop_time = stop_time;
  return newAppointment;
}

void free_appointment(Appointment *appointment)
{
  free(appointment->title);
  free(appointment->description);
  for (size_t i = 0; i < appointment->num_attendees; ++i)
    free(appointment->attendees[i]);
  free(appointment->attendees);
  free(appointment);
}
