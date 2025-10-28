#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class StringPublisher : public rclcpp::Node {
public:
    StringPublisher() : Node("string_node") {
        publisher_ = this->create_publisher<std_msgs::msg::String>("mensagem", 10);
        timer_ = this->create_wall_timer(2s, std::bind(&StringPublisher::publish_string, this));
    }

private:
    void publish_string() {
        auto message = std_msgs::msg::String();
        message.data = "RoboFEI";
        RCLCPP_INFO(this->get_logger(), "Publicando: '%s'", message.data.c_str());
        publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<StringPublisher>());
    rclcpp::shutdown();
    return 0;
}
