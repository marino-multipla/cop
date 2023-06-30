<!--
Copyright (c) 2022 Boston Dynamics, Inc.  All rights reserved.

Downloading, reproducing, distributing or otherwise using the SDK Software
is subject to the terms and conditions of the Boston Dynamics Software
Development Kit License (20191101-BDSDK-SL).
-->

# Arm Simple

This example program is the introductory programming example for Spot arm commands. It demonstrates how
to initialize the SDK to talk to robot, how to command Spot to stand up, assume an arm pose and enable the 
LOCK_HAND_IN_BODY or LOCK_HAND_IN_WORLD option and then move forward for 4 seconds.

In the arm_lock_hand_in_body example, the expected result will be spot is moving with the hand locked in the world reference position.
In the arm_lock_hand_in_world example, the expected result will be spot is moving with the hand locked in the body reference position.


## Understanding Spot Programming

For your best learning experience, please use the [Quickstart Guide](../../../docs/python/quickstart.md)
found in the SDK's docs/python directory. That will help you get your Python programming environment set up properly.

## Common Problems

1. Remember, you will need to launch a software e-stop separately. The E-Stop programming example is [here](../estop/README.md).
2. Make sure the Motor Enable button on the Spot rear panel is depressed.
3. Make sure Spot is sitting upright, with the battery compartment on the side closest the floor.

## Setup Dependencies

This example requires the bosdyn API and client to be installed, and must be run using python3. Using pip, these dependencies can be installed using:

```
python3 -m pip install -r requirements.txt
```

## Run the Example

To run the examples:

```
python3 arm_lock_hand_in_body.py ROBOT_IP

python3 arm_lock_hand_in_world.py ROBOT_IP

```
