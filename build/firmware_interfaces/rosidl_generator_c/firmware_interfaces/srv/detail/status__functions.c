// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from firmware_interfaces:srv/Status.idl
// generated code does not contain a copyright notice
#include "firmware_interfaces/srv/detail/status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
firmware_interfaces__srv__Status_Request__init(firmware_interfaces__srv__Status_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
firmware_interfaces__srv__Status_Request__fini(firmware_interfaces__srv__Status_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
firmware_interfaces__srv__Status_Request__are_equal(const firmware_interfaces__srv__Status_Request * lhs, const firmware_interfaces__srv__Status_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
firmware_interfaces__srv__Status_Request__copy(
  const firmware_interfaces__srv__Status_Request * input,
  firmware_interfaces__srv__Status_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

firmware_interfaces__srv__Status_Request *
firmware_interfaces__srv__Status_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firmware_interfaces__srv__Status_Request * msg = (firmware_interfaces__srv__Status_Request *)allocator.allocate(sizeof(firmware_interfaces__srv__Status_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(firmware_interfaces__srv__Status_Request));
  bool success = firmware_interfaces__srv__Status_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
firmware_interfaces__srv__Status_Request__destroy(firmware_interfaces__srv__Status_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    firmware_interfaces__srv__Status_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
firmware_interfaces__srv__Status_Request__Sequence__init(firmware_interfaces__srv__Status_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firmware_interfaces__srv__Status_Request * data = NULL;

  if (size) {
    data = (firmware_interfaces__srv__Status_Request *)allocator.zero_allocate(size, sizeof(firmware_interfaces__srv__Status_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = firmware_interfaces__srv__Status_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        firmware_interfaces__srv__Status_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
firmware_interfaces__srv__Status_Request__Sequence__fini(firmware_interfaces__srv__Status_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      firmware_interfaces__srv__Status_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

firmware_interfaces__srv__Status_Request__Sequence *
firmware_interfaces__srv__Status_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firmware_interfaces__srv__Status_Request__Sequence * array = (firmware_interfaces__srv__Status_Request__Sequence *)allocator.allocate(sizeof(firmware_interfaces__srv__Status_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = firmware_interfaces__srv__Status_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
firmware_interfaces__srv__Status_Request__Sequence__destroy(firmware_interfaces__srv__Status_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    firmware_interfaces__srv__Status_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
firmware_interfaces__srv__Status_Request__Sequence__are_equal(const firmware_interfaces__srv__Status_Request__Sequence * lhs, const firmware_interfaces__srv__Status_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!firmware_interfaces__srv__Status_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
firmware_interfaces__srv__Status_Request__Sequence__copy(
  const firmware_interfaces__srv__Status_Request__Sequence * input,
  firmware_interfaces__srv__Status_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(firmware_interfaces__srv__Status_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    firmware_interfaces__srv__Status_Request * data =
      (firmware_interfaces__srv__Status_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!firmware_interfaces__srv__Status_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          firmware_interfaces__srv__Status_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!firmware_interfaces__srv__Status_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
firmware_interfaces__srv__Status_Response__init(firmware_interfaces__srv__Status_Response * msg)
{
  if (!msg) {
    return false;
  }
  // batt_volt
  // charge_status
  return true;
}

void
firmware_interfaces__srv__Status_Response__fini(firmware_interfaces__srv__Status_Response * msg)
{
  if (!msg) {
    return;
  }
  // batt_volt
  // charge_status
}

bool
firmware_interfaces__srv__Status_Response__are_equal(const firmware_interfaces__srv__Status_Response * lhs, const firmware_interfaces__srv__Status_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // batt_volt
  if (lhs->batt_volt != rhs->batt_volt) {
    return false;
  }
  // charge_status
  if (lhs->charge_status != rhs->charge_status) {
    return false;
  }
  return true;
}

bool
firmware_interfaces__srv__Status_Response__copy(
  const firmware_interfaces__srv__Status_Response * input,
  firmware_interfaces__srv__Status_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // batt_volt
  output->batt_volt = input->batt_volt;
  // charge_status
  output->charge_status = input->charge_status;
  return true;
}

firmware_interfaces__srv__Status_Response *
firmware_interfaces__srv__Status_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firmware_interfaces__srv__Status_Response * msg = (firmware_interfaces__srv__Status_Response *)allocator.allocate(sizeof(firmware_interfaces__srv__Status_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(firmware_interfaces__srv__Status_Response));
  bool success = firmware_interfaces__srv__Status_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
firmware_interfaces__srv__Status_Response__destroy(firmware_interfaces__srv__Status_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    firmware_interfaces__srv__Status_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
firmware_interfaces__srv__Status_Response__Sequence__init(firmware_interfaces__srv__Status_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firmware_interfaces__srv__Status_Response * data = NULL;

  if (size) {
    data = (firmware_interfaces__srv__Status_Response *)allocator.zero_allocate(size, sizeof(firmware_interfaces__srv__Status_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = firmware_interfaces__srv__Status_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        firmware_interfaces__srv__Status_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
firmware_interfaces__srv__Status_Response__Sequence__fini(firmware_interfaces__srv__Status_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      firmware_interfaces__srv__Status_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

firmware_interfaces__srv__Status_Response__Sequence *
firmware_interfaces__srv__Status_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  firmware_interfaces__srv__Status_Response__Sequence * array = (firmware_interfaces__srv__Status_Response__Sequence *)allocator.allocate(sizeof(firmware_interfaces__srv__Status_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = firmware_interfaces__srv__Status_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
firmware_interfaces__srv__Status_Response__Sequence__destroy(firmware_interfaces__srv__Status_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    firmware_interfaces__srv__Status_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
firmware_interfaces__srv__Status_Response__Sequence__are_equal(const firmware_interfaces__srv__Status_Response__Sequence * lhs, const firmware_interfaces__srv__Status_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!firmware_interfaces__srv__Status_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
firmware_interfaces__srv__Status_Response__Sequence__copy(
  const firmware_interfaces__srv__Status_Response__Sequence * input,
  firmware_interfaces__srv__Status_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(firmware_interfaces__srv__Status_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    firmware_interfaces__srv__Status_Response * data =
      (firmware_interfaces__srv__Status_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!firmware_interfaces__srv__Status_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          firmware_interfaces__srv__Status_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!firmware_interfaces__srv__Status_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
