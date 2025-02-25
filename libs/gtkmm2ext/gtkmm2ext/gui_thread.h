/*
 * Copyright (C) 2010-2015 Paul Davis <paul@linuxaudiosystems.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#pragma once

#include <cstdlib>
#include <gtkmm2ext/gtk_ui.h>
#include <boost/bind/protect.hpp>

#include "gtkmm2ext/visibility.h"

#define ENSURE_GUI_THREAD(obj,method, ...) if (!Gtkmm2ext::UI::instance()->caller_is_self()) { abort (); }

#define gui_context() Gtkmm2ext::UI::instance() /* a UICallback-derived object that specifies the event loop for GUI signal handling */
#define ui_bind(f, ...) boost::protect (std::bind (f, __VA_ARGS__))

#define invalidator(x) PBD::EventLoop::__invalidator ((x), __FILE__, __LINE__)

