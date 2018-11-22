#include "BaseStream.h"

#include "tool.h"

using namespace std;


bool CQ::BaseStream::isRAW() { return raw; }

void CQ::BaseStream::clear() { buf.clear(); }

BaseStream & CQ::BaseStream::append(const string & s) { buf += (raw ? msg_encode(string(s)) : s); return *this; }

BaseStream & CQ::BaseStream::operator<<(const string & s) { return (*this).append(s); }

BaseStream & CQ::BaseStream::append(const char * s) { buf += (raw ? msg_encode(string(s)) : s); return *this; }

BaseStream & CQ::BaseStream::operator<<(const char * c) { return (*this).append(c); }

BaseStream & CQ::BaseStream::append(const bool & i) { buf += i ? "true" : "false"; return *this; }

BaseStream & CQ::BaseStream::operator<<(const bool & i) { return (*this).append(i); }

BaseStream & CQ::BaseStream::append(const int & i) { buf += to_string(i); return *this; }

BaseStream & CQ::BaseStream::operator<<(const int & i) { return (*this).append(i); }

BaseStream & CQ::BaseStream::append(const size_t & i) { buf += to_string(i); return *this; }

BaseStream & CQ::BaseStream::operator<<(const size_t & i) { return (*this).append(i); }

BaseStream & CQ::BaseStream::append(const double & i) { buf += to_string(i); return *this; }

BaseStream & CQ::BaseStream::operator<<(const double & i) { return (*this).append(i); }

BaseStream & CQ::BaseStream::append(const long & i) { buf += to_string(i); return *this; }

BaseStream & CQ::BaseStream::operator<<(const long & i) { return (*this).append(i); }

BaseStream & CQ::BaseStream::append(const long long & l) { buf += to_string(l); return *this; }

BaseStream & CQ::BaseStream::operator<<(const long long & l) { return (*this).append(l); }

BaseStream & CQ::BaseStream::operator<<(void(*control)(BaseStream &)) { control(*this); return *this; }

void CQ::BaseStream::FLUSH() { SEND(); }

 CQ::BaseStream::~BaseStream() {}


