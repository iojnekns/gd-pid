#include "pid.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void PID :: _bind_methods(){
	ClassDB::bind_method(D_METHOD("update_PID"), &PID::update_PID);
    ClassDB::bind_method(D_METHOD("reset"), &PID::reset);

    ClassDB::bind_method(D_METHOD("get_Kp"), &PID::get_Kp);
    ClassDB::bind_method(D_METHOD("set_Kp"), &PID::set_Kp);
    ClassDB::add_property("PID", PropertyInfo(Variant::FLOAT, "Kp"), "set_Kp", "get_Kp");

    ClassDB::bind_method(D_METHOD("get_Ki"), &PID::get_Ki);
    ClassDB::bind_method(D_METHOD("set_Ki"), &PID::set_Ki);
    ClassDB::add_property("PID", PropertyInfo(Variant::FLOAT, "Ki"), "set_Ki", "get_Ki");

    ClassDB::bind_method(D_METHOD("get_Kd"), &PID::get_Kd);
    ClassDB::bind_method(D_METHOD("set_Kd"), &PID::set_Kd);
    ClassDB::add_property("PID", PropertyInfo(Variant::FLOAT, "Kd"), "set_Kd", "get_Kd");

    ClassDB::bind_method(D_METHOD("get_setpoint"), &PID::get_setpoint);
    ClassDB::bind_method(D_METHOD("set_setpoint"), &PID::set_setpoint);
    ClassDB::add_property("PID", PropertyInfo(Variant::FLOAT, "setpoint"), "set_setpoint", "get_setpoint");
}

PID :: PID(){
    Kp = 1;
    Ki = 0.1;
    Kd = 0.01;

    setpoint = 0;
    integral = 0;
    prev_error = 0;

}

PID :: ~PID(){
}

float PID :: update_PID(float current_value, float delta_time){
    error = setpoint - current_value;
    integral += error * delta_time;
    derivative = (error - prev_error) / delta_time;
    output = Kp * error + Ki * integral + Kd * derivative;
    prev_error = error;
    return output;
}

void PID :: reset(){
    setpoint = 0;
    integral = 0;
    prev_error = 0;
}


void PID::set_Kp(const float p_Kp) {
	Kp = p_Kp;
}

float PID::get_Kp() const {
	return Kp;
}

void PID::set_Ki(const float p_Ki) {
	Ki = p_Ki;
}

float PID::get_Ki() const {
	return Ki;
}

void PID::set_Kd(const float p_Kd) {
	Kd = p_Kd;
}

float PID::get_Kd() const {
	return Kd;
}

void PID::set_setpoint(const float p_setpoint) {
	setpoint = p_setpoint;
}

float PID::get_setpoint() const {
	return setpoint;
}