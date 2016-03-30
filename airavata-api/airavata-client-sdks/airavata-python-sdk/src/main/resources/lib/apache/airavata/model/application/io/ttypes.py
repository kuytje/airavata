#
# Autogenerated by Thrift Compiler (0.9.3)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#
#  options string: py
#

from thrift.Thrift import TType, TMessageType, TException, TApplicationException
import apache.airavata.model.appcatalog.computeresource.ttypes


from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol, TProtocol
try:
  from thrift.protocol import fastbinary
except:
  fastbinary = None


class DataType:
  """
  Data Types supported in Airavata. The primitive data types

  """
  STRING = 0
  INTEGER = 1
  FLOAT = 2
  URI = 3
  STDOUT = 4
  STDERR = 5

  _VALUES_TO_NAMES = {
    0: "STRING",
    1: "INTEGER",
    2: "FLOAT",
    3: "URI",
    4: "STDOUT",
    5: "STDERR",
  }

  _NAMES_TO_VALUES = {
    "STRING": 0,
    "INTEGER": 1,
    "FLOAT": 2,
    "URI": 3,
    "STDOUT": 4,
    "STDERR": 5,
  }


class InputDataObjectType:
  """
  Application Inputs. The paramters describe how inputs are passed to the application.

  name:
    Name of the parameter.

  value:
    Value of the parameter. A default value could be set during registration.

  type:
    Data type of the parameter

  applicationArguement:
    The argument flag sent to the application. Such as -p pressure.

  standardInput:
    When this value is set, the parameter is sent as standard input rather than a parameter.
    Typically this is passed using redirection operator ">".

  userFriendlyDescription:
    Description to be displayed at the user interface.

  metaData:
    Any metadat. This is typically ignore by Airavata and is used by gateways for application configuration.


  Attributes:
   - name
   - value
   - type
   - applicationArgument
   - standardInput
   - userFriendlyDescription
   - metaData
   - inputOrder
   - isRequired
   - requiredToAddedToCommandLine
   - dataStaged
   - storageResourceId
  """

  thrift_spec = (
    None, # 0
    (1, TType.STRING, 'name', None, None, ), # 1
    (2, TType.STRING, 'value', None, None, ), # 2
    (3, TType.I32, 'type', None, None, ), # 3
    (4, TType.STRING, 'applicationArgument', None, None, ), # 4
    (5, TType.BOOL, 'standardInput', None, None, ), # 5
    (6, TType.STRING, 'userFriendlyDescription', None, None, ), # 6
    (7, TType.STRING, 'metaData', None, None, ), # 7
    (8, TType.I32, 'inputOrder', None, None, ), # 8
    (9, TType.BOOL, 'isRequired', None, None, ), # 9
    (10, TType.BOOL, 'requiredToAddedToCommandLine', None, None, ), # 10
    (11, TType.BOOL, 'dataStaged', None, None, ), # 11
    (12, TType.STRING, 'storageResourceId', None, None, ), # 12
  )

  def __init__(self, name=None, value=None, type=None, applicationArgument=None, standardInput=None, userFriendlyDescription=None, metaData=None, inputOrder=None, isRequired=None, requiredToAddedToCommandLine=None, dataStaged=None, storageResourceId=None,):
    self.name = name
    self.value = value
    self.type = type
    self.applicationArgument = applicationArgument
    self.standardInput = standardInput
    self.userFriendlyDescription = userFriendlyDescription
    self.metaData = metaData
    self.inputOrder = inputOrder
    self.isRequired = isRequired
    self.requiredToAddedToCommandLine = requiredToAddedToCommandLine
    self.dataStaged = dataStaged
    self.storageResourceId = storageResourceId

  def read(self, iprot):
    if iprot.__class__ == TBinaryProtocol.TBinaryProtocolAccelerated and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastbinary is not None:
      fastbinary.decode_binary(self, iprot.trans, (self.__class__, self.thrift_spec))
      return
    iprot.readStructBegin()
    while True:
      (fname, ftype, fid) = iprot.readFieldBegin()
      if ftype == TType.STOP:
        break
      if fid == 1:
        if ftype == TType.STRING:
          self.name = iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 2:
        if ftype == TType.STRING:
          self.value = iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 3:
        if ftype == TType.I32:
          self.type = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 4:
        if ftype == TType.STRING:
          self.applicationArgument = iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 5:
        if ftype == TType.BOOL:
          self.standardInput = iprot.readBool()
        else:
          iprot.skip(ftype)
      elif fid == 6:
        if ftype == TType.STRING:
          self.userFriendlyDescription = iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 7:
        if ftype == TType.STRING:
          self.metaData = iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 8:
        if ftype == TType.I32:
          self.inputOrder = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 9:
        if ftype == TType.BOOL:
          self.isRequired = iprot.readBool()
        else:
          iprot.skip(ftype)
      elif fid == 10:
        if ftype == TType.BOOL:
          self.requiredToAddedToCommandLine = iprot.readBool()
        else:
          iprot.skip(ftype)
      elif fid == 11:
        if ftype == TType.BOOL:
          self.dataStaged = iprot.readBool()
        else:
          iprot.skip(ftype)
      elif fid == 12:
        if ftype == TType.STRING:
          self.storageResourceId = iprot.readString()
        else:
          iprot.skip(ftype)
      else:
        iprot.skip(ftype)
      iprot.readFieldEnd()
    iprot.readStructEnd()

  def write(self, oprot):
    if oprot.__class__ == TBinaryProtocol.TBinaryProtocolAccelerated and self.thrift_spec is not None and fastbinary is not None:
      oprot.trans.write(fastbinary.encode_binary(self, (self.__class__, self.thrift_spec)))
      return
    oprot.writeStructBegin('InputDataObjectType')
    if self.name is not None:
      oprot.writeFieldBegin('name', TType.STRING, 1)
      oprot.writeString(self.name)
      oprot.writeFieldEnd()
    if self.value is not None:
      oprot.writeFieldBegin('value', TType.STRING, 2)
      oprot.writeString(self.value)
      oprot.writeFieldEnd()
    if self.type is not None:
      oprot.writeFieldBegin('type', TType.I32, 3)
      oprot.writeI32(self.type)
      oprot.writeFieldEnd()
    if self.applicationArgument is not None:
      oprot.writeFieldBegin('applicationArgument', TType.STRING, 4)
      oprot.writeString(self.applicationArgument)
      oprot.writeFieldEnd()
    if self.standardInput is not None:
      oprot.writeFieldBegin('standardInput', TType.BOOL, 5)
      oprot.writeBool(self.standardInput)
      oprot.writeFieldEnd()
    if self.userFriendlyDescription is not None:
      oprot.writeFieldBegin('userFriendlyDescription', TType.STRING, 6)
      oprot.writeString(self.userFriendlyDescription)
      oprot.writeFieldEnd()
    if self.metaData is not None:
      oprot.writeFieldBegin('metaData', TType.STRING, 7)
      oprot.writeString(self.metaData)
      oprot.writeFieldEnd()
    if self.inputOrder is not None:
      oprot.writeFieldBegin('inputOrder', TType.I32, 8)
      oprot.writeI32(self.inputOrder)
      oprot.writeFieldEnd()
    if self.isRequired is not None:
      oprot.writeFieldBegin('isRequired', TType.BOOL, 9)
      oprot.writeBool(self.isRequired)
      oprot.writeFieldEnd()
    if self.requiredToAddedToCommandLine is not None:
      oprot.writeFieldBegin('requiredToAddedToCommandLine', TType.BOOL, 10)
      oprot.writeBool(self.requiredToAddedToCommandLine)
      oprot.writeFieldEnd()
    if self.dataStaged is not None:
      oprot.writeFieldBegin('dataStaged', TType.BOOL, 11)
      oprot.writeBool(self.dataStaged)
      oprot.writeFieldEnd()
    if self.storageResourceId is not None:
      oprot.writeFieldBegin('storageResourceId', TType.STRING, 12)
      oprot.writeString(self.storageResourceId)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def validate(self):
    if self.name is None:
      raise TProtocol.TProtocolException(message='Required field name is unset!')
    return


  def __hash__(self):
    value = 17
    value = (value * 31) ^ hash(self.name)
    value = (value * 31) ^ hash(self.value)
    value = (value * 31) ^ hash(self.type)
    value = (value * 31) ^ hash(self.applicationArgument)
    value = (value * 31) ^ hash(self.standardInput)
    value = (value * 31) ^ hash(self.userFriendlyDescription)
    value = (value * 31) ^ hash(self.metaData)
    value = (value * 31) ^ hash(self.inputOrder)
    value = (value * 31) ^ hash(self.isRequired)
    value = (value * 31) ^ hash(self.requiredToAddedToCommandLine)
    value = (value * 31) ^ hash(self.dataStaged)
    value = (value * 31) ^ hash(self.storageResourceId)
    return value

  def __repr__(self):
    L = ['%s=%r' % (key, value)
      for key, value in self.__dict__.iteritems()]
    return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

  def __eq__(self, other):
    return isinstance(other, self.__class__) and self.__dict__ == other.__dict__

  def __ne__(self, other):
    return not (self == other)

class OutputDataObjectType:
  """
  Application Outputs. The paramters describe how outputs generated by the application.

  name:
    Name of the parameter.

  value:
    Value of the parameter.

  type:
    Data type of the parameter

  applicationArguement:
    The argument flag sent to the application. Such as -p pressure.

  standardInput:
    When this value is set, the parameter is sent as standard input rather than a parameter.
    Typically this is passed using redirection operator ">".

  userFriendlyDescription:
    Description to be displayed at the user interface.

  metaData:
    Any metadat. This is typically ignore by Airavata and is used by gateways for application configuration.


  Attributes:
   - name
   - value
   - type
   - applicationArgument
   - isRequired
   - requiredToAddedToCommandLine
   - dataMovement
   - location
   - searchQuery
   - outputStreaming
   - storageResourceId
  """

  thrift_spec = (
    None, # 0
    (1, TType.STRING, 'name', None, None, ), # 1
    (2, TType.STRING, 'value', None, None, ), # 2
    (3, TType.I32, 'type', None, None, ), # 3
    (4, TType.STRING, 'applicationArgument', None, None, ), # 4
    (5, TType.BOOL, 'isRequired', None, None, ), # 5
    (6, TType.BOOL, 'requiredToAddedToCommandLine', None, None, ), # 6
    (7, TType.BOOL, 'dataMovement', None, None, ), # 7
    (8, TType.STRING, 'location', None, None, ), # 8
    (9, TType.STRING, 'searchQuery', None, None, ), # 9
    (10, TType.BOOL, 'outputStreaming', None, None, ), # 10
    (11, TType.STRING, 'storageResourceId', None, None, ), # 11
  )

  def __init__(self, name=None, value=None, type=None, applicationArgument=None, isRequired=None, requiredToAddedToCommandLine=None, dataMovement=None, location=None, searchQuery=None, outputStreaming=None, storageResourceId=None,):
    self.name = name
    self.value = value
    self.type = type
    self.applicationArgument = applicationArgument
    self.isRequired = isRequired
    self.requiredToAddedToCommandLine = requiredToAddedToCommandLine
    self.dataMovement = dataMovement
    self.location = location
    self.searchQuery = searchQuery
    self.outputStreaming = outputStreaming
    self.storageResourceId = storageResourceId

  def read(self, iprot):
    if iprot.__class__ == TBinaryProtocol.TBinaryProtocolAccelerated and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None and fastbinary is not None:
      fastbinary.decode_binary(self, iprot.trans, (self.__class__, self.thrift_spec))
      return
    iprot.readStructBegin()
    while True:
      (fname, ftype, fid) = iprot.readFieldBegin()
      if ftype == TType.STOP:
        break
      if fid == 1:
        if ftype == TType.STRING:
          self.name = iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 2:
        if ftype == TType.STRING:
          self.value = iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 3:
        if ftype == TType.I32:
          self.type = iprot.readI32()
        else:
          iprot.skip(ftype)
      elif fid == 4:
        if ftype == TType.STRING:
          self.applicationArgument = iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 5:
        if ftype == TType.BOOL:
          self.isRequired = iprot.readBool()
        else:
          iprot.skip(ftype)
      elif fid == 6:
        if ftype == TType.BOOL:
          self.requiredToAddedToCommandLine = iprot.readBool()
        else:
          iprot.skip(ftype)
      elif fid == 7:
        if ftype == TType.BOOL:
          self.dataMovement = iprot.readBool()
        else:
          iprot.skip(ftype)
      elif fid == 8:
        if ftype == TType.STRING:
          self.location = iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 9:
        if ftype == TType.STRING:
          self.searchQuery = iprot.readString()
        else:
          iprot.skip(ftype)
      elif fid == 10:
        if ftype == TType.BOOL:
          self.outputStreaming = iprot.readBool()
        else:
          iprot.skip(ftype)
      elif fid == 11:
        if ftype == TType.STRING:
          self.storageResourceId = iprot.readString()
        else:
          iprot.skip(ftype)
      else:
        iprot.skip(ftype)
      iprot.readFieldEnd()
    iprot.readStructEnd()

  def write(self, oprot):
    if oprot.__class__ == TBinaryProtocol.TBinaryProtocolAccelerated and self.thrift_spec is not None and fastbinary is not None:
      oprot.trans.write(fastbinary.encode_binary(self, (self.__class__, self.thrift_spec)))
      return
    oprot.writeStructBegin('OutputDataObjectType')
    if self.name is not None:
      oprot.writeFieldBegin('name', TType.STRING, 1)
      oprot.writeString(self.name)
      oprot.writeFieldEnd()
    if self.value is not None:
      oprot.writeFieldBegin('value', TType.STRING, 2)
      oprot.writeString(self.value)
      oprot.writeFieldEnd()
    if self.type is not None:
      oprot.writeFieldBegin('type', TType.I32, 3)
      oprot.writeI32(self.type)
      oprot.writeFieldEnd()
    if self.applicationArgument is not None:
      oprot.writeFieldBegin('applicationArgument', TType.STRING, 4)
      oprot.writeString(self.applicationArgument)
      oprot.writeFieldEnd()
    if self.isRequired is not None:
      oprot.writeFieldBegin('isRequired', TType.BOOL, 5)
      oprot.writeBool(self.isRequired)
      oprot.writeFieldEnd()
    if self.requiredToAddedToCommandLine is not None:
      oprot.writeFieldBegin('requiredToAddedToCommandLine', TType.BOOL, 6)
      oprot.writeBool(self.requiredToAddedToCommandLine)
      oprot.writeFieldEnd()
    if self.dataMovement is not None:
      oprot.writeFieldBegin('dataMovement', TType.BOOL, 7)
      oprot.writeBool(self.dataMovement)
      oprot.writeFieldEnd()
    if self.location is not None:
      oprot.writeFieldBegin('location', TType.STRING, 8)
      oprot.writeString(self.location)
      oprot.writeFieldEnd()
    if self.searchQuery is not None:
      oprot.writeFieldBegin('searchQuery', TType.STRING, 9)
      oprot.writeString(self.searchQuery)
      oprot.writeFieldEnd()
    if self.outputStreaming is not None:
      oprot.writeFieldBegin('outputStreaming', TType.BOOL, 10)
      oprot.writeBool(self.outputStreaming)
      oprot.writeFieldEnd()
    if self.storageResourceId is not None:
      oprot.writeFieldBegin('storageResourceId', TType.STRING, 11)
      oprot.writeString(self.storageResourceId)
      oprot.writeFieldEnd()
    oprot.writeFieldStop()
    oprot.writeStructEnd()

  def validate(self):
    if self.name is None:
      raise TProtocol.TProtocolException(message='Required field name is unset!')
    return


  def __hash__(self):
    value = 17
    value = (value * 31) ^ hash(self.name)
    value = (value * 31) ^ hash(self.value)
    value = (value * 31) ^ hash(self.type)
    value = (value * 31) ^ hash(self.applicationArgument)
    value = (value * 31) ^ hash(self.isRequired)
    value = (value * 31) ^ hash(self.requiredToAddedToCommandLine)
    value = (value * 31) ^ hash(self.dataMovement)
    value = (value * 31) ^ hash(self.location)
    value = (value * 31) ^ hash(self.searchQuery)
    value = (value * 31) ^ hash(self.outputStreaming)
    value = (value * 31) ^ hash(self.storageResourceId)
    return value

  def __repr__(self):
    L = ['%s=%r' % (key, value)
      for key, value in self.__dict__.iteritems()]
    return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

  def __eq__(self, other):
    return isinstance(other, self.__class__) and self.__dict__ == other.__dict__

  def __ne__(self, other):
    return not (self == other)
