/*
 * =====================================================================================
 *
 *       Filename:  Timer.h
 *
 *    Description:  Timer class with a static method.
 *
 *        Version:  1.0
 *        Created:  10/17/2012 08:57:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rodrigo Habib Gregori (rhg), rodrigo.gregori@gmail.com
 *        Company:  Universidade Tenológica Federal do Paraná
 *
 * =====================================================================================
 */
#pragma once
#ifdef WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#include <ctime>
#endif

class Timer
{
    public:
        Timer();
        ~Timer();
        static int getTimeMs();
};
