// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from firmware_interfaces:srv/Status.idl
// generated code does not contain a copyright notice

#ifndef FIRMWARE_INTERFACES__SRV__DETAIL__STATUS__STRUCT_HPP_
#define FIRMWARE_INTERFACES__SRV__DETAIL__STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__firmware_interfaces__srv__Status_Request __attribute__((deprecated))
#else
# define DEPRECATED__firmware_interfaces__srv__Status_Request __declspec(deprecated)
#endif

namespace firmware_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Status_Request_
{
  using Type = Status_Request_<ContainerAllocator>;

  explicit Status_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit Status_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    firmware_interfaces::srv::Status_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const firmware_interfaces::srv::Status_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<firmware_interfaces::srv::Status_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<firmware_interfaces::srv::Status_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      firmware_interfaces::srv::Status_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<firmware_interfaces::srv::Status_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      firmware_interfaces::srv::Status_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<firmware_interfaces::srv::Status_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<firmware_interfaces::srv::Status_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<firmware_interfaces::srv::Status_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__firmware_interfaces__srv__Status_Request
    std::shared_ptr<firmware_interfaces::srv::Status_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__firmware_interfaces__srv__Status_Request
    std::shared_ptr<firmware_interfaces::srv::Status_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Status_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const Status_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Status_Request_

// alias to use template instance with default allocator
using Status_Request =
  firmware_interfaces::srv::Status_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace firmware_interfaces


#ifndef _WIN32
# define DEPRECATED__firmware_interfaces__srv__Status_Response __attribute__((deprecated))
#else
# define DEPRECATED__firmware_interfaces__srv__Status_Response __declspec(deprecated)
#endif

namespace firmware_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Status_Response_
{
  using Type = Status_Response_<ContainerAllocator>;

  explicit Status_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->batt_volt = 0.0f;
      this->charge_status = false;
    }
  }

  explicit Status_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->batt_volt = 0.0f;
      this->charge_status = false;
    }
  }

  // field types and members
  using _batt_volt_type =
    float;
  _batt_volt_type batt_volt;
  using _charge_status_type =
    bool;
  _charge_status_type charge_status;

  // setters for named parameter idiom
  Type & set__batt_volt(
    const float & _arg)
  {
    this->batt_volt = _arg;
    return *this;
  }
  Type & set__charge_status(
    const bool & _arg)
  {
    this->charge_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    firmware_interfaces::srv::Status_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const firmware_interfaces::srv::Status_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<firmware_interfaces::srv::Status_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<firmware_interfaces::srv::Status_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      firmware_interfaces::srv::Status_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<firmware_interfaces::srv::Status_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      firmware_interfaces::srv::Status_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<firmware_interfaces::srv::Status_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<firmware_interfaces::srv::Status_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<firmware_interfaces::srv::Status_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__firmware_interfaces__srv__Status_Response
    std::shared_ptr<firmware_interfaces::srv::Status_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__firmware_interfaces__srv__Status_Response
    std::shared_ptr<firmware_interfaces::srv::Status_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Status_Response_ & other) const
  {
    if (this->batt_volt != other.batt_volt) {
      return false;
    }
    if (this->charge_status != other.charge_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const Status_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Status_Response_

// alias to use template instance with default allocator
using Status_Response =
  firmware_interfaces::srv::Status_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace firmware_interfaces

namespace firmware_interfaces
{

namespace srv
{

struct Status
{
  using Request = firmware_interfaces::srv::Status_Request;
  using Response = firmware_interfaces::srv::Status_Response;
};

}  // namespace srv

}  // namespace firmware_interfaces

#endif  // FIRMWARE_INTERFACES__SRV__DETAIL__STATUS__STRUCT_HPP_
