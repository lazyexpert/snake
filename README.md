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

# Roadmap:
- Continue implementation of controller class moving logic from view to controller
- Continue implementation of the game. Final point - gameloop done, start snake moving
