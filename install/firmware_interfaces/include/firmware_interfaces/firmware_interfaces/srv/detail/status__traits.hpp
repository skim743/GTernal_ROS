// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from firmware_interfaces:srv/Status.idl
// generated code does not contain a copyright notice

#ifndef FIRMWARE_INTERFACES__SRV__DETAIL__STATUS__TRAITS_HPP_
#define FIRMWARE_INTERFACES__SRV__DETAIL__STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "firmware_interfaces/srv/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace firmware_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Status_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Status_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Status_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace firmware_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use firmware_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const firmware_interfaces::srv::Status_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  firmware_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use firmware_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const firmware_interfaces::srv::Status_Request & msg)
{
  return firmware_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<firmware_interfaces::srv::Status_Request>()
{
  return "firmware_interfaces::srv::Status_Request";
}

template<>
inline const char * name<firmware_interfaces::srv::Status_Request>()
{
  return "firmware_interfaces/srv/Status_Request";
}

template<>
struct has_fixed_size<firmware_interfaces::srv::Status_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<firmware_interfaces::srv::Status_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<firmware_interfaces::srv::Status_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace firmware_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Status_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: batt_volt
  {
    out << "batt_volt: ";
    rosidl_generator_traits::value_to_yaml(msg.batt_volt, out);
    out << ", ";
  }

  // member: charge_status
  {
    out << "charge_status: ";
    rosidl_generator_traits::value_to_yaml(msg.charge_status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Status_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: batt_volt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "batt_volt: ";
    rosidl_generator_traits::value_to_yaml(msg.batt_volt, out);
    out << "\n";
  }

  // member: charge_status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charge_status: ";
    rosidl_generator_traits::value_to_yaml(msg.charge_status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Status_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace firmware_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use firmware_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const firmware_interfaces::srv::Status_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  firmware_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use firmware_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const firmware_interfaces::srv::Status_Response & msg)
{
  return firmware_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<firmware_interfaces::srv::Status_Response>()
{
  return "firmware_interfaces::srv::Status_Response";
}

template<>
inline const char * name<firmware_interfaces::srv::Status_Response>()
{
  return "firmware_interfaces/srv/Status_Response";
}

template<>
struct has_fixed_size<firmware_interfaces::srv::Status_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<firmware_interfaces::srv::Status_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<firmware_interfaces::srv::Status_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<firmware_interfaces::srv::Status>()
{
  return "firmware_interfaces::srv::Status";
}

template<>
inline const char * name<firmware_interfaces::srv::Status>()
{
  return "firmware_interfaces/srv/Status";
}

template<>
struct has_fixed_size<firmware_interfaces::srv::Status>
  : std::integral_constant<
    bool,
    has_fixed_size<firmware_interfaces::srv::Status_Request>::value &&
    has_fixed_size<firmware_interfaces::srv::Status_Response>::value
  >
{
};

template<>
struct has_bounded_size<firmware_interfaces::srv::Status>
  : std::integral_constant<
    bool,
    has_bounded_size<firmware_interfaces::srv::Status_Request>::value &&
    has_bounded_size<firmware_interfaces::srv::Status_Response>::value
  >
{
};

template<>
struct is_service<firmware_interfaces::srv::Status>
  : std::true_type
{
};

template<>
struct is_service_request<firmware_interfaces::srv::Status_Request>
  : std::true_type
{
};

template<>
struct is_service_response<firmware_interfaces::srv::Status_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // FIRMWARE_INTERFACES__SRV__DETAIL__STATUS__TRAITS_HPP_
