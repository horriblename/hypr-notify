# Notice

`hyprctl notify` is now builtin, the plugin is deprecated. You can still use the statnot config as a notification daemon though. You'll need to modify the file a bit, figure it out yourself :P (and make a PR if you do)

# Hypr-notify

Test hyprland plugin that exposes the `notify` dispatcher

usage:

```
hyprctl dispatch notify 'Notification text'
```

## Compiling

```sh
make all
```

## As a notification daemon

to use it as a notification daemon, install [statnot](https://github.com/halhen/statnot) and run it 
with the provided config file 
`statnot-config.py`

```sh
hyprctl plugin load /path/to/hypr-notify.so
statnot statnot-config.py
```
