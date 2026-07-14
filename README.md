# cpp-basics
Cpp 20 basics with explanations following website learncpp from unit 4 (types)

---

### To run the docker container:

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

