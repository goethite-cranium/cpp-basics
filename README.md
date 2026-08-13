# cpp-basics
Cpp 20 basics with explanations following website learncpp from unit 4 (types)

---

## Run the docker container just for release

1. Navigate to docker folder
```
cd <project>
cd docker
```

2. Build image
```
docker compose build
```

3. Run service
```
docker compose up cpp20
```

(Steps 2 and 3 can be merged with ```docker compose up --build```)

4. Attatch interactive sell
```
docker exec -it cpp-basics
```

### Build source code
Simply execute 
```
cmake -B build -G Ninja
cmake --build build
```

The executables will be built in the ```./build/<unit-folder>/<src-name>```


---

### Building source code
The attached cli can be used to set compiler configuration, compile source code and execute code.

Debugging:
```
cmake -B build-debug -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```
Debugging programs must not be run normally through command. Instead, vscode instance must be connected to interpret and link debugging symbols.

Release:
```
cmake -B build-release -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build 
```

We can use more jobs to make it faster with -j flag.

But, we can use presets from CMakePresets.json, which are shortcuts for these commands that do the same with an alias:

Debugging:
```
cmake --preset debug
cmake --build --preset build-debug
```

Release:
```
cmake --preset release
cmake --build --preset build-release
```

---

## Executing debugging programs
One can debug a program with console commands with
```
gdb ./build-debug/unit_test/test
```
then, use commands with the interactive shell like run, breakpoint, etc.

But, normally, it is desired to use the debugging interactive GUI from vscode. To make it, we MUST change the procedure to build, run and attach the container. To do this, we have to:

0. Install extensions if needed
* dev contaniers
* c/c++ dev tools
* cmake tools
* cmake
Inside the container this is not necessary, since we have the file .devcontainer/devcontainer.json, where the json specified automated installation of extensions and attaching.

1. Build the container  
```
cd docker
docker compose build
```
If we have created a wrong container prevously, we shold put that down and rebuild with ```--no-cache``` flag.

2. Reopen vscode on the container
Open the command pallet with ctrl+shift+p and choose dev containers option ```Dev Containers: Reopen in Container```

3. Compile the code with debug preset
```
cmake --preset debug
cmake --build --preset build-debug
```

4. Change target debugging file in .vscode/launch.json

5. Execute the debugger with F5 or debug and run

.devcontainer/devcontainer.json installs vscode extension lldb as debugger interface instead of cppdbg, which is broken.

F5 -> execute or continue until breakpoint
F10 -> Step over
F11 -> Step into
Shift+F11 -> Step out

We can use conditional breakpoints editing breakpoint
