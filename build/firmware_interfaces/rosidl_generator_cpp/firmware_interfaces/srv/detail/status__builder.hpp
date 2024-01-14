// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from firmware_interfaces:srv/Status.idl
// generated code does not contain a copyright notice

#ifndef FIRMWARE_INTERFACES__SRV__DETAIL__STATUS__BUILDER_HPP_
#define FIRMWARE_INTERFACES__SRV__DETAIL__STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "firmware_interfaces/srv/detail/status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace firmware_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::firmware_interfaces::srv::Status_Request>()
{
  return ::firmware_interfaces::srv::Status_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace firmware_interfaces


namespace firmware_interfaces
{

namespace srv
{

namespace builder
{

class Init_Status_Response_charge_status
{
public:
  explicit Init_Status_Response_charge_status(::firmware_interfaces::srv::Status_Response & msg)
  : msg_(msg)
  {}
  ::firmware_interfaces::srv::Status_Response charge_status(::firmware_interfaces::srv::Status_Response::_charge_status_type arg)
  {
    msg_.charge_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::firmware_interfaces::srv::Status_Response msg_;
};

class Init_Status_Response_batt_volt
{
public:
  Init_Status_Response_batt_volt()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Status_Response_charge_status batt_volt(::firmware_interfaces::srv::Status_Response::_batt_volt_type arg)
  {
    msg_.batt_volt = std::move(arg);
    return Init_Status_Response_charge_status(msg_);
  }

private:
  ::firmware_interfaces::srv::Status_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::firmware_interfaces::srv::Status_Response>()
{
  return firmware_interfaces::srv::builder::Init_Status_Response_batt_volt();
}

}  // namespace firmware_interfaces

#endif  // FIRMWARE_INTERFACES__SRV__DETAIL__STATUS__BUILDER_HPP_
