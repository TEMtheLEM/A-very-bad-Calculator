# A very bad Calculator
A quick bodge-job of a GUI Calculator. Started this with the intention of getting a feel of GUI programming in C++, however I've recently made it more of a joke-y program.<br>
You shouldn't use this on your own PC. Seriously, it's for your own good.

### Notice of using the application
The binary inside of `bin/` does not come bundled with the required libraries needed for the program to run; you will need to install them yourself.

The library used is [wxWidgets 3.0.5](https://www.wxwidgets.org/), which you can download using the attached link. Documentation on downloading and using the library is already provided from the creators.

However; depending on the operating system you have, there may (and likely will) be much easier ways to get the library on your system.<br>
If you're on a Linux system, for example, I recommend that you see if your package manager has the library available.<br>
The team has repositories for [Debian/Ubuntu](https://docs.codelite.org/wxWidgets/repo315/#ubuntu-and-debian) and [Fedora/openSUSE](https://docs.codelite.org/wxWidgets/repo315/#fedora-and-opensuse) users. Arch has it aswell; just run `pacman -S wxgtk3 wxgtk-common`.

Finally, use it in your own projects if you want, or even as a calculator on your own PC (you insane individual); I really don't care as long as you follow the license. Thanks.
