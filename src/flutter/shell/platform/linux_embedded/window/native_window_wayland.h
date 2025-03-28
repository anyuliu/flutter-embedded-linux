// Copyright 2021 Sony Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_PLATFORM_LINUX_EMBEDDED_WINDOW_NATIVE_WINDOW_WAYLAND_H_
#define FLUTTER_SHELL_PLATFORM_LINUX_EMBEDDED_WINDOW_NATIVE_WINDOW_WAYLAND_H_

#include <wayland-egl.h>

#include "flutter/shell/platform/linux_embedded/window/native_window.h"

namespace flutter {

class NativeWindowWayland : public NativeWindow {
 public:
  // @param[in] width_px       Physical width of the window.
  // @param[in] height_px      Physical height of the window.
  NativeWindowWayland(wl_compositor* compositor,
                      const size_t width_px,
                      const size_t height_px);
  ~NativeWindowWayland();

  // |NativeWindow|
  bool Resize(const size_t width_px, const size_t height_px) override;

  wl_surface* Surface() const { return surface_; }

 private:
  wl_surface* surface_ = nullptr;
  wl_surface* surface_offscreen_ = nullptr;
};

}  // namespace flutter

#endif  // FLUTTER_SHELL_PLATFORM_LINUX_EMBEDDED_WINDOW_NATIVE_WINDOW_WAYLAND_H_
