#!/bin/bash

#::firmware=http://plf.parrot.com/sphinx/firmwares/ardrone3/milos_pc/4.4.2/images/ardrone3-milos_pc.ext2.zip

if [ $# -eq 0 ]; then
	echo How to use:
	echo add connection name as argument up to 3
fi

if [ $# -eq 1 ]; then
	sudo systemctl start firmwared.service
	sphinx ./sphinx.drone::name=bebop1::stolen_interface=$1:eth0:192.168.42.1/24::pose="0 0 0.2 0 0 0.5"
fi

if [ $# -eq 2 ]; then
	sudo systemctl start firmwared.service
	sphinx ./sphinx.drone::name=bebop1::stolen_interface=$1:eth0:192.168.42.1/24::pose="0 -0.5 0.2 0 0 0"::firmware=http://plf.parrot.com/sphinx/firmwares/ardrone3/milos_pc/4.4.2/images/ardrone3-milos_pc.ext2.zip::interface=eth1 ./sphinx.drone::name=bebop2::stolen_interface=$2:eth0:192.168.42.1/24::pose="0 0.5 0.2 0 0 0"::firmware=http://plf.parrot.com/sphinx/firmwares/ardrone3/milos_pc/4.4.2/images/ardrone3-milos_pc.ext2.zip::interface=eth2
fi

if [ $# -eq 3 ]; then
	sudo systemctl start firmwared.service
	sphinx ./sphinx.drone::name=bebop1::stolen_interface=$1:eth0:192.168.42.1/24::pose="0 -1 0.2 0 0 0"::interface=eth1::firmware=http://plf.parrot.com/sphinx/firmwares/ardrone3/milos_pc/4.4.2/images/ardrone3-milos_pc.ext2.zip ./sphinx.drone::name=bebop2::stolen_interface=$2:eth0:192.168.42.1/24::pose="0 0 0.2 0 0 0"::interface=eth2::firmware=http://plf.parrot.com/sphinx/firmwares/ardrone3/milos_pc/4.4.2/images/ardrone3-milos_pc.ext2.zip ./sphinx.drone::name=bebop3::stolen_interface=$3:eth0:192.168.42.1/24::pose="0 1 0.2 0 0 0"::interface=eth3::firmware=http://plf.parrot.com/sphinx/firmwares/ardrone3/milos_pc/4.4.2/images/ardrone3-milos_pc.ext2.zip
fi

