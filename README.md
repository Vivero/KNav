# KNav

**KNAV IS DEPRECATED, I'VE MOVED ON TO A PYTHON-BASED IMPLEMENTATION [HERE](https://github.com/Vivero/KerbalPie)**

------

KNav is a flexible platform for implementing computer-assisted navigation and control of vessels in Kerbal Space Program.

KNav is a [kRPC](https://github.com/djungelorm/krpc)-compatible CLI client, written in **C++**. KNav is currently only supported on **Windows**, and compiled with MS Visual Studio Express 2013 for Windows Desktop.

**Note:** *KNav is very new code. Support is limited at this point. Its only useful in-game capability right now is that it allows your craft to maintain a fixed-altitude hover. However, the underlying code should be useful for anyone looking to implement their own auto-pilot programming in C++.*

See it in action [here](https://youtu.be/Y5JDC383600). [Screenshot: user interface](http://i.imgur.com/AmogAGF.png)

Usage:

```
> KNav.exe [ip address]


    [ip address]              IP address of host running KSP with kRPC server plugin.
                              If unspecified, defaults to 127.0.0.1 (localhost)
                              
    Note: kRPC should run on port 50000
```

KNav requires the kRPC server plugin for KSP. Compiling KNav requires the [Google Protocol Buffers](https://developers.google.com/protocol-buffers/) library, kRPC's protocol buffer message definitions file (compiled for C++), and two libraries included in this repository:

## KRPCI
The **kRPC Interface** is a library of functions that interface with the RPC server provided by the kRPC server plugin. It implements the communication protocol described [here](http://djungelorm.github.io/krpc/docs/communication-protocol.html), for the `KRPC` service *only*.

## KRPCI_SpaceCenter
The **kRPC Interface to the SpaceCenter Service** library provides function calls to every procedure provided by the
`SpaceCenter` service in kRPC.

**KRPCI_SpaceCenter** is an auto-generated class produced by the **KRPCI_Interpreter** tool (see below).

------------------------

# KRPCI Interpreter

**KRPCI_Interpreter** is a CLI tool (independent of KNav) that polls kRPC for all available procedures in a
specified service. It then generates a .h/.cpp which defines a class that implements all the functions/classes/enum 
types for that kRPC service.

Usage:

```
> KRPCI_Interpreter.exe <service name> <output dir> [ip address]


    <service name>            The name of kRPC service to query, e.g. SpaceCenter
    <output dir>              Directory to place output files (trailing slash optional)
    [ip address]              Optional: IP address of kRPC host (defaults to localhost)
    
    Note: kRPC should run on port 50000
```

With this tool, changes made to the kRPC `SpaceCenter` service (or any other future services) on the plugin side can be 
effortlessly reflected back on the C++ client side, without requiring a manual re-write of functions to implement 
each and every procedure supported by the `SpaceCenter` service.

Regenerating the KRPCI_SpaceCenter class (or any other service classes) would, of course, require a re-compile of your C++ client that implements these generated classes. I can't really think of any way where a C++ client can query the kRPC services on-the-fly without a re-compile. [djungelorm](https://github.com/djungelorm)'s Python client *does* do this, just by the nature of the Python language itself.

