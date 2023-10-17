#include "main.h"

class DriveControl{
    static bool catapultFlung;
    static bool catapultMoving;
public:
    class ControllerStates{
    private:
        static bool L1_last_state;
        static bool R1_last_state;
        static bool L2_last_state;
        static bool R2_last_state;
        static bool up_last_state;
        static bool down_last_state;
        static bool left_last_state;
        static bool right_last_state;
        static bool X_last_state;
        static bool Y_last_state;
        static bool A_last_state;
        static bool B_last_state;
    public:
        //Returns if the button was pressed down after the last detection
        static bool is_activated(pros::controller_digital_e_t button);
        //Returns if the button is currently pressed down
        static bool is_pressed(pros::controller_digital_e_t button);
    };
    static void update_drive_train();
    static void update_intake();
    static void update_catapult();
    static void update_wings();
    static void update_pto();
    static void update();
};