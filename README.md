ros_sample_image_transport
----------------------
This source repository is testing ROS image transport

You need to setup your environment
--------------------------------------
Environments : Ubuntu 14.04 and install opencv and ROS

Locate the dir to catkin_ws/src/ and put the image to ~/lena.jpg
Run ros core.

	$roscore

Run image subscriber.

	$rosrun ros_sample_image_transport image_transport_subscriber

Run image publisher.

	$rosrun ros_sample_image_transport image_transport_publisher

You can user default debian ROS package to subscribe the image

   $ rosrun image_view image_view image:=/camera/image
