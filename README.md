# Subtitle.Mixer
CEA708 subtitle mixing on FLV tags.


## Installation
```elixir
def deps do
  [
    {:subtitle_mixer, github: "kim-company/subtitle_mixer"}
  ]
end
```

## Gotchas
### On LFS (if tests are failing
Beware that fixtures are stored using the git LFS protocol. On debian, set it up
with
```
% sudo apt install git-lfs
# Within the repo
% git lfs install
% git lfs pull
```

If you add more fixture files, track them on LFS with `git lfs track <the
files>`.

## Copyright and License
Copyright 2022, [KIM Keep In Mind GmbH](https://www.keepinmind.info/)
Licensed under the [Apache License, Version 2.0](LICENSE)
