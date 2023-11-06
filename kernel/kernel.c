#include "commencom/Stdio.h"
#include "commencom/Common.h"
/*
                TODO
    Add Fat(32/16/12) Support to the OS
            Ported C compiler
                BASIC
        Program Saving for BASIC
        Application Binary Support
            Saving Compiled Apps to a FS
        Add a simple GUI (Maybe)
*/
void* alloc(int n) {
    int *ptr = (int *) mem_alloc(n * sizeof(int));
    if (ptr == NULL_POINTER) {
        print("Memory not allocated.\n");
    } else {
        // Get the elements of the array
        for (int i = 0; i < n; ++i) {
//            ptr[i] = i + 1; // shorthand for *(ptr + i)
        }

        for (int i = 0; i < n; ++i) {
//            char str[256];
//            int_to_string(ptr[i], str);
//            print(str);
        }
//        print_nl();
    }
    return ptr;
}

void start_kernel() {
    clear_screen();
    print("Installing interrupt service routines (ISRs).\n");
    isr_install();

    print("Enabling external interrupts.\n");
    asm volatile("sti");

    print("Initializing keyboard (IRQ 1).\n");
    init_keyboard();

    print("Initializing dynamic memory.\n");
    init_dynamic_mem();

    clear_screen();

    print("init_dynamic_mem()\n");
    print_dynamic_node_size();
    print_dynamic_mem();
    print_nl();

    int *ptr1 = alloc(5);
    print("int *ptr1 = alloc(5)\n");
    print_dynamic_mem();
    print_nl();

    int *ptr2 = alloc(10);
    print("int *ptr2 = alloc(10)\n");
    print_dynamic_mem();
    print_nl();
    // Free up memory
    mem_free(ptr1);
    print("mem_free(ptr1)\n");
    print_dynamic_mem();
    print_nl();

    int *ptr3 = alloc(2);
    print("int *ptr3 = alloc(2)\n");
    print_dynamic_mem();
    print_nl();

    mem_free(ptr2);
    print("mem_free(ptr2)\n");
    print_dynamic_mem();
    print_nl();

    mem_free(ptr3);
    print("mem_free(ptr3)\n");
    print_dynamic_mem();
    // Clear the screen then give the welcome prompt then show C:>
    clear_screen();
    print_nl();
    print("Hello Beta Tester or Developer please use OSHelp to learn about Phoenix OS\nPlease use Help to find out all commands\n");
    print("C:> ");
}