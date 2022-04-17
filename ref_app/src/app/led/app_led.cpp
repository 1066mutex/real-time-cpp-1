﻿///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2022.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <mcal/mcal.h>
#include <util/utility/util_time.h>

namespace app { namespace led {

void task_init();
void task_func();

} // namespace led
} // namespace app

namespace local
{
  typedef util::timer<std::uint32_t> app_led_timer_type;

  app_led_timer_type app_led_timer(app_led_timer_type::seconds(1U));
} // namespace local

auto app::led::task_init() -> void
{
  mcal::led::led0().toggle();
}

auto app::led::task_func() -> void
{
  if(local::app_led_timer.timeout())
  {
    local::app_led_timer.start_interval(local::app_led_timer_type::seconds(1U));

    mcal::led::led0().toggle();
  }
}
