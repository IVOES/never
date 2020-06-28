/** 
 * Copyright 2020 Slawomir Maludzinski
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include "module_decl.h"
#include "never.h"
#include <stdlib.h>
#include <stdio.h>

module_decl * module_decl_new(char * id, never * nev)
{
    module_decl * value = (module_decl *)malloc(sizeof(module_decl));

    value->id = id;
    value->nev = nev;

    return value;
}

void module_decl_delete(module_decl * value)
{
    if (value->id != NULL)
    {
        free(value->id);
    }
    if (value->nev != NULL)
    {
        never_delete(value->nev);
    }
    free(value);
}

void module_decl_print(module_decl * value)
{
    if (value->id != NULL)
    {
        printf("module %s\n", value->id);
    }
}