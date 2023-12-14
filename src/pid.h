#ifndef PID_H
#define PID_H

#include <godot_cpp/classes/node.hpp>

namespace godot {

    class PID : public Node{
        GDCLASS(PID, Node)

        private:
            float error;
            float derivative;
            float output;

        protected:
            static void _bind_methods();
            
        public:
            PID();      // constructor
            ~PID();     // destructor
            
            float update_PID(float current_value, float delta_time);
            void reset();

            float Kp;
            float Ki;
            float Kd;
            float setpoint;

            void set_Kp(float p_Kp);
            float get_Kp() const;
            void set_Ki(float p_Ki);
            float get_Ki() const;
            void set_Kd(float p_Kd);
            float get_Kd() const;
            void set_setpoint(float p_setpoint);
            float get_setpoint() const;
            void set_integral(float p_integral);
            float get_integral() const;

            float integral;
            float prev_error;

    };      

}
#endif