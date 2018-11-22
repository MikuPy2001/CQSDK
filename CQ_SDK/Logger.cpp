#include "Logger.h"

#include "BaseAPI.h"
#include "API.h"

CQ::Logger::Logger(std::string title) : title(title) {}

void CQ::Logger::setTitle(std::string title) { this->title = title; }


void CQ::Logger::Debug(const char * msg) const { addLog(Log_Debug, title.c_str(), msg); }
void CQ::Logger::Debug(std::string & msg) const { Debug(msg.c_str()); }

void CQ::Logger::Error(const char * msg) const { addLog(Log_Error, title.c_str(), msg); }
void CQ::Logger::Error(std::string & msg) const { Error(msg.c_str()); }

void CQ::Logger::Fatal(const char * msg) const { addLog(Log_Fatal, title.c_str(), msg); }
void CQ::Logger::Fatal(std::string & msg) const { Fatal(msg.c_str()); }

void CQ::Logger::Info(const char * msg) const { addLog(Log_Info, title.c_str(), msg); }
void CQ::Logger::Info(std::string & msg) const { Info(msg.c_str()); }

void CQ::Logger::InfoRecv(const char * msg) const { addLog(Log_InfoRecv, title.c_str(), msg); }
void CQ::Logger::InfoRecv(std::string & msg) const { InfoRecv(msg.c_str()); }

void CQ::Logger::InfoSend(const char * msg) const { addLog(Log_InfoSend, title.c_str(), msg); }
void CQ::Logger::InfoSend(std::string & msg) const { InfoSend(msg.c_str()); }

void CQ::Logger::InfoSuccess(const char * msg) const { addLog(Log_InfoSuccess, title.c_str(), msg); }
void CQ::Logger::InfoSuccess(std::string & msg) const { InfoSuccess(msg.c_str()); }

void CQ::Logger::Warning(const char * msg) const { addLog(Log_Warning, title.c_str(), msg); }
void CQ::Logger::Warning(std::string & msg) const { Warning(msg.c_str()); }


LogStream CQ::Logger::Debug() const { return LogStream(title, Log_Debug); }

LogStream CQ::Logger::Info() const { return LogStream(title, Log_Info); }

LogStream CQ::Logger::InfoSuccess() const { return LogStream(title, Log_InfoSuccess); }

LogStream CQ::Logger::InfoRecv() const { return LogStream(title, Log_InfoRecv); }

LogStream CQ::Logger::InfoSend() const { return LogStream(title, Log_InfoSend); }

LogStream CQ::Logger::Warning() const { return LogStream(title, Log_Warning); }

LogStream CQ::Logger::Error() const { return LogStream(title, Log_Error); }

LogStream CQ::Logger::Fatal() const { return LogStream(title, Log_Fatal); }