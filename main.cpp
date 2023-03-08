#define WLR_USE_UNSTABLE

#include "globals.hpp"

#include <thread>
#include <unistd.h>

// Do NOT change this function.
APICALL EXPORT std::string PLUGIN_API_VERSION() {
    return HYPRLAND_API_VERSION;
}

APICALL EXPORT PLUGIN_DESCRIPTION_INFO PLUGIN_INIT(HANDLE handle) {
    PHANDLE = handle;

    // HyprlandAPI::addNotification(PHANDLE, "Hello World from an example plugin!", CColor{0.f, 1.f, 1.f, 1.f}, 5000);

    HyprlandAPI::addDispatcher(PHANDLE, "notify", [](std::string arg) { HyprlandAPI::addNotification(PHANDLE, arg, CColor{0.5f, 0.5f, 0.7f, 1.0f}, 5000); });
    HyprlandAPI::addNotification(PHANDLE, "notify has started", CColor{0.5f, 0.5f, 0.7f, 1.0f}, 5000);

    return {"hypr-notify", "Adds the notify dispatcher", "horriblename", "1.0"};
}

APICALL EXPORT void PLUGIN_EXIT() {
    HyprlandAPI::invokeHyprctlCommand("seterror", "disable");
}
