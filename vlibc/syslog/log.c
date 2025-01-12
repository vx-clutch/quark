// Copyright (C) 2024 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.

#include "log.h"
#include "colors.h"
#include <stdarg.h>
#include <stdio.h>

void
plog(int status, const char *message)
{
  switch (status)
  {
  case 0:
    printf("[ %sINFO%s ] %s\n", PURPLE, RESET, message);
    break;
  case 1:
    printf("[ %sOKAY%s ] %s\n", GREEN, RESET, message);
    break;
  case 2:
    printf("[ %sWARN%s ] %s\n", YELLOW, RESET, message);
    break;
  case 3:
    printf("[ %sFAIL%s ] %s\n", RED, RESET, message);
    break;
  }
}

void
plogf(int status, const char *format, ...)
{
  va_list args;
  va_start(args, format);

  switch (status)
  {
  case 0:
    printf("[ %sINFO%s ] ", PURPLE, RESET);
    vprintf(format, args);
    break;
  case 1:
    printf("[ %sOKAY%s ] ", GREEN, RESET);
    vprintf(format, args);
    break;
  case 2:
    printf("[ %sWARN%s ] ", YELLOW, RESET);
    vprintf(format, args);
    break;
  case 3:
    printf("[ %sFAIL%s ] ", RED, RESET);
    vprintf(format, args);
    break;
  }
  putchar('\n');
  va_end(args);
}

/* vlibc is a simple standard-like library.
 * Copyright (C) 2024 vx-clutch
 *
 * The file is part of vlibc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions, and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions, and the following disclaimer in the documentation or
 * other materials provided with the distribution.
 * 3. Neither the name of vx-clutch nor the names of its contributors may be
 * used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
