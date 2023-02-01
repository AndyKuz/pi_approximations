# Assignment 2
Name: Andrew Kuznetsov
Cruz ID: akuznet2

## Short Description:
For this assignment we converted multiple formulas to approximate the respective values of pi, e, and square root of numbers into .c files. Each one
of these .c files utilized a unique famous formula, and we ran these files using the file, mathlib-test.c.

## Build:
To build the files you have two main options you can either run $ make or $ make all this converts the .c files into .o files so that the functions
can be linked between .c files and it converts mathlib-test.c into and executable mathlib-test which we can then use to run the .c files.

## Cleaning:
To clean the files you can run $ make clean which deletes all executable files aswell as any .o files

## Running:
To run the program you first must make sure you ran either $ make or $ make all, then using the executable file mathlib-test, in your command prompt
type $ ./mathlib-test followed by (-a, -s, -e, -b, -m, -r, -v, -n, -h) or a combination of all or some of them. To find out what each command
individually does simply run $ ./mathlib-test -h to print a help menu.
