#pragma once

#include "lib/core/service.hpp"
#include "lib/itc/executor.hpp"

#include <SkCanvas.h>

#include "runtime.hpp"

namespace otto::app::services {

  using namespace lib;

  struct Graphics : core::Service<Graphics> {
    /// Open a window/display drawing the given draw function
    virtual void show(std::function<void(SkCanvas&)>) = 0;

    virtual itc::IExecutor& executor() noexcept = 0;

    /// The board-specfic graphics service
    [[nodiscard]] static auto make_board();
  };

} // namespace otto::app::services

namespace otto::board {
  lib::core::ServiceHandle<app::services::Graphics> make_graphics();
}

namespace otto::app::services {
  inline auto Graphics::make_board()
  {
    return board::make_graphics();
  }
} // namespace otto::app::services
