# Repository Guidelines

## Project Structure & Module Organization
Each classic BSD game lives in its own directory (for example `adventure/`, `hangman/`, `rogue/`) alongside the original sources and OS X specific tweaks. The top-level `Makefile` iterates through the `SUBDIR` list to build every game, while each directory's makefile handles its own objects and data files. Shared defaults for installation paths and compiler flags live in `Makefile.inc`. Packaging recipes for Homebrew are under `Homebrew/`, and licence details are recorded in `COPYRIGHT`.

## Build, Test, and Development Commands
Install or link `bsdmake` before building; the tree assumes BSD make semantics even though the command is invoked as `make` in some scripts. A typical full build is `CC=clang bsdmake` from the repository root. When clang complains about legacy headers, run `CFLAGS="-std=c11 -Wno-nullability-completeness" bsdmake`. Install binaries with `sudo bsdmake install` (set `PREFIX=$HOME/.local` to override the default). When iterating on a single title, run `bsdmake` in that game's directory, and use `bsdmake clean` to reset artifacts.

## Coding Style & Naming Conventions
Source files follow K&R style C with historic BSD comment blocks; preserve hard tabs for indentation and any alignment spaces in data tables. Follow existing naming: lowercase functions, uppercase macros or constants, and snake_case globals. Avoid introducing C99+ constructs or headers that older clang or gcc releases may reject. No formatter is enforced, so keep edits minimal and match surrounding style.

## Testing Guidelines
There is no automated test harness. After building, launch the target binary directly (for example `./hangman/hangman`) and exercise core gameplay paths. For multiplayer games like `hunt`, confirm the daemon `huntd` starts and accepts local clients. Run `bsdmake clean && bsdmake` before opening a pull request to ensure a clean rebuild.

## Commit & Pull Request Guidelines
Recent history favors short, descriptive summaries in lowercase (for example `add compiler flag for sierra`). Use the imperative mood when adding behavior and mention the affected game directory when possible. Keep related source and data updates in a single commit. Pull requests should state the motivation, list the build or run commands you used, and call out configuration changes or follow up tasks.
