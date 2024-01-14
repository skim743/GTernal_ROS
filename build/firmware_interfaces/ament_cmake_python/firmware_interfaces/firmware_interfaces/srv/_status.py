# generated from rosidl_generator_py/resource/_idl.py.em
# with input from firmware_interfaces:srv/Status.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Status_Request(type):
    """Metaclass of message 'Status_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('firmware_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'firmware_interfaces.srv.Status_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__status__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__status__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__status__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__status__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__status__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Status_Request(metaclass=Metaclass_Status_Request):
    """Message class 'Status_Request'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_Status_Response(type):
    """Metaclass of message 'Status_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('firmware_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'firmware_interfaces.srv.Status_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__status__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__status__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__status__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__status__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__status__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Status_Response(metaclass=Metaclass_Status_Response):
    """Message class 'Status_Response'."""

    __slots__ = [
        '_batt_volt',
        '_charge_status',
    ]

    _fields_and_field_types = {
        'batt_volt': 'float',
        'charge_status': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.batt_volt = kwargs.get('batt_volt', float())
        self.charge_status = kwargs.get('charge_status', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.batt_volt != other.batt_volt:
            return False
        if self.charge_status != other.charge_status:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def batt_volt(self):
        """Message field 'batt_volt'."""
        return self._batt_volt

    @batt_volt.setter
    def batt_volt(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'batt_volt' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'batt_volt' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._batt_volt = value

    @builtins.property
    def charge_status(self):
        """Message field 'charge_status'."""
        return self._charge_status

    @charge_status.setter
    def charge_status(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'charge_status' field must be of type 'bool'"
        self._charge_status = value


class Metaclass_Status(type):
    """Metaclass of service 'Status'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('firmware_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'firmware_interfaces.srv.Status')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__status

            from firmware_interfaces.srv import _status
            if _status.Metaclass_Status_Request._TYPE_SUPPORT is None:
                _status.Metaclass_Status_Request.__import_type_support__()
            if _status.Metaclass_Status_Response._TYPE_SUPPORT is None:
                _status.Metaclass_Status_Response.__import_type_support__()


class Status(metaclass=Metaclass_Status):
    from firmware_interfaces.srv._status import Status_Request as Request
    from firmware_interfaces.srv._status import Status_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
