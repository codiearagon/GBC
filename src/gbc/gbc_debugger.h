#include <vector>
#include <SDL2/SDL.h>
#include "opcode_info.h"

#define DEBUGGER_HEIGHT 800
#define DEBUGGER_WIDTH 800

class GBCDebugger {
    public:
        GBCDebugger();
        ~GBCDebugger();

        void log_message();
        void log_instruction();
        void log_status(opcode_info current_op);

        void show_debugger();
        void hide_debugger();

        void draw();
    private:
        uint32_t window_id;

        SDL_Window *window;
        SDL_Renderer *renderer;

        SDL_Rect registers_panel;
        SDL_Rect log_panel;
        SDL_Rect inst_history_panel;
        SDL_Rect status_panel;
        SDL_Rect memory_panel;

        std::vector<std::string> message_history;
        std::vector<opcode_info> inst_history;

        void draw_panel();
};