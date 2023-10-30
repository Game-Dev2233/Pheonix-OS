#include "Stdio.h"
#include "TODO.h"

void help() {
    print("Exit: Shutdown the device\n");
    print("Clear or CLS: Clear the screen\n");
    print("Hello: Says Hello, World!\n");
    print("Help: Shows all commands\n");
    print("OSHelp: Shows Info and plans for the OS");
}

void execute_command(char *input) {
    if (compare_string(input, "EXIT") == 0) {
        // clears the screen to make it seem like it just shut down
        clear_screen();
        // halts the CPU then the entire CPU just is off
        asm volatile("hlt");
    } else if (compare_string(input, "OSVER") == 0) {
        print("OS Version 1.0");
        print("\nC:> ");
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
        print("Phoenix OS is a simple Terminal OS with simple IO and some commands\n");
        print("\nC:> ");
    } else if (compare_string(input, "HELP") == 0) {
        help();
        print("\nC:> ");
    } else if (compare_string(input, "") == 0) {
        print("\nC:> ");
    } else {
        print("Illegal command: ");
        print(input);
        print("\nC:> ");
    }
}