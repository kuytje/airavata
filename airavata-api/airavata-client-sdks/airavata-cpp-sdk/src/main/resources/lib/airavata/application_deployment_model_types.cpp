/**
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "application_deployment_model_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace apache { namespace airavata { namespace model { namespace appcatalog { namespace appdeployment {


SetEnvPaths::~SetEnvPaths() throw() {
}


void SetEnvPaths::__set_name(const std::string& val) {
  this->name = val;
}

void SetEnvPaths::__set_value(const std::string& val) {
  this->value = val;
}

void SetEnvPaths::__set_envPathOrder(const int32_t val) {
  this->envPathOrder = val;
__isset.envPathOrder = true;
}

uint32_t SetEnvPaths::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_name = false;
  bool isset_value = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          isset_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->value);
          isset_value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->envPathOrder);
          this->__isset.envPathOrder = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_name)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_value)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t SetEnvPaths::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("SetEnvPaths");

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->value);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.envPathOrder) {
    xfer += oprot->writeFieldBegin("envPathOrder", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->envPathOrder);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SetEnvPaths &a, SetEnvPaths &b) {
  using ::std::swap;
  swap(a.name, b.name);
  swap(a.value, b.value);
  swap(a.envPathOrder, b.envPathOrder);
  swap(a.__isset, b.__isset);
}

SetEnvPaths::SetEnvPaths(const SetEnvPaths& other0) {
  name = other0.name;
  value = other0.value;
  envPathOrder = other0.envPathOrder;
  __isset = other0.__isset;
}
SetEnvPaths& SetEnvPaths::operator=(const SetEnvPaths& other1) {
  name = other1.name;
  value = other1.value;
  envPathOrder = other1.envPathOrder;
  __isset = other1.__isset;
  return *this;
}
void SetEnvPaths::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "SetEnvPaths(";
  out << "name=" << to_string(name);
  out << ", " << "value=" << to_string(value);
  out << ", " << "envPathOrder="; (__isset.envPathOrder ? (out << to_string(envPathOrder)) : (out << "<null>"));
  out << ")";
}


CommandObject::~CommandObject() throw() {
}


void CommandObject::__set_command(const std::string& val) {
  this->command = val;
}

void CommandObject::__set_commandOrder(const int32_t val) {
  this->commandOrder = val;
__isset.commandOrder = true;
}

uint32_t CommandObject::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_command = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->command);
          isset_command = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->commandOrder);
          this->__isset.commandOrder = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_command)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t CommandObject::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("CommandObject");

  xfer += oprot->writeFieldBegin("command", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->command);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.commandOrder) {
    xfer += oprot->writeFieldBegin("commandOrder", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->commandOrder);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(CommandObject &a, CommandObject &b) {
  using ::std::swap;
  swap(a.command, b.command);
  swap(a.commandOrder, b.commandOrder);
  swap(a.__isset, b.__isset);
}

CommandObject::CommandObject(const CommandObject& other2) {
  command = other2.command;
  commandOrder = other2.commandOrder;
  __isset = other2.__isset;
}
CommandObject& CommandObject::operator=(const CommandObject& other3) {
  command = other3.command;
  commandOrder = other3.commandOrder;
  __isset = other3.__isset;
  return *this;
}
void CommandObject::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "CommandObject(";
  out << "command=" << to_string(command);
  out << ", " << "commandOrder="; (__isset.commandOrder ? (out << to_string(commandOrder)) : (out << "<null>"));
  out << ")";
}


ApplicationModule::~ApplicationModule() throw() {
}


void ApplicationModule::__set_appModuleId(const std::string& val) {
  this->appModuleId = val;
}

void ApplicationModule::__set_appModuleName(const std::string& val) {
  this->appModuleName = val;
}

void ApplicationModule::__set_appModuleVersion(const std::string& val) {
  this->appModuleVersion = val;
__isset.appModuleVersion = true;
}

void ApplicationModule::__set_appModuleDescription(const std::string& val) {
  this->appModuleDescription = val;
__isset.appModuleDescription = true;
}

uint32_t ApplicationModule::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_appModuleId = false;
  bool isset_appModuleName = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->appModuleId);
          isset_appModuleId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->appModuleName);
          isset_appModuleName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->appModuleVersion);
          this->__isset.appModuleVersion = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->appModuleDescription);
          this->__isset.appModuleDescription = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_appModuleId)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_appModuleName)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t ApplicationModule::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ApplicationModule");

  xfer += oprot->writeFieldBegin("appModuleId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->appModuleId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("appModuleName", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->appModuleName);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.appModuleVersion) {
    xfer += oprot->writeFieldBegin("appModuleVersion", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->appModuleVersion);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.appModuleDescription) {
    xfer += oprot->writeFieldBegin("appModuleDescription", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->appModuleDescription);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ApplicationModule &a, ApplicationModule &b) {
  using ::std::swap;
  swap(a.appModuleId, b.appModuleId);
  swap(a.appModuleName, b.appModuleName);
  swap(a.appModuleVersion, b.appModuleVersion);
  swap(a.appModuleDescription, b.appModuleDescription);
  swap(a.__isset, b.__isset);
}

ApplicationModule::ApplicationModule(const ApplicationModule& other4) {
  appModuleId = other4.appModuleId;
  appModuleName = other4.appModuleName;
  appModuleVersion = other4.appModuleVersion;
  appModuleDescription = other4.appModuleDescription;
  __isset = other4.__isset;
}
ApplicationModule& ApplicationModule::operator=(const ApplicationModule& other5) {
  appModuleId = other5.appModuleId;
  appModuleName = other5.appModuleName;
  appModuleVersion = other5.appModuleVersion;
  appModuleDescription = other5.appModuleDescription;
  __isset = other5.__isset;
  return *this;
}
void ApplicationModule::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ApplicationModule(";
  out << "appModuleId=" << to_string(appModuleId);
  out << ", " << "appModuleName=" << to_string(appModuleName);
  out << ", " << "appModuleVersion="; (__isset.appModuleVersion ? (out << to_string(appModuleVersion)) : (out << "<null>"));
  out << ", " << "appModuleDescription="; (__isset.appModuleDescription ? (out << to_string(appModuleDescription)) : (out << "<null>"));
  out << ")";
}


ApplicationDeploymentDescription::~ApplicationDeploymentDescription() throw() {
}


void ApplicationDeploymentDescription::__set_appDeploymentId(const std::string& val) {
  this->appDeploymentId = val;
}

void ApplicationDeploymentDescription::__set_appModuleId(const std::string& val) {
  this->appModuleId = val;
}

void ApplicationDeploymentDescription::__set_computeHostId(const std::string& val) {
  this->computeHostId = val;
}

void ApplicationDeploymentDescription::__set_executablePath(const std::string& val) {
  this->executablePath = val;
}

void ApplicationDeploymentDescription::__set_parallelism(const  ::apache::airavata::model::appcatalog::parallelism::ApplicationParallelismType::type val) {
  this->parallelism = val;
}

void ApplicationDeploymentDescription::__set_appDeploymentDescription(const std::string& val) {
  this->appDeploymentDescription = val;
__isset.appDeploymentDescription = true;
}

void ApplicationDeploymentDescription::__set_moduleLoadCmds(const std::vector<CommandObject> & val) {
  this->moduleLoadCmds = val;
__isset.moduleLoadCmds = true;
}

void ApplicationDeploymentDescription::__set_libPrependPaths(const std::vector<SetEnvPaths> & val) {
  this->libPrependPaths = val;
__isset.libPrependPaths = true;
}

void ApplicationDeploymentDescription::__set_libAppendPaths(const std::vector<SetEnvPaths> & val) {
  this->libAppendPaths = val;
__isset.libAppendPaths = true;
}

void ApplicationDeploymentDescription::__set_setEnvironment(const std::vector<SetEnvPaths> & val) {
  this->setEnvironment = val;
__isset.setEnvironment = true;
}

void ApplicationDeploymentDescription::__set_preJobCommands(const std::vector<CommandObject> & val) {
  this->preJobCommands = val;
__isset.preJobCommands = true;
}

void ApplicationDeploymentDescription::__set_postJobCommands(const std::vector<CommandObject> & val) {
  this->postJobCommands = val;
__isset.postJobCommands = true;
}

uint32_t ApplicationDeploymentDescription::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_appDeploymentId = false;
  bool isset_appModuleId = false;
  bool isset_computeHostId = false;
  bool isset_executablePath = false;
  bool isset_parallelism = false;

  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->appDeploymentId);
          isset_appDeploymentId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->appModuleId);
          isset_appModuleId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->computeHostId);
          isset_computeHostId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->executablePath);
          isset_executablePath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast6;
          xfer += iprot->readI32(ecast6);
          this->parallelism = ( ::apache::airavata::model::appcatalog::parallelism::ApplicationParallelismType::type)ecast6;
          isset_parallelism = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->appDeploymentDescription);
          this->__isset.appDeploymentDescription = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->moduleLoadCmds.clear();
            uint32_t _size7;
            ::apache::thrift::protocol::TType _etype10;
            xfer += iprot->readListBegin(_etype10, _size7);
            this->moduleLoadCmds.resize(_size7);
            uint32_t _i11;
            for (_i11 = 0; _i11 < _size7; ++_i11)
            {
              xfer += this->moduleLoadCmds[_i11].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.moduleLoadCmds = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->libPrependPaths.clear();
            uint32_t _size12;
            ::apache::thrift::protocol::TType _etype15;
            xfer += iprot->readListBegin(_etype15, _size12);
            this->libPrependPaths.resize(_size12);
            uint32_t _i16;
            for (_i16 = 0; _i16 < _size12; ++_i16)
            {
              xfer += this->libPrependPaths[_i16].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.libPrependPaths = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->libAppendPaths.clear();
            uint32_t _size17;
            ::apache::thrift::protocol::TType _etype20;
            xfer += iprot->readListBegin(_etype20, _size17);
            this->libAppendPaths.resize(_size17);
            uint32_t _i21;
            for (_i21 = 0; _i21 < _size17; ++_i21)
            {
              xfer += this->libAppendPaths[_i21].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.libAppendPaths = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->setEnvironment.clear();
            uint32_t _size22;
            ::apache::thrift::protocol::TType _etype25;
            xfer += iprot->readListBegin(_etype25, _size22);
            this->setEnvironment.resize(_size22);
            uint32_t _i26;
            for (_i26 = 0; _i26 < _size22; ++_i26)
            {
              xfer += this->setEnvironment[_i26].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.setEnvironment = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->preJobCommands.clear();
            uint32_t _size27;
            ::apache::thrift::protocol::TType _etype30;
            xfer += iprot->readListBegin(_etype30, _size27);
            this->preJobCommands.resize(_size27);
            uint32_t _i31;
            for (_i31 = 0; _i31 < _size27; ++_i31)
            {
              xfer += this->preJobCommands[_i31].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.preJobCommands = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->postJobCommands.clear();
            uint32_t _size32;
            ::apache::thrift::protocol::TType _etype35;
            xfer += iprot->readListBegin(_etype35, _size32);
            this->postJobCommands.resize(_size32);
            uint32_t _i36;
            for (_i36 = 0; _i36 < _size32; ++_i36)
            {
              xfer += this->postJobCommands[_i36].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.postJobCommands = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  if (!isset_appDeploymentId)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_appModuleId)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_computeHostId)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_executablePath)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  if (!isset_parallelism)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t ApplicationDeploymentDescription::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ApplicationDeploymentDescription");

  xfer += oprot->writeFieldBegin("appDeploymentId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->appDeploymentId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("appModuleId", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->appModuleId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("computeHostId", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->computeHostId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("executablePath", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->executablePath);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("parallelism", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32((int32_t)this->parallelism);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.appDeploymentDescription) {
    xfer += oprot->writeFieldBegin("appDeploymentDescription", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeString(this->appDeploymentDescription);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.moduleLoadCmds) {
    xfer += oprot->writeFieldBegin("moduleLoadCmds", ::apache::thrift::protocol::T_LIST, 7);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->moduleLoadCmds.size()));
      std::vector<CommandObject> ::const_iterator _iter37;
      for (_iter37 = this->moduleLoadCmds.begin(); _iter37 != this->moduleLoadCmds.end(); ++_iter37)
      {
        xfer += (*_iter37).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.libPrependPaths) {
    xfer += oprot->writeFieldBegin("libPrependPaths", ::apache::thrift::protocol::T_LIST, 8);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->libPrependPaths.size()));
      std::vector<SetEnvPaths> ::const_iterator _iter38;
      for (_iter38 = this->libPrependPaths.begin(); _iter38 != this->libPrependPaths.end(); ++_iter38)
      {
        xfer += (*_iter38).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.libAppendPaths) {
    xfer += oprot->writeFieldBegin("libAppendPaths", ::apache::thrift::protocol::T_LIST, 9);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->libAppendPaths.size()));
      std::vector<SetEnvPaths> ::const_iterator _iter39;
      for (_iter39 = this->libAppendPaths.begin(); _iter39 != this->libAppendPaths.end(); ++_iter39)
      {
        xfer += (*_iter39).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.setEnvironment) {
    xfer += oprot->writeFieldBegin("setEnvironment", ::apache::thrift::protocol::T_LIST, 10);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->setEnvironment.size()));
      std::vector<SetEnvPaths> ::const_iterator _iter40;
      for (_iter40 = this->setEnvironment.begin(); _iter40 != this->setEnvironment.end(); ++_iter40)
      {
        xfer += (*_iter40).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.preJobCommands) {
    xfer += oprot->writeFieldBegin("preJobCommands", ::apache::thrift::protocol::T_LIST, 11);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->preJobCommands.size()));
      std::vector<CommandObject> ::const_iterator _iter41;
      for (_iter41 = this->preJobCommands.begin(); _iter41 != this->preJobCommands.end(); ++_iter41)
      {
        xfer += (*_iter41).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.postJobCommands) {
    xfer += oprot->writeFieldBegin("postJobCommands", ::apache::thrift::protocol::T_LIST, 12);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->postJobCommands.size()));
      std::vector<CommandObject> ::const_iterator _iter42;
      for (_iter42 = this->postJobCommands.begin(); _iter42 != this->postJobCommands.end(); ++_iter42)
      {
        xfer += (*_iter42).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ApplicationDeploymentDescription &a, ApplicationDeploymentDescription &b) {
  using ::std::swap;
  swap(a.appDeploymentId, b.appDeploymentId);
  swap(a.appModuleId, b.appModuleId);
  swap(a.computeHostId, b.computeHostId);
  swap(a.executablePath, b.executablePath);
  swap(a.parallelism, b.parallelism);
  swap(a.appDeploymentDescription, b.appDeploymentDescription);
  swap(a.moduleLoadCmds, b.moduleLoadCmds);
  swap(a.libPrependPaths, b.libPrependPaths);
  swap(a.libAppendPaths, b.libAppendPaths);
  swap(a.setEnvironment, b.setEnvironment);
  swap(a.preJobCommands, b.preJobCommands);
  swap(a.postJobCommands, b.postJobCommands);
  swap(a.__isset, b.__isset);
}

ApplicationDeploymentDescription::ApplicationDeploymentDescription(const ApplicationDeploymentDescription& other43) {
  appDeploymentId = other43.appDeploymentId;
  appModuleId = other43.appModuleId;
  computeHostId = other43.computeHostId;
  executablePath = other43.executablePath;
  parallelism = other43.parallelism;
  appDeploymentDescription = other43.appDeploymentDescription;
  moduleLoadCmds = other43.moduleLoadCmds;
  libPrependPaths = other43.libPrependPaths;
  libAppendPaths = other43.libAppendPaths;
  setEnvironment = other43.setEnvironment;
  preJobCommands = other43.preJobCommands;
  postJobCommands = other43.postJobCommands;
  __isset = other43.__isset;
}
ApplicationDeploymentDescription& ApplicationDeploymentDescription::operator=(const ApplicationDeploymentDescription& other44) {
  appDeploymentId = other44.appDeploymentId;
  appModuleId = other44.appModuleId;
  computeHostId = other44.computeHostId;
  executablePath = other44.executablePath;
  parallelism = other44.parallelism;
  appDeploymentDescription = other44.appDeploymentDescription;
  moduleLoadCmds = other44.moduleLoadCmds;
  libPrependPaths = other44.libPrependPaths;
  libAppendPaths = other44.libAppendPaths;
  setEnvironment = other44.setEnvironment;
  preJobCommands = other44.preJobCommands;
  postJobCommands = other44.postJobCommands;
  __isset = other44.__isset;
  return *this;
}
void ApplicationDeploymentDescription::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ApplicationDeploymentDescription(";
  out << "appDeploymentId=" << to_string(appDeploymentId);
  out << ", " << "appModuleId=" << to_string(appModuleId);
  out << ", " << "computeHostId=" << to_string(computeHostId);
  out << ", " << "executablePath=" << to_string(executablePath);
  out << ", " << "parallelism=" << to_string(parallelism);
  out << ", " << "appDeploymentDescription="; (__isset.appDeploymentDescription ? (out << to_string(appDeploymentDescription)) : (out << "<null>"));
  out << ", " << "moduleLoadCmds="; (__isset.moduleLoadCmds ? (out << to_string(moduleLoadCmds)) : (out << "<null>"));
  out << ", " << "libPrependPaths="; (__isset.libPrependPaths ? (out << to_string(libPrependPaths)) : (out << "<null>"));
  out << ", " << "libAppendPaths="; (__isset.libAppendPaths ? (out << to_string(libAppendPaths)) : (out << "<null>"));
  out << ", " << "setEnvironment="; (__isset.setEnvironment ? (out << to_string(setEnvironment)) : (out << "<null>"));
  out << ", " << "preJobCommands="; (__isset.preJobCommands ? (out << to_string(preJobCommands)) : (out << "<null>"));
  out << ", " << "postJobCommands="; (__isset.postJobCommands ? (out << to_string(postJobCommands)) : (out << "<null>"));
  out << ")";
}

}}}}} // namespace
