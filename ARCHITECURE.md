project/
├── CMakeLists.txt
├── src/
│   ├── foo/
│   │   └── app1.cpp
│   ├── bar/
│   │   └── app2.cpp
│   └── test.cpp
└── include/
    ├── foo/
    │   └── app1.hpp
    ├── bar/
    │   └── app2.hpp
    └── test.hpp


Each file is under the corresponding learncpp section. If it need any includes, it will have the same name with corresponding folder chapter under the *include* directory.

## CI/CD files description

* CMakePresets.json
Used with vscode cmake tools extensions, is just a set of shortcuts to cmake configurations and builds.

* .devcontainer/devcontainer.json
As Dockerfile is the linux configuration, the devcontainer.json is the vscode configuration, including automated installation of extensions and their configurations.

* .vscode/launch.json
Defines with the file, whose name and path is always the same, different run types and options for vscode to know how to launch a program, including debugging options.

