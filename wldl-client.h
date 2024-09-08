#ifndef WLDL_CLIENT_H
#define WLDL_CLIENT_H

#include <stdint.h>
#include <stdarg.h>
#include <wayland-util.h>

#define WL_MARSHAL_FLAG_DESTROY (1 << 0)

struct wl_event_queue;

typedef void (*wl_log_func_t)(
	const char*,
	va_list);
typedef int (*wl_dispatcher_func_t)(
	const void*,
	void*,
	uint32_t,
	const struct wl_message*,
	union wl_argument*);

struct wayland_client_lib {
	void* handle;
	const struct wl_interface* display_interface;
	const struct wl_interface* registry_interface;
	const struct wl_interface* callback_interface;
	const struct wl_interface* compositor_interface;
	const struct wl_interface* shm_pool_interface;
	const struct wl_interface* shm_interface;
	const struct wl_interface* buffer_interface;
	const struct wl_interface* data_offer_interface;
	const struct wl_interface* data_source_interface;
	const struct wl_interface* data_device_interface;
	const struct wl_interface* data_device_manager_interface;
	const struct wl_interface* shell_interface;
	const struct wl_interface* shell_surface_interface;
	const struct wl_interface* surface_interface;
	const struct wl_interface* seat_interface;
	const struct wl_interface* pointer_interface;
	const struct wl_interface* keyboard_interface;
	const struct wl_interface* touch_interface;
	const struct wl_interface* output_interface;
	const struct wl_interface* region_interface;
	const struct wl_interface* subcompositor_interface;
	const struct wl_interface* subsurface_interface;
	void (*event_queue_destroy)(struct wl_event_queue*);
	struct wl_proxy* (*proxy_marshal_flags)(
		struct wl_proxy*,
		uint32_t,
		const struct wl_interface*,
		uint32_t,
		uint32_t,
		...);
	struct wl_proxy* (*proxy_marshal_array_flags)(
		struct wl_proxy*,
		uint32_t,
		const struct wl_interface*,
		uint32_t,
		uint32_t,
		union wl_argument*);
	void (*proxy_marshal)(
		struct wl_proxy*,
		uint32_t,
		...);
	void (*proxy_marshal_array)(
		struct wl_proxy*,
		uint32_t,
		union wl_argument*);
	struct wl_proxy* (*proxy_create)(
		struct wl_proxy*,
		const struct wl_interface*);
	void* (*proxy_create_wrapper)(void*);
	void (*proxy_wrapper_destroy)(void*);
	struct wl_proxy* (*proxy_marshal_constructor)(
		struct wl_proxy*,
		uint32_t,
		const struct wl_interface*,
		...);
	struct wl_proxy* (*proxy_marshal_constructor_versioned)(
		struct wl_proxy*,
		uint32_t,
		const struct wl_interface*,
		uint32_t,
		...);
	struct wl_proxy* (*proxy_marshal_array_constructor)(
		struct wl_proxy*,
		uint32_t,
		union wl_argument*,
		const struct wl_interface*);
	struct wl_proxy* (*proxy_marshal_array_constructor_versioned)(
		struct wl_proxy*,
		uint32_t,
		union wl_argument*,
		const struct wl_interface*,
		uint32_t);
	void (*proxy_destroy)(struct wl_proxy*);
	int (*proxy_add_listener)(
		struct wl_proxy*,
		void (**implementation)(void),
		void*);
	const void* (*proxy_get_listener)(struct wl_proxy*);
	int (*proxy_add_dispatcher)(
		struct wl_proxy*,
		wl_dispatcher_func_t,
		const void*,
		void*);
	void (*proxy_set_user_data)(
		struct wl_proxy*,
		void*);
	void* (*proxy_get_user_data)(struct wl_proxy*);
	uint32_t (*proxy_get_version)(struct wl_proxy*);
	uint32_t (*proxy_get_id)(struct wl_proxy*);
	void (*proxy_set_tag)(
		struct wl_proxy*,
		const char* const*);
	const char* const* (*proxy_get_tag)(struct wl_proxy*);
	const char* (*proxy_get_class)(struct wl_proxy*);
	void (*proxy_set_queue)(
		struct wl_proxy*,
		struct wl_event_queue*);
	struct wl_display* (*display_connect)(const char*);
	struct wl_display* (*display_connect_to_fd)(int);
	void (*display_disconnect)(struct wl_display*);
	int (*display_get_fd)(struct wl_display*);
	int (*display_dispatch)(struct wl_display*);
	int (*display_dispatch_queue)(
		struct wl_display*,
		struct wl_event_queue*);
	int (*display_dispatch_queue_pending)(
		struct wl_display*,
		struct wl_event_queue*);
	int (*display_dispatch_pending)(struct wl_display*);
	int (*display_get_error)(struct wl_display*);
	uint32_t (*display_get_protocol_error)(
		struct wl_display*,
		const struct wl_interface**,
		uint32_t*);
	int (*display_flush)(struct wl_display*);
	int (*display_roundtrip_queue)(
		struct wl_display*,
		struct wl_event_queue*);
	int (*display_roundtrip)(struct wl_display*);
	struct wl_event_queue* (*display_create_queue)(struct wl_display*);
	int (*display_prepare_read_queue)(
		struct wl_display*,
		struct wl_event_queue*);
	int (*display_prepare_read)(struct wl_display*);
	void (*display_cancel_read)(struct wl_display*);
	int (*display_read_events)(struct wl_display*);
	void (*log_set_handler_client)(wl_log_func_t);
};

extern struct wayland_client_lib _wldl_client;

#define wl_display_interface \
	(*_wldl_client.display_interface)
#define wl_registry_interface \
	(*_wldl_client.registry_interface)
#define wl_callback_interface \
	(*_wldl_client.callback_interface)
#define wl_compositor_interface \
	(*_wldl_client.compositor_interface)
#define wl_shm_pool_interface \
	(*_wldl_client.shm_pool_interface) 
#define wl_shm_interface \
	(*_wldl_client.shm_interface)
#define wl_buffer_interface \
	(*_wldl_client.buffer_interface)
#define wl_data_offer_interface \
	(*_wldl_client.data_offer_interface)
#define wl_data_source_interface \
	(*_wldl_client.data_source_interface)
#define wl_data_device_interface \
	(*_wldl_client.data_device_interface)
#define wl_data_device_manager_interface \
	(*_wldl_client.data_device_manager_interface)
#define wl_shell_interface \
	(*_wldl_client.shell_interface)
#define wl_shell_surface_interface \
	(*_wldl_client.shell_surface_interface)
#define wl_surface_interface \
	(*_wldl_client.surface_interface)
#define wl_seat_interface \
	(*_wldl_client.seat_interface)
#define wl_pointer_interface \
	(*_wldl_client.pointer_interface)
#define wl_keyboard_interface \
	(*_wldl_client.keyboard_interface)
#define wl_touch_interface \
	(*_wldl_client.touch_interface)
#define wl_output_interface \
	(*_wldl_client.output_interface)
#define wl_region_interface \
	(*_wldl_client.region_interface)
#define wl_subcompositor_interface \
	(*_wldl_client.subcompositor_interface)
#define wl_subsurface_interface \
	(*_wldl_client.subsurface_interface)
#define wl_event_queue_destroy(q) \
	_wldl_client.event_queue_destroy(q)
#define wl_proxy_marshal_flags(p, o, i, v, f, ...) \
	_wldl_client.proxy_marshal_flags(p, o, i, v, f, ##__VA_ARGS__)
#define wl_proxy_marshal_array_flags(p, o, i, v, f, a) \
	_wldl_client.proxy_marshal_array_flags(p, o, i, v, f, a)
#define wl_proxy_marshal(p, o, ...) \
	_wldl_client.proxy_marshal(p, o, ##__VA_ARGS__)
#define wl_proxy_marshal_array(p, o, a) \
	_wldl_client.proxy_marshal_array(p, o, a)
#define wl_proxy_create(f, i) \
	_wldl_client.proxy_create(f, i)
#define wl_proxy_create_wrapper(p) \
	_wldl_client.proxy_create_wrapper(p)
#define wl_proxy_wrapper_destroy(pw) \
	_wldl_client.proxy_wrapper_destroy(pw)
#define wl_proxy_marshal_constructor(p, o, i, ...) \
	_wldl_client.proxy_marshal_constructor(p, o, i, ##__VA_ARGS__)
#define wl_proxy_marshal_constructor_versioned(p, o, i, v, ...) \
	_wldl_client.proxy_marshal_constructor(p, o, i, v, ##__VA_ARGS__)
#define wl_proxy_marshal_array_constructor(p, o, a, i) \
	_wldl_client.proxy_marshal_array_constructor(p, o, a, i)
#define wl_proxy_marshal_array_constructor_versioned(p, o, a, i, v) \
	_wldl_client.proxy_marshal_array_constructor_versioned(p, o, a, i, v)
#define wl_proxy_destroy(p) \
	_wldl_client.proxy_destroy(p)
#define wl_proxy_add_listener(p, i, d) \
	_wldl_client.proxy_add_listener(p, i, d)
#define wl_proxy_get_listener(p) \
	_wldl_client.proxy_get_listener(p)
#define wl_proxy_add_dispatcher(p, df, dd, d) \
	_wldl_client.proxy_add_dispatcher(p, df, dd, d)
#define wl_proxy_set_user_data(p, ud) \
	_wldl_client.proxy_set_user_data(p, ud)
#define wl_proxy_get_user_data(p) \
	_wldl_client.proxy_get_user_data(p)
#define wl_proxy_get_version(p) \
	_wldl_client.proxy_get_version(p)
#define wl_proxy_get_id(p) \
	_wldl_client.proxy_get_id(p)
#define wl_proxy_set_tag(p, t) \
	_wldl_client.proxy_set_tag(p, t)
#define wl_proxy_get_tag(p) \
	_wldl_client.proxy_get_tag(p)
#define wl_proxy_get_class(p) \
	_wldl_client.proxy_get_class(p)
#define wl_proxy_set_queue(p, q) \
	_wldl_client.proxy_set_queue(p, q)
#define wl_display_connect(n) \
	_wldl_client.display_connect(n)
#define wl_display_connect_to_fd(fd) \
	_wldl_client.display_connect_to_fd(fd)
#define wl_display_disconnect(d) \
	_wldl_client.display_disconnect(d)
#define wl_display_get_fd(d) \
	_wldl_client.display_get_fd(d)
#define wl_display_dispatch(d) \
	_wldl_client.display_dispatch(d)
#define wl_display_dispatch_queue(d, q) \
	_wldl_client.display_dispatch_queue(d, q)
#define wl_display_dispatch_queue_pending(d, q) \
	_wldl_client.display_dispatch_queue_pending(d, q)
#define wl_display_dispatch_pending(d) \
	_wldl_client.display_dispatch_pending(d)
#define wl_display_get_error(d) \
	_wldl_client.display_get_error(d)
#define wl_display_get_protocol_error(d, if, id) \
	_wldl_client.display_get_protocol_error(d, if, id)
#define wl_display_flush(d) \
	_wldl_client.display_flush(d)
#define wl_display_roundtrip_queue(d, q) \
	_wldl_client.display_roundtrip_queue(d, q)
#define wl_display_roundtrip(d) \
	_wldl_client.display_roundtrip(d)
#define wl_display_create_queue(d) \
	_wldl_client.display_create_queue(d)
#define wl_display_prepare_read_queue(d, q) \
	_wldl_client.display_prepare_read_queue(d, q)
#define wl_display_prepare_read(d) \
	_wldl_client.display_prepare_read(d)
#define wl_display_cancel_read(d) \
	_wldl_client.display_cancel_read(d)
#define wl_display_read_events(d) \
	_wldl_client.display_read_events(d)
#define wl_log_set_handler_client(h) \
	_wldl_client.log_set_handler_client(h)

#define WAYLAND_CLIENT_CORE_H // Disable standard implementation.
#define WL_DISPLAY_INTERFACE
#define WL_REGISTRY_INTERFACE
#define WL_CALLBACK_INTERFACE
#define WL_COMPOSITOR_INTERFACE
#define WL_SHM_POOL_INTERFACE
#define WL_SHM_INTERFACE
#define WL_BUFFER_INTERFACE
#define WL_DATA_OFFER_INTERFACE
#define WL_DATA_SOURCE_INTERFACE
#define WL_DATA_DEVICE_INTERFACE
#define WL_DATA_DEVICE_MANAGER_INTERFACE
#define WL_SHELL_INTERFACE
#define WL_SHELL_SURFACE_INTERFACE
#define WL_SURFACE_INTERFACE
#define WL_SEAT_INTERFACE
#define WL_POINTER_INTERFACE
#define WL_KEYBOARD_INTERFACE
#define WL_TOUCH_INTERFACE
#define WL_OUTPUT_INTERFACE
#define WL_REGION_INTERFACE
#define WL_SUBCOMPOSITOR_INTERFACE
#define WL_SUBSURFACE_INTERFACE
#include <wayland-client-protocol.h>

int wldl_client_load(const char* libpath);
char* wldl_client_get_error(void);
void wldl_client_unload(void);

#ifdef WLDL_CLIENT_IMPL

#include <dlfcn.h>

struct wayland_client_lib _wldl_client;

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

int wldl_client_load(const char* libpath) {
	libpath = (libpath == NULL) ? "libwayland-client.so" : libpath;
	DLOPEN(libpath);
	DLSYM(display_interface);
	DLSYM(registry_interface);
	DLSYM(callback_interface);
	DLSYM(compositor_interface);
	DLSYM(shm_pool_interface);
	DLSYM(shm_interface);
	DLSYM(buffer_interface);
	DLSYM(data_offer_interface);
	DLSYM(data_source_interface);
	DLSYM(data_device_interface);
	DLSYM(data_device_manager_interface);
	DLSYM(shell_interface);
	DLSYM(shell_surface_interface);
	DLSYM(surface_interface);
	DLSYM(seat_interface);
	DLSYM(pointer_interface);
	DLSYM(keyboard_interface);
	DLSYM(touch_interface);
	DLSYM(output_interface);
	DLSYM(region_interface);
	DLSYM(subcompositor_interface);
	DLSYM(subsurface_interface);
	DLSYM(event_queue_destroy);
	DLSYM(proxy_marshal_flags);
	DLSYM(proxy_marshal_array_flags);
	DLSYM(proxy_marshal);
	DLSYM(proxy_marshal_array);
	DLSYM(proxy_create);
	DLSYM(proxy_create_wrapper);
	DLSYM(proxy_wrapper_destroy);
	DLSYM(proxy_marshal_constructor);
	DLSYM(proxy_marshal_constructor_versioned);
	DLSYM(proxy_marshal_array_constructor);
	DLSYM(proxy_marshal_array_constructor_versioned);
	DLSYM(proxy_destroy);
	DLSYM(proxy_add_listener);
	DLSYM(proxy_get_listener);
	DLSYM(proxy_add_dispatcher);
	DLSYM(proxy_set_user_data);
	DLSYM(proxy_get_user_data);
	DLSYM(proxy_get_version);
	DLSYM(proxy_get_id);
	DLSYM(proxy_set_tag);
	DLSYM(proxy_get_tag);
	DLSYM(proxy_get_class);
	DLSYM(proxy_set_queue);
	DLSYM(display_connect);
	DLSYM(display_connect_to_fd);
	DLSYM(display_disconnect);
	DLSYM(display_get_fd);
	DLSYM(display_dispatch);
	DLSYM(display_dispatch_queue);
	DLSYM(display_dispatch_queue_pending);
	DLSYM(display_dispatch_pending);
	DLSYM(display_get_error);
	DLSYM(display_get_protocol_error);
	DLSYM(display_flush);
	DLSYM(display_roundtrip_queue);
	DLSYM(display_roundtrip);
	DLSYM(display_create_queue);
	DLSYM(display_prepare_read_queue);
	DLSYM(display_prepare_read);
	DLSYM(display_cancel_read);
	DLSYM(display_read_events);
	DLSYM(log_set_handler_client);
	return 0;
}

char* wldl_client_get_error(void) {
	return dlerror();
}

void wldl_client_unload(void) {
	DLCLOSE();
}

#endif // WLDL_CLIENT_IMPL

#endif // WLDL_CLIENT_H
