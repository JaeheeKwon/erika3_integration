#ifndef SHARED_H
#define SHARED_H

#define idle_hook_body()  __asm__ volatile("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");

#endif /* SHARED_H */
