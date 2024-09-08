# wldl
#### A stb style library for loading Wayland at runtime

## Support
Replaces:

- `wayland-client.h` -> `wldl-client.h`
- `wayland-egl.h` -> `wldl-egl.h`

> [!NOTE]
> You will still need the development packages that provide the wayland headers and the `*.so` files.

## Usage
Choose a file in which to put the implementation and define

- `WLDL_CLIENT_IMPL` for `wldl-client.h`
- `WLDL_EGL_IMPL` for `wldl-egl.h`

before including the header. The function calls and interfaces remain the same.

> [!NOTE]
> Before calling **any** function from the libraries, you must first call `wldl_<library>_load()`.
