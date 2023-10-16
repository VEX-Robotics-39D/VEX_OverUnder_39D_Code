#include "main.h"

class Odometry{
    static double x,y,theta;
    static double rightWheelPosition,leftWheelPosition,odometryWheelPosition;
    static const double leftRightWheelDistance;
    static const double odometryWheelDistance;
public:
    static void updateOdom();
    static void updateInertial();
    static void reset();
    static double getX();
    static double getY();
    static double getTheta();
};