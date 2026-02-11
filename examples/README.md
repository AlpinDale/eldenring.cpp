# eldenring.cpp examples

These are small Windows DLLs intended for injection/testing. They use the
generated headers and a couple of lightweight helpers (pattern scan + logging)
to validate things in-game.

## Build

From the `eldenring.cpp` directory:

```
cmake -S . -B build -DELDENRING_CPP_BUILD_EXAMPLES=ON
cmake --build build --config Release
```

Output DLLs are written to:

```
build/examples/<example-name>/
```

The example launcher is written to:

```
build/examples/erd_example_launcher.exe
```

## Examples

### `erd_example_apply_speffect`
Press **O** to apply speffect `4330` to the main player, **P** to remove it.
Logs to `erd_example_apply_speffect.log`.

### `erd_example_player_info`
Press **F6** to log player position/team info.
Logs to `erd_example_player_info.log`.

## Launcher usage

```
erd_example_launcher.exe --dll <path> [--exe <path>]
```

If `--exe` is omitted, it auto-detects the Steam install of Elden Ring.

## Notes

- These examples rely on a few hardcoded offsets and signatures. If the game
  updates, the examples may need their offsets updated.
- They assume the examples are injected into a running Elden Ring process.
