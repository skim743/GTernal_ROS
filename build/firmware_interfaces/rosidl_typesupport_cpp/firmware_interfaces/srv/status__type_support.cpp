// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from firmware_interfaces:srv/Status.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "firmware_interfaces/srv/detail/status__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace firmware_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Status_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Status_Request_type_support_ids_t;

static const _Status_Request_type_support_ids_t _Status_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, firmware_interfaces, srv, Status_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, firmware_interfaces, srv, Status_Request)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Status_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace firmware_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<firmware_interfaces::srv::Status_Request>()
{
  return &::firmware_interfaces::srv::rosidl_typesupport_cpp::Status_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, firmware_interfaces, srv, Status_Request)() {
  return get_message_type_support_handle<firmware_interfaces::srv::Status_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "firmware_interfaces/srv/detail/status__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace firmware_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Status_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Status_Response_type_support_ids_t;

static const _Status_Response_type_support_ids_t _Status_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, firmware_interfaces, srv, Status_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, firmware_interfaces, srv, Status_Response)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Status_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace firmware_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<firmware_interfaces::srv::Status_Response>()
{
  return &::firmware_interfaces::srv::rosidl_typesupport_cpp::Status_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, firmware_interfaces, srv, Status_Response)() {
  return get_message_type_support_handle<firmware_interfaces::srv::Status_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "firmware_interfaces/srv/detail/status__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace firmware_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _Status_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Status_type_support_ids_t;

static const _Status_type_support_ids_t _Status_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, firmware_interfaces, srv, Status)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, firmware_interfaces, srv, Status)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Status_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace firmware_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<firmware_interfaces::srv::Status>()
{
  return &::firmware_interfaces::srv::rosidl_typesupport_cpp::Status_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
