//********************************************************************
// Copyright (c) 2000 by Axiowave Networks, Inc. All rights reserved.
// This software, including  any upgrades, modified versions or updates of
// the same which may be provided to you by Axiowave Networks, Inc. by
// license or otherwise (the "Software"), is owned by Axiowave Networks,
// Inc., and is protected by United States Copyright Law and International
// Treaty provisions. You agree not to modify, adapt, translate, reverse
// engineer, decompile, disassemble, or otherwise attempt to discover the
// source code of the Software.
//********************************************************************

//********************************************************************
// include files
//********************************************************************
#include <stdio.h>
#include <stdlib.h>
#include "ax_string.hpp"

//********************************************************************
// definitions/macros
//********************************************************************

//********************************************************************
// constants
//********************************************************************

//********************************************************************
// static member initialization
//********************************************************************
const char * ax_string::m_zLenStr = "";

//********************************************************************
// forward declerations
//********************************************************************

//********************************************************************
// global functions
//********************************************************************
void *
ax_string_allocate_mem(size_t numBytes)
{
#ifdef USE_STDC_MALLOC
  return ((void *) malloc(numBytes));
#else
  return ((void *) new char[numBytes]);
#endif
}


void
ax_string_free_mem(void *& ptr)
{
  if (ptr) {
#ifdef USE_STDC_MALLOC
    free(ptr);
#else
    delete [] ptr;
#endif
    ptr = NULL;
  }
}


//********************************************************************
// global function: ax_string_copy
// requirements: dest and src pointers need to be valid
//********************************************************************
void
ax_string_copy(char * dest, const char * src, size_t len)
{
  memcpy(dest, src, len);
  dest[len] = '\0';
}


#if 0
//********************************************************************
// global function: ax_string_allocate_and_copy
// requirements: ... none for now ...
//********************************************************************
void
ax_string_allocate_and_copy(char * dest, char * src)
{
  if (src) {
    int len = strlen(src);
    if (len && len <= ax_string_max_str_len) {
      m_dataPtr = (char *) ax_string_allocate_mem(len+1);
      if (m_dataPtr) {
        // memcpy(m_dataPtr, val, len);
        // m_dataPtr[len] = '\0';
        ax_string_copy(m_dataPtr, src);
      }
    }
  }

}
#endif


//********************************************************************
// default constructor:
//********************************************************************
ax_string::ax_string() :
  m_dataPtr(NULL)
{
}

//********************************************************************
// destructor:
//********************************************************************
ax_string::~ax_string()
{
  if (m_dataPtr) {
    ax_string_free_mem((void *&) m_dataPtr);
  }
}


//********************************************************************
// data constructor:
//********************************************************************
ax_string::ax_string(const char * val) :
  m_dataPtr(NULL)
{
  if (val) {
    int len = strlen(val);
    if (len && len <= ax_string_max_str_len) {
      m_dataPtr = (char *) ax_string_allocate_mem(len+1);
      if (m_dataPtr) {
        ax_string_copy(m_dataPtr, val, len);
      }
    }
  }
}


//********************************************************************
// copy constructor:
//********************************************************************
ax_string::ax_string(const ax_string & in) :
  m_dataPtr(NULL)
{
  int len = strlen(in.c_str());
  if (len && len <= ax_string_max_str_len) {
    m_dataPtr = (char *) ax_string_allocate_mem(len+1);
    if (m_dataPtr) {
      ax_string_copy(m_dataPtr, in.c_str(), len);
    }
  }
}


//********************************************************************
// method : c_str
//********************************************************************
const char *
ax_string::c_str(void) const
{
  const char * ret;

  if (m_dataPtr) {
    ret = m_dataPtr;
  } else {
    ret = m_zLenStr;
  }

  return (ret);
}


//********************************************************************
// method: Assignment operator
//********************************************************************
ax_string &
ax_string::operator=(const ax_string & in)
{

  if (this == &in) {
    return (*this);
  }

  if (m_dataPtr) {
    ax_string_free_mem((void *&) m_dataPtr);
  }

  int len = strlen(in.c_str());
  if (len && len <= ax_string_max_str_len) {
    m_dataPtr = (char *) ax_string_allocate_mem(len+1);
    if (m_dataPtr) {
      ax_string_copy(m_dataPtr, in.c_str(), len);
    }
  }

  return (*this);
}


//********************************************************************
// method: Assignment operator
//********************************************************************
ax_string &
ax_string::operator=(const char * in)
{

  if (m_dataPtr) {
    ax_string_free_mem((void *&) m_dataPtr);
  }

  if (!in) {
    return (*this);
  }

  int len = strlen(in);
  if (len && len <= ax_string_max_str_len) {
    m_dataPtr = (char *) ax_string_allocate_mem(len+1);
    if (m_dataPtr) {
      ax_string_copy(m_dataPtr, in, len);
    }
  }

  return (*this);
}


