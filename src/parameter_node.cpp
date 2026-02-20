#include "rclcpp/rclcpp.hpp"

class ParameterNode : public rclcpp::Node
{
public:
  ParameterNode() : Node("parameter_node")
  {
    // Declare parameter with default value
    this->declare_parameter<std::string>("robot_name", "turtlebot");

    // Get parameter value
    robot_name_ = this->get_parameter("robot_name").as_string();

    RCLCPP_INFO(this->get_logger(), "Robot name: %s", robot_name_.c_str());

    // Timer to keep node alive
    timer_ = this->create_wall_timer(
      std::chrono::seconds(2),
      std::bind(&ParameterNode::timer_callback, this)
    );
  }

private:
  void timer_callback()
  {
    RCLCPP_INFO(this->get_logger(), "Running robot: %s", robot_name_.c_str());
  }

  std::string robot_name_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ParameterNode>());
  rclcpp::shutdown();
  return 0;
}
