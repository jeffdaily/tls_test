#pragma once

struct Inc
{
    void operator()();
    static int m_counter;
};

struct IncTLS
{
    void operator()();
    static thread_local int m_counter;
};
