/* GNU Objective C Runtime native exceptions
   Copyright (C) 2010-2025 Free Software Foundation, Inc.
   Contributed by Nicola Pero <nicola.pero@meta-innovation.com>

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#ifndef __objc_exception_INCLUDE_GNU
#define __objc_exception_INCLUDE_GNU

#include "objc.h"
#include "objc-decls.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 'objc_exception_throw' throws the exception 'exception', which is
   an exception object.

   Calls to 'objc_exception_throw' are automatically generated by the
   compiler: an Objective-C "@throw exception;" statement gets
   compiled into the equivalent of "objc_exception_throw
   (exception);".

   'objc_exception_throw' searches for a @catch() that can catch the
   exception.  By default, @catch (MyClass object) will catch all
   exception objects that are of class MyClass or of a subclass of
   MyClass; if the exception object is 'nil', then the exception can
   only be caught with a catch-all exception handler where no
   exception class is specified (such as @catch(id object)).  This
   behaviour can be customized by setting an 'objc_exception_matcher'
   function (using objc_set_exception_matcher(), see below); if one is
   set, it is used instead of the default one.

   If the exception is uncaught (there is no @catch() to catch it),
   the program aborts.  It is possible to customize this behaviour by
   setting an 'objc_uncaught_exception_handler' function (using
   objc_set_uncaught_exception_handler(), see below); if one is set,
   it is executed before abort() is called.  An uncaught exception
   handler is expected to never return.  */
objc_EXPORT void objc_exception_throw (id exception);

/* Compatibility note: the Apple/NeXT runtime seems to also have
   objc_exception_rethrow(), objc_begin_catch() and objc_end_catch().
   Currently the GNU runtime does not use them.  */

/* The following functions allow customizing to a certain extent the
   exception handling.  They are not thread safe and should be called
   during the program initialization before threads are started.  They
   are mostly reserved for "Foundation" libraries; in the case of
   GNUstep, GNUstep Base may be using these functions to improve the
   standard exception handling.  You probably shouldn't use these
   functions unless you are writing your own Foundation library.  */

/* Compatibility note: objc_set_exception_preprocessor() (available on
   the Apple/NeXT runtime) is not available on the GNU runtime.  */

/* An 'objc_exception_matcher' function is used to match an exception
   to a @catch clause.  'catch_class' is the class of objects caught
   by the @catch clause (for example, in "@catch (Object *o)", the
   catch_class is Object).  It should return 1 if the exception should
   be caught by a @catch with a catch_class argument, and 0 if
   not.  */
typedef int (*objc_exception_matcher)(Class catch_class, id exception);

/* Sets a new exception matcher function, and returns the previous
   exception matcher function.  This function is not safe to call in a
   multi-threaded environment because other threads may be trying to
   invoke the exception matcher while you change it!  */
objc_EXPORT objc_exception_matcher
objc_setExceptionMatcher (objc_exception_matcher new_matcher);


/* An 'objc_uncaught_exception_handler' function is a function that
   handles uncaught exceptions.  It should never return.  */
typedef void (*objc_uncaught_exception_handler)(id exception);

/* Sets a new uncaught exception handler function, and returns the
   previous exception handler function.  This function is not safe to
   call in a multi-threaded environment because other threads may be
   trying to invoke the uncaught exception handler while you change
   it.  */
objc_EXPORT objc_uncaught_exception_handler
objc_setUncaughtExceptionHandler (objc_uncaught_exception_handler new_handler);

#ifdef __cplusplus
}
#endif

#endif /* not __objc_exception_INCLUDE_GNU */
