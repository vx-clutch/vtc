// Copyright (C) 2025 vx-clutch ( owestness@gmail.com )
// See end of file for extended copyright information.
#ifndef EREROR_H
#define EREROR_H

#include "../config.h"
#include "../parse_args.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// ANSI color codes
extern const char *RESET;
extern const char *RED;
extern const char *PURPLE;
extern const char *WHITE;
extern const char *GREEN;
extern const char *YELLOW;

void
pfatal(const char *message);

void
pfatalf(const char *format, ...);

#define perror __perror
int
__perror(const char *message);

void
perrorf(const char *format, ...);


int
pwarning(const char *message);

void
pwarningf(const char *format, ...);

#define pdebug(desc, message) __pdebug(__LINE__, __FILE__, desc, message)
#define pdebugf(desc, message, ...) __pdebugf(__LINE__, __FILE__, desc, message, ##__VA_ARGS__)

int
__pdebug(int line, const char *file, const char *desc, const char *message);

int
__pdebugf(int line, const char *file, const char *desc, const char *format, ...);

void
plog(int status, const char *message);

void
plogf(int status, const char *format, ...);

#define INFO 0,
#define OK 1,
#define WARN 2,
#define FAIL 3,

#endif

/* vtc is a simple and extensible compiler.
 * Copyright (C) 2024 vx-clutch
 *
 * The file is part of vtc.
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

