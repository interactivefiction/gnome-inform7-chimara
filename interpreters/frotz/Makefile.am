pkglib_LTLIBRARIES = frotz.la
frotz_la_SOURCES = buffer.c err.c fastmem.c files.c input.c main.c math.c \
	object.c process.c quetzal.c random.c redirect.c sound.c stream.c table.c \
	text.c variable.c glkscreen.c glkmisc.c frotz.h glkfrotz.h glkio.h
frotz_la_CPPFLAGS = -I$(top_srcdir) -I$(top_srcdir)/libchimara
frotz_la_CFLAGS = -Wno-pointer-sign $(AM_CFLAGS)
frotz_la_LDFLAGS = -module $(PLUGIN_LIBTOOL_FLAGS)

frotzdocdir = $(datadir)/doc/$(PACKAGE)/frotz
dist_frotzdoc_DATA = AUTHORS COPYING README TODO

-include $(top_srcdir)/git.mk
