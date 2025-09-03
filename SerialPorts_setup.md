# Serial Ports Setup

## Check if the serial port is connected, Checking if the system created usable device nodes
```
ls -l /dev/ttyUSB*
```

## Load the driver CH340
```
sudo modprobe ch341
sudo modprobe usbserial
```

## View the most recent 50 lines of system messages from the kernel, dmesg stands for diagnostic message
```
dmesg | tail -n 50
```

## Physical USB devices detected, checking if USB device is seen by hardware/kernel
```
lsusb
```

## Issue: in case of driver conflicts

Here an example:

```
[ 6939.000501] ch341 1-2.4:1.0: ch341-uart converter detected 
[ 6939.014560] usb 1-2.4: ch341-uart converter now attached to ttyUSB0 
[ 6939.539235] input: BRLTTY 6.4 Linux Screen Driver Keyboard as /devices/virtual/input/input63 
[ 6939.670680] usb 1-2.4: usbfs: interface 0 claimed by ch341 while 'brltty' sets config #1 
[ 6939.674177] ch341-uart ttyUSB0: ch341-uart converter now disconnected from ttyUSB0 
[ 6939.674216] ch341 1-2.4:1.0: device disconnected
```

Here is happening that brltty is a background service used for braille displays on Linux. It tries to "take over" any serial devices that might be braille-related — including CH340-based USB-to-serial adapters.

A solution can be to Remove or Disable brltty

```
sudo apt remove brltty
```





