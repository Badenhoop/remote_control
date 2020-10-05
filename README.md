# remote_control

## Installation

This package uses [asionet](https://github.com/Badenhoop/asionet) and Boost 1.66 which are both included in the vendor directory.
Since Boost doesn't use CMake, you have to compile it manually.
Assuming your working directory is the root directory of this repository, please run the following commands to compile Boost from source:

    $ cd vendor/boost_1_66_0
    $ ./bootstrap.sh
    $ ./b2 

## Usage

This package provides two nodes:

* sender_node: Subscribes the topics **/motor** and **/servo** and sends that data over UDP to address and port given by the parameters **receiver_address** and **receiver_port**.
* receiver_node: Publishes received data over topics **/motor** and **/servo**.

In order to prevent your remote controlled robot from uncontrolled movement when connection is lost, there's an extra parameter **receiver_timeout** used to publish value 0.0 on the **/motor** when no data is received after the given timeout.

In addition, remote_control_gui.py implements a primitive GUI written in pygame to use the arrow keys for sending remote control commands.