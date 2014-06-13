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

#include <glib.h>
#include <glib-object.h>

#include "matemixer-profile.h"

struct _MateMixerProfilePrivate
{
    gchar   *name;
    gchar   *description;
    gulong   priority;
};

enum
{
    PROP_0,
    PROP_NAME,
    PROP_DESCRIPTION,
    PROP_PRIORITY,
    N_PROPERTIES
};

static GParamSpec *properties[N_PROPERTIES] = { NULL, };

static void mate_mixer_profile_class_init (MateMixerProfileClass *klass);
static void mate_mixer_profile_init       (MateMixerProfile      *profile);
static void mate_mixer_profile_finalize   (GObject               *object);

G_DEFINE_TYPE (MateMixerProfile, mate_mixer_profile, G_TYPE_OBJECT);

static void
mate_mixer_profile_get_property (GObject    *object,
                                 guint       param_id,
                                 GValue     *value,
                                 GParamSpec *pspec)
{
    MateMixerProfile *profile;

    profile = MATE_MIXER_PROFILE (object);

    switch (param_id) {
    case PROP_NAME:
        g_value_set_string (value, profile->priv->name);
        break;
    case PROP_DESCRIPTION:
        g_value_set_string (value, profile->priv->description);
        break;
    case PROP_PRIORITY:
        g_value_set_ulong (value, profile->priv->priority);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, param_id, pspec);
        break;
    }
}

static void
mate_mixer_profile_set_property (GObject      *object,
                                 guint         param_id,
                                 const GValue *value,
                                 GParamSpec   *pspec)
{
    MateMixerProfile *profile;

    profile = MATE_MIXER_PROFILE (object);

    switch (param_id) {
    case PROP_NAME:
        profile->priv->name = g_strdup (g_value_get_string (value));
        break;
    case PROP_DESCRIPTION:
        profile->priv->description = g_strdup (g_value_get_string (value));
        break;
    case PROP_PRIORITY:
        profile->priv->priority = g_value_get_ulong (value);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, param_id, pspec);
        break;
    }
}

static void
mate_mixer_profile_class_init (MateMixerProfileClass *klass)
{
    GObjectClass *object_class;

    object_class = G_OBJECT_CLASS (klass);
    object_class->finalize     = mate_mixer_profile_finalize;
    object_class->get_property = mate_mixer_profile_get_property;
    object_class->set_property = mate_mixer_profile_set_property;

    properties[PROP_NAME] = g_param_spec_string ("name",
                                                 "Name",
                                                 "Name of the profile",
                                                 NULL,
                                                 G_PARAM_CONSTRUCT_ONLY |
                                                 G_PARAM_READWRITE |
                                                 G_PARAM_STATIC_STRINGS);

    properties[PROP_DESCRIPTION] = g_param_spec_string ("description",
                                                        "Description",
                                                        "Description of the profile",
                                                        NULL,
                                                        G_PARAM_CONSTRUCT_ONLY |
                                                        G_PARAM_READWRITE |
                                                        G_PARAM_STATIC_STRINGS);

    properties[PROP_PRIORITY] = g_param_spec_ulong ("priority",
                                                    "Priority",
                                                    "Priority of the profile",
                                                    0,
                                                    G_MAXULONG,
                                                    0,
                                                    G_PARAM_CONSTRUCT_ONLY |
                                                    G_PARAM_READWRITE |
                                                    G_PARAM_STATIC_STRINGS);

    g_object_class_install_properties (object_class, N_PROPERTIES, properties);

    g_type_class_add_private (object_class, sizeof (MateMixerProfilePrivate));
}

static void
mate_mixer_profile_init (MateMixerProfile *profile)
{
    profile->priv = G_TYPE_INSTANCE_GET_PRIVATE (profile,
                                                 MATE_MIXER_TYPE_PROFILE,
                                                 MateMixerProfilePrivate);
}

static void
mate_mixer_profile_finalize (GObject *object)
{
    MateMixerProfile *profile;

    profile = MATE_MIXER_PROFILE (object);

    g_free (profile->priv->name);
    g_free (profile->priv->description);

    G_OBJECT_CLASS (mate_mixer_profile_parent_class)->finalize (object);
}

MateMixerProfile *
mate_mixer_profile_new (const gchar *name, const gchar *description, gulong priority)
{
    return g_object_new (MATE_MIXER_TYPE_PROFILE,
                         "name", name,
                         "description", description,
                         "priority", priority,
                         NULL);
}

const gchar *
mate_mixer_profile_get_name (MateMixerProfile *profile)
{
    g_return_val_if_fail (MATE_MIXER_IS_PROFILE (profile), NULL);

    return profile->priv->name;
}

const gchar *
mate_mixer_profile_get_description (MateMixerProfile *profile)
{
    g_return_val_if_fail (MATE_MIXER_IS_PROFILE (profile), NULL);

    return profile->priv->description;
}

gulong
mate_mixer_profile_get_priority (MateMixerProfile *profile)
{
    g_return_val_if_fail (MATE_MIXER_IS_PROFILE (profile), 0);

    return profile->priv->priority;
}
