#include "Stdio.h"
#include "TODO.h"
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