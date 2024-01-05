/**
 * \file include/SigmaDev/Miscellaneous/Test.h
 * \brief Definition of C_Test and related
 * 
 * SigmaDev Library, by Dawid Jakubowski
 * Available under the MIT License
*/

#ifndef SIGMADEV_TEST_H
#define SIGMADEV_TEST_H

#include <string>
#include <SigmaDev/Miscellaneous/Class.h>
#include <SigmaDev/Miscellaneous/Common.h>

/////////////////////////////
class I_Test {
public:

protected:

};
/////////////////////////////
class C_Test : public I_Test {
public:

protected:

};
/////////////////////////////
class C_TestReturn : public C_Return {
public:

protected:

};
/////////////////////////////
#define CONNECT_TEST_TO_CORE_ENLIST(function_name)
#define TEST_RETURN_VALUE() C_TestReturn
#define TEST_ARGUMENTS() const C_Data& data, const C_References& references

#endif