/* -*- mode: c++ -*-
 * Kaleidoscope-Escape-OneShot -- Turn ESC into a key that cancels OneShots, if active.
 * Copyright (C) 2016-2021  Keyboard.io, Inc
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "kaleidoscope/Runtime.h"
#include <Kaleidoscope-Ranges.h>

constexpr Key OneShotCancelKey {kaleidoscope::ranges::OS_CANCEL};

namespace kaleidoscope {
namespace plugin {

class EscapeOneShot : public kaleidoscope::Plugin {
 public:
  EscapeOneShot(void) {}

  EventHandlerResult onKeyEvent(KeyEvent &event);

  static void setCancelKey(Key cancel_key) {
    settings_.cancel_oneshot_key = cancel_key;
  }
  static Key getCancelKey() {
    return settings_.cancel_oneshot_key;
  }
  static void enable() {
    settings_.disabled = false;
  }
  static void disable() {
    settings_.disabled = true;
  }
  static void toggle() {
    settings_.disabled = !settings_.disabled;
  }
  static bool isEnabled() {
    return !settings_.disabled;
  }

 private:
  struct Settings {
    bool disabled;
    Key cancel_oneshot_key;
  };
  static Settings settings_;
};
};

}
}

extern kaleidoscope::plugin::EscapeOneShot EscapeOneShot;
