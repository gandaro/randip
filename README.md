README for randip
=================

License: GNU GPL v3 or any later

COMPILING
---------

Compile the program with

	$ make

to build it in the current directory or use

	# make install

to install it in `/usr/local/bin`.

USE
---

randip reads 4 * 2 bytes from /dev/urandom when executed and converts them into hexadecimal numbers.
This numbers are displayed in a form you may directly append to a /64 prefix, e. g.

	$ ./randip
	:ddde:330a:ff9a:7d43

You may use it in a bootup script like this:

(Linux, iproute2)

	SUFFIX=`/usr/local/bin/randip`
	ip addr add 1234:4321:5678:8765${SUFFIX}/64 dev eth0

So you may configure your system without the need of SLAAC (Stateless Address Autoconfiguration, as described in RFC 2462) and Privacy Extensions (RFC 4941).  This is nice when using a 6over4 tunnel which does not provide SLAAC, but you still want to use changing addresses.

Don't wonder why randip may generate suffices like :dd:3322:dff:443.  As it's defined in various IPv6 recommendations and standards, leading zeroes may be ommited. 

**ATTENTION**: This solution is not as elegant and secure as SLAAC, so use it only when you are sure what you are doing!!!

REMOVING
--------

You may uninstall randip using

    # make uninstall

PLATFORMS & COMPILERS
---------------------

randip is tested with the following platforms and development tools:

 - Linux 3.1, GNU make 3.81, gcc-4.6
 - Linux 3.1, GNU make 3.81, gcc-4.7
 - OpenBSD 5.0, make included with OpenBSD 5.0, gcc (OpenBSD) 4.2.1
