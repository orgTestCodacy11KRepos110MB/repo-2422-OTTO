#pragma once

#include "lib/util/thread.hpp"

#include "app/services/logic_thread.hpp"
#include "app/services/runtime.hpp"

namespace otto::app::services {

  struct LogicThreadImpl : LogicThread {
    LogicThreadImpl();

    lib::itc::IExecutor& executor() noexcept override;

  private:
    [[no_unique_address]] lib::core::ServiceAccessor<Runtime> runtime;

  protected:
    lib::itc::QueueExecutor executor_;
    lib::util::thread thread_;
  };
} // namespace otto::app::services
