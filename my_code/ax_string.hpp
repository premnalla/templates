
//********************************************************************
// Copyright (c) 2006 Prem Nallasivamipillai. All rights reserved.
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
