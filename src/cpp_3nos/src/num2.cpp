#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;

class Num2Publisher : public rclcpp::Node {
public:
    Num2Publisher() : Node("num2_node") {
        publisher_ = this->create_publisher<std_msgs::msg::Int32>("numero2", 10);
        timer_ = this->create_wall_timer(1s, std::bind(&Num2Publisher::publish_number, this));
    }

private:
    void publish_number() {
        auto message = std_msgs::msg::Int32();
        message.data = 20;
        RCLCPP_INFO(this->get_logger(), "Publicando: %d", message.data);
        publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Num2Publisher>());
    rclcpp::shutdown();
    return 0;
}
