#include "register_types.h"
#include "pid.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_PID(ModuleInitializationLevel p_level){
    if(p_level != MODULE_INITIALIZATION_LEVEL_SCENE){
        return;
    }

    ClassDB::register_class<PID>();
}

void uninitialize_PID(ModuleInitializationLevel p_level){
    if(p_level != MODULE_INITIALIZATION_LEVEL_SCENE){
        return;
    }

}

extern "C"{
    GDExtensionBool GDE_EXPORT PID_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_libarary, GDExtensionInitialization *r_initialization){
        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_libarary, r_initialization);

        init_obj.register_initializer(initialize_PID);
        init_obj.register_terminator(uninitialize_PID);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}