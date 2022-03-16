#pragma once

#include <stddef.h>
#include <time.h>

#include "utilities.h"

typedef struct Appointment
{
  size_t id;
  size_t num_attendees;
  string title;
  string description;
  string *attendees;
  time_t start_time;
  time_t stop_time;
} Appointment;

Appointment *create_appointment(size_t id, string title, string description, time_t start_time, time_t stop_time, string *attendees);
void free_appointment(Appointment *appointment);

bool add_attendee(Appointment *appointment, string attendee);
bool remove_attendee(Appointment *appointment, string attendee);
bool contains_attendee(Appointment *appointment, string attendee);