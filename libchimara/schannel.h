#ifndef __SCHANNEL_H__
#define __SCHANNEL_H__

#include <config.h>
#include <glib.h>
#include "glk.h"
#include "gi_dispa.h"
#include "chimara-glk.h"
#if defined(GSTREAMER_0_10_SOUND) || defined(GSTREAMER_1_0_SOUND)
#include <gst/gst.h>
#endif

struct glk_schannel_struct
{
	/*< private >*/
	glui32 magic, rock;
	gidispatch_rock_t disprock;
	/* Pointer to the list node in the global sound channel list that contains 
	 this sound channel */
	GList *schannel_list;
	/* Pointer to the GTK widget this sound channel belongs to, for convenience */
	ChimaraGlk *glk;

	/* Resource number and notification ID of last played sound */
	glui32 resource, notify;
	/* How many times to repeat the last sound played (-1 = forever) */
	glui32 repeats;
	/* Whether channel is paused */
	gboolean paused;
	
	/* Volume change information */
	double target_volume;
	long target_time_sec, target_time_usec;
	guint volume_timer_id;
	glui32 volume_notify;

#if defined(GSTREAMER_0_10_SOUND) || defined(GSTREAMER_1_0_SOUND)
	/* Each sound channel is represented as a GStreamer pipeline.  */
	GstElement *pipeline, *source, *typefind, *demux, *decode, *convert, *filter, *sink;
#endif
};

#endif
