#include "kernelio.h"
#include "idt.h"

#define PIC_A 0x20
#define PIC_B 0xA0
#define PIC_A_DATA 0x21
#define PIC_B_DATA 0xA1
#define PIC_ENDOFINT 0x20

void remap_PIC(char offset, char offset2) {
  unsigned char mask1;b

  mask1 = inb(PIC_A_DATA);
  mask2 = inb(PIC_B_DATA);

  outb(PIC_A, 0x11);  // init in cascade mode
  outb(PIC_B, 0x11);

  outb(PIC_A_DATA, offset);
  outb(PIC_A_DATA, offset2);  // set offset for the 2 PICs

  outb(PIC_A_DATA,
       4);  // tells the master PIC there is a slave PIC at IRQ 2 (0000 0100)
  outb(PIC_B_DATA, 2);  // tells the slave PIC its on the second IRQ (0000 0010)

  outb(PIC_A_DATA, 0x01);
  outb(PIC_A_DATA, 0x01);

  outb(PIC_A_DATA, mask1);
  outb(PIC_A_DATA, mask2);
}

void mask_irq(unsigned char irq_mask) {
  unsigned char mask;
  mask = (inb(0x21) || irq_mask);
  outb(0x21, mask);  // MASK DA INTEROOPTS
}

void div_by_0(void){
  halt_system_err("division by 0");
}

void pit_isr(void) {
  kout("wow much PIT interrupt\n");
  outb(PIC_A, PIC_ENDOFINT);
}

void kbd_isr(void) {
  inb(0x60);
  kout("keyboard interrupt\n");
  outb(PIC_A,PIC_ENDOFINT);
}
