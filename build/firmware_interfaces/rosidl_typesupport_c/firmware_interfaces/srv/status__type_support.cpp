// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from firmware_interfaces:srv/Status.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "firmware_interfaces/srv/detail/status__struct.h"
#include "firmware_interfaces/srv/detail/status__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace firmware_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Status_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Status_Request_type_support_ids_t;

static const _Status_Request_type_support_ids_t _Status_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Status_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Status_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Status_Request_type_support_symbol_names_t _Status_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, firmware_interfaces, srv, Status_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, firmware_interfaces, srv, Status_Request)),
  }
};

typedef struct _Status_Request_type_support_data_t
{
  void * data[2];
} _Status_Request_type_support_data_t;

static _Status_Request_type_support_data_t _Status_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Status_Request_message_typesupport_map = {
  2,
  "firmware_interfaces",
  &_Status_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Status_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Status_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Status_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Status_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace firmware_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, firmware_interfaces, srv, Status_Request)() {
  return &::firmware_interfaces::srv::rosidl_typesupport_c::Status_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "firmware_interfaces/srv/detail/status__struct.h"
// already included above
// #include "firmware_interfaces/srv/detail/status__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace firmware_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Status_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Status_Response_type_support_ids_t;

static const _Status_Response_type_support_ids_t _Status_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Status_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Status_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Status_Response_type_support_symbol_names_t _Status_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, firmware_interfaces, srv, Status_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, firmware_interfaces, srv, Status_Response)),
  }
};

typedef struct _Status_Response_type_support_data_t
{
  void * data[2];
} _Status_Response_type_support_data_t;

static _Status_Response_type_support_data_t _Status_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Status_Response_message_typesupport_map = {
  2,
  "firmware_interfaces",
  &_Status_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Status_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Status_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Status_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Status_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace firmware_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, firmware_interfaces, srv, Status_Response)() {
  return &::firmware_interfaces::srv::rosidl_typesupport_c::Status_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "firmware_interfaces/srv/detail/status__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace firmware_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Status_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Status_type_support_ids_t;

static const _Status_type_support_ids_t _Status_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Status_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Status_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Status_type_support_symbol_names_t _Status_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, firmware_interfaces, srv, Status)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, firmware_interfaces, srv, Status)),
  }
};

typedef struct _Status_type_support_data_t
{
  void * data[2];
} _Status_type_support_data_t;

static _Status_type_support_data_t _Status_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Status_service_typesupport_map = {
  2,
  "firmware_interfaces",
  &_Status_service_typesupport_ids.typesupport_identifier[0],
  &_Status_service_typesupport_symbol_names.symbol_name[0],
  &_Status_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Status_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Status_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace firmware_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, firmware_interfaces, srv, Status)() {
  return &::firmware_interfaces::srv::rosidl_typesupport_c::Status_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
