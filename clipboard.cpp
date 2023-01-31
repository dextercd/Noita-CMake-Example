#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstring>

/**
 * Set the clipboard to the provided text.
 * @return true if the clipboard change was successful.
 */
extern "C" __declspec(dllexport)
bool set_clipboard(const char* text)
{
    bool success = false;
    bool clipboard_opened = false;
    HGLOBAL global_data = nullptr;

    // Need a window for the clipboard API, it's never made visible
    HWND clipboard_window = CreateWindowA(
        "Message", nullptr, 0, 0, 0, 0, 0, nullptr, nullptr, nullptr, nullptr);

    if (!clipboard_window)
        goto cleanup;

    if (!(clipboard_opened = OpenClipboard(clipboard_window)) || !EmptyClipboard())
        goto cleanup;

    std::size_t data_length = std::strlen(text) + 1;
    global_data = GlobalAlloc(GMEM_MOVEABLE, data_length);
    if (!global_data)
        goto cleanup;

    void* data = GlobalLock(global_data);
    if (!data)
        goto cleanup;

    std::memcpy(data, text, data_length);

    if (!GlobalUnlock(global_data))
        goto cleanup;

    if (SetClipboardData(CF_TEXT, global_data)) {
        global_data = nullptr; // System now manages the data
        success = true;
    }

cleanup:
    if (global_data)
        GlobalFree(global_data);

    if (clipboard_opened)
        CloseClipboard();

    if (clipboard_window)
        DestroyWindow(clipboard_window);

    return success;
}
