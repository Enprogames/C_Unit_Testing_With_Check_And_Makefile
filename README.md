# Check Unit Testing with Makefile
This repository contains a simple example of how to use [Check](https://libcheck.github.io/check/) with a Makefile.

I am very new to the C programming language, and after spending extensive time unit testing in other languages, I wanted to have some way of unit testing my C code. The official [Check](https://libcheck.github.io/check/) documentation is very good, but it requires you to use CMake, and I had a hard time finding a simple example of how to use Check with a simple Makefile.

There are a few pitfalls that I ran into when trying to use Check with a Makefile, and I wanted to share my solution with others who might be struggling with the same issues. Here are the issues I ran into:
- I am running Check on Ubuntu 20.04, and the version of Check in the Ubuntu repository is 0.10. The latest version of Check at the time of writing is 0.15, and there are some large differences between these versions. After doing some research, I found that the only way to use the latest version was to build from source. I have included instructions on how to do this below.
- The libraries that you have to link when using check aren't obvious. I had to do some digging to find out which libraries I needed to link. I have included these in the Makefile. Whenever you compile a testing binary using check, you need to include `-pthread -lcheck -lrt -lm`. The libraries are as follows:
    - `-pthread`: This is the POSIX thread library. Check uses threads to run the tests.
    - `-lcheck`: This is the Check library.
    - `-lrt`: This is the POSIX real-time library.
    - `-lm`: This is the math library.

## The Program
To demonstrate how unit testing can be achieved, I have created a very simple geometry program. The focus here is not on the program's functionality but on demonstrating unit testing. I wanted to have something simple, then use unit testing to ensure it works properly. The program contains the following components:
- `point`: Has a `Point2D` struct, and a function to calculate the distance between two points.
- `vector`: Has a `Vector` struct, and functions to calculate the magnitude of a vector, and for calculating the dot product of two vectors.


## Unit Tests
If you've gotten this far, and you've unit tested using other languages, you've probably discovered that unit testing in C is a bit weird. The main reason for this is that C doesn't have a built-in testing framework. This means that you either have to setup your own tests (e.g. using `assert.h`), or use a third-party library like `check` or `google-test`. I chose to use `check` because it is written in pure C, and it was the first I encountered. It also seemed to be the most simple to use with a Makefile (please message me if you find a way to use `google-test` with a Makefile!). These aspects of `check` make it a good choice for beginners, or anyone writing a small to medium sized C project.

The unit tests are located in the `tests` directory. There are three test files:
- `test_point`: Tests the `Point2D` struct, and the `distance` function.
- `test_vector`: Tests the `Vector` struct, and the `magnitude` and `dot_product` functions.
- `test_all`: The main testing binary. This runs all of the tests. This is the binary that is run when you run `make test`. In the future, I would like to expand this to run individual tests, or groups of tests.

## Makefile
This is not a Makefile tutorial. If you don't understand what's going on in the Makefile, please familiarize yourself with Makefiles. There are plenty of good tutorials out there.

## Usage
1. Clone the repository: `git clone <CLONE_URL>`
2. Change to the directory: `cd c_unit_testing_with_check_and_makefile`
3. Compile the program: `make`
4. Run the program: `make run`
5. Run the unit tests: `make test`
6. Clean up the build files: `make clean`
    - Do this whenever you make changes to the code, and want to recompile and retest.

## Install (Build) Check from Source
As mentioned in the introduction, I am running Ubuntu 20.04, and the version of Check in the Ubuntu repository is 0.10. But this is not the latest version of Check. Please build from source if you want to use the latest version of Check. This can be done with the following steps:

1. Download the latest check version .tar.gz file: [Check Releases](https://github.com/libcheck/check/releases)
2. Unpack the tar file somewhere temporary: `tar -xvzf check-*.tar.gz`
3. Change to the directory: `cd check-*`
4. Build from source ([Check Documentation](https://libcheck.github.io/check/web/install.html#linuxsource)):
    ```bash
    $ ./configure
    $ make
    $ make check
    $ sudo make install
    ```
5. Refresh library cache: `sudo ldconfig`
6. Check if the library is installed: `pkg-config --modversion check`
    - If the library is installed, you should see the version number output to the terminal e.g. `0.15.2`. This command might require sudo access.

## Install C on Ubuntu
If you are using Ubuntu, you may need to install the GCC compiler. You can do this by running the following command:
```bash
$ sudo apt install build-essential
$ gcc --version
```

## Resources
I used the following resources to learn how to use Check with a Makefile:

- [Check Documentation](https://libcheck.github.io/check/doc/check_html/index.html)
- [CS5600 Introduction to Unit Testing C code with Check](https://www.ccs.neu.edu/home/skotthe/classes/cs5600/fall/2015/labs/intro-check.html)
- [Using C unit testing framework Check without Autotools?](https://stackoverflow.com/a/15046864/6946463)

## Contributing
If you have any suggestions, please open an issue or a pull request. I am very new to C, and I am sure there are better ways to do things. I would love to hear your feedback!
