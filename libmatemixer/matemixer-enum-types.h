/*
 * Copyright (C) 2014 Michal Ratajsky <michal.ratajsky@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the licence, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MATEMIXER_ENUM_TYPES_H
#define MATEMIXER_ENUM_TYPES_H

#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

/*
 * GTypes are not generated by glib-mkenums, see:
 * https://bugzilla.gnome.org/show_bug.cgi?id=621942
 */

#define MATE_MIXER_TYPE_STATE (mate_mixer_state_get_type ())
GType mate_mixer_state_get_type (void) G_GNUC_CONST;

#define MATE_MIXER_TYPE_BACKEND_TYPE (mate_mixer_backend_type_get_type ())
GType mate_mixer_backend_type_get_type (void) G_GNUC_CONST;

#define MATE_MIXER_TYPE_PORT_STATUS (mate_mixer_port_status_get_type ())
GType mate_mixer_port_status_get_type (void) G_GNUC_CONST;

#define MATE_MIXER_TYPE_STREAM_FLAGS (mate_mixer_stream_flags_get_type ())
GType mate_mixer_stream_flags_get_type (void) G_GNUC_CONST;

#define MATE_MIXER_TYPE_STREAM_STATUS (mate_mixer_stream_status_get_type ())
GType mate_mixer_stream_status_get_type (void) G_GNUC_CONST;

#define MATE_MIXER_TYPE_CHANNEL_POSITION (mate_mixer_channel_position_get_type ())
GType mate_mixer_channel_position_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif /* MATEMIXER_ENUM_TYPES_H */
