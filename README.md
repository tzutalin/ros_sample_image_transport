ros_sample_image_transport
----------------------
This source repository is testing ROS image transport

You need to setup your environment
--------------------------------------
Environments : Ubuntu 14.04 and install opencv and ROS

Locate the dir to catkin_ws/src/ and put the image to ~/lena.jpg
Run ros core.

Open a terminal 1:

`$ roscore`

Open a terminal 2:
Run image subscriber to receive two topics: /camera/rgbd/image and /camera/depth/image_raw

`$ rosrun ros_sample_image_transport image_transport_subscriber`

Open a terminal 3:
Run image publisher.

`$ rosrun ros_sample_image_transport image_transport_publisher`

Open a terminal 4:
You can user default debian ROS package to subscribe the image

`$ rosrun image_view image_view image:=/camera/rgb/image`

Note:
You can also refer the tutorial : How to setup [Xtion and OpenNI2](http://myzharbot.robot-home.it/blog/software/myzharbot-ros/asus-xtion-pro-live-openni2-ros-framework/)

