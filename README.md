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

randip reads when executed 4 * 2 bytes from /dev/urandom and converts them into hexadecimal numbers.
This numbers are displayed in a form you may directly append to a /64 prefix, e. g.

	$ ./randip
	:ddde:330a:ff9a:7d43

You may use it in a bootup script like this:

(Linux, iproute2)

```bash
SUFFIX=`/usr/local/bin/randip`
ip addr add 1234:4321:5678:8765${SUFFIX}/64 dev eth0
```

So you may configure your system without the need of SLAAC (Stateless Address Autoconfiguration, as described in RFC 2462) and Privacy Extensions (RFC 4941).  This is nice when using a 6over4 tunnel which does not provide SLAAC, but you want to use changing addresses.

**ATTENTION**: This solution is not as elegant and secure as SLAAC, so use it only when you are sure what you are doing!!!

REMOVING
--------

You may uninstall randip using

    # make uninstall