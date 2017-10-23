# Snake
Classical snake game implemented with C++ and SFML library.

# Features
All gaming dimensions are responsive to the window dimensions.
The behavior is close to the responsive web pages behavior.

# Dependencies
[SFML](http://www.sfml-dev.org/) - find your install way. 

For Ubuntu distros:
```
sudo apt-get install libsfml-dev
```


# Start application
Shell script gently compiles application and starts it 
```
./start.sh
```

# Compile manually 
```
make
```

# Start manually 
```
./build/snake
```

# Environment
Developing and testing on Linux Mint 18 Cinnamon. 

Whenever you face compilation issues. Edit Makefile to add your compilation flags.

# TODO:
- Create 'controller' file and remove all logic from 'view' file
