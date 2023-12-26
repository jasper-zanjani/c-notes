# Command-line parsing

There are a [variety](https://stackoverflow.com/questions/9642732/parsing-command-line-arguments-in-c) of ways to parse command-line arguments and options for creating a CLI utility, but the most immediate solution is **getopt()** ([unistd.h](../Libraries/unistd.h)).

- [**argp**](https://www.gnu.org/software/libc/manual/html_node/Argp.html) from the GNU C library which is more complex but also more powerful
- [argparse](https://github.com/Cofyc/argparse) inspired by Python's argparse module
- [opt](https://public.lanl.gov/jt/Software/)

## getopt

```c
// Parse command-line arguments and options, returning -1 on error
int     getopt  (int argc, char* argv[], const char* optstring)
```

In getopt, all options are concatenated together in the _optstring_.
Options that take arguments are suffixed by colon (**:**).

There are two potential errors that may occur as getopt() processes an option list:

- An option not specified in *optstring* is encountered.
- Argument not supplied to an option that expects one.

By default, getopt() prints an appropriate error message on STDERR and returns the character ? as the function result, assigning the erroneous character to the global variable **optopt**.
However, if the global variable **opterr** is set to 0, the error message can be suppressed and custom error handling can be implemented.
Alternatively, error messages can be suppressed by prepending colon (:) to the optstring, which suppresses error messages and also returns colorn (:) as the function result in case of a missing argument.

A command line is parsed by repeated calls to getopt in a while loop.
The call to getopt is placed as the index of a while loop which continues until the function returns -1.
A switch statement is used to dispatch on the return value from getopt.

This trivial example shows the basic structure of the syntax, but any option will return an error.

```c
--8<-- "includes/cli/cli00.c"
```

In this example, only a single command-line option is accepted.
Notice an arm has been implemented for question mark (?) which will be returned by getopt() in case of an unknown option - any option except *-a*.

```c
--8<-- "includes/cli/cli01.c"
```

The following example elaborates further, implementing option *-b* which needs an argument.
Because *optstring* is prepended by a colon (:), an additional arm is implemented to handle the error when an argument is not provided to *-b*.

```c hl_lines="8 13-14"
--8<-- "includes/cli/cli02.c"
```

This [example provided by GNU](https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html) shows how the switch statement can assign values to local variables before exiting the while loop and proceeding with execution.
Note that the question mark (**?**) case is what will process any unknown option, and the switch should never reach the default arm.

```c
--8<-- "includes/cli/clignu.c"
```