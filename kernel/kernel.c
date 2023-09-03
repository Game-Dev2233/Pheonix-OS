#include "../cpu/idt.h"
#include "../cpu/isr.h"
#include "../cpu/timer.h"
#include "../drivers/display.h"
#include "../drivers/keyboard.h"
#include "util.h"
#include "mem.h"
#include "commencom/TODO.h"
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

/*
this is just a empty command template
else if (compare_string(input, "") == 0) {
        print("\nC:> ");
    }
*/
// Defines the execute command for well executing commands
// Defines the execute command for well-executing commands
void execute_command(char *input) {
    if (compare_string(input, "EXIT") == 0) {
        // clears the screen to make it seem like it just shut down
        clear_screen();
        // halts the CPU then the entire CPU just is off
        asm volatile("hlt");
    } else if (compare_string(input, "TODO") == 0) {
        todolist();
        print("\nC:> ");
    } else if (compare_string(input, "CLEAR") == 0) {
        // clears the screen
        clear_screen();
        print("\nC:> ");
    } else if (compare_string(input, "CLS") == 0) {
        clear_screen();
        print("\nC:> ");
    } else if (compare_string(input, "HELLO") == 0) {
        print("Hello, World!\n");
        print("\nC:> ");
    } else if (compare_string(input, "OSHELP") == 0) {
        print("Phoenix OS is a simple Terminal OS with simple IO basic memory management and a\n");
        print("simple planned Filesystem Without folders and a simple x86_64-elf-gcc compiler\n");
        print("port");
        print("\nC:> ");
    } else if (compare_string(input, "HELP") == 0) {
        print("Exit: Shutdown the device\nClear or CLS: Clear the screen\nHello: Says Hello, World!\nHelp: Shows all commands\nOSHelp: Shows Info and plans for the OS");
        print("\nC:> ");
    } else if (compare_string(input, "") == 0) {
        print("\nC:> ");
    } else {
        print("Illegal command: ");
        print(input);
        print("\nC:> ");
    }
}