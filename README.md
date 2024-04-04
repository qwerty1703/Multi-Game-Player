# Multi-Game-Player
Offers classic titles like Tic Tac Toe, Hangman, Car Game, Flappy Bird, Dino Run, and Space Shooter. It showcases C++'s versatility through text-based navigation, bypassing the need for a graphical interface.


The project utilizes the concepts of inheritance and runtime polymorphism to integrate eight games into a single console application. Inheritance allows for the creation of derived classes inheriting properties and characteristics from a base class, enabling the specialized implementation of each game. Runtime polymorphism is achieved through virtual functions and function overriding, allowing the compiler to resolve function calls dynamically at runtime.

The parent class, "Game," serves as the base for all games, providing common member functions such as "instruction()" and "play()." Each game is implemented as a subclass of "Game," overriding these functions to tailor the gameplay experience. 

The program presents a list of available games to the user, prompting them to choose a game by entering a corresponding number. Utilizing a switch-case structure, the program instantiates the object of the selected game's subclass and calls its respective functions. 

This design ensures that each game retains its unique functionality while sharing common features defined in the base class. The inheritance hierarchy enables efficient code reuse and maintenance, allowing for the seamless integration of new games in the future.
