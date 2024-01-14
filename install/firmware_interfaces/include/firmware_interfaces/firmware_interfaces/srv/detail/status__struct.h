// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from firmware_interfaces:srv/Status.idl
// generated code does not contain a copyright notice

#ifndef FIRMWARE_INTERFACES__SRV__DETAIL__STATUS__STRUCT_H_
#define FIRMWARE_INTERFACES__SRV__DETAIL__STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Status in the package firmware_interfaces.
typedef struct firmware_interfaces__srv__Status_Request
{
  uint8_t structure_needs_at_least_one_member;
} firmware_interfaces__srv__Status_Request;

// Struct for a sequence of firmware_interfaces__srv__Status_Request.
typedef struct firmware_interfaces__srv__Status_Request__Sequence
{
  firmware_interfaces__srv__Status_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} firmware_interfaces__srv__Status_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Status in the package firmware_interfaces.
typedef struct firmware_interfaces__srv__Status_Response
{
  float batt_volt;
  bool charge_status;
} firmware_interfaces__srv__Status_Response;

// Struct for a sequence of firmware_interfaces__srv__Status_Response.
typedef struct firmware_interfaces__srv__Status_Response__Sequence
{
  firmware_interfaces__srv__Status_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} firmware_interfaces__srv__Status_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FIRMWARE_INTERFACES__SRV__DETAIL__STATUS__STRUCT_H_
