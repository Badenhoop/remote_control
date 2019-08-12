# remote_control

## Installation

This package requires [asionet](https://github.com/Badenhoop/asionet) to be installed for networking.

## Usage

This package provides two nodes:

* sender_node: Subscribes the topics **/motor** and **/servo** and sends that data over UDP to address and port given by the parameters **receiver_address** and **receiver_port**.
* receiver_node: Publishes received data over topics **/motor** and **/servo**.

In order to prevent your remote controlled robot from uncontrolled movement when connection is lost, there's an extra parameter **receiver_timeout** used to publish value 0.0 on the **/motor** when no data is received after the given timeout.

In addition, remote_control_gui.py implements a primitive GUI written in pygame to use the arrow keys for sending remote control commands.