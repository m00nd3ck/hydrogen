#include "../../kernel/libc/libc.h"

typedef unsigned int u32int;
typedef int s32int;
typedef unsigned short u16int;
typedef short s16int;
typedef unsigned char u8int;
typedef char s8int;

void kout(char *kouttext);
void kout_char(char koutchar);
void kout_color(char kout_color);
void clearscreen();
void initkbd();
void kin(char *kintext);
void outb(u16int port, u8int value);
void outw(u16int port, u16int value);
void halt_system_err(char *err);
void bootmsg();
unsigned char inb(u16int port);
unsigned short inw(u16int port);
unsigned int inl(u16int port);
void haltcpu(void);
void brk(void);
void kout_mem(char *membase, char *sepchar, char *memlenght, char type);
