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

#ifndef MATEMIXER_SWITCH_H
#define MATEMIXER_SWITCH_H

#include <glib.h>
#include <glib-object.h>

#include <libmatemixer/matemixer-enums.h>
#include <libmatemixer/matemixer-types.h>

G_BEGIN_DECLS

#define MATE_MIXER_TYPE_SWITCH                  \
        (mate_mixer_switch_get_type ())
#define MATE_MIXER_SWITCH(o)                    \
        (G_TYPE_CHECK_INSTANCE_CAST ((o), MATE_MIXER_TYPE_SWITCH, MateMixerSwitch))
#define MATE_MIXER_IS_SWITCH(o)                 \
        (G_TYPE_CHECK_INSTANCE_TYPE ((o), MATE_MIXER_TYPE_SWITCH))
#define MATE_MIXER_SWITCH_CLASS(k)              \
        (G_TYPE_CHECK_CLASS_CAST ((k), MATE_MIXER_TYPE_SWITCH, MateMixerSwitchClass))
#define MATE_MIXER_IS_SWITCH_CLASS(k)           \
        (G_TYPE_CHECK_CLASS_TYPE ((k), MATE_MIXER_TYPE_SWITCH))
#define MATE_MIXER_SWITCH_GET_CLASS(o)          \
        (G_TYPE_INSTANCE_GET_CLASS ((o), MATE_MIXER_TYPE_SWITCH, MateMixerSwitchClass))

typedef struct _MateMixerSwitchClass    MateMixerSwitchClass;
typedef struct _MateMixerSwitchPrivate  MateMixerSwitchPrivate;

/**
 * MateMixerSwitch:
 *
 * The #MateMixerSwitch structure contains only private data and should only
 * be accessed using the provided API.
 */
struct _MateMixerSwitch
{
    GObject object;

    /*< private >*/
    MateMixerSwitchPrivate *priv;
};

/**
 * MateMixerSwitchClass:
 * @parent_class: The parent class.
 *
 * The class structure for #MateMixerSwitch.
 */
struct _MateMixerSwitchClass
{
    GObjectClass parent_class;

    /*< private >*/
    MateMixerSwitchOption *(*get_option)        (MateMixerSwitch       *swtch,
                                                 const gchar           *name);

    const GList           *(*list_options)      (MateMixerSwitch       *swtch);

    gboolean               (*set_active_option) (MateMixerSwitch       *swtch,
                                                 MateMixerSwitchOption *option);
};

GType                  mate_mixer_switch_get_type          (void) G_GNUC_CONST;

const gchar *          mate_mixer_switch_get_name          (MateMixerSwitch       *swtch);
const gchar *          mate_mixer_switch_get_label         (MateMixerSwitch       *swtch);
MateMixerSwitchFlags   mate_mixer_switch_get_flags         (MateMixerSwitch       *swtch);
MateMixerSwitchRole    mate_mixer_switch_get_role          (MateMixerSwitch       *swtch);

MateMixerSwitchOption *mate_mixer_switch_get_option        (MateMixerSwitch       *swtch,
                                                            const gchar           *name);

const GList *          mate_mixer_switch_list_options      (MateMixerSwitch       *swtch);

MateMixerSwitchOption *mate_mixer_switch_get_active_option (MateMixerSwitch       *swtch);
gboolean               mate_mixer_switch_set_active_option (MateMixerSwitch       *swtch,
                                                            MateMixerSwitchOption *option);

G_END_DECLS

#endif /* MATEMIXER_SWITCH_H */
