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
/**
 * struct Pf_func - format
 * _printf- print function
 * @op: pointer
 * @f: function pointer
*/
typedef struct Pf_func
{
	char *op;
	int (*f)(va_list);
} print_fun;
int _putchar(char c); /*prototype putchar*/
int _strcmp(const char *s1, char *s2);
int (*get_op_func(const char *s, int pos))(va_list);

int _pow_recursion(int x, int y);
int print_single_char(va_list c);
int print_string_char(va_list s);
int print_int(va_list i);
int print_dec(va_list d);
int print_decimal(va_list d);
int the_range(unsigned int n);
/*****************/

#endif
