# KNav
Kerbal Navigation Suite, and KRPC Interface libraries

---------------------

KNav is a flexible platform for implementing computer-assisted navigation and control of vessels in Kerbal Space Program.

KNav is a [kRPC](https://github.com/djungelorm/krpc)-compatible CLI client, written in **C++**. KNav is currently only supported on **Windows**, and compiled with MS Visual Studio Express 2013 for Windows Desktop.

**Note:** *KNav is very new code. It's only useful in-game capability right now is that it allows your craft to maintain a fixed-altitude hover. However, the underlying code should be useful for anyone looking to implement their own auto-pilot programming in C++.*

Usage:

```
> KNav.exe [ip address]


    [ip address]              IP address of host running KSP with kRPC server plugin.
                              If unspecified, defaults to 127.0.0.1 (localhost)
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
> KRPCI_Interpreter.exe <service name> <output dir>


    <service name>            The name of kRPC service to query, e.g. SpaceCenter
    <output dir>              Directory to place output files
```

With this tool, changes made to the kRPC `SpaceCenter` service on the plugin side can be effortlessly reflected back on
the C++ client side, without requiring a manual re-write of functions to implement each and every procedure supported by
the `SpaceCenter` service.

