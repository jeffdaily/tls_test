#include "inc.hpp"

int Inc::m_counter = 0;
thread_local int IncTLS::m_counter = 0;

void Inc::operator()()    { ++m_counter; }
void IncTLS::operator()() { ++m_counter; }
