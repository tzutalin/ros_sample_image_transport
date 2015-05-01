#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

static const std::string TOPIC_NAME = "camera/image";

int publishImage(std::string filepath)
{
    Mat image;
    image = imread(filepath, CV_LOAD_IMAGE_COLOR);   // Read the file
    std::cout << "Path " << filepath << std::endl;
    if(!image.data)                              // Check for invalid input
    {
        std::cout << "Could not open or find the image" << std::endl ;
        return -1;
    }

    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    image_transport::Publisher pub = it.advertise(TOPIC_NAME, 1);
    sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
    ros::Rate loop_rate(5);

    while (nh.ok()) {
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
}


int publishImageWithoutImage_transport(std::string filepath)
{
    ros::NodeHandle nh;
    cv_bridge::CvImage cv_image;
    cv_image.image = cv::imread(filepath, CV_LOAD_IMAGE_COLOR);
    cv_image.encoding = "bgr8";
    sensor_msgs::Image ros_image;
    cv_image.toImageMsg(ros_image);

    ros::Publisher pub = nh.advertise<sensor_msgs::Image>(TOPIC_NAME, 1);
    ros::Rate loop_rate(5);

    while (nh.ok())
    {
        pub.publish(ros_image);
        ros::spinOnce();
        loop_rate.sleep();
    }

}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "image_transport_publisher");
    publishImageWithoutImage_transport("/home/darrenl/lena.jpg");
    return 0;
}
