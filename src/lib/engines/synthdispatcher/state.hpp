#pragma once

#include "lib/util/visitor.hpp"

#include "lib/audio.hpp"
#include "lib/graphics.hpp"

namespace otto {

  struct SynthDispatcherState {
    int active_engine = 0;
    std::string name;
    ISynthAudio* audio;
    ScreenWithHandlerPtr main_screen;
    ScreenWithHandlerPtr mod_screen;
    ScreenWithHandlerPtr voices_screen;
  };

} // namespace otto