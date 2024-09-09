#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void initialize_cinedot(ModuleInitializationLevel level)
{
    if (level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        return;
    }

    UtilityFunctions::print("Cinedot initialized");
}

void terminate_cinedot(ModuleInitializationLevel level)
{
    if (level != MODULE_INITIALIZATION_LEVEL_SCENE)
    {
        return;
    }

    UtilityFunctions::print("Cinedot terminated");
}

extern "C"
{
    GDExtensionBool GDE_EXPORT cinedot_library_init(
        GDExtensionInterfaceGetProcAddress get_proc_address,
        const GDExtensionClassLibraryPtr library,
        GDExtensionInitialization *initialization)
    {
        godot::GDExtensionBinding::InitObject init(get_proc_address, library, initialization);

        init.register_initializer(initialize_cinedot);
        init.register_terminator(terminate_cinedot);
        init.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init.init();
    }
}