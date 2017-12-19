
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

#ifndef _ax_string_hpp_
#define _ax_string_hpp_

//********************************************************************
// include files
//********************************************************************

//********************************************************************
// definitions/macros
//********************************************************************
#define ax_string_max_str_len                                     1024

//********************************************************************
// forward declerations
//********************************************************************

/**
 * Description ... Use instead of STL <string>. Overhead is heap mem
 *                 alloc/dealloc.
 *
 *
 * file/class: ax_string.hpp
 *
 * Design Document:
 *
 * Description:
 *
 * System:
 *
 * Sub-system:
 *
 * History:
 *
 * @version 1.0
 * @author Prem Nallasivampillai
 * @see
 *
 */

class ax_string
{
public:

  /// default constructor not allowed
  ax_string();

  /// data constructor
  ax_string(const char *);

  /// destructor
  virtual ~ax_string();

  ///
  virtual const char * c_str(void) const;

  /// assignment operator
  ax_string & operator= (const ax_string &);

  /// assignment operator
  ax_string & operator= (const char *);

  /// copy constructor
  ax_string(const ax_string &);

protected:

private:

  ///
  char * m_dataPtr;

  ///
  static const char * m_zLenStr;

};

#endif // _ax_string_hpp_
