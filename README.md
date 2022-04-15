# A very bad Calculator
A quick bodge-job of a GUI Calculator. Started this with the intention of getting a feel on GUI programming in C++, however I've recently made it more of a joke-y program.<br>

You shouldn't use this on your own PC. Seriously, I say this for your own good. It's a waste of space.

### If you really want to use this program, go ahead. But read this first:
The binary inside of `bin/` does not come bundled with the required libraries needed for the program to run; <i>you will need to install them yourself</i>.

The library used is [wxWidgets 3.0.5](https://www.wxwidgets.org/), which you can download using the attached link. Documentation on downloading and using the library is already provided from the creators.

However, depending on the operating system you have, there may (and likely will) be much easier ways to get the library on your system.<br>
If you're on a Linux system, for example, I recommend that you see if your package manager has the library available.<br>
The team has repositories for [Debian/Ubuntu](https://docs.codelite.org/wxWidgets/repo315/#ubuntu-and-debian) and [Fedora/openSUSE](https://docs.codelite.org/wxWidgets/repo315/#fedora-and-opensuse) users. Arch has it as well; just run `pacman -S wxgtk3 wxgtk-common`.

Finally, use this in your own projects OR even as a calculator on your own PC, if you so wish (you mad individual); I really don't care as long as you follow the license. Thanks.
