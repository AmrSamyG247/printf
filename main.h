#ifndef _AMR_MERIEM_A
#define _AMR_MERIEM_A
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * struct print_buffer - structer for the write buffer.
 * index: current index of the buffer.
 * size: size of the buffer.
 * overflow: this recoreds the overflow.
 * str: pointer to memory that contains the content for this buffer.
 */
typedef struct print_buffer
{
	size_t index;
	size_t size;
	size_t overflow;
	char *str;
} 
buffer;
buffer *buf_new();
buffer *buf_custom(size_t);
size_t buf_size(buffer *);
size_t buf_index(buffer *);
char *buf_content(buffer *);
void buf_write(buffer *);
void buf_end(buffer *);
void buf_wr(buffer *);
void buf_inc(buffer *);

/**
 * struct print_ops - struct for the write operators.
 * op: hold a symbol that represents the operator.
 * fn: pointer function to the write functions.
 */

typedef struct print_ops
{
	char *op;
	int (*fn)(buffer *, va_list);
} 
prtOp;
prtOp *prtOp_init();
void append_num(buffer *buf, unsigned int num);
int write_bin(buffer *buf, va_list v_ls);

/* man3 pintf helper functions */

int _printf(const char *format, ...);
int opid(buffer *buf, va_list v_ls, const char *src, int src_i);
int write_char(buffer *buf, va_list v_ls);
int write_str(buffer *buf, va_list v_ls);
int write_mod(buffer *buf, va_list v_ls);
int write_int(buffer *buf, va_list v_ls);
char *itoc(int num, char *dest);

/***************/
typedef struct specifiers
{
	char *specifier;
	int (*f)(va_list args);
} spc_dt;

int _write(char c);
int _print_a_char(va_list args);
int _print_a_string(va_list args);
int _print_format(const char *format, va_list args);
int _print_spec(char format, va_list args);
int _print_invalid_spec(char prev_format, char format, int count);
int _print_a_integer(va_list args);
void _recursion_integer(int a);
int _print_int_binary(va_list args);
void _recursion_int_binary(int a);
int _validate_char(char _type);

/*****************/

#endif
