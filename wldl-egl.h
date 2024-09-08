#ifndef WLDL_EGL_H
#define WLDL_EGL_H

#include "wayland-util.h"
#include <wayland-egl-backend.h>

#define WL_EGL_PLATFORM 1

struct wayland_egl_lib {
  void* handle;
  struct wl_egl_window* (*window_create)(
    struct wl_surface*,
    int,
    int);
  void (*window_destroy)(struct wl_egl_window*);
  void (*window_resize)(
    struct wl_egl_window*,
    int,
    int,
    int,
    int);
  void (*window_get_attached_size)(
    struct wl_egl_window*,
    int*,
    int*);
};

extern struct wayland_egl_lib _wldl_egl;

#define wl_egl_window_create(s, w, h) \
  _wldl_egl.window_create(s, w, h)
#define wl_egl_window_destroy(wnd) \
  _wldl_egl.window_destroy(wnd)
#define wl_egl_window_resize(wnd, w, h, dx, dy) \
  _wldl_egl.window_resize(wnd, w, h, dx, dy)
#define wl_egl_window_get_attached_size(wnd, w, h) \
  _wldl_egl.window_get_attached_size(wnd, w, h)

int wldl_egl_load(const char* libpath);
char* wldl_egl_get_error(void);
void wldl_egl_unload(void);

#ifdef WLDL_EGL_IMPL

#include <dlfcn.h>

struct wayland_egl_lib _wldl_egl;

#define DLOPEN(file) 																							\
	do { 																														\
		_wldl_client.handle = dlopen((file), RTLD_NOW | RTLD_GLOBAL); \
		if (_wldl_client.handle == NULL)															\
			return -1; 																									\
	} while (0)

#define DLSYM(symb) 																							\
	do { 																														\
		_wldl_client.symb = dlsym(_wldl_client.handle, "wl_##symb"); 	\
		if (_wldl_client.symb == NULL)															 	\
			return -1; 																									\
	} while (0)

#define DLCLOSE() 																								\
	do { 																														\
		if (_wldl_client.handle != NULL)  														\
			dlclose(_wldl_client.handle);																\
	} while (0)

int wldl_egl_load(const char* libpath) {
  libpath = (libpath == NULL) ? "libwayland-egl.so" : libpath;
  DLOPEN(libpath);
  DLSYM(window_create);
  DLSYM(window_destroy);
  DLSYM(window_resize);
  DLSYM(window_get_attached_size);
  return 0;
}

char* wldl_egl_get_error(void) {
  return dlerror();
}

void wldl_egl_unload(void) {
  DLCLOSE();
}

#endif // WLDL_EGL_IMPL

#endif // WLDL_EGL_H
